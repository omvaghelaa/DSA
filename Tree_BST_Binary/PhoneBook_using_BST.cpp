#include<iostream>
using namespace std;

struct node{
    long long pno;
    string name;
    node* lchild;
    node* rchild;
};

void insert(node* &root,long long phone,string name)
{
    node* t = root;
    node* r = NULL;
    if(root == NULL){
        node* newnode = new node();
        newnode->pno = phone;
        newnode->name = name;
        newnode->lchild = newnode->rchild = NULL;
        root = newnode;
        return;
    }

    while(t!=NULL){
        r = t;
        if(t->name>name){
            t = t->lchild;
        }else if(t->name<name){
            t = t->rchild;
        }else{
            cout<<"Duplicate Entry !!!";
            return;
        }
    }

    node* newnode = new node();
    newnode->pno = phone;
    newnode->name = name;
    newnode->lchild = newnode->rchild = NULL;

    if(name<r->name){
        r->lchild = newnode;
    }else{
        r->rchild = newnode;
    }
}

node* deletenode(node* root,string key){
    if(root == NULL){
        cout<<"Empty !!!!";
        return NULL;
    }
    node* curr = root;
    node* parent = NULL;
    while(curr != NULL && curr->name != key){
        parent = curr;
        if(curr->name < key){
            curr = curr->rchild;
        }else{
            curr = curr->lchild;
        }
    }

    if(curr==NULL){
        cout<<"Key Not Found !!!";
        return root;
    }

    if(curr->lchild == NULL || curr->rchild == NULL){
        node* child = NULL;
        if(curr->lchild == NULL){
            child = curr->rchild;
        }else{
            child = curr->lchild;
        }
        if(parent == NULL){
            free(curr);
            return child;
        }
        if(parent->rchild == curr){
            parent->rchild = child;
        }else{
            parent->lchild = child;
        }
        free(curr);
    }else{
        node* parentSucc = curr;
        node* succ = parentSucc->rchild;
        if(succ->lchild != NULL){
            parentSucc = succ;
            succ=succ->lchild;
        }
        curr->name = succ->name;
        curr->pno = succ->pno;

        if(parentSucc->lchild == succ){
            parentSucc->lchild = succ->rchild;
        }else{
            parentSucc->rchild = succ->rchild;
        }

        free(succ);
    }
    return root;
}
bool search(node* root,string name){
    if(root==NULL){
        cout<<"Empty";
        return 0;
    }
    if(root->name>name){
        root=root->lchild;
    }else if(root->name<name){
        root=root->rchild;
    }else{
        return 1;
    }
    return 0;
}


void inorderASC(node* root){
    if(root==NULL){return;}
    inorderASC(root->lchild);
    cout<<root->name<<" : "<<root->pno<<"\n";
    inorderASC(root->rchild);
}

void inorderDSC(node* root){
    if(root==NULL){return;}
    inorderDSC(root->rchild);
    cout<<root->name<<" : "<<root->pno<<"\n";
    inorderDSC(root->lchild);
}

int main(){
    node* root = NULL;
    insert(root,9510105217,"OM");
    insert(root,9289292382,"Amit");
    insert(root,8372939334,"Shyam");
    insert(root,8438374300,"Raj");
    insert(root,4032382093,"Vikram");
    insert(root,6038339203,"John");
    insert(root,8038203820,"Alice");

    cout<<"\nInorder Traversal ASc : \n";
    inorderASC(root);

    cout<<"\n\nInorder Traversal DSc : \n";
    inorderDSC(root);

    node* result = deletenode(root,"Raj");
    cout<<"\n\nInorder After Deletion : \n";
    inorderASC(result);

    cout<<"\n\nfinding ......\n\n";
    cout<<search(root,"OM");

    return 0;
}