# include <iostream>
# include <vector>
using namespace std;

void display(vector<int> v)
{
    for (auto e : v)
        cout << e << " ";
}

vector<int> prefixsum(int arr[] , int n)
{
    vector<int> ans;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        ans.push_back(sum);
    }
    return ans;
}


int main(int argc, char const *argv[])
{
    int arr[] = {10, 20, 10, 5, 15};
    display(prefixsum(arr,5));
    return 0;
}