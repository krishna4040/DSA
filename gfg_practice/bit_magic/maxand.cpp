# include <iostream>
using namespace std;

/*Given an array arr[] of N positive elements. 
The task is to find the Maximum AND Value generated by any pair(arri, arrj) from the array such that i != j.*/
int maxand(int arr[] , int n)
{
    int mand = INT32_MIN;
    for (int i = 0; i < n; i++)
        for (int j = i+1; j < n; j++)
            mand = max(mand , arr[i]&arr[j]);
    return mand;
}

int main(int argc, char const *argv[])
{
    int arr[] = {4,8,12,16};
    cout << maxand(arr,4);
    return 0;
}