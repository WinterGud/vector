#include <iostream>
#include <vector>
#include <stdexcept>
#include "vector.hpp"

int main() {
    // Test Case 1
    std::vector<int> intVector;
    intVector.push_back(4);
    
    std::cout << "Test Case 1: Size of intVector: " << intVector.size() << std::endl;

    // Test Case 2
    intVector.push_back(42);
    std::cout << "Test Case 2: Added an int, new size: " << intVector.size() << std::endl;

    intVector[0] = 0;
    
    // Test Case 3  
    intVector.pop_back();
    std::cout << "Test Case 3: Removed an int, new size: " << intVector.size() << std::endl;

    // Test Case 4
    //intVector.pop_back();
    std::cout << "Test Case 4: Attempted to remove the same int again, size: " << intVector.size() << std::endl;

    // Test Case 5
    try {
        //intVector.push_back("Hello"); // This will not compile since the vector is of type int
    } catch (const std::exception &e) {
        std::cerr << "Test Case 5: " << e.what() << std::endl;
    }

    // Test Case 6
    vector<vector<int>> intVectorOfVectors;
    std::cout << "Test Case 6: Size of intVectorOfVectors: " << intVectorOfVectors.size() << std::endl;

    // Test Case 7
    vector<int> initialVector;
    initialVector.push_back(1);
    initialVector.push_back(2);
    intVectorOfVectors.push_back(initialVector);
    intVectorOfVectors.push_back(initialVector);
    std::cout << "Test Case 7: Size of intVectorOfVectors after adding 2 vectors: " << intVectorOfVectors.size() << std::endl;

    intVectorOfVectors.pop_back();

    // Test Case 8
    vector<int> secondVector = intVectorOfVectors[1];
    std::cout << "Test Case 8: Size of secondVector: " << secondVector.size() << std::endl;

   
    // Test Case 11
    try {
        //intVectorOfVectors[1].push_back("World"); // This will not compile since the inner vector is of type int
    } catch (const std::exception &e) {
        std::cerr << "Test Case 11: " << e.what() << std::endl;
    }

    // Test Case 12
    vector<int> capacityVector;
    std::cout << "Test Case 12: Initial capacity of capacityVector: " << capacityVector.capacity() << std::endl;

    // Test Case 13
    for (int i = 0; i < 10; ++i) {
        capacityVector.push_back(i);
    }
    std::cout << "Test Case 13: Added 10 elements, new capacity: " << capacityVector.capacity() << std::endl;

    // Test Case 14
    capacityVector.clear();
    std::cout << "Test Case 14: Cleared the vector, capacity remains: " << capacityVector.capacity() << std::endl;

    // Test Case 15
    try {
        int value = capacityVector.at(0); // This will throw an out_of_range exception
    } catch (const char* er) {
        std::cerr << "Test Case 15: " << er << std::endl;
    }


    // Test Case 18
    try {
        int value = capacityVector.at(0); // This will throw an out_of_range exception
    } catch (const char* er) {
        std::cerr << "Test Case 18: " << er << std::endl;
    }

    return 0;
}
