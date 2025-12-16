#include <iostream>
using namespace std;

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node* buildtree()
{
    struct node *root = (struct node *)malloc(sizeof(struct node));
    if (!root)
    {
        cout << "Memory Allocation Error !!!" << endl;
        exit(1);
    }
    cout << "Enter Data (-1 for NULL): ";
    int data;
    cin >> data;

    if (data == -1)
    {
        return NULL;
    }

    root->data = data;

    cout << "Enter data for inserting in LEFT of " << data << endl;
    root->left = buildtree();

    cout << "Enter data for inserting in RIGHT of " << data << endl;
    root->right = buildtree();

    return root;
}


struct Queue
{
    node *arr[100]; 
    int front, rear;

    Queue()
    {
        front = -1;
        rear = -1;
    }

    void enqueue(node *x)
    {
        if (rear == 99)
        {
            cout << "Queue overflow!" << endl;
            return;
        }
        rear = rear+1;
        if(front == -1){
            front = 0;
        }
        arr[rear] = x;
        
    }

    void dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue underflow!" << endl;
            return;
        }
         if (front == rear) { 
            
            front = rear = -1;
        } else {
            front++;
        }
    }

    node* getFront(){
        return arr[front];
    }

    bool isEmpty()
    {
       return (front == -1);
    }
};


void levelorder(struct node *root)
{
    if (root == NULL)
    {
        cout << "Tree is empty!\n";
        return;
    }

    Queue q;
    q.enqueue(root);

    while (!q.isEmpty())
    {
        node *temp = q.getFront();
        q.dequeue();
        cout << temp->data << " ";

        if (temp->left != NULL)
            q.enqueue(temp->left);

        if (temp->right != NULL)
            q.enqueue(temp->right);
    }
}


int main()
{
    struct node *root = buildtree();

    cout << "\nLevel Order Traversal: ";
    levelorder(root);
    cout << endl;

    return 0;
}
