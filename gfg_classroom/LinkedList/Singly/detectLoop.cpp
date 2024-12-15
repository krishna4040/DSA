#include "bits/stdc++.h"
using namespace std;

struct node
{
    int data;
    node *next;
    bool visited;
    node(int x) : data(x), next(NULL), visited(0) {}
};

bool detectLoop(node *head)
{
    if (head == NULL)
        return 0;
    node *curr = head;
    while (curr->next != NULL && curr->next->visited != 1)
    {
        curr->visited = 1;
        curr = curr->next;
    }
    if (curr == NULL || curr->next == NULL)
        return false;
    else
        return true;
}

bool detectLoopM3(node *head)
{
    if (head == NULL)
        return 0;
    node *temp = new node(1);
    node *curr = head;
    while (curr->next != temp && curr->next != NULL)
    {
        node *next = curr->next;
        curr->next = temp;
        curr = next;
    }
    if (curr->next == temp)
        return 1;
    else
        return 0;
}

bool hashMethod(node *head)
{
    unordered_set<node *> s;
    for (node *curr = head; curr != NULL; curr = curr->next)
    {
        if (s.find(curr) != s.end())
            return 1;
        s.insert(curr);
    }
    return 0;
}

bool floyds(node *head)
{
    node *fast = head, *slow = head;
    while (fast->next != NULL || fast != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (fast == slow)
            return 1;
    }
    return 0;
}

// Remove loop
void flyodsExtension(node *head)
{
    node *slow = head, *fast = head;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
            break;
    }
    if (slow != fast)
        return;
    slow = head;
    while (slow->next != fast->next)
    {
        slow = slow->next;
        fast = fast->next;
    }
    fast->next = NULL;
}

int main(int argc, char const *argv[])
{
    node *head = new node(10);
    head->next = new node(20);
    head->next->next = new node(30);

    cout << hashMethod(head);

    return 0;
}
