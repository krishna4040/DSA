# include "bits/stdc++.h"
using namespace std;

struct node
{
    int data;
    node *next;
    node *prev;
    node(int x){data = x; next = NULL; prev = NULL;}
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

// Insert at begin
node* insertBeg(node *head , int x)
{
    node *newHead = new node(x);
    if (head == NULL)
        return newHead;
    newHead->next = head;
    head->prev = newHead;
    return newHead;
}

// Insert at End
node* insertEnd(node *head , int x)
{
    node *tail = new node(x);
    if (head == NULL)
        return tail;
    node *curr = head;
    while (curr->next != NULL)
        curr = curr->next;
    curr->next = tail;
    tail->prev = curr;
    return head;
}

// Insert At pos
node* insertPos(node *head , int x , int pos)
{
    node *temp = new node(x);

    if (head == NULL)
        return temp;

    node *curr = head;
    while (pos != 1)
    {
        curr = curr->next;
        pos--;
    }

    temp->next = curr->next;
    temp->prev = curr->prev;

    curr->next->next->prev = temp;
    curr->next = temp;

    return head;
}

int main(int argc, char const *argv[])
{
    node *head = NULL;

    head = insertBeg(head,30);
    head = insertBeg(head,20);
    head = insertBeg(head,10);
    // print(head);

    head = insertEnd(head,40);
    head = insertEnd(head,50);
    head = insertEnd(head,60);
    // print(head);

    head = insertPos(head,60,3);
    head->print();

    return 0;
}