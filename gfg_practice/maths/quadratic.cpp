# include "bits/stdc++.h"
using namespace std;

/*Given a quadratic equation in the form ax2 + bx + c. Find its roots.
Note: Return the maximum root followed by the minimum root.*/
vector <int> quadratic(int a , int b , int c)
{
    vector <int> roots;
    int d = b*b - (4*a*c);
    if (d < 0)
    {
        roots.push_back(-1);
    }
    else
    {
        float x = (-b + sqrt(d)) / (2*a);
        float y = (-b - sqrt(d)) / (2*a);
        if(x>y)
        {
            roots.push_back(floor(x));
            roots.push_back(floor(y));
        }
        else
        {
            roots.push_back(floor(y));
            roots.push_back(floor(x));
        }
    }
    return roots;
}

int main()
{
    int a , b , c;
    cin >> a >> b >> c;
    for (int i = 0; i < quadratic(a,b,c).size(); i++)
    {
        cout << quadratic(a,b,c)[i];
    }
    return 0;
}