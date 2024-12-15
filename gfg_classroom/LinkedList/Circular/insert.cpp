#include "bits/stdc++.h"
using namespace std;

struct node
{
    int data;
    node *next;
    node(int x) : data(x), next(NULL) {}
    void printlist(node *head)
    {
        if (head == NULL)
            return;
        node *p = head;
        do{
            cout << p->data << " ";
            p = p->next;
        } while (p != head);
    }
};

// Insert at Begin
node *insertBeg(node *head, int x)
{
    node *newHead = new node(x);
    if (head == NULL)
    {
        newHead->next = newHead;
        return newHead;
    }
    else
    {
        newHead->next = head->next;
        head->next = newHead;
        swap(head->data , newHead->data);
    }
    return head;
}

// Insert at End
node *insertEnd(node *head, int x)
{
    node *newHead = new node(x);
    if (head == NULL)
        newHead->next = newHead;
    else
    {
        newHead->next = head->next;
        head->next = newHead;
        swap(head->data , newHead->data);
    }
    return newHead;
}

int main(int argc, char const *argv[])
{
    node *head = NULL;
    head = insertBeg(head,10);
    head = insertBeg(head,20);
    head = insertBeg(head,30);
    head = insertBeg(head,40);

    head->printlist(head);

    return 0;
}