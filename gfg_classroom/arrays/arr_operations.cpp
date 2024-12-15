# include <iostream>
using namespace std;

int search(int arr[] , int n , int x)
{
    for (int i = 0; i < n; i++)
        if (arr[i] == x)
            return i;
    return -1;
}
int insert(int arr[] , int n , int x , int cap , int pos)
{
    if (n == cap)
        return n;
    int idx = pos - 1;
    for (int i = n-1; i >= idx; i--)
        arr[i+1] = arr[i];
    arr[idx] = x;
    return n+1;
}
int del(int arr[] , int n , int x)
{
    int i;
    for (i = 0; i < n; i++)
        if (arr[i] == x)
            break;
    if (i == n)
        return n;
    for (int j = 0; j < n-1; j++)
        arr[j] = arr[j+1];
    return n-1;
}

int main(int argc, char const *argv[])
{
    
    return 0;
}
