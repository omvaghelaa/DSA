#include<iostream>
using namespace std;

#define SIZE 5
int dq[SIZE];
int front = -1;
int rear = -1;

// Insert at front
void insertFront(int val){
    if((rear + 1) % SIZE == front){
        cout << "Overflow\n";
        return;
    }
    if(front == -1 && rear == -1){  // empty deque
        front = rear = 0;
    }
    else if(front == 0){
        front = SIZE - 1;
    }
    else{
        front--;
    }
    dq[front] = val;
}

// Insert at rear
void insertRear(int x){
    if((rear + 1) % SIZE == front){
        cout << "Overflow !!!!\n";
        return;
    }
    else if(front == -1 && rear == -1){  // empty deque
        front = rear = 0;
    }
    else if(rear == SIZE - 1){
        rear = 0;
    }
    else{
        rear++;
    }
    dq[rear] = x;
}

// Delete from front
void deleteFront(){
    if(front == -1 && rear == -1){
        cout << "Underflow\n";
        return;
    }
    else if(front == rear){  // only one element
        front = rear = -1;
    }
    else if(front == SIZE - 1){
        front = 0;
    }
    else{
        front++;
    }
}

// Delete from rear
void deleteRear(){
    if(front == -1 && rear == -1){
        cout << "Underflow\n";
        return;
    }
    else if(front == rear){  // only one element
        front = rear = -1;
    }
    else if(rear == 0){
        rear = SIZE - 1;
    }
    else{
        rear--;
    }
}

// Display deque
void display(){
    if(front == -1){
        cout << "Deque is empty\n";
        return;
    }
    int i = front;
    cout << "Deque: ";
    while(true){
        cout << dq[i] << " ";
        if(i == rear) break;
        i = (i + 1) % SIZE;
    }
    cout << "\n";
}

int main(){
    insertRear(10);
    insertRear(20);
    insertFront(5);
    insertFront(2);
    display();

    deleteFront();
    display();

    deleteRear();
    display();

    return 0;
}
