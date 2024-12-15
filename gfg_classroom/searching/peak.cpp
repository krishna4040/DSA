# include <iostream>
using namespace std;

int peakeElement(int arr[] , int n)
{
    int l = 0 , h = n-1;
    while (l <= h)
    {
        int m = (l+h)/2;
        if ((m == 0 || arr[m] > arr[m-1]) && (m == n-1 || arr[m] >= arr[m+1]))
            return m;
        if (m > 0 && arr[m-1] > arr[m])
            h = m - 1;
        else
            l = m + 1;
    }
    return -1;
}

int main(int argc, char const *argv[])
{
    int arr[] = {5,10,20,15,7};
    cout << peakeElement(arr,5);
    return 0;
}
