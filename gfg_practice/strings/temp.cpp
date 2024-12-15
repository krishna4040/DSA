# include "bits/stdc++.h"
using namespace std;
# define int long long

int mooresVoting(int arr[] , int n)
{
    
}

signed main(int argc, char const *argv[])
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int* a = new int[n];
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }
        sort(a,a+n);
        for(int i=0;i<n;i++)
        {
            cout<<a[i]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
