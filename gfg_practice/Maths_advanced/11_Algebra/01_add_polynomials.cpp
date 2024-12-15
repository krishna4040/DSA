# include "bits/stdc++.h"
using namespace std;

vector<int> addPolynomail(int p1[] , int p2[] , int n , int m)
{
    vector<int> res;
    int i = 0 , j = 0;
    while (i != n && j != m)
    {
        res.push_back(p1[i] + p2[j]);
        i++;
        j++;
    }
    while (i != n)
    {
        res.push_back(p1[i]);
        i++;
    }
    while (j != m)
    {
        res.push_back(p2[j]);
        j++;
    }
    return res;
}

int main(int argc, char const *argv[])
{
    int p1[] = {1,2,3,4};
    int p2[] = {1,2,3};
    vector<int> v = addPolynomail(p1,p2,4,3);
    for (auto &&i : v)
    {
        cout << i << " ";
    }
    
    return 0;
}
