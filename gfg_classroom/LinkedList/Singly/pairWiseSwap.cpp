#include "bits/stdc++.h"
using namespace std;

struct node
{
    int data;
    node *next;
    node(int x)
    {
        data = x;
        next = NULL;
    }
};

void print(node *head)
{
    node *curr = head;
    while (curr != NULL)
    {
        cout << curr->data << "->";
        curr = curr->next;
    }
    return;
}

node *pairwiseSwap(node *head)
{
    if (head == NULL || head->next == NULL)
        return head;
    node *curr = head->next->next;
    node *prev = head;
    head = head->next;
    head->next = prev;
    while (curr != NULL || curr->next != NULL)
    {
        prev->next = curr->next;
        prev = curr;
        node *next = curr->next->next;
        curr->next->next = curr;
        curr = next;
    }
    prev->next = curr;
    return head;
}

int main(int argc, char const *argv[])
{
    node *head = new node(10);
    head->next = new node(20);
    head->next->next = new node(30);

    node *l = pairwiseSwap(head);
    print(l);

    return 0;
}
