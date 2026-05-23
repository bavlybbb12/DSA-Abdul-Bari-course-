#include <iostream>
using namespace std;

struct queue {

    int* arr;
    int front ;
    int rear ;
    int capacity ;

};

void create_queue ( queue*& q , int capacity ) {

    q = new queue ;
    q->capacity = capacity ;
    q->front = 0 ;
    q->rear = 0 ;
    q->arr = new int [ capacity ] ;

}

bool full ( const queue* q ) {
    return q->rear == q->capacity ;
}

bool empty ( const queue* q ) {
    return q->front == q->rear ;
}

void enqueue ( queue* q , int value ) {

    if ( full ( q ) ) { cout << "Queue is full" << endl ; return ; }
    q->arr[ q->rear ] = value ;
    q->rear++ ;

}

void dequeue ( queue* q ) {

    if ( empty ( q ) ) { cout << "Queue is empty" << endl ; return ; }
    q->front++ ;

}

void display ( const queue* q ) {

    for ( int i = q->front ; i < q->rear ; i++ ) {
        cout << q->arr[i] << " " ;
    }
    cout << endl ;

}

void destroy ( queue*& q ) {

    delete[] q->arr ;
    delete q ;
    q = nullptr ;

}

int main () {

    queue* q ;
    create_queue ( q , 5 ) ;

    enqueue ( q , 1 ) ;
    enqueue ( q , 2 ) ;
    enqueue ( q , 3 ) ;
    enqueue ( q , 4 ) ;
    enqueue ( q , 5 ) ;
    enqueue ( q , 6 ) ;

    display ( q ) ;

    dequeue ( q ) ;
    dequeue ( q ) ;

    display ( q ) ;

    destroy ( q ) ;

}