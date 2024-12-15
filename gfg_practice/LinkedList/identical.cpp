# include "bits/stdc++.h"
using namespace std;

// Given two ll of size m , n respectively check if they are equal

struct node
{
    int data;
    node *next;
    node(int x) : data(x) , next(NULL) {}
};

bool areIdentical(node *h1 , node *h2)
{
    if(h1 == NULL && h2 == NULL)
        return 1;
    if(h1 == NULL || h2 == NULL)
        return 0;
    node *c1 = h1 , *c2 = h2;
    while (c1 != NULL && c2 != NULL)
    {
        if (c1->data != c2->data)
            return 0;
        c1 = c1->next;
        c2 = c2->next;
    }
    if(c1 == c2)
        return 1;
    return 0;
}

int main(int argc, char const *argv[])
{
    
    return 0;
}