#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node *bottom;

    Node(int d)
    {
        data = d;
        next = NULL;
        bottom = NULL;
    }
};

Node *merge(Node *&a, Node *&b)
{
    if (!a)
        return b;
    if (!b)
        return a;

    Node *result;

    if (a->data < b->data)
    {
        result = a;
        result->bottom = merge(a->bottom, b);
    }
    else
    {
        result = b;
        result->bottom = merge(a, b->bottom);
    }

    result->next = NULL;
    return result;
}

Node *flatten(Node *&head)
{
    if (!head || !head->next)
        return head;

    head->next = flatten(head->next);
    head = merge(head, head->next);

    return head;
}

void printList(Node *head)
{
    while (head)
    {
        cout << head->data << " ";
        head = head->bottom;
    }
    cout << endl;
}

int main()
{
    int n;
    cout << "Enter the number of sorted bottom linked list: ";
    cin >> n;

    Node *head = NULL;
    Node *prev = NULL;

    for (int i = 0; i < n; i++)
    {
        int m;
        cout << "Enter the number of element in row-" << i + 1 << ":";
        cin >> m;

        Node *verticalHead = NULL;
        Node *verticalPrev = NULL;

        for (int j = 0; j < m; j++)
        {
            int x;
            cout << "Enter the element-" << j + 1 << " of row-" << i + 1 << ":";
            cin >> x;

            Node *newNode = new Node(x);

            if (!verticalHead)
                verticalHead = newNode;
            else
                verticalPrev->bottom = newNode;

            verticalPrev = newNode;
        }

        if (!head)
            head = verticalHead;
        else
            prev->next = verticalHead;

        prev = verticalHead;
    }

    head = flatten(head);
    cout << "Final flatten linked list: ";
    printList(head);

    return 0;
}
