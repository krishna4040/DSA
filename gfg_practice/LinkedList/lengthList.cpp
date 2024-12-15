# include "bits/stdc++.h"
using namespace std;

// Return length of list
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

int length(node *head)
{
    node *curr = head;
    int count = 0;
    while (curr != NULL)
    {
        count++;
        curr = curr->next;
    }
    return count;
}

int main(int argc, char const *argv[])
{
    node *head = new node(10);
    head->next = new node(20);
    head->next->next = new node(30);
    cout << length(head);
    return 0;
}