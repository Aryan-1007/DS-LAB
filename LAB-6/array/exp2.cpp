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

    void push(char ch)
    {
        if (top == 100 - 1)
        {
            cout << "Stack Overflow!\n";
            return;
        }
        arr[++top] = ch;
    }

    char pop()
    {
        if (top == -1)
        {
            return '\0';
        }
        return arr[top--];
    }

    bool isEmpty()
    {
        return (top == -1);
    }
};

int main()
{
    string str;
    cout << "Enter a string: ";
    cin >> str;

    Stack s;

    for (int i = 0; i < str.length(); i++)
    {
        s.push(str[i]);
    }

    cout << "Reversed string: ";
    while (!s.isEmpty())
    {
        cout << s.pop();
    }

    cout << endl;

    return 0;
}
