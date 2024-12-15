# include "bits/stdc++.h"
using namespace std;

bool satisfy(int n)
{
    while (n)
    {
        int lsd = n % 10;
        n /= 10;
        if (lsd == 1 || lsd == 2 || lsd == 3)
            return 1;
    }
    return 0;
}

void findall()
{
    unordered_map<int,int> m;
    for (int i = 1; i <= 1000000; i++)
        m.insert({i,satisfy(i)});
}

int main(int argc, char const *argv[])
{
    
    return 0;
}