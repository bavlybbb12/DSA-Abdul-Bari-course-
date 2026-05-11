#include <iostream>
#include <algorithm>
#include <vector>
using namespace std ;

struct Node {

    int data ;
    Node* next ;

};

struct doublynode {

    int data ;
    doublynode* next ;
    doublynode* prev ;

};

void create(int arr[], int n, Node*& head) {
    if (n == 0) return;

    head = new Node;
    head->data = arr[0];
    head->next = nullptr;
    
    Node* tail = head;

    for (int i = 1; i < n; i++) {
        Node* temp = new Node;
        temp->data = arr[i];
        temp->next = nullptr;
        tail->next = temp;
        tail = temp;
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
    
    Node* current = head ;
    while ( current != nullptr ) {
        
        Node* nextNode = current->next ;
        delete current ;
        current = nextNode ;
        
    }
    head = nullptr ;
    
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

string has_loop ( const Node* head ) {

    if ( head == nullptr ) return "No loop";

    const Node* slow = head ;
    const Node* fast = head ;

    while ( fast && fast->next ) {

        slow = slow->next ;
        fast = fast->next->next ;

        if ( slow == fast ) return "Loop detected";
    }

    return "No loop";

}

void display_circular ( const Node* head ) {
    
    if ( head == nullptr ) return ;

    const Node* current = head ;
    do {
        cout << current->data << " " ;
        current = current->next ;
    } while ( current != head ) ;

}

void destroy_circular ( Node*& head ) {
    
    if ( head == nullptr ) return ;

    Node* current = head->next ;
    while ( current != head ) {
        
        Node* nextNode = current->next ;
        delete current ;
        current = nextNode ;
        
    }
    
    delete head ;
    head = nullptr ;
    
}

int count_circular ( const Node* head ){

    if ( head == nullptr ) return 0 ;

    int count = 0 ;
    const Node* current = head ;
    do {
        count++ ;
        current = current->next ;
    } while ( current != head ) ;

    return count ;
}

void insert_circular ( Node*& head , int index , int value ) {

    Node* tmp = new Node ;
    tmp->data = value ;
    tmp->next = nullptr ;

    if ( index < 0 || index > count_circular( head ) ) {
        cout << "Invalid index. Index should be non-negative." << endl ;
        delete tmp ;
        return ;
    }

    if ( index == 0 ) {

        if ( head == nullptr ) {
            tmp->next = tmp ;
            head = tmp ;
        }
        else {
            Node* tail = head ;
            while ( tail->next != head ) tail = tail->next ;
            tmp->next = head ;
            tail->next = tmp ;
            head = tmp ;
        }
        return ;

    }
    
    else {

        Node* current = head ;
        for ( int i = 0 ; i < index - 1 ; i++ ) current = current->next ;
        tmp->next = current->next ;
        current->next = tmp ;
    }


}

void remove_circular ( Node*& head , int index ) {

    if ( !head ) {cout << " Empty list." ; return ;}

    if ( index < 0 || index >= count_circular ( head ) ) { cout << "Invalid index" << endl ; return ; }

    if ( index == 0 ) {

        if ( head->next == head  ) {delete head ; head = nullptr ; return ;}
        Node* tail = head ;
        while ( tail->next != head ) tail = tail->next ;
        tail->next = head->next ;
        delete head ;
        head = tail->next ;
        return ;

    }

    Node* current = head ;
    for ( int i = 0 ; i < index - 1 ; i++ ) current = current-> next ;
    Node* temp = current->next ;
    current->next = temp->next ;
    delete temp ;

}

void create_circular ( int arr[] , int n , Node*& head ) {

    if ( n == 0 ) return ;

    head = new Node ;
    head->data = arr[0] ;
    head->next = head ;

    Node* tail = head ;
    for ( int i = 1 ; i < n ; i++ ) {

        Node* temp = new Node ;
        temp->data = arr[i] ;
        temp->next = head ;
        tail->next = temp ;
        tail = temp ;

    }

}

void create_doubly ( int arr[] , int n , doublynode*& head ) {

    if ( n == 0 ) return ;
    
    head = new doublynode ;
    head->data = arr[0] ;
    head->prev = nullptr ;
    head->next = nullptr ;

    doublynode* tail = head ;
    for ( int i = 1 ; i < n ; i++ ) {
        
        doublynode* temp = new doublynode ;
        temp->data = arr[i] ;
        temp->prev = tail ;
        temp->next = nullptr ;
        tail->next = temp ;
        tail = temp ;

    }

}

void insert_doubly ( doublynode*& head , int index , int value ) {

    if ( index < 0 ){cout << "Invalid index.\n"; return;}
    doublynode* temp = new doublynode ;
    temp->data = value ;
    temp->prev = nullptr ;
    temp->next = nullptr ;

    if ( index == 0 ) {

        temp->next = head ;
        if ( head ) head->prev = temp ;
        head = temp ;
        return ;

    }
    
    else {

        doublynode* current = head ;
        for ( int i = 0 ; i < index - 1 && current ; i++ ) {
            current = current->next ;
        }
        if ( current == nullptr ) {
            cout << "Index out of bounds.\n";
            delete temp ;
            return ;
        }
        temp->next = current->next ;
        temp->prev = current ;
        if ( current->next ) current->next->prev = temp ;
        current->next = temp ;

    }
}

void destroy_doubly ( doublynode*& head ) {

    doublynode* current = head ;
    while ( current ) {
        
        doublynode* nextNode = current->next ;
        delete current ;
        current = nextNode ;
        
    }
    head = nullptr ;
    
}

void display_doubly ( const doublynode* head ) {

    while ( head ) {
        
        cout << head->data << " " ;
        head = head->next ;

    }
}

void deleting_doubly ( doublynode*& head , int index ) {

    if ( index < 0 || head == nullptr ) { cout << "Invalid index.\n"; return ; }

    if ( index == 0 ) {

        doublynode* temp = head ;
        head = head->next ;
        if ( head ) head->prev = nullptr ;
        delete temp ;
        return ;

    }

    doublynode* current = head ;
    for ( int i = 0 ; i < index && current ; i++ ) current = current->next ;
    if ( current == nullptr ) {
        cout << "Index out of bounds.\n";
        return ;
    }
    current->prev->next = current->next ;
    if ( current->next ) current->next->prev = current->prev ;
    delete current ;

}

int main () {

    Node* list = nullptr ;

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

    cout << "Loop detection: " << has_loop( merged ) << endl ;

    Node* circular = new Node ;
    create_circular ( arr , sizeof(arr) / sizeof(arr[0]) , circular ) ;
    cout << "Circular linked list: " ;
    display_circular ( circular ) ;
    cout << endl ;
    cout << "Count in circular linked list: " << count_circular ( circular ) << endl ;

    insert_circular ( circular , 1 , 2 ) ;
    cout << "After inserting 2 at index 1 in circular linked list: " ;
    display_circular ( circular ) ;
    cout << endl ;

    remove_circular ( circular , 0 ) ;
    cout << "After removing element at index 0 in circular linked list: " ;
    display_circular ( circular ) ;
    cout << endl ;

    doublynode* first = nullptr ;

    create_doubly( arr , sizeof(arr) / sizeof(arr[0]) , first ) ;
    insert_doubly ( first , 2 , 10 ) ;
    cout << "Doubly linked list after inserting 10 at index 2: " ;
    display_doubly ( first ) ;
    cout << endl ;

    deleting_doubly ( first , 2 ) ;
    cout << "Doubly linked list after deleting element at index 2: " ;
    display_doubly ( first ) ;
    cout << endl ;

    destroy_circular ( circular ) ;
    destroy ( merged ) ;
    list = nullptr ;
    head1 = nullptr ;
    destroy ( head2 ) ;
    destroy_doubly ( first ) ;
    
    
    return 0 ;
}
