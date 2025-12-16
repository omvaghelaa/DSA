#include<iostream>
using namespace std;

struct node{
    int data;
    struct node* left;
    struct node* right;
};

struct node* buildtree(){
    struct node* root = (struct node*)malloc(sizeof(struct node));
    cout<<"Enter Data : ";
    int data;
    cin>>data;
    if(data == -1){
        return NULL;
    }
    root->data = data;
    
    cout<<"Enter left of "<<data<<": ";
    root->left = buildtree();

    cout<<"Enter right of "<<data<<": ";
    root->right = buildtree();

    return root;
}

void inorder(struct node* root){
    if(root != NULL){
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }
}

void preorder(struct node* root){
    if(root != NULL){
        cout<<root->data<<" ";
        preorder(root->left);
        preorder(root->right);
    }
}
void postorder(struct node* root){
    if(root != NULL){
        postorder(root->left);
        postorder(root->right);
        cout<<root->data<<" ";
    }
}


int main(){
    struct node* root = buildtree();

    cout<<"preorder : ";
    preorder(root);
    cout<<endl;

    cout<<"Postorder : ";
    postorder(root);
    cout<<endl;

    cout<<"Inorder : ";
    inorder(root);
    cout<<endl;

    return 0;
}