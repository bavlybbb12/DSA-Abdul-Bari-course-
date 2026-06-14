#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class HashTable {
private: 
    struct Node {
        int data;
        Node* next;
        Node(int val) : data(val), next(nullptr) {}
    };

    vector<Node*> table;

    void insert_sorted(Node*& head, int val) {
        Node* newNode = new Node(val);
        if (!head || head->data >= val) {
            newNode->next = head;
            head = newNode;
            return;
        }
        Node* current = head;
        while (current->next && current->next->data < val) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }

    void display(Node* head) {
        while (head) {
            cout << head->data << " ";
            head = head->next;
        }
        cout << endl;
    }

    void destroy(Node*& head) {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
        head = nullptr;
    }

    bool search(Node* head, int val) {
        while (head) {
            if (head->data == val) return true;
            if (head->data > val) return false;
            head = head->next;
        }
        return false;
    }

    bool deleteNode(Node*& head, int val) {
        if (!head) return false;
        if (head->data == val) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return true;
        }
        Node* current = head;
        while (current->next && current->next->data != val) {
            current = current->next;
        }
        if (current->next) {
            Node* temp = current->next;
            current->next = current->next->next;
            delete temp;
            return true;
        }
        return false; 
    }

    int hashFunction(int key) {
        return abs(key) % table.size();
    }

public:
    HashTable(int size = 10) {
        table.resize(size, nullptr); 
    }

    ~HashTable() {
        for (Node* head : table) {
            destroy(head);
        }
    }

    void insert(int key) {
        int index = hashFunction(key);
        insert_sorted(table[index], key);
    }

    void display() {
        for (size_t i = 0; i < table.size(); ++i) {
            cout << "Index " << i << ": ";
            display(table[i]);
        }
    }

    bool search(int key) {
        int index = hashFunction(key);
        return search(table[index], key);
    }

    bool deleteKey(int key) {
        int index = hashFunction(key);
        return deleteNode(table[index], key);
    }
};