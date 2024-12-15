# include "bits/stdc++.h"
using namespace std;

struct node
{
    int data;
    node *next;
    node(int x){data = x; next = NULL;}
};

// Iterative
int search(node *head , int x)
{
    int count = 0;
    while (head != NULL)
    {
        if (head->data == x)
            return count;
        count++;
        head = head->next;
    }
    return -1;
}

// Recursive
bool isPresent(node *head , int x)
{
    if (head == NULL)
        return 0;
    if (head->data == x)
        return 1;
    return isPresent(head->next , x);
}

int main(int argc, char const *argv[])
{
    node *head = new node(10);
    head->next = new node(20);
    head->next->next = new node(30);
    head->next->next->next = new node(40);

    cout << search(head,10) << endl;
    cout << search(head,50) << endl;
    cout << isPresent(head,20) << endl;
    cout << isPresent(head,5);

    return 0;
}