# include "bits/stdc++.h"
using namespace std;

/*In C++, the language allows you to provide additional template parameters that are not used or needed by the particular template implementation. This is known as an "unused template parameter" and is allowed by the language rules.
When you provide an additional template parameter that is not utilized by the template implementation, it does not result in a compilation error because the language standard allows for unused template parameters. The compiler does not enforce that all provided template parameters are utilized by the template implementation.
However, it's important to note that providing unused template parameters is generally considered poor coding practice. It can lead to confusion for other developers who might assume that the additional parameter has a purpose or functionality within the template. It's recommended to only provide template parameters that are required and used by the template implementation.

Syntax: unordered_map<string,int,char> m;
char hass no use*/


int main(int argc, char const *argv[])
{
    // key - value
    unordered_map<string,int> m;

    // Insert
    m["gfg"] = 20;
    m["ide"] = 30;
    m.insert({"courses" , 153});

    // printing map
    for (auto &&i : m)
        cout << i.first << " " << i.second << endl;

    // accesing individual element
    cout << m["gfg"];
    cout << m.at("gfg");

    // Size
    cout << "Size of map is: " << m.size();

    // Searching
    if (m.find("gfg") != m.end())
    {
        auto itr = m.find("gfg");
        cout << itr->first << " " << itr->second;
    }
    else
        cout << "Not found";

    if (m.count("gfg"))
        cout << "Found";
    else
        cout << "Not Found";

    // Erase and clear
    m.erase("gfg");
    m.erase(m.begin());
    m.erase(m.begin() , m.end());
    m.clear();

    // iterators
    /*
        * forward iterators: begin() , end();
        * constant forward iterators: cbegin() , cend();
        * reverse iterators: rbegin() , rend();
        * reverse constant iterators: cebegin() , crend();
    */
    unordered_map<string,int> :: iterator i = m.begin() , j = m.end();
    advance(i,3);
    auto itr = next(i,4);
    auto ptr = prev(j,5);
    return 0;
}