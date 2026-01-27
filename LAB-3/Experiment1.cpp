#include <bits/stdc++.h>
using namespace std;

struct NODE
{
    int data;
    NODE *next;
};

/* Insert at head */
void insertAtHead(NODE *&head, int value)
{
    NODE *newNode = new NODE();
    newNode->data = value;
    newNode->next = head;
    head = newNode;
}

/* Insert at tail */
void insertAtTail(NODE *&head, int value)
{
    NODE *newNode = new NODE();
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL)
    {
        head = newNode;
        return;
    }

    NODE *temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
}

/* Delete by value (first occurrence) */
void deleteByValue(NODE *&head, int value)
{
    if (head == NULL)
        return;

    if (head->data == value)
    {
        NODE *temp = head;
        head = head->next;
        delete temp;
        return;
    }

    NODE *curr = head;
    while (curr->next != NULL && curr->next->data != value)
        curr = curr->next;

    if (curr->next == NULL)
        return;

    NODE *temp = curr->next;
    curr->next = temp->next;
    delete temp;
}

/* Delete by position (0-based) */
void deleteByPosition(NODE *&head, int position)
{
    if (head == NULL || position < 0)
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

/* Search for a value */
int searchValue(NODE *head, int value)
{
    int pos = 0;
    while (head != NULL)
    {
        if (head->data == value)
            return pos;
        head = head->next;
        pos++;
    }
    return -1;
}

/* Reverse the list */
void reverseList(NODE *&head)
{
    NODE *prev = NULL;
    NODE *curr = head;

    while (curr != NULL)
    {
        NODE *nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }
    head = prev;
}

/* Detect cycle */
bool detectCycle(NODE *head)
{
    NODE *slow = head;
    NODE *fast = head;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
            return true;
    }
    return false;
}

/* Display list */
void displayList(NODE *head)
{
    while (head != NULL)
    {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
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
    displayList(head);

    insertAtHead(head, 5);
    insertAtTail(head, 40);

    cout << "After insertions: ";
    displayList(head);

    deleteByValue(head, 20);
    cout << "After deleting value 20: ";
    displayList(head);

    deleteByPosition(head, 2);
    cout << "After deleting position 2: ";
    displayList(head);

    int pos = searchValue(head, 30);
    cout << "Search 30 found at position: " << pos << endl;

    reverseList(head);
    cout << "Reversed List: ";
    displayList(head);

    if (detectCycle(head))
        cout << "Cycle detected\n";
    else
        cout << "No cycle detected\n";

    return 0;
}
