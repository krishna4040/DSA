#include "bits/stdc++.h"
using namespace std;

struct node
{
    int data;
    node *next;
    node(int d) : data(d), next(NULL) {}
};

// Hashing method
int getIntersection(node *h1, node *h2)
{
    node *c1 = h1, *c2 = h2;
    unordered_set<node *> s;
    while (c1 != NULL)
    {
        s.insert(c1);
        c1 = c1->next;
    }
    while (c2 != NULL)
    {
        if (s.find(c2) != s.end())
            return c2->data;
        s.insert(c2);
        c2 = c2->next;
    }
    return -1;
}

// Efficient method
int getIntersectionPoint(node *h1, node *h2)
{
    int c1 = 0, c2 = 0;
    for (node *curr = h1; curr != NULL; curr = curr->next)
        c1++;
    for (node *curr = h2; curr != NULL; curr = curr->next)
        c2++;
    int d = abs(c1 - c2);
    node *curr1 = h1, *curr2 = h2;
    if (c1 > c2)
        while (d--)
            curr1 = curr1->next;
    else
        while (d--)
            curr2 = curr2->next;
    while (curr1 != NULL && curr2 != NULL)
    {
        curr1 = curr1->next;
        curr2 = curr2->next;
        if (curr1 == curr2)
            return curr1->data;
    }
    return -1;
}

int main(int argc, char const *argv[])
{
    node *head = new node(5);
    head->next = new node(8);
    head->next->next = new node(7);
    head->next->next->next = new node(10);
    head->next->next->next->next = new node(12);
    head->next->next->next->next->next = new node(15);

    node *start = new node(9);
    start->next = head->next->next->next;

    cout << getIntersectionPoint(head, start);

    return 0;
}