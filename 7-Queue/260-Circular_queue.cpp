#include <iostream>
using namespace std;

struct queue {
    int* arr;
    int front;
    int rear;
    int capacity;
};

void create_queue(queue*& q, int capacity) {
    q = new queue;
    q->capacity = capacity;
    q->front = 0;
    q->rear = 0;
    q->arr = new int[capacity];
}

bool full(const queue* q) {
    return (q->rear + 1) % q->capacity == q->front;
}

bool empty(const queue* q) {
    return q->front == q->rear;
}

void enqueuecircular(queue* q, int value) {
    if (full(q)) { 
        cout << "Queue is full! Cannot enqueue " << value << endl; 
        return; 
    }
    q->arr[q->rear] = value;
    q->rear = (q->rear + 1) % q->capacity;
}

void dequeuecircular(queue* q) {
    if (empty(q)) { 
        cout << "Queue is empty!" << endl; 
        return; 
    }
    q->front = (q->front + 1) % q->capacity;
}

void display(const queue* q) {
    if (empty(q)) {
        cout << "Queue is empty" << endl;
        return;
    }
    
    int i = q->front;
    while (i != q->rear) {
        cout << q->arr[i] << " ";
        i = (i + 1) % q->capacity; 
    }
    cout << endl;
}

void destroy(queue*& q) {
    delete[] q->arr;
    delete q;
    q = nullptr;
}

int main() {
    queue* q;
    create_queue(q, 5); 

    enqueuecircular(q, 1);
    enqueuecircular(q, 2);
    enqueuecircular(q, 3);
    enqueuecircular(q, 4);
    enqueuecircular(q, 5); 
    display(q);

    dequeuecircular(q);
    dequeuecircular(q);

    display(q); 

    enqueuecircular(q, 8);
    enqueuecircular(q, 9);
    
    display(q); 

    destroy(q);
    return 0;
}