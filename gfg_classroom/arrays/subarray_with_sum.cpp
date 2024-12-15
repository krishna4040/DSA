# include <iostream>
using namespace std;

// Naive solution
bool subarraySum(int arr[] , int n , int sum)
{
    for (int i = 0; i < n; i++)
    {
        int curr_sum = 0;
        for (int j = i; j < n; j++)
        {
            curr_sum += arr[j];
            if (curr_sum == sum)
                return 1;
        }
    }
    return 0;
}

// efficient sol


int main(int argc, char const *argv[])
{
    int arr[] = {1,4,20,3,10,5};
    cout << subarraySum(arr,6,33);
    return 0;
}
