# include "bits/stdc++.h"
using namespace std;

struct node
{
    int data;
    node *next;
    node(int x) : data(x) , next(NULL) {}
};

// naive
int middle(node *head)
{
    int len = 0;
    node *curr = head;
    while (curr->next != NULL)
    {
        len++;
        curr = curr->next;
    }
    curr = head;
    int half = (len&1) ? len/2+1 : len/2;
    while (half)
    {
        half--;
        curr = curr->next;
    }
    return curr->data;
}

// Hare-tortoise
int Middle(node *head) 
{
    node *slow = head , *fast = head;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow->data;
}

int main(int argc, char const *argv[])
{
    node *head = new node(10);
    head->next = new node(20);
    head->next->next = new node(30);
    head->next->next->next = new node(40);

    cout << Middle(head);

    return 0;
}