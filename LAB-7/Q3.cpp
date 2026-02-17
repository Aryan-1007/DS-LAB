#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node *next;
    Node(int d)
    {
        data = d;
        next = NULL;
    }
};

class Queue
{
private:
    Node *front = NULL;
    Node *rear = NULL;

public:
    void Enqueue(int x)
    {
        if (isEmpty())
        {
            front = rear = new Node(x);
        }
        else
        {
            rear->next = new Node(x);
            rear = rear->next;
        }
        display();
    }
    void Dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue is empty" << endl;
            return;
        }
        Node *temp = front;
        cout << "Popped element is: " << front->data << endl;
        if (front == rear)
        {
            front = rear = NULL;
            delete (temp);
        }
        front = front->next;
        delete (temp);
        display();
    }
    bool isEmpty()
    {
        if (front == NULL)
        {
            return 1;
        }
        return 0;
    }
    void peek()
    {
        if (isEmpty())
        {
            cout << "Queue is empty" << endl;
            return;
        }
        cout << "Top element is: " << front->data << endl;
        display();
    }
    void display()
    {
        if (isEmpty())
        {
            cout << "Queue is empty" << endl;
            return;
        }
        cout << "Queue elements are: ";
        Node *temp = front;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl
             << endl
             << endl
             << endl
             << endl;
    }
};

int main(int argc, char const *argv[])
{
    Queue q;
    int choice;

    while (1)
    {
        cout << "Enter 1 to Enqueue, 2 to Dequeue, 3 to Peek, 4 to Display, 5 to Check if empty,6 to Exit: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            int x;
            cout << "Enter element to be inserted: ";
            cin >> x;
            q.Enqueue(x);
            break;
        case 2:
            q.Dequeue();
            break;
        case 3:
            q.peek();
            break;
        case 4:
            q.display();
            break;
        case 5:
            if (q.isEmpty())
                cout << "Queue is empty" << endl;
            else
                cout << "Queue is not empty" << endl;
            break;
        case 6:
            exit(0);
        default:
            cout << "Invalid choice" << endl;
        }
    }
    return 0;
}
