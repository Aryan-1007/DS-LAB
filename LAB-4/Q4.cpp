#include <bits/stdc++.h>
using namespace std;

struct NODE
{
    int data;
    NODE *next;
    NODE *random;

    NODE(int d)
    {
        data = d;
        next = NULL;
        random = NULL;
    }
};

NODE *convert(vector<int> arr)
{
    NODE *head = new NODE(arr[0]);
    NODE *mover = head;

    for (int i = 1; i < arr.size(); i++)
    {
        mover->next = new NODE(arr[i]);
        mover = mover->next;
    }
    return head;
}

void display(NODE *head)
{
    while (head != NULL)
    {
        cout << "Data: " << head->data << ", Random: ";
        if (head->random)
            cout << head->random->data;
        else
            cout << "NULL";
        cout << endl;
        head = head->next;
    }
}

NODE *cloneLinkedList(NODE *head)
{
    if (!head)
        return NULL;

    NODE *temp = head;
    while (temp)
    {
        NODE *copy = new NODE(temp->data);
        copy->next = temp->next;
        temp->next = copy;
        temp = copy->next;
    }

    temp = head;
    while (temp)
    {
        if (temp->random)
            temp->next->random = temp->random->next;
        temp = temp->next->next;
    }

    NODE *dummy = new NODE(-1);
    NODE *res = dummy;
    temp = head;

    while (temp)
    {
        res->next = temp->next;
        temp->next = temp->next->next;
        res = res->next;
        temp = temp->next;
    }

    return dummy->next;
}

int main()
{
    vector<int> arr = {1, 3, 5, 9};
    NODE *head = convert(arr);

    head->random = head->next->next;       // 1 -> 5
    head->next->random = head;             // 3 -> 1
    head->next->next->random = head->next; // 5 -> 3
    head->next->next->next->random = head; // 9 -> 1

    cout << "Original List:\n";
    display(head);

    NODE *clonedHead = cloneLinkedList(head);

    cout << "\nCloned List:\n";
    display(clonedHead);

    return 0;
}
