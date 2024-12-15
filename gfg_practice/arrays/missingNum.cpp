#include <iostream>
#include <cstring>
using namespace std;

/*variation of bucket sort algorithm*/

int findSmallestMissing(int arr[], int n) {
    bool present[n+1];
    memset(present, false, sizeof(present));

    // Marking the occurrence of positive integers in arr
    for (int i = 0; i < n; i++) {
        if (arr[i] > 0 && arr[i] <= n) {
            present[arr[i]] = true;
        }
    }

    // Finding the first unmarked element in present[]
    for (int i = 1; i <= n; i++) {
        if (!present[i]) {
            return i;
        }
    }

    // If all elements are present, then N+1 is the smallest missing positive integer
    return n+1;
}

int main() {
    int arr[] = {3, 4, -1, 1, 5, -5, 0};
    int n = sizeof(arr) / sizeof(arr[0]);
    int smallestMissing = findSmallestMissing(arr, n);
    cout << "Smallest missing positive number is: " << smallestMissing << endl;
    return 0;
}