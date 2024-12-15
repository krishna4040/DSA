# include "bits/stdc++.h"
using namespace std;

vector<int>merge(vector<int>&A , vector<int>&B , vector<int>&C)
{
    int n = A.size();
    int m = B.size();
    int p = C.size();
    vector<int> ans;
    int i = 0 , j = 0 , k = 0;
    int minimum = INT_MAX;
    while (i < n && j < m && k < p)
    {
        minimum = min(A[i],min(B[j],C[k]));
        if (minimum == A[i])
        {
            ans.push_back(minimum);
            i++;
        }
        else if (minimum == B[j])
        {
            ans.push_back(minimum);
            j++;
        }
        else
        {
            ans.push_back(minimum);
            k++;
        }
    }
    while (i < n && j < m)
    {
        if (A[i] <= B[j])
        {
            ans.push_back(A[i]);
            i++;
        }
        else
        {
            ans.push_back(B[j]);
            j++;
        }
    }
    while (j < m && k < p)
    {
        if (B[j] < C[k])
        {
            ans.push_back(B[j]);
            j++;
        }
        else
        {
            ans.push_back(C[k]);
            k++;
        }
    }
    while (k < p && i < n)
    {
        if (A[i] < C[k])
        {
            ans.push_back(A[i]);
            i++;
        }
        else
        {
            ans.push_back(C[k]);
            k++;
        }
    }
    while (i < n)
    {
        ans.push_back(A[i]);
        i++;
    }
    while (j < m)
    {
        ans.push_back(B[j]);
        j++;
    }
    while (k < p)
    {
        ans.push_back(C[k]);
        k++;
    }
    return ans;
}

int main(int argc, char const *argv[])
{
    
    return 0;
}