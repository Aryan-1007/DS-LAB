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

Node *mergeSorted(Node *a, Node *b)
{
    if (!a)
        return b;
    if (!b)
        return a;

    if (a->data <= b->data)
    {
        a->next = mergeSorted(a->next, b);
        return a;
    }
    else
    {
        b->next = mergeSorted(a, b->next);
        return b;
    }
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

int main(int argc, char const *argv[])
{
    vector<int> arr;
    int x;
    cout << "Enter element and write -1 to stop the inserting" << endl;
    while (cin >> x && x != -1)
    {
        arr.push_back(x);
    }
    Node *head = convert(arr);

    cout << "List-1: ";
    display(head);

    vector<int> arr1;
    cout << "Enter element and write -1 to stop the inserting" << endl;
    while (cin >> x && x != -1)
    {
        arr1.push_back(x);
    }
    Node *head1 = convert(arr1);

    cout << "List-2: ";
    display(head1);

    Node *final = mergeSorted(head, head1);

    cout << "FInal List: ";
    display(final);
    return 0;
}
