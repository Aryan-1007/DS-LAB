#include <iostream>
#include <cctype>
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

    void push(int val)
    {
        Node *newNode = new (nothrow) Node();

        if (newNode == NULL)
        {
            cout << "Stack Overflow (Memory Full)\n";
            return;
        }

        newNode->data = val;
        newNode->next = top;
        top = newNode;
    }

    int pop()
    {
        if (isEmpty())
        {
            cout << "Stack Underflow\n";
            return -1;
        }

        Node *temp = top;
        int val = top->data;
        top = top->next;
        delete temp;

        return val;
    }

    ~Stack()
    {
        while (!isEmpty())
            pop();
    }
};

int main()
{
    string postfix;
    cout << "Enter postfix expression: ";
    cin >> postfix;

    Stack s;

    for (int i = 0; i < postfix.length(); i++)
    {
        char ch = postfix[i];

        if (isdigit(ch))
        {
            s.push(ch - '0'); // convert char to integer
        }
        else
        {
            int val2 = s.pop();
            int val1 = s.pop();
            int result = 0;

            switch (ch)
            {
            case '+':
                result = val1 + val2;
                break;
            case '-':
                result = val1 - val2;
                break;
            case '*':
                result = val1 * val2;
                break;
            case '/':
                result = val1 / val2;
                break;
            default:
                cout << "Invalid operator\n";
                return 0;
            }

            s.push(result);
        }
    }

    cout << "Result: " << s.pop() << endl;

    return 0;
}