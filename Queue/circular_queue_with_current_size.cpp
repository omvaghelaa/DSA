#include<iostream>
using namespace std;

const int size = 4;
int queue[size];
int front =-1;
int rear = -1;
int currentSize = 0;

void enque(int x){
    // if((front == 0 && rear == size-1)){
    //     cout<<"Queue Already FULL !!!!!!!\n";
    //     return -1;
    if(currentSize == size){
        cout<<"Fulll !!!!";
        return;
    }
    rear = (rear+1)%size;
    queue[rear] = x;
    currentSize++;
    
    if(front == -1){
        front = 0;
    }
}

void deque(){
    if(currentSize == 0){
        front=rear=-1;
        cout<<"Empty !!!";
        return;
    }
    front = (front+1)%size;
    currentSize--;
}

void display() {
    if(currentSize == 0) {
        cout << "Queue EMPTY !!!\n";
        return;
    }
    int i = front;
    for(int count = 0; count < currentSize; count++) {
        cout << queue[i] << " ";
        i = (i + 1) % size;
    }
    cout << endl;
}

int main(){
    enque(1);
    enque(2);
    enque(3);
    enque(4);
    deque();
    
    
    display();
    return 0;
}