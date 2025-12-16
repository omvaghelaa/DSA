#include<iostream>
using namespace std;

struct node{
    int data;
    struct node *next;
};
struct node *head = NULL;


//Insert At First
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

//search node
void search(int check){
    struct node* temp = head;
    int i=1;
    while(temp!=NULL){
        if(temp->data == check){
            cout<<"Found At Position : "<<i;
        }
        i++;
        temp = temp->next;
    }
    cout<<endl;
}

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
    search(4);
    display();
    return 0;
}