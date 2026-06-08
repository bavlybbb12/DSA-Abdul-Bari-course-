#include <iostream>
#include <vector>
using namespace std;

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

class BinarySearchTree {
    
    private :

    Node* root;

    Node* Insert(Node* &root, int val) {
        
        if ( !root ) {root = new Node(val) ; return root;}
        if ( val < root->data ) Insert(root->left, val) ;
        else Insert(root->right, val) ;
        return root ;    

    }

    bool search(Node* root, int val) {

        if ( !root ) return false ;;
        if ( root->data == val ) return true ;
        if ( val < root->data ) return search(root->left, val) ;
        else return search(root->right, val) ;

    }

    void Inorder(Node* root) {

        if ( !root ) return ;
        Inorder(root->left) ;
        cout << root->data << " " ;
        Inorder(root->right) ;

    }

    Node* findMin(Node* root) {
        while (root->left) root = root->left;
        return root;
    }

    Node* deleteNode(Node* root, int key) {

        if ( !root ) return root ;
        if ( key < root->data ) root->left = deleteNode(root->left, key) ;
        else if ( key > root->data ) root->right = deleteNode(root->right, key );
        else {
            
            if ( !root->left ) {
                Node* temp = root->right;
                delete root;
                return temp;
            }
            if ( !root->right ) {
                Node* temp = root->left;
                delete root;
                return temp;
            }
            Node* temp = findMin(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
        return root ;

    }

    public:

    BinarySearchTree() {root = nullptr;}

    void Insert(int val) {Insert(root, val) ;}
    bool search(int val) {return search(root, val) ;}
    void Inorder() {Inorder(root) ;}
    void deleteNode(int key) {deleteNode(root, key);}
};

int main() {
    BinarySearchTree bst;

    // Insert data in an unsorted order
    bst.Insert(50);
    bst.Insert(30);
    bst.Insert(70);
    bst.Insert(20);
    bst.Insert(40);
    bst.Insert(60);
    bst.Insert(80);

    cout << "BST Data (Inorder Traversal): ";
    bst.Inorder();

    int targets[] = {40, 99};
    for (int target : targets) {
        if (bst.search(target)) {
            cout << "Target " << target << " was found in the BST!" << endl;
        } else {
            cout << "Target " << target << " does not exist in the BST." << endl;
        }
    }

    return 0;
}