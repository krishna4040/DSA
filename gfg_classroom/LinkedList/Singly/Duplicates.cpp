# include "bits/stdc++.h"
using namespace std;

struct node
{
    int data;
    node *next;
    node(int x): data(x) , next(NULL) {}
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

// to delete next node from linked list
node *removeNode(node *curr)
{
    node *temp = curr->next;
    curr->next = temp->next;
    delete temp;
    return curr;
}

// remove duplicates from a sorted list
node* removeDuplicates(node *head)
{
    if (head == NULL)
        return NULL;
    node *curr = head;
    while (curr != NULL && curr->next != NULL)
    {
        node *next = curr->next;
        if (curr->data == next->data)
            curr = removeNode(curr);
        else
            curr = next;
    }
    return head;
}

int main(int argc, char const *argv[])
{
    node *head = new node(10);
    head->next = new node(20);
    head->next->next = new node(20);
    head->next->next->next = new node(20);
    head->next->next->next->next = new node(30);
    head->next->next->next->next->next = new node(30);

    head = removeDuplicates(head);
    head->print();

    return 0;
}