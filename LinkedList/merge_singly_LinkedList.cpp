#include<iostream>
using namespace std;

struct node{
    int data;
    struct node* next;
};

void createnode(struct node* &head,int val){
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = val;
    newnode->next = NULL;
    if(head == NULL){
        head = newnode;
    }else{
        struct node* temp = head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = newnode;
    }
}

struct node* merged(struct node* Link_1,struct node* Link_2){
        struct node* merged = NULL;
        struct node* temp = Link_1;
        struct node* head = Link_2;
        struct node* reminder = Link_1;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = head;
        head = reminder;
}

void display(struct node* temp){
    while(temp!=NULL){
        cout<<temp->data<<" ";
    }
}


int main(){
    
    struct node* L1 = NULL;
    struct node* L2 = NULL;

    createnode(L1,1);
    createnode(L1,2);
    createnode(L1,3);
    createnode(L1,4);
    createnode(L1,5);
    createnode(L1,6);

    createnode(L2,8);
    createnode(L2,9);
    createnode(L2,10);
    createnode(L2,11);
    createnode(L2,12);
    
    display(merged(L1,L2));   
    return 0;
}