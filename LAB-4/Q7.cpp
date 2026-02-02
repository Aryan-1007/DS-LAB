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

Node *moveLastToFront(Node *&head)
{
    if (head == NULL || head->next == NULL)
        return head;

    Node *secLast = NULL;
    Node *last = head;

    while (last->next)
    {
        secLast = last;
        last = last->next;
    }

    secLast->next = NULL;
    last->next = head;
    head = last;

    return head;
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
    Node *head = createNode(10);
    head->next = createNode(20);
    head->next->next = createNode(30);
    head->next->next->next = createNode(40);
    cout << "Initial list:\n";
    display(head);
    cout << "\nFinal list:\n";
    head = moveLastToFront(head);
    display(head);
    return 0;
}
