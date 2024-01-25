#include <algorithm>
#include <iostream>
#include "vector.hpp"


int main()
{
    vector<int> r;
    for (int i = 0; i < 9; i++)
        r.push_back(i);

    for(int i = 0; i < 9; i++)
        std::cout << r[i] << '\n';
    
    std::cout << "все";
    return 0;
}
