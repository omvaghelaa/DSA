#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* createNode(int data) {
    Node* newnode = new Node;
    newnode->data = data;
    newnode->left = newnode->right = NULL;
    return newnode;
}

int height(Node* root) {
    if (root == NULL)
        return -1;  

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    return 1 + max(leftHeight, rightHeight);
}

int main() {

    Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);

    cout << "Height of Binary Tree = " << height(root) << endl;
    
    return 0;
}
