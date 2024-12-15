/*Print a sequence of numbers starting with N where A[0] = N, without using loop,
in which  A[i+1] = A[i] - 5,  until A[i] > 0. After that A[i+1] = A[i] + 5  repeat it until A[i] = N.*/
# include <iostream>
# include <vector>
using namespace std;

vector<int> pattern(int n)
{
    vector<int> v;
    int temp = n;
    v.push_back(temp);
    temp -= 5;
    while (temp >= 0)
    {
        v.push_back(temp);
        if(temp == 0)
            break;
        temp -= 5;
    }
    while (temp != n)
    {
        
        if(temp == 0)
        {
            temp+=5;
            continue;
        }
        v.push_back(temp);
        temp += 5;
    }
    v.push_back(temp);
    return v;
}

int main(int argc, char const *argv[])
{
    vector<int> v = pattern(16);
    for (auto &&i : v)
    {
        cout << i << " ";
    }
    
    return 0;
}