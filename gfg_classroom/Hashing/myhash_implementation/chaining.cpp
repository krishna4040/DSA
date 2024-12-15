# include "bits/stdc++.h"
using namespace std;

class myhash
{
private:
    int bucket;
    list<int> *table;
    int h(int key) {return key % bucket;}
public:
    myhash(int b) : bucket(b) {table = new list<int> [b];}
    void insert(int key)
    {
        int i = h(key);
        table[i].push_back(key);
    }
    void remove(int key)
    {
        int i = h(key);
        table[i].remove(key);
    }
    bool search(int key)
    {
        int i = h(key);
        for (auto &&x : table[i])
            if (x == key)
                return 1;
        return 0;
    }
};

int main(int argc, char const *argv[])
{
    myhash h(7);
    for (int i = 50; i <= 100; i++)
        h.insert(i);

    return 0;
}