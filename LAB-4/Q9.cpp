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

Node *getIntersection(Node *head1, Node *head2)
{
    if (!head1 || !head2)
        return NULL;

    Node *a = head1;
    Node *b = head2;

    while (a != b)
    {
        a = (a == NULL) ? head2 : a->next;
        b = (b == NULL) ? head1 : b->next;
    }
    return a;
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

    return 0;
}
