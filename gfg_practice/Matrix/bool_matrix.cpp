# include "bits/stdc++.h"
using namespace std;

void modifyboolean(vector<vector<int>> &mat)
{
    int n = mat.size() , m = mat[0].size();
    vector<vector<int>> temp(n,vector<int>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (mat[i][j])
                temp[i][j] = true;

    for (int i = 0; i < n; i++)
    {
        int r , c;
        for (int j = i; j < m; j++)
        {
            if (temp[i][j])
            {
                r = i;
                c = j;
            }
        }
        for (int k = 0; k < n; k++)
            mat[k][c] = 1;
        for (int k = 0; k < m; k++)
            mat[r][k] = 1;
    }
}

int main(int argc, char const *argv[])
{
    vector<vector<int>> v = {
        {1,0,0,0},
        {0,0,1,1},
        {0,0,0,0},
        {1,1,0,0}
    };
    modifyboolean(v);
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 4; j++)
            cout << v[i][j];

    return 0;
}