#include<iostream>
using namespace std;

struct node{
    int data;
    struct node* ptr;
};

struct node* head= NULL;
void createnode(int val){
    struct node* newnode;
    newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data=val;
    newnode->ptr=NULL;

    if(head == NULL){
        head = newnode;
    }
    else{
        struct node* temp = head;
        while(temp->ptr != NULL){
        temp = temp->ptr;
        }
        temp->ptr = newnode;
    }
}

void display(){
    struct node* temp = head;
    while (temp != NULL)
    {
        cout<<temp->data<<endl;
        temp = temp->ptr;
    }
    
}


int main(){

createnode(3);
createnode(4);

display();
    return 0;
}