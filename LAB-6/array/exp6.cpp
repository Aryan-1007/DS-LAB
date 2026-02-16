#include <iostream>
using namespace std;

class MinStack
{
private:
    int arr[100];
    int minArr[100];
    int top;

public:
    MinStack()
    {
        top = -1;
    }

    bool isEmpty()
    {
        return top == -1;
    }

    void push(int val)
    {
        if (top < 100 - 1)
        {
            arr[++top] = val;

            if (top == 0)
                minArr[top] = val;
            else
                minArr[top] = (val < minArr[top - 1]) ? val : minArr[top - 1];

            cout << "Pushed successfully\n";
        }
    }

    void pop()
    {
        if (!isEmpty())
        {
            cout << "Popped: " << arr[top--] << endl;
        }
    }

    void getMin()
    {
        if (!isEmpty())
            cout << "Minimum element: " << minArr[top] << endl;
    }
};

int main()
{
    MinStack s;
    int choice, value;

    do
    {
        cout << "\n1.Push\n2.Pop\n3.Get Min\n4.Exit\nEnter choice: ";
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
            s.getMin();
            break;
        }

    } while (choice != 4);

    return 0;
}
