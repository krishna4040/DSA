/*Given an array A of positive integers. Your task is to find the leaders in the array. An element of array is leader
if it is greater than or equal to all the elements to its right side. The rightmost element is always a leader. */

# include <iostream>
# include <vector>
# include <algorithm>
using namespace std;

vector<int> leaders(int arr[], int n)
{
    vector<int> v;
    int curr_ldr = arr[n-1];
    v.push_back(curr_ldr);
    for (int i = n - 2; i >= 0; i--)
    {
        if (arr[i] > curr_ldr)
        {
            curr_ldr = arr[i];
            v.push_back(curr_ldr);
        }
    }
    vector<int> :: iterator i ,j;
    i = v.begin();
    j = v.end();
    reverse(i,j);
    return v;
}
int main(int argc, char const *argv[])
{
    
    return 0;
}
