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

node* fingNode(node* root){
    while (root && root->lchild != NULL)
    {
        root = root->lchild;
    }
    return root;
    
}

node* deletenode(node* root,int key){
    if(root == NULL){
        cout<<"Not Found !!";
        return root;
    }
    if(root->data > key){
        root->lchild = deletenode(root->lchild,key);
    }else if(root->data<key){
        root->rchild = deletenode(root->rchild,key);
    }else{
         if(root->lchild == NULL && root->rchild == NULL){
            free(root);
        }
        else if(root->lchild == NULL){
            node* temp = root->rchild;
            free(root);
            return temp;
        }
        else if(root->rchild == NULL){
            node* temp = root->lchild;
            free(root);
            return temp;
        }
        else{
            node* temp = fingNode(root->rchild);
            root->data = temp->data;
            root->rchild = deletenode(root->rchild,temp->data);
        }

    }
}

void inorder(node* root){
    if(root == NULL){
        return;
    }
    inorder(root->lchild);
    cout<<root->data<<" ";
    inorder(root->rchild);
}



int main(){
    node* root = NULL;
    root = buildTree(root,3);
    root = buildTree(root,6);
    root = buildTree(root,2);
    root = buildTree(root,7);
    root = buildTree(root,4);
    root = buildTree(root,9);

    root = deletenode(root,7);

    cout<<"Inorder : ";
    inorder(root);
    return 0;
}