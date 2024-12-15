# include "bits/stdc++.h"
using namespace std;

struct node{
    int data;
    node *next;
    node *prev;
    node(int x): data(x) , next(NULL) , prev(NULL) {}
    void print(){
        node *curr = this;
        while (curr != NULL)
        {
            cout << curr->data << " ";
            curr = curr->next;
        }
    }
};

// Delete from begin
node* deleteBeg(node *head)
{
    if (head == NULL)
        return NULL;
    if (head->next == NULL)
    {
        delete head;
        return NULL;
    }
    node *curr = head->next;
    delete head;
    return curr;
}

// Delete from last
node* deleteLast(node *head)
{
    if (head == NULL)
        return NULL;
    if (head->next == NULL)
    {
        delete head;
        return NULL;
    }
    node *curr = head;
    while (curr->next != NULL)
        curr = curr->next;
    curr->prev->next = NULL;
    delete curr;
    return head;
}

int main(int argc, char const *argv[])
{
    node *head = new node(10);

    head->next = new node(20);
    head->next->prev = head;

    head->next->next = new node(30);
    head->next->next->prev = head->next;

    head = deleteBeg(head);
    head->print();
    
    head = deleteLast(head);
    head->print();

    return 0;
}