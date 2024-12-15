# include "bits/stdc++.h"
# include <unordered_set>
using namespace std;

int sain(int argc, char const *argv[])
{
    unordered_set<int> s;

    // Insert
    s.insert(10);
    s.insert(5);
    s.insert(15);
    s.insert(5); // ignored

    // printing sap
    for (auto &&i : s)
        cout << i;

    // Size
    cout << "Size of sap is: " << s.size();

    // Searching
    if (s.find(5) != s.end())
    {
        auto itr = s.find(5);
        cout << "Found" << *itr;
    }
    else
        cout << "Not found";

    if (s.count(15))
        cout << "Found";
    else
        cout << "Not Found";

    // Erase and clear
    s.erase(15);
    s.erase(s.begin());
    s.erase(s.begin() , s.end());
    s.clear();

    // iterators
    /*
        * forward iterators: begin() , end();
        * constant forward iterators: cbegin() , cend();
        * reverse iterators: rbegin() , rend();
        * reverse constant iterators: cebegin() , crend();
    */
    unordered_set<int> :: iterator i = s.begin() , j = s.end();
    advance(i,3);
    auto itr = next(i,4);
    auto ptr = prev(j,5);
    return 0;
}