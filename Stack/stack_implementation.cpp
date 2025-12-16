#include<iostream>
using namespace std;

#define N 5
int stack[N];
int top = -1;

void push(int data){
    if(top == N-1){
        cout<<"Stack Already FULL !!!!!!!\n";
        return;
    }
    top = top+1;
    stack[top] = data;
}
void pop(){
    if(top == -1){
        cout<<"Stack Empty !!!!!!!!";
        return;
    }
    top = top-1;
}

void peek(){
    if(top == -1){
        cout<<"Already Empty !!!!!!";
        return;
    }
    cout<<stack[top];
}

void display(){
    for(int i=top;i>=0;i--){
        cout<<stack[i]<<" ";
    }
}

int main(){
    
    cout<<"1. Push\n2. Pop\n3. Peek\n4. Display\n5. Exit\n";
    
    int choice;
    cout<<"Enter your choice : ";
    int data;
    
    switch(choice){
        case 1:
            cout<<"Enter Data to be pushed : ";
            cin>>data;
            push(data);
            break;
        case 2:
            pop();
            break;
        case 3:
            peek();
            break;
        case 4:
            display();
            break;
        case 5:
            cout<<"Exiting....";
            break;
        default:
            cout<<"Invalid Choice !!!!!!!!";
    }
    
    return 0;
}