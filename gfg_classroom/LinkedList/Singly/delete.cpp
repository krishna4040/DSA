# include "bits/stdc++.h"
using namespace std;

struct node
{
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

// Delete from beginning
node* deleteBeg(node *head)
{
    if (head == NULL)
        return head;
    else
    {
        node *temp = head->next;
        delete head;
        return temp;
    }
}

// Delete from End
node* deleteEnd(node *head)
{
    if (head == NULL)
        return head;
    if (head->next == NULL)
    {
        delete head;
        return NULL;
    }
    node *curr = head;
    while (curr->next->next != NULL)
        curr = curr->next;
    delete curr->next;
    curr->next = NULL;
    return head;
}

int main(int argc, char const *argv[])
{
    node *head = new node(10);
    head->next = new node(20);
    head->next->next = new node(30);
    head->next->next->next = new node(40);

    head = deleteEnd(head);

    head->print();

    return 0;
}