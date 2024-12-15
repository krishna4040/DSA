# include "bits/stdc++.h"
using namespace std;

struct node
{
    int data;
    node *next , *prev;
    node(int x): data(x) , next(NULL) , prev(NULL) {}
};

node* insertBeg(node *head , int x , char pos='s')
{
    node *temp = new node(x);
    if (head == NULL)
    {
        temp->next = temp;
        temp->prev = temp;
        return temp;
    }
    temp->next = head;
    temp->prev = head->prev;
    head->prev->next = temp;
    head->prev = temp;
    return (pos == 'e') ? head : temp;
}

int main(int argc, char const *argv[])
{
    
    return 0;
}