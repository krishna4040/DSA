// /sort list of 0s 1s and 2s
# include "bits/stdc++.h"
using namespace std;

struct node
{
    int data;
    node *next;
    node(int x): data(x) , next(NULL) {}
};

void printList(node *head)
{
    node *curr = head;
    while (curr != nullptr)
    {
        cout << curr->data << " ";
        curr = curr->next;
    }
}

node* dnfSort(node *head) 
{
    node *temp = head;
    int c0 = 0 , c1 = 0 , c2 = 0;
    while (temp != NULL)
    {
        if (temp->data == 0)
            c0++;
        else if (temp->data == 1)
            c1++;
        else
            c2++;
        temp = temp->next;
    }
    temp = head;
    while (c0){temp->data = 0;c0--;temp=temp->next;}
    while (c1){temp->data = 1;c1--;temp=temp->next;}
    while (c2){temp->data = 2;c2--;temp=temp->next;}
    return head;
}

int main(int argc, char const *argv[])
{
    node *head = new node(1);
    head->next = new node(2);
    head->next->next = new node(0);

    head = dnfSort(head);
    printList(head);


    return 0;
}