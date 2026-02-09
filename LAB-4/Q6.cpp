#include <bits/stdc++.h>
using namespace std;

struct NODE
{
    int data;
    NODE *next;

    NODE(int d)
    {
        data = d;
        next = NULL;
    }
};

NODE *convert(vector<int> arr)
{
    NODE *head = new NODE(arr[0]);
    NODE *mover = head;

    for (int i = 1; i < arr.size(); i++)
    {
        mover->next = new NODE(arr[i]);
        mover = mover->next;
    }
    return head;
}

void display(NODE *head)
{
    while (head)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

NODE *reverseList(NODE *head)
{
    NODE *prev = NULL;
    NODE *curr = head;

    while (curr)
    {
        NODE *nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }
    return prev;
}

bool isPalindrome(NODE *head)
{
    if (!head || !head->next)
        return true;

    NODE *slow = head;
    NODE *fast = head;

    // Find middle
    while (fast->next && fast->next->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    slow->next = reverseList(slow->next);

    NODE *first = head;
    NODE *second = slow->next;

    while (second)
    {
        if (first->data != second->data)
            return false;
        first = first->next;
        second = second->next;
    }

    return true;
}

int main()
{
    vector<int> arr;
    int x;
    cout << "Enter element and write -1 to stop the inserting" << endl;
    while (cin >> x && x != -1)
    {
        arr.push_back(x);
    }
    NODE *head = convert(arr);

    display(head);

    if (isPalindrome(head))
        cout << "Palindrome\n";
    else
        cout << "Not Palindrome\n";

    return 0;
}
