# include "bits/stdc++.h"
using namespace std;

struct node
{
    int data;
    node *next;
    node(int x): data(x) , next(NULL) {}
    void print(){
        node *curr = this;
        while (curr != NULL)
        {
            cout << curr->data << " ";
            curr = curr->next;
        }
    }
};

pair<node*,  node*> rev(node *head , int k)
{
    node *curr = head , *prev = NULL;
    int count = 0;
    while (curr != NULL && count < k)
    {
        node *next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        count++;
    }
    return make_pair(prev,curr);
}

node* revInGrps(node *head , int k , int n)
{
    node *curr = head;
    pair<node*,node*> pair = rev(curr,k);
    node *newHead = pair.first;
    node *temp = pair.second->next;
    pair.second->next = pair.first;
    n -= k;
    if (pair.second == NULL)
        return newHead;
    while (n > 0 && temp->next != NULL)
    {
        pair = rev(temp,k);
        if (pair.second == NULL)
            return pair.first;
        temp = pair.second->next;
        pair.second->next = pair.first;
        n -= k;
    }
    return newHead;
}

int main(int argc, char const *argv[])
{
    node *head = new node(10);
    head->next = new node(20);
    head->next->next = new node(30);
    head->next->next->next = new node(40);
    head->next->next->next->next = new node(50);
    head->next->next->next->next->next = new node(60);

    head = revInGrps(head,3,6);
    head->print();


    return 0;
}