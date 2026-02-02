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

Node *removeDupli(Node *&head)
{
    Node *temp = head;
    if (head == NULL)
        return NULL;
    int data = INT_MIN;
    Node *prev;
    while (temp != NULL)
    {
        if (temp->data != data)
        {
            data = temp->data;
            prev = temp;
            temp = temp->next;
            continue;
        }
        else
        {
            prev->next = temp->next;
            delete temp;
            temp = prev->next;
        }
    }
    return head;
}

void display(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << "->";
        head = head->next;
    }
    cout << "NULL";
}
int main(int argc, char const *argv[])
{
    Node *head = createNode(2);
    head->next = createNode(2);
    head->next->next = createNode(2);
    head->next->next->next = createNode(5);
    head->next->next->next->next = createNode(5);
    head->next->next->next->next->next = createNode(9);
    cout << "Initial list:\n";
    display(head);
    cout << "\nFinal list:\n";
    head = removeDupli(head);
    display(head);
    return 0;
}
