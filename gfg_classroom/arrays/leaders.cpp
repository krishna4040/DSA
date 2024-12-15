# include <iostream>
using namespace std;

// Naive approach
void leaders(int arr[] , int n)
{
    for (int i = 0; i < n; i++)
    {
        bool leader = 1;
        for (int j = i+1; j < n; j++)
            if (arr[j] > arr[i])
            {
                leader = 0;
                break;
            }
        if (leader)
            cout << arr[i] << " ";
    }
}


// Efficient approach
void leaders(int arr[] , int n)
{
    int max_from_right = arr[n-1];
    cout << max_from_right << " ";
    for (int i = n - 2; i >= 0; i--)
        if (arr[i] > max_from_right)
        {
            max_from_right = arr[i];
            cout << max_from_right << " ";
        }
}

int main(int argc, char const *argv[])
{
    int arr[] = {7,10,4,3,6,5,2};
    leaders(arr,7);
    return 0;
}
