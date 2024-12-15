# include "bits/stdc++.h"
using namespace std;

// Delete duplicate nodes from sorted LL

struct node
{
    int data;
    node *next;
    node(int x) : data(x) , next(NULL) {}
};

node* removeDuplicate(node *head)
{
    node *curr = head;
    while (curr->next != NULL)
    {
        while (curr == curr->next)
        {
            node *temp = curr->next;
            curr->next = curr->next->next;
            delete temp;
            curr = curr->next;
        }
        curr = curr->next;
    }
    return head;
}

void print(node *head)
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
    head->next->next->next = new node(30);
    head->next->next->next->next = new node(30);
    head->next->next->next->next->next = new node(30);
    head = removeDuplicate(head);
    print(head);

    return 0;
}
