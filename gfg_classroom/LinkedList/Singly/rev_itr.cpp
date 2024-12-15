# include "bits/stdc++.h"
using namespace std;

struct node
{
    int data;
    node *next;
    node(int x) : data(x) , next(NULL) {}
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

// use an auxilary arr and play copy-paste game
node* rev(node *head)
{
    if (head == NULL || head->next == NULL)
        return head;
    node *prev = NULL , *curr = head;
    while (curr != NULL)
    {
        node *temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }
    return prev;
}

int main(int argc, char const *argv[])
{
    node *head = new node(10);
    head->next = new node(20);
    head->next->next = new node(30);

    head = rev(head);
    head->print();

    return 0;
}