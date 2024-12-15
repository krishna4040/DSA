# include "bits/stdc++.h"
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int x): data(x) , next(NULL) {}
};


// Swap kth Node from beg and last of a singly ll
Node* swapKth(Node *head , int k , int len)
{
    int x = len-k+1;
    Node *start = head , *last = head;
    k--; x--;
    while (k) {
        start = start->next;
        k--;
    }
    while (x) {
        last = last->next;
        x--;
    }
    swap(last->data , start->data);
    return head;
}

void print(Node *head)
{
    Node *curr = head;
    while (curr != NULL)
    {
        cout << curr->data << " ";
        curr = curr->next;
    }
}


int main(int argc, char const *argv[])
{
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head = swapKth(head,1,4);
    print(head);
    return 0;
}