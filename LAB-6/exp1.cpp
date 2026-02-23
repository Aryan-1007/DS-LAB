#include <iostream>
using namespace std;

class Stack
{
private:
    int arr[100];
    int top;

public:
    Stack()
    {
        top = -1;
    }

    bool isEmpty()
    {
        return (top == -1);
    }

    bool isFull()
    {
        return (top == 100 - 1);
    }

    void push(int value)
    {
        if (isFull())
        {
            cout << "Stack Overflow!\n";
            return;
        }
        arr[++top] = value;
        cout << "Element pushed successfully.\n";
    }

    void pop()
    {
        if (isEmpty())
        {
            cout << "Stack Underflow!\n";
            return;
        }
        cout << "Popped element: " << arr[top--] << endl;
    }

    void peek()
    {
        if (isEmpty())
        {
            cout << "Stack is empty.\n";
            return;
        }
        cout << "Top element: " << arr[top] << endl;
    }

    void display()
    {
        if (isEmpty())
        {
            cout << "Stack is empty.\n";
            return;
        }
        cout << "Stack elements: ";
        for (int i = top; i >= 0; i--)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    Stack s;
    int choice, value;

    do
    {
        s.display();
        cout << "\n--- STACK MENU ---\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Peek\n";
        cout << "4. Check if Empty\n";
        cout << "5. Check if Full\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter value to push: ";
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
                cout << "Stack is Empty.\n";
            else
                cout << "Stack is NOT Empty.\n";
            break;

        case 5:
            if (s.isFull())
                cout << "Stack is Full.\n";
            else
                cout << "Stack is NOT Full.\n";
            break;

        case 6:
            cout << "Exiting...\n";
            break;

        default:
            cout << "Invalid choice!\n";
        }

    } while (choice != 6);

    return 0;
}
