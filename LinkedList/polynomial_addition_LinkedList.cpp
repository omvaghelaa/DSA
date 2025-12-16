#include<iostream>
using namespace std;

struct node{
    int cof;
    int exp;
    struct node* next;
};

void InsertNode(struct node*& head,int coff,int expp){
    struct node* newnode;
    newnode = (struct node*)malloc(sizeof(struct node));
    newnode->cof=coff;
    newnode->exp=expp;
    newnode->next=NULL;
    if(head == NULL){
        head =  newnode;
    }else{
        struct node* temp = head;
        while(temp->next != NULL){
            temp=temp->next;
        }
        temp->next = newnode;
    }

}

struct node* polyadd(struct node* poly1,struct node* poly2){
    struct node* result = NULL;
    while(poly1 != NULL && poly2 != NULL){
    if(poly1->exp == poly2->exp){
        InsertNode(result,poly1->cof+poly2->cof,poly1->exp);
        poly1 = poly1->next;
        poly2 = poly2->next;
    }
    else if(poly1->exp > poly2->exp){
        InsertNode(result,poly1->cof,poly1->exp);
        poly1 = poly1->next;
    }
    else if(poly1->exp < poly2->exp){
        InsertNode(result,poly2->cof,poly2->exp);
        poly2 = poly2->next;
    }
}
    while(poly1 != NULL){
        InsertNode(result,poly1->cof,poly1->exp);
        poly1 = poly1->next;
    }
    while(poly2 != NULL){
        InsertNode(result,poly2->cof,poly2->exp);
        poly2 = poly2->next;
    }
    return result;
}

void display(struct node* poly){
    while(poly != NULL){
        cout<<"("<<poly->cof<<","<<poly->exp<<")"<<" ";
        poly = poly->next;
    }
}

int main(){

    struct node* poly1 = NULL;
    struct node* poly2 = NULL;
    InsertNode(poly1,3,2);
    InsertNode(poly1,2,1);
    InsertNode(poly1,9,0);

    InsertNode(poly2,6,2);
    InsertNode(poly2,4,1);
    InsertNode(poly2,6,0);
    
    display(polyadd(poly1,poly2));

    return 0;
}