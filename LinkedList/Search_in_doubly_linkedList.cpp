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

void search(int check){
    struct node* temp = head;
    int i= 1;
    while(temp != NULL){
        if(temp->data == check){
            cout<<"Found at Position : "<<i<<endl;
        }
        i++;
        temp=temp->next;
    }
    
}

int main(){
    insertAtFirst(2);
    insertAtFirst(3);
    insertAtFirst(5);
    search(3);
    return 0;
}