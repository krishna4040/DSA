# include "bits/stdc++.h"
using namespace std;

struct node
{
    int data;
    node *next;
    node(int x): data(x) , next(NULL) {}
};

// Delete from beg
node* deleteBeg(node *head)
{
    if (head == NULL)
        return NULL;
    if (head->next == head)
    {
        delete head;
        return NULL;
    }
    swap(head->data , head->next->data);
    node *temp = head->next;
    head->next = head->next->next;
    delete temp;
    return head;
}

// Delete kth node
node* deleteKth(node *head , int k)
{
    // reach the node
    if (head == NULL)
        return NULL;
    node *curr = head;
    k--;
    while (k) {
        curr = curr->next;
        k--;
    }
    // theta 1 opr
    return deleteBeg(curr);
}

void printList(node *head)
{
    node *curr = head;
    do {
        cout << curr->data << " ";
        curr = curr = curr->next;
    } while (curr != head);
}

int main(int argc, char const *argv[])
{
    node *head = new node(10);
    head->next = new node(20);
    head->next->next = new node(30);
    head->next->next->next = head;
    head = deleteKth(head,3);
    printList(head);
    return 0;
}
