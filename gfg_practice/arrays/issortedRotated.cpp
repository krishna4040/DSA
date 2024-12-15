/*Given an array arr[] of N distinct integers, check if this array is Sorted (non-increasing or non-decreasing) 
and Rotated counter-clockwise. Note that input array may be sorted in either increasing or decreasing order, then rotated.
A sorted array is not considered as sorted and rotated, i.e., there should be at least one rotation.*/

//* approach: find pivot point (idx of min element) and check if elements are inc or dec upto and after pivot point
// * also ensure that pivot point must not be 0 too be left rotated

# include <iostream>
using namespace std;

int find_pivot(int arr[], int n) {
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] > arr[(mid + 1) % n])
            return (mid + 1) % n;
        else if (arr[mid] >= arr[low])
            low = mid + 1;
        else
            high = mid - 1;
    }
    return 0;
}

bool is_sorted_and_rotated(int arr[], int n) {
    int pivot = find_pivot(arr, n);
    if (pivot == 0)
        return false;
    if (arr[0] >= arr[pivot] && arr[n-1] <= arr[pivot-1])
        return true;
    return false;
}

int main(int argc, char const *argv[])
{
    
    return 0;
}