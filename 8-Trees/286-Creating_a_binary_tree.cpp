#include <iostream>
#include <vector>
#include <queue>
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

    void Inorder(Node* node) {
        if (node == nullptr) return;
        Inorder(node->left);
        cout << node->data << " ";
        Inorder(node->right);
    }
};

int main() {
    BinaryTree tree;
    tree.Create();
    cout << "Inorder Traversal: ";
    tree.Inorder(tree.root);
    cout << endl;
    return 0;
}