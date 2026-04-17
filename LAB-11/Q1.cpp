#include <iostream>
#include <queue>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int v)
    {
        data = v;
        left = right = NULL;
    }
};

#include <vector>

// Function to print array representation
void printArray(Node *root)
{
    if (!root)
        return;

    vector<int> arr;
    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        if (temp)
        {
            arr.push_back(temp->data);
            q.push(temp->left);
            q.push(temp->right);
        }
        else
        {
            arr.push_back(-1); // represent NULL
        }
    }

    // Remove trailing -1 values (optional, cleaner output)
    while (!arr.empty() && arr.back() == -1)
        arr.pop_back();

    cout << "Array representation: ";
    for (int x : arr)
        cout << x << " ";
}

int main()
{
    int val;
    cout << "Enter root value (-1 for NULL): ";
    cin >> val;

    if (val == -1)
        return 0;

    Node *root = new Node(val);
    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        int l, r;
        cout << "Enter left child of " << temp->data << " (-1 for NULL): ";
        cin >> l;
        if (l != -1)
        {
            temp->left = new Node(l);
            q.push(temp->left);
        }

        cout << "Enter right child of " << temp->data << " (-1 for NULL): ";
        cin >> r;
        if (r != -1)
        {
            temp->right = new Node(r);
            q.push(temp->right);
        }
    }

    cout << "Tree created successfully";
    printArray(root);
}