# include "bits/stdc++.h"
using namespace std;

void display(vector<vector<int>> &arr)
{
    for (int i = 0; i < arr.size(); i++)
        for (int j = 0; j < arr[i].size(); j++)
            cout << arr[i][j] << " ";
}
vector<int> BoundryTraversal(vector<vector<int>> &mat)
{
    vector<int> ans;
    int n = mat.size(); // rows
    int m = mat[0].size(); // columns

    if (n == 1) 
    {
        for (int j = 0; j < m; j++)
            ans.push_back(mat[0][j]);
        return ans;
    }
    else if (m == 1)
    {
        for (int i = n - 1; i >= 0; i--)
            ans.push_back(mat[i][0]);
        return ans;
    }
    // first row = 0 fix
    for (int j = 0; j < m; j++)
        ans.push_back(mat[0][j]);

    // last column = mat[0].size()-1 fix
    for (int i = 1; i < mat.size(); i++)
        ans.push_back(mat[i][m-1]);

    // last row = mat.size()-1 fix
    for (int j = mat[0].size() - 2; j >= 0; j--)
        ans.push_back(mat[n-1][j]);

    // first column = 0 fix
    for (int i = mat.size() - 2; i > 0; i--)
        ans.push_back(mat[i][0]);

    return ans;
}

int main(int argc, char const *argv[])
{
    vector<vector<int>> v = {
        {1,2,3,6}
    };
    vector<int> bonudry = BoundryTraversal(v);
    for (auto &&i : bonudry)
        cout << i << " ";
    return 0;
}