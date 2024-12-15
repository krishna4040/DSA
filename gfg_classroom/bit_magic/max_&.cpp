# include <iostream>
using namespace std;

int maxand(int arr[] , int n)
{
    int mx = 0;
    for (int i = 0; i < n; i++)
        for (int j = i+1; j < n; j++)
            mx = max(mx , arr[i] & arr[j]);
    return mx;
}

// using bit manipulation

// Utility function to check number of elements
// having set msb as of pattern
int checkBit(int pattern, int arr[], int n)
{
    int count = 0;
    for (int i = 0; i < n; i++)
        if ((pattern & arr[i]) == pattern)
            count++;
    return count;
}

// Function for finding maximum and value pair
int maxAND(int arr[], int n)
{
    int res = 0, count;

    // iterate over total of 32bits from msb to lsb
    for (int bit = 31; bit >= 0; bit--) {
        // find the count of element having same pattern as
        // obtained by adding bits on every iteration.
        count = checkBit(res | (1 << bit), arr, n);

        // if count >= 2 set particular bit in result
        if (count >= 2)
            res = res | (1 << bit); // this is the pattern
                                    // we continued
    }

    return res;
}

// Driver function
int main()
{
    int arr[] = { 4, 8, 6, 2 };
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Maximum AND Value = " << maxAND(arr, n);
    return 0;
}