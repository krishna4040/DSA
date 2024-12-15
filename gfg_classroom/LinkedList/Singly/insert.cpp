# include "bits/stdc++.h"
using namespace std;

struct node{
    int data;
    node *next;
    node(int x){data = x; next = NULL;}
    void print()
    {
        node *curr = this;
        while (curr != NULL)
        {
            cout << curr->data << " ";
            curr = curr->next;
        }
    }
};

// Insert at beginning
node* insertBeg(node *head , int x)
{
    node *newHead = new node(x);
    if (head == NULL)
        return newHead;
    newHead->next = head;
    return newHead;
}

// Insert at end
node* insertEnd(node *head , int x)
{
    node *tail = new node(x);
    if (head == NULL)
        return tail;
    node *curr = head;
    while (curr->next != NULL)
        curr = curr->next;
    curr->next = tail;
    return head;
}

// Insert at given position
node* insertAtPos(node *head , int x , int pos)
{
    node *newNode = new node(x);
    if (head == NULL)
        return newNode;
    node *curr = head;
    while (pos != 1 && curr != NULL)
    {
        curr = curr->next;
        pos--;
    }
    if (curr == NULL)
        return head;
    newNode->next = curr->next;
    curr->next = newNode;
    return head;
}

int main(int argc, char const *argv[])
{
    node *head = NULL;
    head = insertBeg(head,30);
    head = insertBeg(head,20);
    head = insertBeg(head,10);

    head = insertEnd(head,40);
    head = insertEnd(head,50);
    head = insertEnd(head,60);

    head->print();

    return 0;
}