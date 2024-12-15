# include "bits/stdc++.h"
using namespace std;

struct node
{
    int data;
    node *next;
    node(int x): data(x) , next(NULL) {}
    void print() 
    {
        node *curr = this;
        while (curr != NULL)
        {
            cout << curr->data << " ";
            curr = curr->next;
        }
    }
};

// method1
node* rev(node *head) 
{
    if (head == NULL || head->next == NULL)
        return head;
    node *res_head = rev(head->next);
    node *res_tail = head->next;
    res_tail->next = head;
    head->next = NULL;
    return res_head;
}

// method2
node* revback(node *curr , node *prev = NULL)
{
    if (curr == NULL)
        return prev;
    node *next = curr->next;
    curr->next = prev;
    return revback(next,curr);
}

int main(int argc, char const *argv[])
{
    node *head = new node(10);
    head->next = new node(20);
    head->next->next = new node(30);

    head = revback(head);
    head->print();

    return 0;
}