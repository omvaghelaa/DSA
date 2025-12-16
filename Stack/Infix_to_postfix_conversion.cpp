#include<iostream>
#include<cstring>
using namespace std;

const int size = 50;
char stack[size];
int top = -1;

void push(char val){
    if(top == size-1){
        cout<<"Overflow !!!!!";
    } else {
        stack[++top] = val;
    }
}

char pop(){
    if(top == -1){
        cout<<"Underflow !!!!!!";
        return '\0';
    } else {
        return stack[top--];
    }
}

char peek(){
    if(top == -1){
        return '\0';
    } else {
        return stack[top];
    }
}

int precedence(char c){
    if(c == '^')
        return 3;
    else if(c == '*' || c == '/')
        return 2;
    else if(c == '+' || c == '-')
        return 1;
    else
        return -1;
}

void infixToPostfix(char infix[], char postfix[]){
    int k = 0;
    for(int i = 0; infix[i] != '\0'; i++){
        char c = infix[i];

        // operand → directly add
        if((c>='A' && c<='Z') || (c>='a' && c<='z') || (c>='0' && c<='9')){
            postfix[k++] = c;
        }
        // left parenthesis → push
        else if(c == '('){
            push(c);
        }

        else if(c == ')'){
            while(top != -1 && peek() != '('){
                postfix[k++] = pop();
            }
            pop();
        }
        else {
            while(top != -1 && precedence(peek()) >= precedence(c)){
                postfix[k++] = pop();
            }
            push(c);
        }
    }
    while(top != -1){
        postfix[k++] = pop();
    }
    postfix[k] = '\0';
}

int main(){
    char infix[] = "((a+(b*c))-((d/e)^f))"; 
    char postfix[size];
    
    infixToPostfix(infix, postfix);

    cout << "Infix: " << infix << endl;
    cout << "Postfix: " << postfix << endl;

    return 0;
}
