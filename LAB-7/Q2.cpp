#include <iostream>
using namespace std;

struct Node
{
    int data;
    int priority;
    Node *next;

    Node(int d, int p)
    {
        data = d;
        priority = p;
        next = NULL;
    }
};

class Queue
{
private:
    Node *front = NULL;

public:
    bool isEmpty()
    {
        return (front == NULL);
    }

    // PUSH (Insert according to priority)
    void push(int x, int p)
    {
        Node *newNode = new Node(x, p);

        // If empty or higher priority than front
        if (isEmpty() || p < front->priority)
        {
            newNode->next = front;
            front = newNode;
        }
        else
        {
            Node *temp = front;

            // Find correct position
            while (temp->next != NULL && temp->next->priority <= p)
            {
                temp = temp->next;
            }

            newNode->next = temp->next;
            temp->next = newNode;
        }

        cout << "Element inserted successfully!\n";
    }

    // POP
    void pop()
    {
        if (isEmpty())
        {
            cout << "Priority Queue is empty!\n";
            return;
        }

        Node *temp = front;
        cout << "Popped element is: " << front->data << endl;

        front = front->next;
        delete temp;
    }

    // PEEK
    void peek()
    {
        if (isEmpty())
        {
            cout << "Priority Queue is empty!\n";
            return;
        }

        cout << "Top element is: " << front->data << endl;
    }

    // DISPLAY
    void display()
    {
        if (isEmpty())
        {
            cout << "Priority Queue is empty!\n";
            return;
        }

        Node *temp = front;
        cout << "Queue elements are:\n";

        while (temp != NULL)
        {
            cout << temp->data << " (priority=" << temp->priority << ") -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};

int main()
{
    Queue q;
    int choice, value, priority;

    do
    {
        cout << "\n===== PRIORITY QUEUE MENU =====\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Peek\n";
        cout << "4. Display\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter value: ";
            cin >> value;
            cout << "Enter priority (0 = highest priority): ";
            cin >> priority;
            q.push(value, priority);
            break;

        case 2:
            q.pop();
            break;

        case 3:
            q.peek();
            break;

        case 4:
            q.display();
            break;

        case 5:
            cout << "Exiting program...\n";
            break;

        default:
            cout << "Invalid choice! Try again.\n";
        }

    } while (choice != 5);

    return 0;
}