#include <iostream>
using namespace std;

struct Node {

    Node* left ;
    Node* right ;
    int data ;
    int height ;

    Node(int val) {
        data = val ;
        left = nullptr ;
        right = nullptr ;
        height = 1 ;
    }

};

int height(Node* root) {
    
    return root ? root->height : 0 ;

}

int BF ( Node* root ) {

    return root ? height(root->left) - height(root->right) : 0 ;

}

Node* LL ( Node* root ) {

    Node* newRoot = root->left ;
    root->left = newRoot->right ;
    newRoot->right = root ;

    root->height = 1 + max( height(root->left) , height(root->right) ) ;
    newRoot->height = 1 + max( height(newRoot->left) , height(newRoot->right) ) ;

    return newRoot ;

}

Node* RR ( Node* root ) {

    Node* newRoot = root->right ;
    root->right = newRoot->left ;
    newRoot->left = root ;

    root->height = 1 + max( height(root->left) , height(root->right) ) ;
    newRoot->height = 1 + max( height(newRoot->left) , height(newRoot->right) ) ;

    return newRoot ;

}

Node* LR ( Node* root ) {

    root->left = RR(root->left) ;
    return LL(root) ;

}

Node* RL ( Node* root ) {

    root->right = LL(root->right) ;
    return RR(root) ;

}

Node* Insert(Node* root, int val) {

    if ( !root ) { 
        return new Node(val); 
    }
    
    if ( val < root->data ) {
        root->left = Insert(root->left, val); 
    } else {
        root->right = Insert(root->right, val); 
    }

    root->height = 1 + max( height(root->left) , height(root->right) ) ;
    int bf = BF(root) ;

    if ( bf > 1 && val < root->left->data ) return LL(root) ;
    if ( bf > 1 && val > root->left->data ) return LR(root) ;
    if ( bf < -1 && val > root->right->data ) return RR(root) ;
    if ( bf < -1 && val < root->right->data ) return RL(root) ;

    return root ;    
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

    root->height = 1 + max( height(root->left) , height(root->right) ) ;
    int bf = BF(root) ;

    if ( bf > 1 && BF(root->left) >= 0 ) return LL(root) ;
    if ( bf > 1 && BF(root->left) < 0 ) return LR(root) ;
    if ( bf < -1 && BF(root->right) <= 0 ) return RR(root) ;
    if ( bf < -1 && BF(root->right) > 0 ) return RL(root) ;

    return root ;

}

bool search(Node* root, int val) {

    if ( !root ) return false ;;
    if ( root->data == val ) return true ;
    if ( val < root->data ) return search(root->left, val) ;
    else return search(root->right, val) ;

}

int main() {
    Node* root = nullptr ;
    
    root = Insert(root, 10) ;
    root = Insert(root, 20) ;
    root = Insert(root, 30) ; 
    root = Insert(root, 40) ;
    root = Insert(root, 50) ; 
    root = Insert(root, 25) ;

    cout << "The balanced AVL root is: " << root->data << endl ; 

    root = deleteNode(root, 20);
    cout << "After deletion, the balanced AVL root is: " << root->data << endl ;
    
    return 0 ;
}