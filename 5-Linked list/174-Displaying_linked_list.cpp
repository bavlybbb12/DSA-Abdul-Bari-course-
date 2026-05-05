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

int main () {

    Node* list = new Node ;
    list->next = nullptr ;

    int arr [] = { 1 , 2 , 3 , 4 , 5 } ;

    create ( arr , sizeof(arr) / sizeof(arr[0]) , list ) ;

    display ( list ) ;
    cout << endl ;

    display_recursively ( list ) ;

    destroy ( list ) ;
    list = nullptr ;
    

}