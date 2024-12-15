# include "bits/stdc++.h"
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

void traverse(node *head)
{
    while (head->next != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << head->data;
}

void printlist(node *head)
{
    if (head == NULL)
        return;
    cout << head->data << " ";
    printlist(head->next);
}

int main(int argc, char const *argv[])
{
    node *head = new node(10);
    head->next = new node(20);
    head->next->next = new node(30);
    head->next->next->next = new node(40);

    traverse(head);

    return 0;
}