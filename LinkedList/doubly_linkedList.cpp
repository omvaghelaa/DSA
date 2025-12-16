#include<iostream>
using namespace std;

struct node{
    int data;
    struct node* prev;
    struct node* next;
};

struct node* head = NULL;
void insertEND(int n){
    struct node* newnode;
    newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = n;
    newnode->next = newnode->prev = NULL;
    if(head==NULL){
        head=newnode;
    }
    else{
        struct node* temp = head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = newnode;
        newnode->prev = temp;
    }
}

void insertSTART(int n){
    struct node* newnode= (struct node*)malloc(sizeof(struct node));
    newnode->data=n;
    newnode->next = newnode->prev = NULL;

    if(head == NULL){
        head=newnode; 
    }else{
        newnode->next = head;
        head->prev = newnode;
        head=newnode;
    }
}

void insertAnyPos(int n,int pos){
    struct node* newnode;
    newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = n;
    newnode->next = newnode->prev = NULL;

    if(head==NULL){
        head = newnode;
    }else{
        struct node* temp = head;
        int i = 1;
        while(i<pos-1){
            temp=temp->next;
            i++;
        }
        newnode->prev = temp;
        newnode->next = temp->next;
        temp->next->prev = newnode;
        temp->next = newnode;

    }
}

void deleteFRONT()
{
    if(head == NULL){
        cout<<"Already empty !!!";
        
    }else{
        struct node* temp = head;
        head = head->next;
        head->prev  = NULL;
        free(temp);
    }
}

void deleteEND(){
    struct node* temp = head;
   // struct node* pretemp;
    while(temp->next != NULL){
       // pretemp = temp;
        temp=temp->next;
    }
    //pretemp->next=NULL;
    temp->prev->next = NULL;
    free(temp);
}

void deleteAtAnyPos(int pos){
    struct node* temp = head;
   // struct node* pretemp;
    int i = 1;
    if(pos == 1)
    {
        struct node* temp = head;
        head = head->next;
        head->prev = NULL;
        free(temp);
    }else{
    while(i<pos){
       // pretemp = temp;
        temp = temp->next;
        i++;
    }
    if(temp == NULL){
        cout<<"POS OUTBOUND !!"<<endl;
    }else{
   // pretemp->next=temp->next;
   // temp->next->prev = pretemp;
   // temp->prev = pretemp->next;
   temp->prev->next = temp->next;
   temp->next->prev = temp->prev;
    free(temp);
    }
}
}

void display(){
    struct node* temp = head;
    while(temp!=NULL){
        cout<<temp->data <<" ";
        temp=temp->next;
    }
}

int main(){

    insertEND(2);
    insertEND(4);
    insertEND(5);
    insertSTART(9);
    insertSTART(8);
    insertAnyPos(3,2);
    // deleteEND();
    // deleteEND();
    // deleteFRONT();
    deleteAtAnyPos(2);

    display();
    return 0;
}