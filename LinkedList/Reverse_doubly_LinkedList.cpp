#include<iostream>
using namespace std;

struct node{
    int data;
    struct node* next;
    struct node* prev;
};
struct node* head = NULL;

//Insert At First
void insertAtFirst(int value){
    struct node* newnode;
    newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = value;
    newnode->prev = newnode->next = NULL;
    if(head == NULL){
        head = newnode;
    }
    else{
        newnode->next = head;
        head->prev = newnode;
        head = newnode;
    }
}

void reverse(){
    struct node* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    head = temp;
    while(temp!= NULL){
        cout<<temp->data<<" ";
        temp = temp->prev;
    }
}

void display()
{
    struct node* temp = head;
    while(temp!= NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}

int main(){
    insertAtFirst(2);
    insertAtFirst(3);
    insertAtFirst(5);
    display();
    reverse();
    return 0;
}