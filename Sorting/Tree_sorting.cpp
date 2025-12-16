#include<iostream>
using namespace std;

struct node{
    int data;
    node* lchild;
    node* rchild;
};

node* buildTree(node* root,int key){
    if(root == NULL){
        node* newnode = (node*)malloc(sizeof(struct node));
        newnode->data = key;
        newnode->lchild = newnode->rchild = NULL;
        return newnode;
    }
    if(root->data > key){
        root->lchild = buildTree(root->lchild,key);
    }else if(root->data<key){
        root->rchild = buildTree(root->rchild,key);
    }else{
        cout<<"Duplicate !!!";
        return root;
    }

    return root;
}

void ascending(node* root){
    if(root == NULL){
        return;
    }
    ascending(root->lchild);
    cout<<root->data<<" ";
    ascending(root->rchild);
}
void descending(node* root){
    if(root == NULL){
        return;
    }
    descending(root->rchild);
    cout<<root->data<<" ";
    descending(root->lchild);
}



int main(){
    node* root = NULL;
    root = buildTree(root,3);
    root = buildTree(root,6);
    root = buildTree(root,2);
    root = buildTree(root,7);
    root = buildTree(root,4);
    root = buildTree(root,9);

    cout<<"Sorting Ascending : ";
    ascending(root);
    cout<<endl;
    cout<<"Sorting Descending : ";
    descending(root);
    cout<<endl;
    return 0;
}