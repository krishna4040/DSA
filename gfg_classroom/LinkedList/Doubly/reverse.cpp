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

node* rev(node *head)
{
    if (head == NULL || head->next == NULL)
        return head;
    node* curr = head;
    node* temp = NULL;
    while (curr != NULL)
    {
        temp = curr->prev;
        curr->prev = curr->next;
        curr->next = temp;
        curr = curr->prev;
    }
    return temp->prev;
}

int main(int argc, char const *argv[])
{
    node *head = new node(10);
    head->next = new node(20);
    head->next->prev = head;
    head->next->next = new node(30);
    head->next->next->prev = head->next;
    return 0;
}