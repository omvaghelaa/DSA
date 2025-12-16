#include<iostream>
using namespace std;

struct node{
    int data;
    struct node *next;
};
struct node *head = NULL;


void insertAtFirst(int value){
    struct node *newnode;
    newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = value;
    newnode->next = NULL;
    if(head == NULL)
    {
        head = newnode;
    }
    else{
        newnode->next = head;
        head = newnode;
    }
}

void reverse(){
    struct node* prev = NULL;
    struct node* next = NULL;
    struct node* curr = head;

    while(curr != NULL){
        next = curr->next;
        curr->next = prev;

        prev = curr;
        curr = next;
    }
    head = prev;
}

//Dispaly Linkedlist
void display(){
    struct node *temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}

int main(){
    insertAtFirst(2);
    insertAtFirst(4);
    insertAtFirst(3);
    insertAtFirst(1);
    display();
    reverse();
    display();
    return 0;
}