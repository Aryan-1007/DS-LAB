#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

bool detectCycle(Node *head)
{
    Node *fast = head;
    Node *slow = head;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            return 1;
        }
    }
    return 0;
}
int main(int argc, char const *argv[])
{
    Node *head = new Node();
    head->data = 1;

    Node *second = new Node();
    second->data = 2;

    Node *third = new Node();
    third->data = 3;

    Node *fourth = new Node();
    fourth->data = 4;

    Node *fifth = new Node();
    fifth->data = 5;

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;

    // Creating a cycle: 5 -> 3
    fifth->next = third;

    if (detectCycle(head))
        cout << "Cycle detected\n";
    else
        cout << "No cycle\n";
    return 0;
}
