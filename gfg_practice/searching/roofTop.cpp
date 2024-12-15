/*You are given heights of consecutive buildings. You can move from the roof of a building to the roof of next adjacent building.
You need to find the maximum number of consecutive steps you can put forward such that you gain an increase in altitude with each step.*/
# include <iostream>
using namespace std;

int maxsteps(int arr[] , int n)
{
    int res = 0;
    int cons_max = 0 , curr_max = 0;
    for (int i = 0; i < n-1; i++)
    {
        if (arr[i+1] > arr[i]){
            curr_max++;
        }
        cons_max = max(cons_max , curr_max);
        if (arr[i+1] <= arr[i]){
            curr_max = 0;
        }
        res = max(res,cons_max);
    }
    return res;
}

int main(int argc, char const *argv[])
{
    
    return 0;
}