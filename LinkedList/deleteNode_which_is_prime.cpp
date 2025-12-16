/*Write a program to find and delete prime numbers from the given singly
linked list whose first node's address is given by FIRST.*/


#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

bool isPrime(int n) {
    if(n <= 1) return false;
    for(int i = 2; i * i <= n; i++)
        if(n % i == 0)
            return false;
    return true;
}

void deletePrimes(Node* &first) {
    Node* temp = first;
    Node* prev = NULL;

    while(temp != NULL) {
        if(isPrime(temp->data)) {
            if(prev == NULL) { // deleting head
                first = temp->next;
                delete temp;
                temp = first;
            } else {
                prev->next = temp->next;
                delete temp;
                temp = prev->next;
            }
        } else {
            prev = temp;
            temp = temp->next;
        }
    }
}

void insert(Node* &first, int data) {
    Node* newNode = new Node;
    newNode->data = data;
    newNode->next = NULL;

    if(first == NULL) {
        first = newNode;
        return;
    }
    Node* temp = first;
    while(temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
}

void display(Node* first) {
    Node* temp = first;
    while(temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

int main() {
    Node* FIRST = NULL;

    insert(FIRST, 10);
    insert(FIRST, 3);
    insert(FIRST, 7);
    insert(FIRST, 12);
    insert(FIRST, 5);

    cout << "Original List: ";
    display(FIRST);

    deletePrimes(FIRST);

    cout << "After Deleting Primes: ";
    display(FIRST);

    return 0;
}
