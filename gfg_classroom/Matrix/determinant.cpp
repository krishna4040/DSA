# include "bits/stdc++.h"
using namespace std;

void getcofactor(vector<vector<int>> mat , vector<vector<int>> &temp , int discarded_row , int discarded_col , int n)
{
    int i = 0 , j = 0;
    for (int r = 0; r < n; r++)
    {
        for (int c = 0; c < n; c++)
        {
            if (r != discarded_row && c != discarded_col)
            {
                temp[i][j] = mat[r][c];
                j++;
                if (j == n-1){j = 0;i++;}
            }
        }
    }
}

int determinant(vector<vector<int>> mat , int n)
{
    int d = 0;
    if (n == 1)
        return mat[0][0];
    vector<vector<int>> temp(n,vector<int>(n));
    int sign = 1;
    for (int j = 0; j < n; j++)
    {
        getcofactor(mat,temp,0,j,n);
        d += sign * mat[0][j] * determinant(temp,n-1);
        sign *= -1;
    }
    return d;
}

int main(int argc, char const *argv[])
{
    vector<vector<int>> v = {
        {1,-2,3},
        {2,0,3},
        {1,5,4}
    };
    cout << determinant(v,3);
    return 0;
}