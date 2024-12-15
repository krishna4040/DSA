# include <iostream>
using namespace std;

struct node
{
    int data;
    node *next;
    node *prev;
    node(int x)
    {
        data = x;
        next = NULL;
        prev = NULL;
    }
};


int main(int argc, char const *argv[])
{
    node *head = new node(10);

    head->next = new node(20);
    head->next->prev = head;

    head->next->next = new node(30);
    head->next->next->prev = head->next;

    return 0;
}