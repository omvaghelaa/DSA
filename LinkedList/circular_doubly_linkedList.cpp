#include<iostream>
using namespace std;

struct node{
    int data;
    struct node* next;
    struct node* prev;
};
struct node* head = NULL;

void insertEnd(int n){
    struct node* newnode;
    newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data=n;
    newnode->next=newnode->prev=NULL;

    if(head == NULL){
        head = newnode;
        head->next=head->prev=head;
    }
    else{
        struct node* temp = head;
        while(temp->next != head){
            temp = temp->next;
        }
        newnode->prev = temp;
        newnode->next = head;
        head->prev = newnode;
        temp->next = newnode;
    }
}

void insertStart(int n)
{
    struct node* newnode;
    newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = n;
    newnode->next = newnode->prev = NULL;

    if(head == NULL){
        head=newnode;
        newnode->next = newnode->prev = head;
    }
    else{
        struct node* lastnode = head->prev;
        head->prev = newnode;
        newnode->next = head;
        newnode->prev = lastnode;
        lastnode->next=newnode;
        head = newnode;
    }
}

void insertPos(int n,int pos){
    struct node* newnode;
     newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = n;
    newnode->next = newnode->prev = NULL;

    if(head == NULL){
        head=newnode;
        newnode->next = newnode->prev = head;
    }
    else{
        if(pos == 1){
            insertStart(n);
            return;
        }
        
        struct node* temp = head;
        int i=1;
        while(i<pos-1){
            temp = temp->next;
            i++;
        }
        newnode->next = temp->next;
        temp->next->prev = newnode;
        temp->next = newnode;
        newnode->prev = temp;
        

    }
}

void deleteStart(){
    if(head==NULL){
        cout<<"empty";
        return;
    }
    if(head->next == head){
        free(head);
        return;
    }
    struct node* temp = head;
    struct node* last = head->prev;
    head = head->next;
    head->prev = last;
    last->next = head;
    free(temp);

}

void deleteEnd(){
    struct node* temp = head->prev;
    temp->prev->next = head;
    head->prev = temp->prev;
    free(temp);
}

void deletePos(int pos){
    struct node* temp = head;
    int i = 1;
    if(pos == 1){
        deleteStart();
        return;
    }
    while(i<pos){
        temp = temp->next;
        i++;
    }
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    free(temp);

}

void display(){
    if(head == NULL){
        return;
    }
    struct node* temp = head;
    do{
        cout<<temp->data<<" ";
        temp=temp->next;
    }while(temp != head);
}


int main(){
    
    insertEnd(10);
    insertEnd(20);
    insertEnd(30);
    insertStart(90);
    insertStart(120);
    insertPos(44,2);
    insertPos(1,5);
    //deletePos(4);
    //deleteEnd();
    //deleteEnd();
   //deleteStart();
    display();
    return 0;
}