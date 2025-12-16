#include<iostream>
using namespace std;

const int size = 5;
int queue[size];
int front =-1;
int rear = -1;

void enque(int data){
    if(rear == size-1){
        cout<<"Queue Already FULL !!!!!!!\n";
        return; 
    }else if(front == -1 && rear == -1){
        front = rear = 0;
        queue[rear] = data;
        return;
    }else{
        rear++;
        queue[rear] = data;
    }
}

void deque()
{
    if(front == -1){
        cout<<"Queue Already EMPTY !!!!!!!\n";
        return;
    }else if(front == rear){
        front = rear = -1;
    }else{
        front++;
    }
}

void display(){
    if(front == -1 && rear == -1){
        cout<<"Queue Empty !!!!!!!!\n";
        return;
    }else{
        for(int i=front;i<=rear;i++){
            cout<<queue[i]<<" ";
        }
    }
}

int main(){

    enque(10);
    enque(20);
    enque(30);
    display();
    
    
    return 0;
}