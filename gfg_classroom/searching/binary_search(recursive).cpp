# include <iostream>
using namespace std;

int bsearch(int arr[] , int low , int high , int x)
{
    if (low > high)
        return -1;
    int mid = (low+high)/2;
    if (arr[mid] == x)
        return mid;
    else if (arr[mid] > x)
        bsearch(arr,low,mid-1,x);
    else
        bsearch(arr,mid+1,high,x);
    return -1;
}

int main(int argc, char const *argv[])
{
    
    return 0;
}
