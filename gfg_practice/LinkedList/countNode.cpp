# include "bits/stdc++.h"
using namespace std;

// Given a linked list of size N. The task is to complete the function countNodesinLoop() that checks whether a given Linked List contains a loop or not and if the loop is present then return the count of nodes in a loop or else return 0. C is the position of the node to which the last node is connected. If it is 0 then no loop.
struct node
{
    int data;
    node *next;
    node(int x){data = x; next = NULL;}
};

int getNoodeCount(node *head , int c)
{
    while (c)
    {
        head = head->next;
        c--;
    }
    int count = 0;
    while (head != NULL)
    {
        count++;
        head = head->next;
    }
    return count;
}


int main(int argc, char const *argv[])
{
    
    return 0;
}