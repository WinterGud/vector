#include <algorithm>
#include <iostream>
#include <vector>
#include "vector.hpp"


int main()
{
    vector<int> v1;
    for (int i = 9; i > 0; i--)
    {
        v1.push_back(i);
    }
    v1.push_back(123);
    v1.push_back(44);
    v1.push_back(1234);
    v1.push_back(532);

    vector<vector<int>> vv1;
    vv1.push_back(v1);
    vv1.push_back(v1);
    vv1.push_back(v1);

    for(int i = 0; i < vv1[0].size(); i++)
        std::cout << vv1[0][i] << ' ';
    

    for(auto it : vv1)
    {
        for(const auto it2 : it)
        {
            std::cout << it2;
        }
    }
    
    return 0;
}
