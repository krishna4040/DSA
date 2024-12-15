/*Given an array of distinct elements which was initially sorted. This array may be rotated at some unknown point. 
The task is to find the minimum element in the given sorted and rotated array. */
# include <iostream>
using namespace std;

int minElement(int arr[] , int n)
{
    int minimum = INT32_MAX;
    int l = 0 , h = n-1;
    while (l <= h)
    {
        int m = (l+h)/2;
        if (arr[m] > arr[l])
        {
            // left half is sorted
            minimum = arr[l];
            l = m + 1;
        }
        else
        {
            minimum = arr[m+1];
            h = m - 1;
        }
    }
    return minimum;
}

int main(int argc, char const *argv[])
{
    
    return 0;
}
