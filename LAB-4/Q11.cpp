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

struct compare
{
    bool operator()(Node *a, Node *b)
    {
        return a->data > b->data;
    }
};

Node *mergeKLists(vector<Node *> &lists)
{
    priority_queue<Node *, vector<Node *>, compare> pq;

    for (auto l : lists)
        if (l)
            pq.push(l);

    Node dummy(-1);
    Node *tail = &dummy;

    while (!pq.empty())
    {
        Node *curr = pq.top();
        pq.pop();

        tail->next = curr;
        tail = tail->next;

        if (curr->next)
            pq.push(curr->next);
    }
    return dummy.next;
}

int main()
{
    Node *l1 = convert({1, 4, 5});
    Node *l2 = convert({2, 6});
    Node *l3 = convert({3, 4});

    vector<Node *> lists = {l1, l2, l3};

    Node *result = mergeKLists(lists);
    display(result);

    return 0;
}
