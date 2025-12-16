/*Answer the following.
Given a singly linked list of integer numbers and special characters.
Write an algorithm to reverse the given linked list without affecting the
position of the special characters. Example:
Input: 1 -> # -> 2 -> @ -> 3 -> $ -> 4 -> 5 -> NULL
Output: 5 -> # -> 4 -> @ -> 3 -> $ -> 2 -> 1 -> NULL
*/

#include <iostream>
#include <stack>
#include <cctype> 
using namespace std;

struct Node {
    char data;
    Node* next;
};

Node* createNode(char data) {
    Node* newnode = new Node;
    newnode->data = data;
    newnode->next = NULL;
    return newnode;
}

void insert(Node* &head, char data) {
    Node* newnode = createNode(data);
    if (!head) {
        head = newnode;
        return;
    }
    Node* temp = head;
    while (temp->next) {
        temp = temp->next;
    }
    temp->next = newnode;
}

void reverseIntegers(Node* head) {
    stack<char> st;

    Node* temp = head;
    while (temp != NULL) {
        if (isdigit(temp->data))
            st.push(temp->data);
        temp = temp->next;
    }

    // Second pass: pop and replace integers
    temp = head;
    while (temp != NULL) {
        if (isdigit(temp->data)) {
            temp->data = st.top();
            st.pop();
        }
        temp = temp->next;
    }
}

void display(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

int main() {
    Node* head = NULL;

    // Input list 1 -> # -> 2 -> @ -> 3 -> $ -> 4 -> 5
    insert(head, '1');
    insert(head, '#');
    insert(head, '2');
    insert(head, '@');
    insert(head, '3');
    insert(head, '$');
    insert(head, '4');
    insert(head, '5');

    cout << "Original List:\n";
    display(head);

    reverseIntegers(head);

    cout << "\nModified List:\n";
    display(head);

    return 0;
}
