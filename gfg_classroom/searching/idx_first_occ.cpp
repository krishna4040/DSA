# include <iostream>
using namespace std;

int idxFirst(int arr[] , int n , int x)
{
    int low = 0 , high = n-1;
    while (low <= high)
    {
        int mid = (low+high)/2;
        if (arr[mid] == x)
        {
            if (mid == 0 || arr[mid] != arr[mid-1])
                return mid;
            else
                high = mid-1;
        }
        else if (arr[mid] > x)
            high = mid-1;
        else
            low = mid+1;
    }
}

int main(int argc, char const *argv[])
{
    int arr[] = {1,10,10,10,20,20,30};
    cout << idxFirst(arr,7,20);
    return 0;
}
