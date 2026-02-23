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
        Node *newNode = new Node();

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
        {
            return '\0';
        }

        Node *temp = top;
        char ch = top->data;
        top = top->next;
        delete temp;

        return ch;
    }

    ~Stack()
    {
        while (!isEmpty())
        {
            pop();
        }
    }
};

int main()
{
    string str;
    cout << "Enter a string: ";
    cin >> str;

    Stack s;

    // Push all characters into stack
    for (int i = 0; i < str.length(); i++)
    {
        s.push(str[i]);
    }

    // Pop all characters to reverse
    cout << "Reversed string: ";
    while (!s.isEmpty())
    {
        cout << s.pop();
    }

    cout << endl;

    return 0;
}