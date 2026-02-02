struct Node
{
    int data;
    Node *next;
    Node *bottom;

    Node(int x)
    {
        data = x;
        next = nullptr;
        bottom = NULL;
    }
};

Node *merge(Node *a, Node *b)
{
    if (!a)
        return b;
    if (!b)
        return a;

    Node *result;

    if (a->data <= b->data)
    {
        result = a;
        result->bottom = merge(a->bottom, b);
    }
    else
    {
        result = b;
        result->bottom = merge(a, b->bottom);
    }

    result->next = nullptr; // important
    return result;
}

Node *flatten(Node *head)
{
    if (!head || !head->next)
        return head;

    head->next = flatten(head->next);
    head = merge(head, head->next);

    return head;
}

int main(int argc, char const *argv[])
{

    return 0;
}
