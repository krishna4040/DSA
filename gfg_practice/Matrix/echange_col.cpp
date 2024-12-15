# include "bits/stdc++.h"
using namespace std;

//You are given a matrix of dimensions (n1 x m1). You have to exchange its first column with the last column.

void exchangeCol(vector<vector<int>> &mat)
{
    int n = mat.size() , m = mat[0].size();
    for (int i = 0; i < n; i++)
        swap(mat[i][0] , mat[i][m-1]);
}

int main(int argc, char const *argv[])
{
    
    return 0;
}