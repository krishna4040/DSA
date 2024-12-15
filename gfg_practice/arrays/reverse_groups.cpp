/*Given an array arr[] of positive integers of size N. Reverse every sub-array group of size K.
Note: If at any instance, there are no more subarrays of size greater than or equal to K, then reverse the last subarray
(irrespective of its size). You shouldn't return any array, modify the given array in-place.*/

# include <vector>
# include <iostream>
using namespace std;

void reverse(int arr[] , int low , int high)
{
    while (low < high)
    {
        swap(arr[low] , arr[high]);
        low++;
        high--;
    }
}
void reverseGroup(int arr[] , int n , int k)
{
    int s = 0;
    int d = k;
    int t = n;
    while (t / k != 0)
    {
        reverse(arr,s,d-1);
        s += k;
        d += k;
        t -= k;
    }
    reverse(arr,s,n-1);
}

int main(int argc, char const *argv[])
{
    int arr[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19};
    reverseGroup(arr,19,5);
    for (int i = 0; i < 19; i++)
        cout << arr[i] << " ";

    return 0;
}
