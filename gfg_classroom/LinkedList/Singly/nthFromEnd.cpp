# include "bits/stdc++.h"
using namespace std;

struct node
{
    int data;
    node *next;
    node(int x): data(x) , next(NULL) {}
};

int nthFromEnd(node *head , int n)
{
    node *first = head;
    for (int i = 0; i < n; i++)
    {
        if (first == NULL)
            return;
        first = first->next;
    }
    node *second = head;
    while (first != NULL)
    {
        first = first->next;
        second = second->next;
    }
    return second->data;
}

int main(int argc, char const *argv[])
{
    node *head = new node(10);
    head->next = new node(20);
    head->next->next = new node(30);
    head->next->next->next = new node(40);
    head->next->next->next->next = new node(50);

    cout << nthFromEnd(head,2);

    return 0;
}