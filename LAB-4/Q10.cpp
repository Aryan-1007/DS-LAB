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

Node *merge(Node *a, Node *b)
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

Node *flatten(Node *head)
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
    Node *head = new Node(5);
    head->bottom = new Node(7);
    head->bottom->bottom = new Node(8);

    head->next = new Node(10);
    head->next->bottom = new Node(20);

    head->next->next = new Node(19);
    head->next->next->bottom = new Node(22);

    head->next->next->next = new Node(28);
    head->next->next->next->bottom = new Node(40);
    head->next->next->next->bottom->bottom = new Node(45);

    head = flatten(head);
    printList(head);

    return 0;
}
