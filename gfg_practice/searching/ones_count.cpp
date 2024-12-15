/*Given a binary sorted non-increasing array of 1s and 0s. You need to print the count of 1s in the binary array.*/
# include <iostream>
using namespace std;

int onescount(bool arr[] , int n)
{
    int low = 0 , high = n-1;
    while (low <= high)
    {
        int mid = (low+high)/2;
        if (arr[mid] == 0)
            high = mid-1;
        else
        {
            if (arr[mid+1] == 0 || mid == n-1)
                return mid+1;
            else
                low = mid + 1;
        }
    }
    return 0;
}

int main(int argc, char const *argv[])
{
    bool arr[] = {1,1,1,1,1,0};
    cout << onescount(arr,6);
    return 0;
}
