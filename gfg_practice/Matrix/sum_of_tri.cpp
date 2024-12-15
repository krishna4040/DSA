# include "bits/stdc++.h"
using namespace std;

vector<int> triangleSum(vector<vector<int>> mat , int n)
{
    vector<int> res;
    int upperSum = 0 , lowerSum = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i >= j)
                lowerSum += mat[i][j];
            if (j >= i)
                upperSum += mat[i][j];
        }
    }
    res.push_back(upperSum);
    res.push_back(lowerSum);
    return res;
}

int main(int argc, char const *argv[])
{
    
    return 0;
}