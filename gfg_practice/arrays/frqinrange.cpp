/*Given an array A[] of N positive integers which can contain integers from 1 to P where elements can be repeated or can
be absent from the array.Your task is to count the frequency of all elements from 1 to N.
Note: The elements greater than N in the array can be ignored for counting and do modify the array in-place.*/
# include <iostream>
# include <vector>
using namespace std;

void frequencyCount(vector<int>& arr,int n, int p)
{ 
    int frq[n];
    for (int i = 0; i < n; i++)
    {
        int count = 0;
        for (int j = 0; j < n; j++)
        {
            if (i+1 == arr[j])
            {
                count++;
            }
        }
        cout << count << " ";
    }
}

int main(int argc, char const *argv[])
{
    vector<int> arr = {2, 3, 2, 3, 5};
    frequencyCount(arr,5,5);
    return 0;
}
