#include <iostream>
using namespace std ;

struct Node {

    int data ;
    Node* next ;

    Node ( int d ) : data(d) , next(nullptr) {}

};

struct Stack {
    
    Node* top ;

    Stack () : top(nullptr) {}

};

void create ( Stack*& stack , int arr[] , int size ) {

    if ( stack != nullptr ) { cout << "Stack is already initialized" << endl; return; }
    if ( size <= 0 ) { cout << "Invalid size" << endl; return; }
    stack = new Stack();

    for ( int i = size-1 ; i >= 0 ; i -- ) {

        Node* newNode = new Node(arr[i]) ;
        newNode->next = stack->top ;
        stack->top = newNode ;

    }

}

void push ( Stack*& stack , int item ) {

    if ( !stack ) { cout << "Stack is not initialized" << endl; return; }

    Node* newNode = new Node(item) ;
    newNode->next = stack->top ;
    stack->top = newNode ;

}

void pop ( Stack*& stack ) {

    if ( !stack ) { cout << "Stack isn't initialized" << endl; return;}
    if ( !stack->top ) { cout << "Stack underflow" << endl; return; }

    Node* temp = stack->top ;
    stack->top = stack->top->next ;
    delete temp ;

}

void peek ( const Stack* stack , int index ) {

    if ( !stack ) {cout << "Stack isn't initialized" << endl; return;}
    if ( !stack->top ) { cout << "Stack underflow" << endl; return; }
    if ( index < 0 ) { cout << "Invalid index" << endl; return; }

    Node* current = stack->top ;
    for ( int i = 0 ; current && i < index ; i ++ ) {
        current = current->next ;
    }
    if ( current ) {
        cout << "Element at index " << index << " is " << current->data << endl;
    } else {
        cout << "Index out of bounds" << endl;
    }
}

void top ( const Stack* stack ) {

    if ( !stack ) { cout << "Stack isn't initialized" << endl; return; }
    if ( !stack->top ) { cout << "Stack underflow" << endl; return; }
    cout << "Top element is: " << stack->top->data << endl;

}

void isEmpty ( const Stack* stack ) {

    if ( !stack ) { cout << "Stack isn't initialized" << endl; return; }
    cout << "Stack is " << ( stack->top == nullptr ? "empty" : "not empty" ) << endl;

}

void display ( const Stack* stack ) {

    if ( !stack ) { cout << "Stack isn't initialized" << endl; return; }
    if ( !stack->top ) { cout << "Stack underflow" << endl; return; }

    cout << "Stack elements: ";
    Node* current = stack->top ;
    while ( current ) {
        cout << current->data << " ";
        current = current->next ;
    }
    cout << endl;

}

void destroy ( Stack*& stack ) {

    if ( !stack ) { cout << "Stack isn't initialized" << endl; return; }
    Node* current = stack->top ;
    while ( current ) {
        Node* temp = current ;
        current = current->next ;
        delete temp ;
    }
    delete stack ;
    stack = nullptr ;

}

int main () {

    Stack* stack = nullptr ;
    int arr[] = { 1 , 2 , 3 , 4 , 5 } ;
    create(stack, arr, 5) ;
    display(stack) ;

    push(stack, 6) ;
    display(stack) ;

    pop(stack) ;
    display(stack) ;

    peek(stack, 2) ;

    top(stack) ;

    isEmpty(stack) ;
    display(stack) ;
    
    destroy(stack) ;

    return 0 ;

}