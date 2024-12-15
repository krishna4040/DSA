# include "bits/stdc++.h"
using namespace std;
/*Given an array of integers, sort the array according to frequency of elements. That is elements that have higher frequency come first.
If frequencies of two elements are same, then smaller number comes first.*/
unordered_map<int,int> m;
void countFrq(int *arr , int n)
{
    for (int i = 0; i < n; i++)
        m[arr[i]]++;
}
bool mycomp(int n1 , int n2) 
{
    if (m[n1] == m[n2])
        return n1 < n2;
    else
        return m[n1] > m[n2];
}
void sortArr(int *arr , int n)
{
    countFrq(arr,n);
    sort(arr , arr+n, mycomp);
}
int main(int argc, char const *argv[])
{
    int arr [] = {2,5,6,9,9,9,9,9,9,9,9,1,1,1,2,5,1,1};
    sortArr(arr,18);
    for (int i = 0; i < 18; i++)
        cout << arr[i] << " ";
    return 0;
}