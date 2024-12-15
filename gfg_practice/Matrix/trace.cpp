# include "bits/stdc++.h"
using namespace std;

int trace(vector<vector<int>> mat , int n)
{
    int t = 0;
    for (int i = 0; i < n; i++)
        t += mat[i][i];
    return t;
}

int main(int argc, char const *argv[])
{
    
    return 0;
}