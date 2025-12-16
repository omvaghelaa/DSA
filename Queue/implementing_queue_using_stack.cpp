#include<iostream>
#include<stack>
using namespace std;

stack<int> s1;
stack<int> s2;

void enqueue(int data){
    while(!s1.empty()){
        s2.push(s1.top());
        s1.pop();
    }
    s1.push(data);
    while(!s2.empty()){
        s1.push(s2.top());
        s2.pop();
    }
}

void dequeue(){
    s1.pop();
}

void peek(){
    cout<<s1.top();
}

void disp(){
    stack<int> temp = s1;
    while(!temp.empty()){
        cout<<temp.top();
        temp.pop();
    }
}

int main(){
    
    enqueue(1);
    enqueue(2);
    enqueue(3);
    dequeue();
    disp();
    return 0;
}