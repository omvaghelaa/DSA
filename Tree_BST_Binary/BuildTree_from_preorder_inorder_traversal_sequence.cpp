#include <iostream>
using namespace std;

struct node {
    int data;
    node* left;
    node* right;
};

int findNode(int inorder[], int start, int end, int value) {
    for (int i = start; i <= end; i++) {
        if (inorder[i] == value)
            return i;
    }
    return -1;
}

node* buildTree(int inorder[], int preorder[], int start, int end, int &preIndex) {
    if (start > end)
        return NULL;

    int current = preorder[preIndex++];
    node* newnode = new node;
    newnode->data = current;
    newnode->left = newnode->right = NULL;

    if (start == end)
        return newnode;

    int pos = findNode(inorder, start, end, current);

    newnode->left = buildTree(inorder, preorder, start, pos - 1, preIndex);
    newnode->right = buildTree(inorder, preorder, pos + 1, end, preIndex);

    return newnode;
}

void preorderTraversal(node* root) {
    if (root == NULL)
        return;
    cout << root->data << " ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

int main() {
    int preorder[] = {0, 1, 3, 4, 2, 5};
    int inorder[] = {3, 1, 4, 0, 5, 2};
    int index = 0;
    int size = sizeof(inorder) / sizeof(inorder[0]);

    node* root = buildTree(inorder, preorder, 0, size - 1, index);
    cout << "Preorder Traversal of Constructed Tree: ";
    preorderTraversal(root);
    return 0;
}
