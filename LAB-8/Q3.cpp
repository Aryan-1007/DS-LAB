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

        cout << "Inserted successfully!\n";
    }

    void Dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue is empty\n";
            return;
        }

        Node *temp = front;
        cout << "Removed element: " << front->data << endl;

        front = front->next;

        if (front == NULL)
            rear = NULL;

        delete temp;
    }

    void findMinMax()
    {
        if (isEmpty())
        {
            cout << "Queue is empty\n";
            return;
        }

        Node *temp = front;
        int minVal = temp->data;
        int maxVal = temp->data;

        while (temp != NULL)
        {
            if (temp->data < minVal)
                minVal = temp->data;

            if (temp->data > maxVal)
                maxVal = temp->data;

            temp = temp->next;
        }

        cout << "Minimum element: " << minVal << endl;
        cout << "Maximum element: " << maxVal << endl;
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
};

int main()
{
    Queue q;
    int choice, value;

    do
    {
        cout << "\n===== MENU =====\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Display\n";
        cout << "4. Find Min & Max\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter value: ";
            cin >> value;
            q.Enqueue(value);
            break;

        case 2:
            q.Dequeue();
            break;

        case 3:
            q.display();
            break;

        case 4:
            q.findMinMax();
            break;

        case 5:
            cout << "Exiting...\n";
            break;

        default:
            cout << "Invalid choice\n";
        }

    } while (choice != 5);

    return 0;
}