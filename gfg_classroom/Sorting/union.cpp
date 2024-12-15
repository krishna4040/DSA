# include "bits/stdc++.h"
using namespace std;

void arr_union(int a[] , int b[] , int n , int m)
{
    vector<int> res;
    int i = 0 , j = 0;
    while (i < n && j < m)
    {
        if (a[i] <= b[j])
        {
            res.push_back(a[i]);
            i++;
        }
        else
        {
            res.push_back(b[j]);
            j++;
        }
    }
    while (i < n)
    {
        res.push_back(a[i]);
        i++;
    }
    while (j < m)
    {
        res.push_back(b[j]);
        j++;
    }
    cout << res[0] << " ";
    for (int i = 1; i < res.size(); i++)
    {
        if (res[i] == res[i-1])
            continue;
        cout << res[i] << " ";
    }
}

int main(int argc, char const *argv[])
{
    int a[] = {1,1,1,1};
    int b[] = {2,2,2,2};
    arr_union(a,b,4,4);
    return 0;
}