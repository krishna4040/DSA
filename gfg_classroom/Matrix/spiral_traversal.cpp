# include "bits/stdc++.h"
using namespace std;

vector<int> spiralTraversal(vector<vector<int>> &mat)
{
    vector<int> ans;
    int n = mat.size() , m = mat[0].size();

    int top = 0 , bottom = n-1 , left = 0 , right = m-1;
    while (top <= bottom && left <= right)
    {
        for (int j = left; j <= right; j++)
            ans.push_back(mat[top][j]);
        top++;

        for (int i = top; i <= bottom; i++)
            ans.push_back(mat[i][right]);
        right--;

        if (top <= bottom)
        {
            for (int j = right; j >= left; j--)
                ans.push_back(mat[bottom][j]);
            bottom--;
        }

        if (left <= right)
        {
            for (int i = bottom; i >= top; i--)
                ans.push_back(mat[i][left]);
            left++;
        }
    }
    return ans;
}

int main(int argc, char const *argv[])
{
    
    return 0;
}