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
    if (root == NULL)
        return new Node(val);

    if (val < root->data)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);

    return root;
}

void inorder(Node *root)
{
    if (root)
    {
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
}

int main()
{
    int n, x;
    cout << "Enter number of elements: ";
    cin >> n;

    Node *root = NULL;

    for (int i = 0; i < n; i++)
    {
        cout << "Enter value: ";
        cin >> x;
        root = insert(root, x);
    }

    cout << "Inorder (sorted): ";
    inorder(root);
}