#include <algorithm>
#include <iostream>
#include "vector.hpp"


int main()
{
    vector<int> v1;
    for (int i = 0; i < 9; i++)
        v1.push_back(i);
    
    std::cout << v1.begin();
    
    for(int i = 0; i < 9; i++)
        std::cout << v1[i] << '\n';
    
    return 0;
}
