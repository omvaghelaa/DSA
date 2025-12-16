#include <iostream>
using namespace std;

struct node {
    int data;
    struct node* left;
    struct node* right;
};

struct node* createnode(int value) {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = value;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}

struct node* buildtree() {
    cout << "Enter Data (-1 for NULL): ";
    int data;
    cin >> data;

    if (data == -1) {
        return NULL; // sentinel, don’t create node
    }

    struct node* root = createnode(data);

    cout << "Enter data for inserting in LEFT of " << data << endl;
    root->left = buildtree();

    cout << "Enter data for inserting in RIGHT of " << data << endl;
    root->right = buildtree();

    return root;
}


void preorder(struct node* root) {
    if (root == NULL) return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

int main() {
    struct node* root = buildtree();

    cout << "\nPreorder Traversal: ";
    preorder(root);
    cout << endl;

    return 0;
}
