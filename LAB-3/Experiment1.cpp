#include <bits/stdc++.h>
using namespace std;

struct NODE
{
    int data;
    NODE *next;
};
void insertAtBeginning(NODE *&head, int newData)
{
    NODE *newNode = new NODE();
    newNode->data = newData;
    newNode->next = head;
    head = newNode;
}
void insertAtEnd(NODE *&head, int newData)
{
    NODE *newNode = new NODE();
    newNode->data = newData;
    newNode->next = NULL;
    if (head == NULL)
    {
        head = newNode;
        return;
    }
    NODE *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
}
void deleteByValue(NODE *&head, int value)
{
    if (head == NULL)
        return;
    if (head->data == value)
    {
        NODE *temp = head;
        head = head->next;
        delete temp;
        return;
    }
    NODE *current = head;
    NODE *previous = NULL;
    while (current != NULL && current->data != value)
    {
        previous = current;
        current = current->next;
    }
    if (current == NULL)
        return;
    previous->next = current->next;
    delete current;
}
void deleteByPostion(NODE *&head, int position)
{
    if (head == NULL)
        return;
    NODE *temp = head;
    NODE *previous = NULL;
    int cnt = 0;
    while (cnt != position)
    {
        previous = temp;
        temp = temp->next;
        cnt++;
    }
    previous->next = temp->next;
    delete temp;
}
int searchValue(NODE *&head, int value)
{
    int pos{};
    NODE *temp = head;
    if (temp->data != value)
    {
        temp = temp->next;
        pos++;
    }
    if (temp->next == NULL)
        return -1;
    return pos;
}
void reverseList(NODE *&head)
{
    NODE *current = head;
    NODE *previous = NULL;
    NODE *next = NULL;
    while (current != NULL)
    {
        next = current->next;
        current->next = previous;
        previous = current;
        current = next;
    }
    head = previous;
}
void DetectLoop(NODE *&head)
{
    NODE *slow = head;
    NODE *fast = head;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            cout << "Loop detected in the linked list." << endl;
            return;
        }
    }
    cout << "No loop detected in the linked list." << endl;
}
void displayList(NODE *head)
{
    NODE *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}
int main(int argc, char const *argv[])
{

    int n;
    cout << "Enter number of nodes: ";
    cin >> n;
    NODE *head = NULL;
    for (int i = 0; i < n; i++)
    {
        int data;
        cout << "Enter data for node " << i + 1 << ": ";
        cin >> data;
        insertAtEnd(head, data);
    }
    return 0;
}