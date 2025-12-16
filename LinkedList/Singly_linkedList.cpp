#include<iostream>
using namespace std;

struct node{
    int data;
    struct node* ptr;
};

struct node* head = NULL;
void insertFirst(int n){
    struct node* newnode;
    newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = n;
    newnode->ptr=NULL;

    if(head==NULL){
        head = newnode;
    }else{
        newnode->ptr = head;
        head=newnode;
    }

}

void insertEnd(int n){
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = n;
    newnode->ptr = NULL;

    if(head==NULL){
        head = newnode;
    }
    else{
        struct node* temp;
        temp = head;
        while(temp->ptr != NULL){
            temp = temp->ptr;
        }
        temp->ptr=newnode;
    }
}


void insertAtAnyPosition(int pos,int n){
    struct node* newnode;
    int i=1;
    newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data=n;
    newnode->ptr=NULL;
    if(pos == 1){
        newnode->ptr = head;
        head=newnode;
        return;
    }
    if(head==NULL){
        head=newnode;
    }else{
        struct node* temp = head;
        while(i<pos-1){
            temp=temp->ptr;
            i++;
        }
        if(temp == NULL){
            cout<<"out of pos !!!";
            free(newnode);
            return;
        }
        newnode->ptr=temp->ptr;
        temp->ptr = newnode;
    }
}

void deleteFirst(){
    struct node* temp = head;
    head = head->ptr;
    free(temp);
}

void deleteLast(){
    struct node* temp = head;
    struct node* pretemp;
    while(temp->ptr != NULL){
        pretemp = temp;
        temp=temp->ptr;
    }
    free(temp);
    pretemp->ptr=NULL;
}

void deletePOS(int pos){
    struct node* temp = head;
    struct node* pretemp;
    int i=1;
    if(head == NULL){
        return;
    }
    while(i<pos){
        pretemp = temp;
        temp = temp->ptr;
        i++;
    }
    pretemp->ptr = temp->ptr;
    free(temp);

}

void display(){
    struct node* temp;
    temp = head;
    while(temp != NULL){
        cout<<temp->data<<endl;
        temp = temp->ptr;
    }
}

int main(){

    insertFirst(4);
    insertFirst(5);
    insertEnd(4);
    //deleteFirst();
    //deleteLast();
    //display();
    cout<<endl;
    // insertEnd(5);
    insertAtAnyPosition(1,7);
    
    insertAtAnyPosition(3,8);
    deletePOS(3);
    display();
    return 0;
}

