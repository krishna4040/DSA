# include <iostream>
# include <algorithm>
using namespace std;

bool ispair(int arr[] , int n , int x , int s)
{
    int i = s , j = n-1;
    while (i < j)
    {
        if (arr[i] + arr[j] == x)
            return 1;
        else if (arr[i] + arr[j] > x)
            j--;
        else
            i++;
    }
    return 0;
}

bool isTriplet(int arr[] , int n , int x)
{
    sort(arr,arr+n);
    for (int i = 0; i < n-2; i++)
        if (ispair(arr,n,x-arr[i],i+1))
            return 1;
    return 0;
}

int main(int argc, char const *argv[])
{
    int arr[] = {2,3,4,8,9,20,40};
    cout << isTriplet(arr,7,32);
    return 0;
}