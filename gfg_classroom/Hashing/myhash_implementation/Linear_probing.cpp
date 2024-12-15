# include "bits/stdc++.h"
using namespace std;

class myhash
{
private:
    int size , cap;
    int *arr;
    int hash(int key) {return key % cap;}
public:
    myhash(int c);
    bool insert(int key);
    bool remove(int key);
    bool search(int key);
};
myhash :: myhash(int c)
{
    cap = c;
    size = 0;
    for (int i = 0; i < cap; i++)
        arr[i] = -1;
}
bool myhash :: insert(int key)
{
    int i = hash(key);
    while (arr[i] != -1 && arr[i] != -2 && arr[i] != key)
        i = (i + 1) % cap;
    if (arr[i] == key)
        return false;
    else
    {
        arr[i] = key;
        size++;
        return true;
    }
}
bool myhash :: remove(int key)
{
    int h = hash(key);
    int i = h;
    while (arr[i] != -1)
    {
        if (arr[i] == key)
        {
            arr[i] = -2;
            size--;
            return true;
        }
        i = (i+1) % cap;
        if (i == h)
            return false;
    }
    return false;
}
bool myhash :: search(int key)
{
    int h = hash(key);
    int i = h;
    while (arr[i] != -1)
    {
        if (arr[i] == key)
            return true;
        i = (i+1) % cap;
        if (i == h)
            return false;
    }
    return false;
}


int main(int argc, char const *argv[])
{
    myhash h(11);
    for (int i = 10000; i < 10011; i++)
        h.insert(i);
    cout << h.search(10000);
    return 0;
}