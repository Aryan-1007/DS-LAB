#include <bits/stdc++.h>
using namespace std;

struct NODE
{
    int data;
    NODE *next;
};

/* Insert at end in O(1) time */
void insertAtEndO1(NODE *&head, NODE *&tail, int value)
{
    NODE *newNode = new NODE();
    newNode->data = value;
    newNode->next = NULL;

    // Empty list
    if (head == NULL)
    {
        head = tail = newNode;
        return;
    }

    tail->next = newNode;
    tail = newNode;
}

/* Display list */
void display(NODE *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main()
{
    /* -------- Hard-coded initial linked list -------- */
    NODE *head = new NODE();
    head->data = 10;

    NODE *second = new NODE();
    second->data = 20;

    NODE *third = new NODE();
    third->data = 30;

    head->next = second;
    second->next = third;
    third->next = NULL;

    NODE *tail = third;

    cout << "Initial List: ";
    display(head);

    /* -------- O(1) insertion at end -------- */
    insertAtEndO1(head, tail, 40);
    insertAtEndO1(head, tail, 50);

    cout << "After inserting at end: ";
    display(head);

    return 0;
}
