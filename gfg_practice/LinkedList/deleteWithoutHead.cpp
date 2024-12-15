#include "bits/stdc++.h"
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int x): data(x) , next(NULL) {}
};


// You are given a pointer/ reference to the node which is to be deleted from the linked list of N nodes. The task is to delete the node. Pointer/ reference to head node is not given.

void deleteNode(Node *del)
{
    swap(del->data, del->next->data);
    Node *temp = del->next;
    del->next = del->next->next;
    delete temp;
}

int main(int argc, char const *argv[])
{

    return 0;
}
