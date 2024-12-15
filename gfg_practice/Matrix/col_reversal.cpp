# include "bits/stdc++.h"
using namespace std;

void reverseRow(vector<vector<int>> &mat)
{
    int n = mat.size() , m = mat[0].size();
    for (int j = 0; j < m; j++)
    {
        int l = 0 , h = n-1;
        while (l < h)
        {
            swap(mat[l][j],mat[h][j]);
            l++;
            h--;
        }
    }
}

int main(int argc, char const *argv[])
{
    
    return 0;
}