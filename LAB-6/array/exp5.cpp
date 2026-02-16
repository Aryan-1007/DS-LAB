#include <iostream>
using namespace std;

class Stack
{
private:
    int arr[100];
    int top;

public:
    Stack() { top = -1; }

    bool isEmpty() { return top == -1; }

    void push(int val)
    {
        if (top < 99)
            arr[++top] = val;
        else
            cout << "Stack Overflow\n";
    }

    int pop()
    {
        if (!isEmpty())
            return arr[top--];
        cout << "Stack Underflow\n";
        return -1;
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
            s.push(ch - '0');
        else
        {
            int val2 = s.pop();
            int val1 = s.pop();
            int result;

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
            }

            s.push(result);
        }
    }

    cout << "Result: " << s.pop() << endl;

    return 0;
}
