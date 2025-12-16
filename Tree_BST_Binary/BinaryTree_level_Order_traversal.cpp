#include<iostream>
using namespace std;

struct node{
    int data;
    struct node* left;
    struct node* right;
};

node* createTree(){
    struct node* root = (struct node*)malloc(sizeof(struct node));
    cout<<"Enter Data : ";
    int data;
    cin>>data;
    if(data == -1){
        return NULL;
    }
    root->data = data;

    cout<<"Enter Data Left of"<<data<<": ";
    root->left = createTree();

    cout<<"Enter Data Right of"<<data<<": ";
    root->right = createTree();

    return root;
}

struct Queue{
    node* arr[100];
    int rear,front;

    Queue(){
        rear = front = -1;
    }

    void enqueue(node *x){
        if(rear == 99){
            cout<<"Overflow!!!";
            return;
        }else{
            rear = rear+1;
            arr[rear] = x;
        }
        if(front == -1){
            front = 0;
        }
    }

    void dequeue(){
        if(isEmpty()){
            cout<<"Underflow !!!";
            return;
        }else if(front == rear){
            front = rear = -1;
        }
        else{
            front = front+1;
        }
    }

    node* getFront(){
        return arr[front];
    }

    bool isEmpty(){
        return (front == -1);
    }
};

void levelOrder(struct node* root){
    if(root == NULL){
        cout<<"Tree is Empty!!!!";
        return;
    }
    Queue q;
    q.enqueue(root);

    while(!q.isEmpty()){
        struct node* temp = q.getFront();
        q.dequeue();

        cout<<temp->data<<" ";

        if(temp->left != NULL){
            q.enqueue(temp->left);
        }
        
        if(temp->right != NULL){
            q.enqueue(temp->right);
        }
    }
}

int main(){
    struct node* root = createTree();

    cout<<"Travel : ";
    levelOrder(root);
    return 0;
}