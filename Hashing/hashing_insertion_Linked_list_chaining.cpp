#include<iostream>
using namespace std;

struct node{
    int data;
    node* next;
};

int hashfunc(int key){
    return key%20;
}

void hashtbl(node* hashtable[],int key){
    int index = hashfunc(key);
    node* newnode=(node*)malloc(sizeof(node));
    newnode->data = key;
    newnode->next = NULL;

    newnode->next = hashtable[index];
    hashtable[index] = newnode;
}

void retrive(node* hashtable[],int key){
    int index = hashfunc(key);
    node* temp = hashtable[index];
    bool flag = 0;
    while(temp != NULL){
        if(temp->data == key){
            flag = 1;   
            break;
        }
        temp = temp->next;
    }
    if(flag == 1){
        cout<<"found!!";
    }else{
        cout<<"Not!!";
    }
    
}
void disp(node* hashtable[])
{
    for(int i=0;i<20;i++){
        node* temp = hashtable[i];
        cout<<i<<" : ";
        while(temp!=NULL){
            cout<<temp->data<<"->";
            temp = temp->next;
        }
        cout<<"NULL\n";
    }
}
int main(){
    
    node* hashtable[20];
    for(int i=0;i<20;i++){
        hashtable[i] = NULL;
    }

    int elements[] = {
         15, 25, 35, 20, 30,
        12, 22, 32, 42, 52,
        17, 27, 37, 47, 57,
        19, 29, 39, 49, 59
    };

    for(int i=0;i<20;i++){
        hashtbl(hashtable,elements[i]);
    }

    //disp(hashtable);

    retrive(hashtable,121);

    return 0;
}