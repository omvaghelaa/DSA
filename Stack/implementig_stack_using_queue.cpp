#include<iostream>
#include<queue>
using namespace std;

queue<int> q1;
queue<int>q2;

void push(int data){
    while(!q1.empty()){
        q2.push(q1.front());
        q1.pop();
    }
    q1.push(data);
    while(!q2.empty()){
        q1.push(q2.front());
        q2.pop();
    }
}

void pop(){
    if(q1.empty()){
        cout<<"underflow";
        return;
    }
    int temp = q1.front();
    q1.pop();
   // cout<<temp;
}

void peek(){
    cout<<q1.front();
}

void disp(){
    queue<int> tmp = q1;
    while(!tmp.empty()){
        cout<<tmp.front();
        tmp.pop();
    }
}

int main(){
    push(1);
    push(2);
    push(3);
    pop();
    cout<<endl;
    disp();
    return 0;
}