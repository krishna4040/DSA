# include "bits/stdc++.h"
using namespace std;

// Moores voting algorithm
int morethannBYk(int *arr , int n , int k)
{
    float div = (float)n / (float)k;
    unordered_map<int,int> m;
    for (int i = 0; i < n; i++)
        m[arr[i]]++;

    for (int i = 0; i < n; i++)
        if (m[arr[i]] > div)
            cout << arr[i] << " ";
}

int main(int argc, char const *argv[])
{
    
    return 0;
}