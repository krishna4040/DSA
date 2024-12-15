# include "bits/stdc++.h"
using namespace std;

int oprBeautiful(vector<vector<int>> mat)
{
    int n = mat.size();
    int desieredSum = accumulate(mat[0].begin(),mat[0].end(),0);
    int totalOpr = 0;
    for (int i = 0; i < n; i++)
    {
        int rowSum = accumulate(mat[i].begin(),mat[i].end(),0);
        int colsum = 0;
        for (int j = 0; j < n; j++)
            colsum += mat[i][j];
        int rowDeviation = abs(desieredSum-rowSum);
        int colDeviation = abs(desieredSum-colsum);
        totalOpr += rowDeviation + colDeviation;
    }
    return totalOpr;
}

int main(int argc, char const *argv[])
{
    
    return 0;
}