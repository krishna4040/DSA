/*Given an array Arr of n integers arranged in a circular fashion. Your task is to find
the minimum absolute differencebetween adjacent elements.*/
# include <iostream>
# include <cmath>
using namespace std;

int minAdjDiff(int arr[], int n)
{
    int temp[n+1];
    for (int i = 0; i < n; i++)
    {
        temp[i] = arr[i];
    }
    temp[n] = arr[0];
    int diff[n];
    for (int i = 0; i < n; i++)
    {
        diff[i] = abs(temp[i]-temp[i+1]); 
    }
    int m = INT32_MAX;
    for (int i = 0; i < n; i++)
    {
        m = min(m,diff[i]);
    }
    return m;
}

int main(int argc, char const *argv[])
{
    
    return 0;
}