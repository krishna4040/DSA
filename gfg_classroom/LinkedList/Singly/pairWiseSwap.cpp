#include "bits/stdc++.h"
using namespace std;

struct node
{
    int data;
    node *next;
    node(int x) : data(x), next(NULL) {}
};

// swapping method
node *pairWiseSwap(node *head)
{
    node *curr = head;
    while (curr != NULL && curr->next != NULL)
    {
        swap(curr->data, curr->next->data);
        curr = curr->next->next;
    }
    return head;
}

// pointer ref method
node *pairSwap(node *head)
{
}

int main(int argc, char const *argv[])
{
    node *head = new node(10);
    head->next = new node(20);
    head->next->next = new node(30);
    head->next->next->next = new node(40);
    head->next->next->next->next = new node(50);

    head = pairWiseSwap(head);
    node *curr = head;
    while (curr != NULL)
    {
        cout << curr->data << " ";
        curr = curr->next;
    }

    return 0;
}