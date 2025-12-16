#include<iostream>
using namespace std;

struct node{
    int data;
    struct node* left;
    struct node* right;
};

void insert(struct node* &root,int key){
    struct node* t = root; // t = current node we are checking
    struct node* r =NULL;  //r = parent of t (used to attach the new node once t reaches NULL)
    if(root == NULL){
        struct node* newnode = (struct node*)malloc(sizeof(struct node));
        newnode->data = key;
        newnode->left = newnode->right = NULL; 
        root = newnode;  
        return; 
    }

    //finding node
    while(t!=NULL){
        r = t;
        if(key < t->data){
            t = t->left;
        }else if(key > t->data){
            t = t->right;
        }else{
            return;
        }
    }

    //createing link
    node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = key;
    newnode->left = newnode->right = NULL;

    if(key<r->data){
        r->left = newnode;
    }else{
        r->right = newnode;
    }
}

bool search(node* root,int key){
    node* t = root; //here we directly use root witout tacking t as reference because we are not modifying the tree
    
    while(t!=NULL){
        if(t->data==key){
            return true;
        }
        else if(key < t->data){
            t = t->left;
        }else if(key > t->data){
            t = t->right;
        }
        
    }
    return false;
}

node* deleteNode(node* root,int key){
    if(root == NULL){
        cout<<"Empty";
        return NULL;
    }
    struct node* curr = root;
    node* parent=NULL;
    while(curr!=NULL && curr->data != key){
        parent = curr;
        if(key<curr->data){
            curr = curr->left;
        }else if(key > curr->data){
            curr = curr->right;
        }
    }

    if(curr == NULL){
        cout<<"Key Not Found !!!";
        return root;
    }

    if(curr->left == NULL || curr->right == NULL){
        node* child = NULL;
        if(curr->left != NULL){
            child = curr->left;
        }else{
            child = curr->right;
        }

        if(parent == NULL){
            free(curr);
            return child;
        }

        if(parent->left == curr){
            parent->left = child;
        }else{
            parent->right = child;
        }

        free(curr);
    }
    else{
        node* Parentsucc = curr;
        node* succ = curr->right;

        while(succ->left != NULL){
            Parentsucc = succ;
            succ = succ->left;
        }

        curr->data = succ->data;

        if(Parentsucc->left == succ){
            Parentsucc->left = succ->right;
        }else{
            Parentsucc->right = succ->right;
        }
        free(succ);
    }
    return root;

}
void inorder(node* root)
{
    if(root == NULL){return;}
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
int main(){
    struct node* root = NULL;
    insert(root,50);
    insert(root,30);
    insert(root,70);
    insert(root,20);
    insert(root,40);
    insert(root,60);
    insert(root,80);

    cout<<"Inorder : ";
    inorder(root);

    //cout<<search(root,100);
    node* result = deleteNode(root,50);
    cout<<"\n\nResult after deletion : ";
    inorder(result);
    return 0;
}