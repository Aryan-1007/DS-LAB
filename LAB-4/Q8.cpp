#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

Node *createNode(int data)
{
    Node *newNode = new Node();
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

Node *mergeSorted(Node *a, Node *b)
{
    if (!a)
        return b;
    if (!b)
        return a;

    if (a->data <= b->data)
    {
        a->next = mergeSorted(a->next, b);
        return a;
    }
    else
    {
        b->next = mergeSorted(a, b->next);
        return b;
    }
}

void display(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main(int argc, char const *argv[])
{
    Node *head1 = createNode(1);
    head1->next = createNode(4);
    head1->next->next = createNode(8);

    cout << "List-1: ";
    display(head1);

    Node *head = createNode(2);
    head->next = createNode(3);
    head->next->next = createNode(9);

    cout << "List-2: ";
    display(head);

    Node *final = mergeSorted(head1, head);

    cout << "FInal List: ";
    display(final);
    return 0;
}
