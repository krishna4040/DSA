# include "bits/stdc++.h"
using namespace std;

// Naive solutuion
vector<pair<int,int>> mergeOverlapping(pair<int,int>arr[] , int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int s = max(arr[i].first,arr[j].first);
            int e = min(arr[i].second,arr[j].second);
            if (s == arr[i].first)
            {
                if (arr[j].first < s && arr[j].second > s)
                {
                    // they overlap
                    arr[i].first = min(arr[i].first,arr[j].first);
                    arr[i].second = max(arr[i].second,arr[j].second);
                    arr[j].first = -1;
                    arr[j].second = -1;
                }
            }
            else
            {
                if (arr[i].first < s && arr[i].second > s)
                {
                    // they overlap
                    arr[i].first = min(arr[i].first,arr[j].first);
                    arr[i].second = max(arr[i].second,arr[j].second);
                    arr[j].first = -1;
                    arr[j].second = -1;
                }
            }
        }
    }
    vector<pair<int,int>> v;
    for (int i = 0; i < n; i++)
    {
        if (arr[i].first == -1)
            continue;
        v.push_back(arr[i]);
    }
    return v;
}

// Efficient
int mergeIntervel(pair<int,int> arr[] , int n)
{
    sort(arr,arr+n);
    int res = 0;
    for (int i = 1; i < n; i++)
    {
        if (arr[res].second >= arr[i].first)
        {
            arr[res].second = max(arr[res].second,arr[i].second);
            arr[res].first = min(arr[res].first,arr[i].first);
        }
        else
        {
            res++;
            arr[res] = arr[i];
        }
    }
    return res;
}

int main(int argc, char const *argv[])
{
    pair<int,int> arr[] = {
        {7,9},{6,10},{4,5},{1,3},{2,4}
    };
    // vector<pair<int,int>> v = mergeOverlapping(arr,5);
    // for (auto &&i : v)
    //     cout << i.first << " " << i.second << endl;

    int idx = mergeIntervel(arr,5);
    for (int i = 0; i <= idx; i++)
        cout << arr[i].first << " " << arr[i].second << endl;

    return 0;
}