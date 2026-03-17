#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;

    Node(int d)
    {
        data = d;
        next = NULL;
    }
};

Node *convert(vector<int> arr)
{
    Node *head = new Node(arr[0]);
    Node *mover = head;

    for (int i = 1; i < arr.size(); i++)
    {
        Node *temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}

void display(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

Node *mergeTwoLists(Node *l1, Node *l2)
{
    if (!l1)
        return l2;
    if (!l2)
        return l1;

    Node *result = NULL;

    if (l1->data < l2->data)
    {
        result = l1;
        result->next = mergeTwoLists(l1->next, l2);
    }
    else
    {
        result = l2;
        result->next = mergeTwoLists(l1, l2->next);
    }

    return result;
}

Node *mergeKLists(Node *lists[], int k)
{
    if (k == 0)
        return NULL;

    Node *result = lists[0];

    for (int i = 1; i < k; i++)
    {
        result = mergeTwoLists(result, lists[i]);
    }

    return result;
}

int main()
{
    Node *l1 = convert({1, 4, 5});
    Node *l2 = convert({2, 6});
    Node *l3 = convert({3, 4});
    cout << "Initial lists" << endl;
    cout << "list-1: ";
    display(l1);
    cout << "list-2: ";
    display(l2);
    cout << "list-3: ";
    display(l3);
    Node *lists[] = {l1, l2, l3};

    Node *result = mergeKLists(lists, 3);
    cout << "Final List: ";
    display(result);

    return 0;
}
