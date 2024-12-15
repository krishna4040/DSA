# include "bits/stdc++.h"
using namespace std;

vector<int> NonRepeated(int *arr , int n)
{
    unordered_map<int,int> m;
    for (int i = 0; i < n; i++)
        m[arr[i]]++;

    vector<int> ans;

    // Mainting array order
    for (int i = 0; i < n; i++)
        if (m[arr[i]] == 1)
            ans.push_back(arr[i]);
    return ans;
}

int main(int argc, char const *argv[])
{
    
    return 0;
}