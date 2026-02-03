#include <bits/stdc++.h>
using namespace std;

struct NODE
{
    int data;
    NODE *next;

    NODE(int d)
    {
        data = d;
        next = NULL;
    }
};

NODE *convert(vector<int> arr)
{
    NODE *head = new NODE(arr[0]);
    NODE *mover = head;

    for (int i = 1; i < arr.size(); i++)
    {
        NODE *temp = new NODE(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}

NODE *reverseInGroups(NODE *head, int k)
{
    if (head == NULL || k <= 1)
        return head;

    NODE dummy(0);
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
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7};
    NODE *head = convert(arr);

    cout << "Initial list:\n";
    display(head);
    cout << "\nFinal list:\n";
    head = reverseInGroups(head, 3);
    display(head);
    return 0;
}
