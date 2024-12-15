# include "bits/stdc++.h"
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int x){
        data = x;
        next = NULL;
    }
};

int main(int argc, char const *argv[])
{
    Node *head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    return 0;
}