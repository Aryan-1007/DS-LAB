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

int findMiddle(Node *head)
{
    Node *slow = head;
    Node *fast = head;

    while (fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow->data;
}

int main(int argc, char const *argv[])
{
    Node *head = createNode(11);
    head->next = createNode(22);
    head->next->next = createNode(33);
    head->next->next->next = createNode(44);
    head->next->next->next->next = createNode(55);

    int mid = findMiddle(head);
    cout << "Middle Element is " << mid;
    return 0;
}
