// Insert after current middle
# include "bits/stdc++.h"
using namespace std;

struct node
{
    int data;
    node *next;
    node(int x) : data(x) , next(NULL) {}
};
void print(node *head) {
    node *curr = head;
    while (curr != NULL)
    {
        cout << curr->data << " ";
        curr = curr->next;
    }
}

node* insertMiddle(node *head , int x)
{
    node *slow = head , *fast = head;
    node *temp = new node(x);
    if (head == NULL)
        return temp;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    temp->next = slow->next;
    slow->next = temp;
    if(fast == NULL)
        swap(temp->data,slow->data);
    return head;
}

int main(int argc, char const *argv[])
{
    node *head = new node(10);
    head->next = new node(20);
    head->next->next = new node(40);

    head = insertMiddle(head , 30);
    print(head);

    return 0;
}
