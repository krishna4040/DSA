/*Given a keypad as shown in the diagram, and an N digit number which is represented by array a[ ],
the task is to list all words which are possible by pressing these numbers.*/
# include <iostream>
# include <vector>
using namespace std;

void solve(int arr[] , int n , string op , int index , vector<string>&ans , string map[])
{
    if (index == n)
    {
        ans.push_back(op);
        return;
    }
    int num = arr[index];   // iterator to iterate over map of numbers to string
    string value = map[num];    // stores the mapped string
    for (int i = 0; i < value.length(); i++)  // i is iterator to to iterate over each char of that string
    {
        op.push_back(value[i]);
        solve(arr , n , op , index+1 , ans , map);
        op.pop_back();
    }
}

vector<string> keypad(int arr[] , int n)
{
    vector <string> ans; // ans vector
    string op;  // combination string
    int index = 0; // iterator to iterate over array or dial numbers
    string map[10] = {"" , "" , "abc" , "def" , "ghi" , "jkl" , "mno" , "pqrs" , "tuv" , "wxyz"};
    // edge case
    if (n == 0)
        return ans;
    solve(arr , n , op , index , ans , map);
}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    for (int i = 0; i < keypad(arr,n).size(); i++)
        cout << keypad(arr,n)[i] << " ";
    return 0;
}
