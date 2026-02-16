#include <iostream>
using namespace std;

class Stack
{
private:
    char arr[100];
    int top;

public:
    Stack()
    {
        top = -1;
    }

    bool isEmpty()
    {
        return top == -1;
    }

    void push(char ch)
    {
        if (top < 100 - 1)
            arr[++top] = ch;
    }

    char pop()
    {
        if (!isEmpty())
            return arr[top--];
        return '\0';
    }

    char peek()
    {
        if (!isEmpty())
            return arr[top];
        return '\0';
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
            s.pop();
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
