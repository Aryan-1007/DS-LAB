#include <iostream>
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

    int count()
    {
        int cnt = 0;
        Node *temp = front;

        while (temp != NULL)
        {
            cnt++;
            temp = temp->next;
        }

        return cnt;
    }

    void display()
    {
        Node *temp = front;
        cout << "Queue: ";
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main()
{
    Queue q;
    int choice, value;

    do
    {
        cout << "\n1.Enqueue\n2.Display\n3.Count\n4.Exit\n";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter value: ";
            cin >> value;
            q.Enqueue(value);
            break;

        case 2:
            q.display();
            break;

        case 3:
            cout << "Total elements: " << q.count() << endl;
            break;
        }

    } while (choice != 4);

    return 0;
}