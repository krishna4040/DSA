# include <iostream>
using namespace std;

//Naive approach
int maxprofit(int price[] , int start , int end)
{
    if (end <= start)
        return 0;
    int profit = 0;
    for (int i = start; i < end; i++)
        for (int j = i+1; j < end; j++)
            if (price[j] > price[i])
            {
                int curr_prf = price[j]-price[i]+maxprofit(price,start,i-1)+maxprofit(price,j+1,end);
                profit = max(profit,curr_prf);
            }
    return profit;
}

// peak-valley approach
int maxprofit(int price[] , int n)
{
    int profit = 0;
    for (int i = 0; i < n; i++)
        if (price[i] > price[i-1])
            profit += price[i]-price[i-1];
    return profit;
}

int main(int argc, char const *argv[])
{
    
    return 0;
}