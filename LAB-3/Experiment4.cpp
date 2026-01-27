#include <bits/stdc++.h>
using namespace std;

struct NODE
{
    int data;
    NODE *next;
};

/* Insert node at position k */
void insertAtPosition(NODE *&head, int position, int value)
{
    NODE *newNode = new NODE();
    newNode->data = value;

    if (position == 0)
    {
        newNode->next = head;
        head = newNode;
        return;
    }

    NODE *temp = head;
    for (int i = 0; i < position - 1 && temp != NULL; i++)
        temp = temp->next;

    if (temp == NULL)
    {
        delete newNode;
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

/* Delete node at position k */
void deleteAtPosition(NODE *&head, int position)
{
    if (head == NULL)
        return;

    if (position == 0)
    {
        NODE *temp = head;
        head = head->next;
        delete temp;
        return;
    }

    NODE *temp = head;
    for (int i = 0; i < position - 1 && temp->next != NULL; i++)
        temp = temp->next;

    if (temp->next == NULL)
        return;

    NODE *delNode = temp->next;
    temp->next = delNode->next;
    delete delNode;
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

    cout << "Initial List: ";
    display(head);

    /* -------- Insert at position -------- */
    insertAtPosition(head, 1, 15); // 10 15 20 30
    insertAtPosition(head, 3, 25); // 10 15 20 25 30

    cout << "After insertions: ";
    display(head);

    /* -------- Delete at position -------- */
    deleteAtPosition(head, 2); // delete 20

    cout << "After deletion at position 2: ";
    display(head);

    return 0;
}
