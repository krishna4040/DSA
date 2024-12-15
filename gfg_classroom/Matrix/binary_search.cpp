// Row-wise and column-wise sorted matrix
# include "bits/stdc++.h"
using namespace std;

// TC: O(n)
pair<int,int> BinarySearch(vector<vector<int>> &mat , int x)
{
    int n = mat.size();
    int top = 0 , right = n-1;
    while (top < n && right >= 0)
    {
        if (mat[top][right] == x)
            return make_pair(top,right);
        else if (x > mat[top][right])
            top++;
        else
            right--;
    }
    return make_pair(-1,-1);
}


int main(int argc, char const *argv[])
{
    vector<vector<int>> v = {
        {1,2,3},
        {4,5,6},
        {7,8,9}
    };
    pair<int,int> p = BinarySearch(v,4);
    if (p.first == -1)
        cout << "Not found!";
    else
        cout << p.first << " " << p.second;
    return 0;
}