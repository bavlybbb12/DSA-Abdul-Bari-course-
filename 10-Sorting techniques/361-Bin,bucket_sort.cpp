#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

void insert(Node*& head, int val) {
    Node* newNode = new Node(val);
    if (head == nullptr) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = newNode;
}

int deleteNode(Node*& head) {
    if (head == nullptr) return -1;
    
    Node* temp = head;
    head = head->next; 
    
    int val = temp->data;
    delete temp;       
    return val;
}

void binSort(vector<int>& arr) {
    if (arr.empty()) return;

    int max_val = *max_element(arr.begin(), arr.end());

    vector<Node*> bins(max_val + 1, nullptr);

    for (int i = 0; i < arr.size(); i++) {
        insert(bins[arr[i]], arr[i]);
    }

    int index = 0;
    for (int i = 0; i <= max_val; i++) {
        while (bins[i] != nullptr) {
            arr[index++] = deleteNode(bins[i]); 
        }
    }
}

int main() {
    vector<int> arr = {8, 3, 2, 8, 5, 2, 3};
    
    binSort(arr);
    
    for(int num : arr) cout << num << " ";
    cout << endl;
    
    return 0;
}