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
    while(a!=NULL || b!=NULL)
    {
        Node* n1 =a->next;
        Node* n2 =b->next;
        if(a->data<= b->data)
        {
            
        }
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
    vector<int> arr = {1, 4, 8};
    Node *head = convert(arr);
    // Node *head1 = createNode(1);
    // head1->next = createNode(4);
    // head1->next->next = createNode(8);

    cout << "List-1: ";
    display(head);

    vector<int> arr1 = {2, 3, 9};
    Node *head1 = convert(arr1);
    // Node *head = createNode(2);
    // head->next = createNode(3);
    // head->next->next = createNode(9);

    cout << "List-2: ";
    display(head1);

    Node *final = mergeSorted(head, head1);

    cout << "FInal List: ";
    display(final);
    return 0;
}
