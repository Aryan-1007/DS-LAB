#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

class Stack
{
private:
    Node *top;

public:
    Stack()
    {
        top = NULL;
    }

    bool isEmpty()
    {
        return (top == NULL);
    }

    void push(int value)
    {
        Node *newNode = new Node();

        if (newNode == NULL)
        {
            cout << "Stack Overflow (Memory Full)\n";
            return;
        }

        newNode->data = value;
        newNode->next = top;
        top = newNode;

        cout << value << " pushed into stack\n";
    }

    void pop()
    {
        if (isEmpty())
        {
            cout << "Stack Underflow (Stack is empty)\n";
            return;
        }

        Node *temp = top;
        cout << "Popped element: " << top->data << endl;
        top = top->next;
        delete temp;
    }

    void peek()
    {
        if (isEmpty())
        {
            cout << "Stack is empty\n";
            return;
        }

        cout << "Top element: " << top->data << endl;
    }
    void display()
    {
        if (isEmpty())
        {
            cout << "Stack is empty\n";
            return;
        }

        Node *temp = top;
        cout << "Stack elements: ";
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
    Stack s;
    int choice, value;

    while (true)
    {
        s.display();
        cout << "\n1. Push\n2. Pop\n3. Peek\n4. isEmpty\n5. Exit\n";
        cout << "Enter your choice: ";
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
            s.peek();
            break;

        case 4:
            if (s.isEmpty())
                cout << "Stack is empty\n";
            else
                cout << "Stack is not empty\n";
            break;

        case 5:
            return 0;

        default:
            cout << "Invalid choice\n";
        }
    }

    return 0;
}
