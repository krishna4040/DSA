# include "bits/stdc++.h"
using namespace std;

void reverseRow(vector<vector<int>> &mat)
{
    int n = mat.size() , m = mat[0].size();
    for (int i = 0; i < n; i++)
    {
        int l = 0 , h = m-1;
        while (l < h)
        {
            swap(mat[i][l],mat[i][h]);
            l++;
            h--;
        }
    }
}

int main(int argc, char const *argv[])
{
    
    return 0;
}