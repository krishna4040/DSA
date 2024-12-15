/*Given a sorted array arr[] of distinct integers. Sort the array into a wave-like array(In Place).
In other words, arrange the elements into a sequence such that arr[1] >= arr[2] <= arr[3] >= arr[4] <= arr[5].....
If there are multiple solutions, find the lexicographically smallest one.
Note:The given array is sorted in ascending order, and you don't need to return anything to make changes in the original array itself.*/
# include <iostream>
# include <vector>
using namespace std;

void convertToWave(int n, vector<int>& arr)
{
    for (int i = 0; i < n; i+=2)
    {
        if (i+1 > n-1)
        {
            break;
        }
        swap(arr[i],arr[i+1]);
    }
}

int main(int argc, char const *argv[])
{
    vector<int> arr = {1,2,3,4};
    convertToWave(4,arr);
    for (int i = 0; i < 4; i++)
    {
        cout << arr[i] << " ";
    }
    
    return 0;
}