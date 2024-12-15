/*You are involved in a betting game whose rules are as follows :
a) If you win a round, the bet amount will be added to your current sum and next bet amount will become $1;
b) If you lose a round, the bet amount will be reduced from your current sum and next bet will become twice the previous.
c) game ends either when all the rounds are complete or when you don't have sufficient sum.
Initially, you are given with a string result consisiting of characters from the set {'W', 'L'}, where 'W' indicates a win and 'L' indicates a loss, and initial sum is 4. Initial bet amount for the 1st round will be $1.
You need to find and print the amount at the end of the game (final sum) and in case you do not have enough money in between the game to play the next round, then return -1*/
# include <iostream>
using namespace std;

int betgame(string s)
{
    int sum = 4;
    int bet = 1;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == 'W')
        {
            sum += bet;
            bet = 1;
        }
        else if (s[i] == 'L')
        {
            sum -= bet;
            bet *= 2;
        }
        if (sum < bet)
            return -1;
    }
    return sum;
}

int main(int argc, char const *argv[])
{
    string s;
    getline(cin , s);
    cout << betgame(s);
    return 0;
}