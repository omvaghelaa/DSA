#include<iostream>
using namespace std;

struct node {
    int data;
   struct node* next;
};
struct node* head = NULL;

void insertEnd(int n){
    struct node* newnode;
    newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = n;
    newnode->next = NULL;
    if(head == NULL){
        head = newnode;
        head->next = head;
    }
    else{
        struct node* temp = head;
        while(temp->next != head){
            temp = temp->next;
        }
        temp->next = newnode;
        newnode->next = head;   
    }
}

void insertStart(int n){
    struct node* newnode;
    newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = n;
    newnode->next=NULL;
    if(head==NULL){
        head=newnode;
        head->next=head;
    }
    else{
        struct node* temp=head;
        while(temp->next != head){
            temp=temp->next;
        }
        temp->next = newnode;
        newnode->next=head;
        head = newnode;
    }
}

void insertPos(int n,int pos){
    struct node* newnode;
    newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = n;
    newnode->next=NULL;
    if(head==NULL){
        head=newnode;
        head->next=head;
    }
    else{
        struct node* temp = head;
        int i = 1;
        if(pos==1){
            insertStart(n);
            return;
        }
        while(i<pos-1){
            temp=temp->next;
            i++;
        }
        newnode->next=temp->next;
        temp->next = newnode;
        
    }
}

void deleteEnd(){
    if(head == NULL){
        cout<<"EMPTY";
        return;
    }
    if(head->next == head){
        free(head);
        head = NULL;
        return;
    }
    struct node* temp = head;
    struct node* pretemp;
    while(temp->next != head){
        pretemp = temp;
        temp = temp->next;
    }
    pretemp->next = head;
    free(temp);

}

void deleteSTART(){
     if(head == NULL){
        cout<<"EMPTY";
        return;
    }
    if(head->next == head){
        free(head);
        head = NULL;
        return;
    }
    struct node* temp = head;
    struct node* lastnode = head;
    while(lastnode->next != head){
        lastnode=lastnode->next;
    }
    lastnode->next = head->next;
    head = head->next;
    free(temp);

}



void deletePos(int pos){
    if(head==NULL){
        cout<<"EMPTY";
        return;
    }
    if(head->next == head){
        free(head);
        head = NULL;
        return;
    }
    struct node* temp = head;
    struct node* pretemp;
    int i =1;
    while(i<pos){
        pretemp = temp;
        temp = temp->next;
        i++;
    } 
    pretemp->next = temp->next;
    free(temp); 
}

void display(){
    if(head == NULL){
        return;
    }
    struct node* temp = head;
    do{
        cout << temp->data << " ";
        temp = temp->next;
    }while(temp != head);
}


int main(){
    insertEnd(10);
    insertEnd(20);
    insertEnd(40);
    insertStart(90);
    insertStart(120);
    insertPos(35,4);
    // deleteEnd();
   // deleteSTART();
  //  deletePos(2);
    display();
    return 0;
}