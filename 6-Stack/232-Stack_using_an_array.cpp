#include <iostream>
using namespace std;

struct Stack {

    int top;
    int capacity;
    int* arr;

    Stack () : top(-1), capacity(0), arr(nullptr) {}
    Stack ( int cap, int* a ) : top(-1), capacity(cap), arr(a) {}

};

void push ( Stack*& stack , int item ) {

    if ( stack == nullptr ) { cout << "Stack is not initialized" << endl; return; }
    if ( stack->top == stack->capacity - 1 ) { cout << "Stack overflow" << endl; return; }
    stack->arr[++ stack->top] = item;

}

void pop ( Stack*& stack ) {

    if ( stack == nullptr ) { cout << "Stack isnt initialized" << endl; return; }
    if ( stack->top == -1 ) { cout << "Stack underflow" << endl; return; }
    stack->arr[-- stack->top + 1] = 0;

}

void peek ( const Stack* stack , int index ) {

    if ( stack == nullptr ) { cout << "Stack isnt initialized" << endl; return; }
    if ( stack->top == -1 ) { cout << "Stack underflow" << endl; return; }
    if ( index < 0 || index > stack->top ) { cout << "Invalid index" << endl; return; }
    cout << "Element at index " << index << " is: " << stack->arr[index] << endl;

}

void top ( const Stack* stack ) {

    if ( stack == nullptr ) { cout << "Stack isnt initialized" << endl; return; }
    if ( stack->top == -1 ) { cout << "Stack underflow" << endl; return; }
    cout << "Top element is: " << stack->arr[stack->top] << endl;

}

void isEmpty ( const Stack* stack ) {

    if ( stack == nullptr ) { cout << "Stack isnt initialized" << endl; return; }
    cout << "Stack is " << ( stack->top == -1 ? "empty" : "not empty" ) << endl;

}

void isFull ( const Stack* stack ) {

    if ( stack == nullptr ) { cout << "Stack isnt initialized" << endl; return; }
    cout << "Stack is " << ( stack->top == stack->capacity - 1 ? "full" : "not full" ) << endl;

}

void display ( const Stack* stack ) {

    if ( stack == nullptr ) { cout << "Stack isnt initialized" << endl; return; }
    if ( stack->top == -1 ) { cout << "Stack underflow" << endl; return; }
    cout << "Stack elements: ";
    for ( int i = stack->top ; i >= 0 ; i -- ) {
        cout << stack->arr[i] << " ";
    }
    cout << endl;

}

int main() {

    Stack* stack = new Stack(100, new int[100]);
    cout << "Stack created with capacity: " << stack->capacity << endl;

}