#include <bits/stdc++.h>
using namespace std;

struct NODE
{
    int data;
    NODE *next;
};

/* Detect cycle using Floyd’s algorithm */
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

/* Remove cycle without losing any node */
void removeCycle(NODE *head)
{
    NODE *slow = head;
    NODE *fast = head;

    // Step 1: Detect cycle
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
            break;
    }

    // No cycle
    if (fast == NULL || fast->next == NULL)
        return;

    // Step 2: Find start of cycle
    slow = head;
    while (slow != fast)
    {
        slow = slow->next;
        fast = fast->next;
    }

    // Step 3: Remove cycle
    NODE *temp = slow;
    while (temp->next != slow)
        temp = temp->next;

    temp->next = NULL;
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
    head->data = 1;

    NODE *second = new NODE();
    second->data = 2;

    NODE *third = new NODE();
    third->data = 3;

    NODE *fourth = new NODE();
    fourth->data = 4;

    NODE *fifth = new NODE();
    fifth->data = 5;

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;

    // Creating a cycle: 5 -> 3
    fifth->next = third;

    /* -------- Detect cycle -------- */
    if (detectCycle(head))
        cout << "Cycle detected\n";
    else
        cout << "No cycle\n";

    /* -------- Remove cycle -------- */
    removeCycle(head);

    if (!detectCycle(head))
        cout << "Cycle removed successfully\n";

    cout << "Final List: ";
    display(head);

    return 0;
}
