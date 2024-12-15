# include <iostream>
using namespace std;

int bs_in_rotated_sorted_array(int arr[] , int n , int x)
{
    int l = 0 , h = n-1;
    while (l <= h)
    {
        int m = (l+h)/2;
        if (arr[m] == x)
            return m;
        if (arr[m] > arr[l])
        {
            if (x <= arr[m] && x > arr[l])
                h = m - 1;
            else
                l = m + 1;
        }
        else
        {
            if (x >= arr[m] && x < arr[h])
                l = m + 1;
            else
                h = m - 1;
        }
    }
}

int main(int argc, char const *argv[])
{
    int arr[] = {10,20,30,40,50,8,9};
    cout << bs_in_rotated_sorted_array(arr,7,30);
    return 0;
}
