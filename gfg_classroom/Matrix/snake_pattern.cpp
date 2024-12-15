# include "bits/stdc++.h"
using namespace std;

void display(vector<vector<int>> &arr)
{
    for (int i = 0; i < arr.size(); i++)
        for (int j = 0; j < arr[i].size(); j++)
            cout << arr[i][j] << " ";
}

vector<vector<int>> snakeTraversal(vector<vector<int>>& mat)
{
    vector<vector<int>> ans(mat.size(), vector<int>(mat[0].size()));

    for (int i = 0; i < mat.size(); i++)
    {
        if (i % 2 == 0) // row is even ==> elements are copied l to r
            for (int j = 0; j < mat[i].size(); j++)
                ans[i][j] = mat[i][j];
        else            // row is odd ==> elements are copied r to l
            for (int j = mat[i].size() - 1; j >= 0; j--)
                ans[i][mat[i].size()-1 - j] = mat[i][j];
    }
    return ans;
}


int main(int argc, char const *argv[])
{
    vector<vector<int>> v = {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };
    vector<vector<int>> snake = snakeTraversal(v);
    display(snake);
    return 0;
}