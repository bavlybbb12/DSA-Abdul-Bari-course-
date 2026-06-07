#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std ;

struct Node {

    int data;
    Node* left;
    Node* right;
    
    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }

};

class BinaryTree {
public:

    Node* root;
    BinaryTree() {root = nullptr ;}

    void Create () {

        int val;
        queue<Node*> q;

        cout << "Enter the value of the root node: " << endl;
        cin >> val;
        root = new Node(val);
        q.push(root);

        while (!q.empty()) {
            Node* current = q.front();
            q.pop();

            cout << "Enter the value of the left child of " << current->data << " (or -1 to skip): " << endl;
            cin >> val;
            if (val != -1) {
                current->left = new Node(val);
                q.push(current->left);
            }

            cout << "Enter the value of the right child of " << current->data << " (or -1 to skip): " << endl;
            cin >> val;
            if (val != -1) {
                current->right = new Node(val);
                q.push(current->right);
            }
        }
    }

    void Preorder_recursively(Node* node) {
        if (node == nullptr) return;
        cout << node->data << " ";
        Preorder_recursively(node->left);
        Preorder_recursively(node->right);
    }

    void Inorder_recursively(Node* node) {
        if (node == nullptr) return;
        Inorder_recursively(node->left);
        cout << node->data << " ";
        Inorder_recursively(node->right);
    }

    void Postorder_recursively(Node* node) {
        if (node == nullptr) return;
        Postorder_recursively(node->left);
        Postorder_recursively(node->right);
        cout << node->data << " ";
    }

    void Preorder_iteratively(Node* node) {
        if (node == nullptr) return;
        stack<Node*> s;
        s.push(node);
        while (!s.empty()) {
            Node* current = s.top();
            s.pop();
            cout << current->data << " ";
            if (current->right) s.push(current->right);
            if (current->left) s.push(current->left);
        }
    }

    void Inorder_iteratively(Node* node) {
        if (node == nullptr) return;
        stack<Node*> s;
        Node* current = node;
        while (current != nullptr || !s.empty()) {
            while (current != nullptr) {
                s.push(current);
                current = current->left;
            }
            current = s.top();
            s.pop();
            cout << current->data << " ";
            current = current->right;
        }
    }

    void Postorder_iteratively(Node* node) {
        if (node == nullptr) return;
        stack<Node*> s1, s2;
        s1.push(node);
        while (!s1.empty()) {
            Node* current = s1.top();
            s1.pop();
            s2.push(current);
            if (current->left) s1.push(current->left);
            if (current->right) s1.push(current->right);
        }
        while (!s2.empty()) {
            cout << s2.top()->data << " ";
            s2.pop();
        }
    }
};

int main() {
    BinaryTree tree;
    tree.Create();
    cout << "Inorder Traversal: ";
    tree.Inorder_recursively(tree.root);
    cout << endl;
    cout << "Preorder Traversal: ";
    tree.Preorder_recursively(tree.root);
    cout << endl;
    cout << "Postorder Traversal: ";
    tree.Postorder_recursively(tree.root);
    cout << endl;
    cout << "Preorder Traversal (Iteratively): ";
    tree.Preorder_iteratively(tree.root);
    cout << endl;
    cout << "Inorder Traversal (Iteratively): ";
    tree.Inorder_iteratively(tree.root);
    cout << endl;
    cout << "Postorder Traversal (Iteratively): ";
    tree.Postorder_iteratively(tree.root);
    cout << endl;
    return 0;
}