#include <bits/stdc++.h>
using namespace std;

struct NODE
{
    int data;
    NODE *next;
};

void insertAtBeginning(NODE *&head, NODE *&oldHead, int value)
{
    oldHead = head; // save previous state

    NODE *newNode = new NODE();
    newNode->data = value;
    newNode->next = head;
    head = newNode;
}

/* Undo last insertion */
void undo(NODE *&head, NODE *&oldHead)
{
    if (head == NULL)
        return;

    NODE *temp = head;
    head = oldHead; // restore old list
    delete temp;
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

    head->next = new NODE();
    head->next->data = 20;

    head->next->next = new NODE();
    head->next->next->data = 30;

    head->next->next->next = NULL;

    NODE *oldHead = NULL;

    cout << "Initial List: ";
    display(head);

    /* -------- Insert at beginning -------- */
    insertAtBeginning(head, oldHead, 5);
    cout << "After insertion: ";
    display(head);

    /* -------- Undo insertion -------- */
    undo(head, oldHead);
    cout << "After undo: ";
    display(head);

    return 0;
}
