#include <iostream>
#include <algorithm>
#include <vector>
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

void display ( const Node* head ) {

    while ( head ) {
        
        cout << head->data << " " ;
        head = head->next ;

    }
}

void display_recursively ( const Node* head ) {

    if ( head == nullptr ) return ;
    cout << head->data << " " ;
    display_recursively ( head->next ) ;
}

void destroy ( Node*& head ) {

    if ( head == nullptr ) return ;
    destroy ( head->next ) ;
    delete head ;

}

void count ( const Node* head ) {

    int count = 0;
    while ( head ) {
        
        count++ ;
        head = head->next ;

    }
    cout << "Number of nodes: " << count << endl;

}

int count_recursivly ( const Node* head ) {

    if ( head ) return 1 + count_recursivly ( head->next ) ;
    return 0 ;

}

void sum ( const Node* head ) {

    int sum = 0 ;
    while ( head ) {

        sum += head->data ;
        head = head->next ;

    }

    cout << "Sum of all elements: " << sum << endl;

} 

int sum_recursively ( const Node* head ) {

    if ( head ) return head->data + sum_recursively ( head->next ) ;
    return 0 ;

}

void maximum ( const Node* head ) {
    
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

void search ( const Node* head , int key ) {

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

void remove ( Node*& head , int index ) {

    if ( index < 0 || index >= count_recursivly( head ) ) { cout << "Invalid syntax" << endl ; return ; }
    if ( index == 0 ) {

        Node* temp = head ;
        head = head-> next ;
        delete temp ;
        return ;
    }

    Node* current = head ;
    for ( int i = 0 ; i < index - 1 ; i++ ) current = current-> next ;
    Node* temp = current->next ;
    current->next = temp->next ;
    delete temp ;

}

void sort_verify(const Node* head) {
    
    if (head == nullptr || head->next == nullptr) {
        cout << "List is empty or has one element." << endl;
        return;
    }

    bool asc = true, desc = true;
    const Node* current = head;
    
    while (current->next) {
        if (current->data > current->next->data) asc = false;
        if (current->data < current->next->data) desc = false;
        if (!asc && !desc) break;
        current = current->next;
    }

    if (asc && desc) cout << "All elements are equal." << endl;
    else if (asc) cout << "Sorted in ascending order." << endl;
    else if (desc) cout << "Sorted in descending order." << endl;
    else cout << "List is not sorted." << endl;

}

void duplicate ( Node*& head ) {

    if ( head == nullptr ) return ;

    Node* current = head ;
    while ( current->next ) {

        if ( current->data == current->next->data ) {

            Node* temp = current->next ;
            current->next = temp->next ;
            delete temp ;

        }
        else {
            current = current->next ;
        }

    }

}

void reverse ( Node*& head ) {

    Node* prev = nullptr ;
    Node* current = head ;
    Node* next = nullptr ;

    while ( current ) {

        next = current->next ;
        current->next = prev ;
        prev = current ;
        current = next ;

    }
    head = prev ;

}

Node* reverse_recursively ( Node*& current , Node* prev = nullptr ) {

    if ( current == nullptr ) return prev ;
    Node* next = current->next ;
    current->next = prev ;
    return reverse_recursively ( next , current ) ;

}

void concatenate ( Node* head1 , Node* head2 , Node*& concatenated ) {


    if ( head1 == nullptr ) {
        concatenated = head2 ;
        return ;
    }
    if ( head2 == nullptr ) {
        concatenated = head1 ;
        return ;
    }

    Node* tail = head1 ;
    while ( tail->next ) tail = tail->next ;
    tail->next = head2 ;
    concatenated = head1 ;

}

void sort ( Node*& head ) {

    Node* current = head ;
    while ( current ) {
        Node* index = current->next ;
        while ( index ) {

            if ( current->data > index->data ) {
                swap ( current->data , index->data ) ;
            }
            index = index->next ;
        }
        current = current->next ;
    }

}

Node* merge ( Node* head1 , Node* head2 , Node*& merged ) {

    if ( !head1 ) { merged = head2 ; return merged ;}
    if ( !head2 ) { merged = head1 ; return merged ;}

    if ( head1->data < head2->data ) {
        merged = head1 ;
        merged->next = merge ( head1->next , head2 , merged->next ) ;
    }
    else {
        merged = head2 ;
        merged->next = merge ( head1 , head2->next , merged->next ) ;
    }

    return merged ;

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

    remove ( list , 2 ) ;
    cout << "After removing element at index 2: " ;
    display ( list ) ;
    cout << endl ;

    sort_verify ( list ) ;

    duplicate ( list ) ;
    cout << "After removing duplicates: " ;
    display ( list ) ;
    cout << endl ;

    reverse ( list ) ;
    cout << "After reversing the linked list: " ;
    display ( list ) ;
    cout << endl ;

    list = reverse_recursively ( list ) ;
    cout << "After reversing the linked list recursively: " ;
    display ( list ) ;
    cout << endl ;

    Node* merged ;
    Node* head1 = list ;
    Node* head2 = nullptr ;
    merge ( head1 , head2 , merged ) ;
    cout << "Merged list: " ;
    display( merged ) ;

    destroy ( list ) ;
    list = nullptr ;
    

}