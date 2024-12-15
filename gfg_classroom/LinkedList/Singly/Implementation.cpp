# include "bits/stdc++.h"
using namespace std;

template <class T>
class node
{
private:
    T data;
    node *next;
public:
    node(T x) : data(x) , next(NULL) {}

    node* push_front(T x)
    {
        node *temp = new node(x);
        if (this == NULL)
            return temp;
        temp->next = this;
        return temp;
    }

    node* push_back(T x)
    {
        node *temp = new node(x);
        if (this == NULL)
            return temp;
        node *curr = this;
        while (curr->next != NULL)
            curr = curr->next;
        curr->next = temp;
        return this;
    }

    node* insertPos(T x , int pos)
    {
        node *temp = new node(x);
        if (this == NULL)
            return temp;
        node *curr = this;
        if (pos == 1)
        {
            temp->next = this->next;
            this->next = temp;
            return this;
        }
        while (pos != 1 && curr != NULL)
        {
            curr = curr->next;
            pos--;
        }
        if (curr == NULL)
            return this;
        temp->next = curr->next;
        curr->next = temp;
        return this;
    }

    node* pop_front()
    {
        if (this == NULL)
            return this;
        node *curr = this->next;
        delete this;
        return curr;
    }

    node* pop_back()
    {
        if (this == NULL)
            return this;
        if (this->next == NULL)
        {
            delete this;
            return NULL;
        }
        node *curr = this;
        while (curr->next->next != NULL)
            curr = curr->next;
        delete curr->next;
        curr->next = NULL;
        return this;
    }

    int search(T x)
    {
        if (this == NULL)
            return -1;
        int pos = 0;
        node *curr = this;
        while (curr != NULL)
        {
            if (curr->data == x)
                return pos;
            pos++;
            curr = curr->next;
        }
        return -1;
    }

    void printList()
    {
        node *curr = this;
        while (curr != NULL)
        {
            cout << curr->data << " ";
            curr = curr->next;
        }
    }
};

int main(int argc, char const *argv[])
{
    node<int> *head = NULL;
    head = head->push_front(30);
    head = head->push_front(20);
    head = head->push_front(10);
    head = head->insertPos(40,3);
    head = head->push_back(50);
    head = head->pop_back();
    head = head->pop_front();

    cout << head->search(10) << endl;
    head->printList();

    node<char> *h2 = NULL;
    h2 = h2->push_front('c');
    h2->printList();

    return 0;
}