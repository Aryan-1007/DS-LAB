#include <bits/stdc++.h>
using namespace std;

struct NODE
{
    int data;
    NODE *next;
};

/* Delete Nth node from end in one traversal */
void deleteNthFromEnd(NODE *&head, int n)
{
    if (head == NULL || n <= 0)
        return;

    NODE dummy;
    dummy.next = head;

    NODE *fast = &dummy;
    NODE *slow = &dummy;

    // Move fast pointer n steps ahead
    for (int i = 0; i < n; i++)
    {
        if (fast->next == NULL)
            return;
        fast = fast->next;
    }

    // Move both pointers
    while (fast->next != NULL)
    {
        fast = fast->next;
        slow = slow->next;
    }

    // Delete node
    NODE *temp = slow->next;
    slow->next = temp->next;
    delete temp;

    head = dummy.next;
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
    fifth->next = NULL;

    cout << "Initial List: ";
    display(head);

    /* -------- Delete Nth node from end -------- */
    int n = 2;
    deleteNthFromEnd(head, n);

    cout << "After deleting " << n << "nd node from end: ";
    display(head);

    return 0;
}
