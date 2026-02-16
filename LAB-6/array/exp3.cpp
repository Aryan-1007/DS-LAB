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
