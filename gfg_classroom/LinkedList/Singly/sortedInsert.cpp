# include "bits/stdc++.h"
using namespace std;

struct node
{
    int data;
    node *next;
    node(int x): data(x) , next(NULL) {}
};

node* sortedInsert(node *head , int x)
{
    node *temp = new node(x);
    if (head == NULL)
        return temp;
    if (head->data > temp->data)
    {
        temp->next = head;
        return temp;
    }
    node *curr = head;
    while (curr->next->data < temp->data && curr->next != NULL)
        curr = curr->next;
    temp->next = curr->next;
    curr->next = temp;
    return head;
}

void printList(node *head)
{
    node *curr = head;
    while (curr != NULL)
    {
        cout << curr->data << " ";
        curr = curr->next;
    }
}

int main(int argc, char const *argv[])
{
    node *head = new node(10);
    head->next = new node(20);
    head->next->next = new node(30);
    head->next->next->next = new node(40);
    head = sortedInsert(head,25);
    printList(head);
    return 0;
}