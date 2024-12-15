# include "bits/stdc++.h"
using namespace std;

vector<int> snakepattern(vector<vector<int>> mat)
{
    vector<int> ans;
    for (int i = 0; i < mat.size(); i++)
    {
        if (i % 2 == 0)
            for (int j = 0; j < mat[i].size(); j++)
                ans.push_back(mat[i][j]);
        else
            for (int j = mat[i].size() - 1; j >= 0; j--)
                ans.push_back(mat[i][j]);
    }
    return ans;
}

int main(int argc, char const *argv[])
{
    
    return 0;
}