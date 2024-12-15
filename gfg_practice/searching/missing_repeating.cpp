/*Description: Given an unsorted array of size n. Array elements are in the range from 1 to n. One number from set
{1, 2, …n} is missing and one number occurs twice in the array. Our task is to find these two numbers*/

# include <iostream>
# include <vector>
using namespace std;

int fact(int n)
{
    if (n == 0 || n == 1)
        return 1;
    return n * fact(n-1);
}
int sum(int n)
{
    return n*(n+1)/2;
}

vector<int> missingRepeating(int arr[] , int n)
{
    int s = 0 , p = 1;
    for (int i = 0; i < n; i++)
    {
        s += arr[i];
        p *= arr[i];
    }
    int real_sum = sum(n);
    int real_pro = fact(n);
    int yminusx = real_sum - s;
    int xbyy = real_pro/p;
    int y = yminusx/(xbyy-1);
    int x = yminusx + y;
    vector<int> v;
    v.push_back(x);
    v.push_back(y);
    return v;
}

int main(int argc, char const *argv[])
{
    int arr[] = {2,3,2,1,5};
    vector<int> v = missingRepeating(arr,5);
    for (auto &&i : v)
    {
        cout << i << " ";
    }
    return 0;
}