# include "bits/stdc++.h"
using namespace std;

pair<int,int> linearSearch(vector<vector<int>> &mat , int x)
{
    for (int i = 0; i < mat.size(); i++)
        for (int j = 0; j < mat[0].size(); j++)
            if (mat[i][j] == x)
                return make_pair(i,j);
    return make_pair(-1,-1);
}

int main(int argc, char const *argv[])
{
    vector<vector<int>> v = {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };
    pair<int,int> p = linearSearch(v,4);
    if (p.first == -1)
        cout << "Not found!";
    else
        cout << p.first << " " << p.second;
    return 0;
}