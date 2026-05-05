using namespace std;

struct Node {

    int data;
    struct Node* next;

};

int main() {

    struct Node* p ;
    p = new Node;
    p->data = 10;
    p->next = nullptr;

    return 0;
}