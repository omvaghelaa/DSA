#include<iostream>
using namespace std;

const int size = 5;
int queue[size];
int rear = -1;
int front = -1;

void enque(int data){
    if((rear+1)%size == front){
        cout<<"Overflow";
        return;
    }else if(front==-1 && rear==-1){
        front=rear=0;
    }else{
        rear = (rear+1)%size;
    }
    queue[rear] = data;
}

void dqueue(){
    if(front==-1 && rear==-1){
        cout<<"UnderFlow";
        return;
    }else if(front == rear){
        front = rear = -1;
    }else{
        front = (front+1)%size;
    }
}

int peek(){
    if(front==-1&&rear==-1){
        cout<<"underflow";
        return -1;
    }
    return queue[front];
}

void display(){
    if(front == -1 && rear==-1){
        cout<<"Empty";
    }else{
        int i = front;
        while(true){
            cout<<queue[i]<<" ";
            if(i==rear){break;}
            i = (i+1)% size;
        }
    }
}

int main(){
    enque(1);
    enque(4);
    enque(2);
    enque(3);
    enque(9);
  

    dqueue();
    enque(0);

    display();
    return 0;
}