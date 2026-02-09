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

Node *moveLastToFront(Node *&head)
{
    if (head == NULL || head->next == NULL)
        return head;

    Node *secLast = NULL;
    Node *last = head;

    while (last->next)
    {
        secLast = last;
        last = last->next;
    }

    secLast->next = NULL;
    last->next = head;
    head = last;

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

    cout << "Initial list:\n";
    display(head);
    cout << "\nFinal list:\n";
    head = moveLastToFront(head);
    display(head);
    return 0;
}
