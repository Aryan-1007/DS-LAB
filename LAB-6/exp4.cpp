#include <iostream>
#include <cctype>
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

int precedence(char op)
{
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    return 0;
}

int main()
{
    string infix, postfix = "";
    cout << "Enter infix expression: ";
    cin >> infix;

    Stack s;

    for (int i = 0; i < infix.length(); i++)
    {
        char ch = infix[i];

        if (isalnum(ch))
            postfix += ch;

        else if (ch == '(')
            s.push(ch);

        else if (ch == ')')
        {
            while (!s.isEmpty() && s.peek() != '(')
                postfix += s.pop();
            s.pop(); // remove '('
        }

        else
        {
            while (!s.isEmpty() && precedence(s.peek()) >= precedence(ch))
                postfix += s.pop();
            s.push(ch);
        }
    }

    while (!s.isEmpty())
        postfix += s.pop();

    cout << "Postfix expression: " << postfix << endl;

    return 0;
}