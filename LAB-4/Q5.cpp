#include <bits/stdc++.h>
using namespace std;

struct NODE
{
    int data;
    NODE *next;
};

NODE *createNode(int data)
{
    NODE *newNode = new NODE();
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

NODE *reverseInGroups(NODE *head, int k)
{
    if (head == NULL || k <= 1)
        return head;

    NODE dummy;
    dummy.next = head;
    NODE *prevGroup = &dummy;

    while (true)
    {
        NODE *kth = prevGroup;
        for (int i = 0; i < k && kth != NULL; i++)
            kth = kth->next;

        if (kth == NULL)
            break;

        NODE *groupNext = kth->next;
        NODE *prev = groupNext;
        NODE *curr = prevGroup->next;

        while (curr != groupNext)
        {
            NODE *nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }

        NODE *temp = prevGroup->next;
        prevGroup->next = kth;
        prevGroup = temp;
    }

    return dummy.next;
}
void display(NODE *head)
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
    NODE *head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);
    head->next->next->next->next = createNode(5);
    head->next->next->next->next->next = createNode(6);
    head->next->next->next->next->next->next = createNode(7);
    cout << "Initial list:\n";
    display(head);
    cout << "\nFinal list:\n";
    head = reverseInGroups(head, 3);
    display(head);
    return 0;
}
