# include "bits/stdc++.h"
using namespace std;

/*Given an unsorted array arr[] of n positive integers. Find the number of triangles that can be formed with three different
array elements as lengths of three sides of triangles. */

int countTriangles(int arr[], int n) {
    sort(arr, arr + n);
    int count = 0;

    for (int i = 0; i < n - 2; i++) {
        int k = i + 2;
        for (int j = i + 1; j < n - 1; j++) {
            while (k < n && arr[i] + arr[j] > arr[k]) {
                k++;
            }
            count += k - j - 1;
        }
    }

    return count;
}

int main(int argc, char const *argv[])
{
    
    return 0;
}