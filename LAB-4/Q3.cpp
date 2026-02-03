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

Node *removeDupli(Node *&head)
{
    Node *temp = head;
    if (head == NULL)
        return NULL;
    int data = INT_MIN;
    Node *prev;
    while (temp != NULL)
    {
        if (temp->data != data)
        {
            data = temp->data;
            prev = temp;
            temp = temp->next;
            continue;
        }
        else
        {
            prev->next = temp->next;
            delete temp;
            temp = prev->next;
        }
    }
    return head;
}

void display(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << "->";
        head = head->next;
    }
    cout << "NULL";
}
int main(int argc, char const *argv[])
{
    vector<int> arr = {2, 2, 2, 5, 5, 9};
    Node *head = convert(arr);

    cout << "Initial list:\n";
    display(head);
    cout << "\nFinal list:\n";
    head = removeDupli(head);
    display(head);
    return 0;
}
