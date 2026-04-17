#include <iostream>
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

Node *insert(Node *root, int val)
{
    if (!root)
        return new Node(val);
    if (val < root->data)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);
    return root;
}

bool search(Node *root, int key)
{
    if (!root)
        return false;
    if (root->data == key)
        return true;

    if (key < root->data)
        return search(root->left, key);
    else
        return search(root->right, key);
}

int main()
{
    int n, x, key;
    cout << "Enter number of elements: ";
    cin >> n;

    Node *root = NULL;

    for (int i = 0; i < n; i++)
    {
        cin >> x;
        root = insert(root, x);
    }

    cout << "Enter key: ";
    cin >> key;

    if (search(root, key))
        cout << "Found";
    else
        cout << "Not Found";
}