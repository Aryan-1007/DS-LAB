#include <iostream>
using namespace std;

struct Node
{
    char data;
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

    void push(char ch)
    {
        Node *newNode = new (nothrow) Node();

        if (newNode == NULL)
        {
            cout << "Stack Overflow (Memory Full)\n";
            return;
        }

        newNode->data = ch;
        newNode->next = top;
        top = newNode;
    }

    char pop()
    {
        if (isEmpty())
            return '\0';

        Node *temp = top;
        char ch = top->data;
        top = top->next;
        delete temp;

        return ch;
    }

    char peek()
    {
        if (!isEmpty())
            return top->data;
        return '\0';
    }

    ~Stack()
    {
        while (!isEmpty())
            pop();
    }
};

bool isMatchingPair(char open, char close)
{
    if (open == '(' && close == ')')
        return true;
    if (open == '{' && close == '}')
        return true;
    if (open == '[' && close == ']')
        return true;
    return false;
}

int main()
{
    string expr;
    cout << "Enter expression: ";
    cin >> expr;

    Stack s;
    bool balanced = true;

    for (int i = 0; i < expr.length(); i++)
    {
        char ch = expr[i];

        if (ch == '(' || ch == '{' || ch == '[')
            s.push(ch);
        else if (ch == ')' || ch == '}' || ch == ']')
        {
            if (s.isEmpty() || !isMatchingPair(s.pop(), ch))
            {
                balanced = false;
                break;
            }
        }
    }

    if (!s.isEmpty())
        balanced = false;

    if (balanced)
        cout << "Balanced\n";
    else
        cout << "Not Balanced\n";

    return 0;
}