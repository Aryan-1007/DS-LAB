#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

class MinStack
{
private:
    Node *top;
    Node *minTop; // Stack to store minimums

public:
    MinStack()
    {
        top = NULL;
        minTop = NULL;
    }

    bool isEmpty()
    {
        return (top == NULL);
    }

    void push(int val)
    {
        // Create new node for main stack
        Node *newNode = new (nothrow) Node();
        if (newNode == NULL)
        {
            cout << "Stack Overflow (Memory Full)\n";
            return;
        }

        newNode->data = val;
        newNode->next = top;
        top = newNode;

        // Handle min stack
        Node *minNode = new (nothrow) Node();
        if (minNode == NULL)
        {
            cout << "Memory Error\n";
            return;
        }

        if (minTop == NULL || val <= minTop->data)
            minNode->data = val;
        else
            minNode->data = minTop->data;

        minNode->next = minTop;
        minTop = minNode;

        cout << "Pushed successfully\n";
    }

    void pop()
    {
        if (isEmpty())
        {
            cout << "Stack Underflow\n";
            return;
        }

        // Pop from main stack
        Node *temp = top;
        cout << "Popped: " << top->data << endl;
        top = top->next;
        delete temp;

        // Pop from min stack
        Node *minTemp = minTop;
        minTop = minTop->next;
        delete minTemp;
    }

    void getMin()
    {
        if (isEmpty())
        {
            cout << "Stack is empty\n";
            return;
        }

        cout << "Minimum element: " << minTop->data << endl;
    }

    ~MinStack()
    {
        while (!isEmpty())
            pop();
    }
};

int main()
{
    MinStack s;
    int choice, value;

    do
    {
        cout << "\n1.Push\n2.Pop\n3.Get Min\n4.Exit\nEnter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter value: ";
            cin >> value;
            s.push(value);
            break;
        case 2:
            s.pop();
            break;
        case 3:
            s.getMin();
            break;
        case 4:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice\n";
        }

    } while (choice != 4);

    return 0;
}