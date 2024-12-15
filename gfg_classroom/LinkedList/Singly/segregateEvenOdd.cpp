#include "bits/stdc++.h"
using namespace std;

struct node
{
    int data;
    node *next;
    node(int x) : data(x), next(NULL) {}
};

node *evenOdd(node *head)
{
    node *es = NULL, *ee = NULL;
    node *os = NULL, *oe = NULL;

    node *curr = head;
    while (curr != NULL && curr->next != NULL)
    {
        if (curr->data & 1)
        {
            if (os == NULL)
            {
                os = curr;
                oe = curr;
            }
            else
            {
                oe->next = curr;
                oe = oe->next;
            }
        }
        else
        {
            if (es == NULL)
            {
                es = curr;
                ee = curr;
            }
            else
            {
                ee->next = curr;
                ee = ee->next;
            }
        }
        curr = curr->next;
    }
    if (os == NULL || es == NULL)
        return head;
    ee->next = os;
    oe->next = NULL;
    return es;
}

int main(int argc, char const *argv[])
{
    node *head = new node(1);
    head->next = new node(2);
    head->next->next = new node(3);
    head->next->next->next = new node(4);
    head->next->next->next->next = new node(5);

    head = evenOdd(head);
    node *curr = head;
    while (curr != NULL)
    {
        cout << curr->data << " ";
        curr = curr->next;
    }

    return 0;
}