# include "bits/stdc++.h"
# include <unordered_set>
using namespace std;
/*Given two integer arrays A1[ ] and A2[ ] of size N and M respectively. Sort the first array A1[ ] 
such that all the relative positions of the elements in the first array are the same as the elements in the second array A2[ ].*/

vector<int> v;
void setvec(int *arr , int n)
{
    for (int i = 0; i < n; i++)
        v.push_back(arr[i]);
}
bool mycomp(int n1 , int n2)
{
    int x , y;
    for (int i = 0; i < v.size(); i++)
    {
        if (n1 == v[i])
            x = i;
        if (n2 == v[i])
            y = i;
    }
    return x < y;
}

void sortAbyB(int A[] , int n , int B[] , int m)
{
    setvec(B,m);
    sort(A,A+n,mycomp);
}

int main(int argc, char const *argv[])
{
    int A[] = {2, 1, 2, 5, 7, 1, 9, 3, 6, 8, 8};
    int B[] = {2, 1, 8, 3};
    sortAbyB(A,11,B,4);
    for (int i = 0; i < 11; i++)
        cout << A[i] << " ";
    
    return 0;
}