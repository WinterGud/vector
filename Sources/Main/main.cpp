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

    std::sort(v1.begin().getPointer(), v1.end().getPointer());

    std::cout << "\n" <<std::find(v1.begin().getPointer(), v1.end().getPointer(), 123) << '\n';
    
    for(vector<int>::iterator it = v1.begin(); it != v1.end(); ++it)
        std::cout << it << '\n';
    
    return 0;
}
