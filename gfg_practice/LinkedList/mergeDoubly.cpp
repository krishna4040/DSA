// MergeSort doubly ll
# include "bits/stdc++.h"
using namespace std;

struct node
{
    int data;
    node *next;
    node(int x): data(x) , next(NULL) {}
};

node* middle(node *head)
{
    node *slow = head , *fast = head;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

void merge(node *l , node *m , node * h)
{
    int n1 , n2;
    node *curr = l;
    while (curr != m)
    {
        n1++;
        curr = curr->next;
    }
    while (curr != h)
    {
        n2++;
        curr = curr->next;
    }
}

node* mergeSort(node *l , node *r) 
{
    if (r->data > l->data)
    {
        node *m = middle(l);
        mergeSort(l,m);
        mergeSort(m->next,r);
        merge(l,m,r);
    }
}

int main(int argc, char const *argv[])
{
    
    return 0;
}
