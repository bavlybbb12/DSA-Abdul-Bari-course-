#include <iostream>
using namespace std ;

struct Node {

    int data ;
    struct Node* next ;

};

void create( int arr [] , int n , Node* head) {

    Node* temp , * tail ;
    
    head->data = arr [ 0 ] ;
    head->next = nullptr ;
    tail = head ;
    
    for ( int i = 1 ; i < n ; i++ ) {

        temp = new Node ;
        temp->data = arr [ i ] ;
        temp->next = nullptr ;
        tail->next = temp ;
        tail = temp ;

    }

}

void display (  Node* head ) {

    while ( head ) {
        
        cout << head->data << " " ;
        head = head->next ;

    }
}

void display_recursively ( Node* head ) {

    if ( head == nullptr ) return ;
    cout << head->data << " " ;
    display_recursively ( head->next ) ;
}

void destroy ( Node* head ) {

    if ( head == nullptr ) return ;
    destroy ( head->next ) ;
    delete head ;

}

void count ( Node* head ) {

    int count = 0;
    while ( head ) {
        
        count++ ;
        head = head->next ;

    }
    cout << "Number of nodes: " << count << endl;

}

int count_recursivly ( Node* head ) {

    if ( head ) return 1 + count_recursivly ( head->next ) ;
    return 0 ;

}

void sum ( Node* head ) {

    int sum = 0 ;
    while ( head ) {

        sum += head->data ;
        head = head->next ;

    }

    cout << "Sum of all elements: " << sum << endl;

} 

int sum_recursively ( Node* head ) {

    if ( head ) return head->data + sum_recursively ( head->next ) ;
    return 0 ;

}

void maximum ( Node* head ) {
    
    if ( head == nullptr ) {
        cout << "List is empty." << endl ;
        return ;
    }

    int max_value = head->data ;
    head = head->next ;

    while ( head ) {

        if ( head->data > max_value ) {
            max_value = head->data ;
        }
        head = head->next ;

    }

    cout << "Maximum element in the linked list: " << max_value << endl;

}

void search ( Node* head , int key ) {

    int index = 0 ;
    while ( head ) {

        if ( head->data == key ) {
            cout << "Element " << key << " found at index: " << index << endl ;
            return ;
        }
        head = head->next ;
        index++ ;

    }

    cout << "Element " << key << " not found in the linked list." << endl ;

}

void insert ( Node*& head , int index , int value ) {

    Node* temp = new Node ;
    temp->data = value ;
    temp->next = nullptr ;

    if ( index < 0 || index > count_recursivly( head ) ) {
        cout << "Invalid index. Index should be non-negative." << endl ;
        delete temp ;
        return ;
    }

        if ( index == 0 ) {

        temp->next = head ;
        head = temp ;
        return ;

    }

    else {

        Node* current = head ;
        for ( int i = 0 ; i < index - 1 ; i++ ) {
            current = current->next ;
        }
        temp->next = current->next ;
        current->next = temp ;
    }

}

int main () {

    Node* list = new Node ;
    list->next = nullptr ;

    int arr [] = { 1 , 2 , 3 , 4 , 5 } ;

    create ( arr , sizeof(arr) / sizeof(arr[0]) , list ) ;

    display ( list ) ;
    cout << endl ;

    display_recursively ( list ) ;
    cout << endl ;

    count ( list ) ;
    cout << "Recursive count: " << count_recursivly ( list ) << endl ;

    sum ( list ) ;

    cout << endl ;
    cout << "Recursive sum: " << sum_recursively ( list ) << endl ;

    maximum ( list ) ;

    search ( list , 3 ) ;

    insert ( list , 2 , 10 ) ;
    cout << "After inserting 10 at index 2: " ;
    display ( list ) ;
    cout << endl ;

    destroy ( list ) ;
    list = nullptr ;
    

}