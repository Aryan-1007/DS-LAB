#include <iostream>
#include <stack>
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
    bool isEmpty()
    {
        return (front == NULL);
    }

    void Enqueue(int x)
    {
        if (isEmpty())
            front = rear = new Node(x);
        else
        {
            rear->next = new Node(x);
            rear = rear->next;
        }
    }

    int Dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue is empty\n";
            return -1;
        }

        Node *temp = front;
        int val = front->data;
        front = front->next;

        if (front == NULL)
            rear = NULL;

        delete temp;
        return val;
    }

    void display()
    {
        if (isEmpty())
        {
            cout << "Queue is empty\n";
            return;
        }

        Node *temp = front;
        cout << "Queue: ";
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    void reverse()
    {
        stack<int> s;

        while (!isEmpty())
            s.push(Dequeue());

        while (!s.empty())
        {
            Enqueue(s.top());
            s.pop();
        }

        cout << "Queue reversed successfully!\n";
    }
};

int main()
{
    Queue q;
    int choice, value;

    do
    {
        cout << "\n1.Enqueue\n2.Dequeue\n3.Display\n4.Reverse\n5.Exit\n";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter value: ";
            cin >> value;
            q.Enqueue(value);
            break;

        case 2:
            cout << "Removed: " << q.Dequeue() << endl;
            break;

        case 3:
            q.display();
            break;

        case 4:
            q.reverse();
            break;
        }

    } while (choice != 5);

    return 0;
}