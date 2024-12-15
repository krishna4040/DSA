#include <iostream>
using namespace std;

struct node
{
    int data;
    node *next;
    node(int x) : data(x), next(NULL) {}
    void print()
    {
        node *curr = this;
        while (curr != NULL)
        {
            cout << curr->data << "->";
            curr = curr->next;
        }
        cout << "NULL";
    }
};

node *insertLast(node *head, int x)
{
    node *temp = new node(x);
    if (head == NULL)
        return temp;
    node *curr = head;
    while (curr->next != NULL)
        curr = curr->next;
    curr->next = temp;
    return head;
}

node *merge(node *head1, node *head2)
{
    node *merged = NULL;
    if (head1 == NULL)
        return head2;
    else if (head2 == NULL)
        return head1;

    if (head1->data <= head2->data)
    {
        merged = head1;
        merged->next = merge(head1->next, head2);
    }
    else
    {
        merged = head2;
        merged->next = merge(head1, head2->next);
    }
    return merged;
}

node *mergeSort(node *head)
{
    if (head == NULL || head->next == NULL)
        return head;

    // Finding the middle of the linked list
    node *slow = head;
    node *fast = head->next;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    node *mid = slow->next;
    slow->next = NULL;

    node *left = mergeSort(head);
    node *right = mergeSort(mid);

    return merge(left, right);
}

int main()
{
    node *head = new node(30);
    head = insertLast(head, 20);
    head = insertLast(head, 10);

    head = mergeSort(head);
    head->print();

    return 0;
}
