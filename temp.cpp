
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
int main(int argc, char const *argv[])
{
    vector<int> arr;
    for (int i = 0; i < 5; i++)
    {
        int x;
        cout << "enter element: ";
        cin >> x;
        arr.push_back(x);
    }
    Node *head = convert(arr);
    int value;
    cout << "enter";
    cin >> value;
    Node *curr = head;
    Node *prev = NULL;

    while (curr->next != NULL)
    {
        if (curr->data == value)
        {
            Node *temp = curr;
            prev->next = curr->next;
            curr = curr->next;
            delete temp;
        }
        else
        {
            prev = curr;
            curr = curr->next;
        }
    }
    display(head);
    return 0;
}
