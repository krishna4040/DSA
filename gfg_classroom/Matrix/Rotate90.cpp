# include "bits/stdc++.h"
using namespace std;

void display(vector<vector<int>> &arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = 0; j < arr[i].size(); j++)
            cout << arr[i][j] << " ";
        cout << endl;
    }
}
vector<vector<int>> RotateACW(vector<vector<int>> &mat , int n)
{
    vector<vector<int>> ans(n,vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            ans[i][j] = mat[j][n-1-i];
    return ans;
}
void inplaceRotate(vector<vector<int>> &mat , int n)
{
    for (int i = 0; i < mat.size(); i++)
        for (int j = i; j < mat.size(); j++)
            swap(mat[i][j],mat[j][i]);
    for (int j = 0; j < n; j++)
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
    vector<vector<int>> mat = {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };
    vector<vector<int>> r = RotateACW(mat,3);
    display(r);

    return 0;
}