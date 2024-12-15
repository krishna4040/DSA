# include "bits/stdc++.h"
using namespace std;

// in an array return indx of first occurence of first repeating element
int firstRepeated(int *arr , int n)
{
    unordered_map<int,int> m;
    for (int i = 0; i < n; i++)
        m[arr[i]]++;

    for (int i = 0; i < n; i++)
        if (m.find(arr[i])->second > 1)
            return i;
    return -1;
}

int main(int argc, char const *argv[])
{
    
    return 0;
}
