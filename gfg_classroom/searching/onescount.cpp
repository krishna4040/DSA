# include <iostream>
using namespace std;

int onescount(bool arr[] , int n)
{
    int low = 0 , high = n-1;
    while (low <= high)
    {
        int mid = (low+high)/2;
        if (arr[mid] == 0)
            low = mid + 1;
        else
        {
            if (arr[mid-1] == 0 || mid == 0)
                return n - mid;
            else
                high = mid - 1;
        }
    }
    return 0;
}

int main(int argc, char const *argv[])
{
    bool arr[] = {0,0,1,1,1,1};
    cout << onescount(arr,6);
    return 0;
}
