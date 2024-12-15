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
vector<vector<int>> Add(vector<vector<int>> &A , vector<vector<int>> &B)
{
    int n = A.size() , m = A[0].size();
    int p = B.size() , q = B[0].size();
    vector<vector<int>> ans(n,vector<int>(m));
    if (n != p || m != q)
        return ans;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            ans[i][j] = A[i][j] + B[i][j];
    return ans;
}
vector<vector<int>> Sub(vector<vector<int>> &A , vector<vector<int>> &B)
{
    int n = A.size() , m = A[0].size();
    int p = B.size() , q = B[0].size();
    vector<vector<int>> ans(n,vector<int>(m));
    if (n != p || m != q)
        return ans;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            ans[i][j] = A[i][j] - B[i][j];
    return ans;
}
vector<vector<int>> MatrixMultiply(vector<vector<int>> &A , vector<vector<int>> &B)
{
    int n = A.size() , m = A[0].size();
    int p = B.size() , q = B[0].size();
    vector<vector<int>> ans(n,vector<int>(q,0));
    if (m != p)
        return ans;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < q; j++)
            for (int k = 0; k < m; k++)
                ans[i][j] += A[i][k] * B[k][j];
    return ans;
}
vector<vector<int>> ScalerMultiply(vector<vector<int>> &A , int k)
{
    vector<vector<int>> ans(A.size(),vector<int>(A[0].size()));
    for (int i = 0; i < A.size(); i++)
        for (int j = 0; j < A[i].size(); j++)
            ans[i][j] = A[i][j] * k;
    return ans;
}
vector<vector<int>> Transpose(vector<vector<int>> &A)
{
    int n = A.size() , m = A[0].size();
    vector<vector<int>> ans(m,vector<int>(n));
    if (n != m)
        return ans;
    for (int i = 0; i < A.size(); i++)
        for (int j = 0; j < A[i].size(); j++)
            ans[i][j] = A[j][i];
    return ans;
}
void ModifiedTranspose(vector<vector<int>> &mat)
{
    for (int i = 0; i < mat.size(); i++)
        for (int j = i; j < mat[i].size(); j++)
            swap(mat[i][j],mat[j][i]);
}

int main(int argc, char const *argv[])
{
    vector<vector<int>> A = {
        {1,2,3},
        {4,5,6}
    };
    vector<vector<int>> B = {
        {1,2},
        {3,4},
        {5,6}
    };
    vector<vector<int>> ans = MatrixMultiply(A,B);
    display(ans);

    return 0;
}