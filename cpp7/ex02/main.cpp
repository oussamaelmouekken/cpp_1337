#include "Array.hpp"

int main()
{
    std::cout << "=== Basic Array Test ===\n";
    
    // Test 1: Create array of 5 integers
    Array<int> numbers(5);
    std::cout << "Created array with size: " << numbers.size() << "\n";

    for (unsigned i = 0; i < numbers.size(); i++) {
        numbers[i] = i * 10;
    }
    
    std::cout << "Array contents: ";
    for (unsigned i = 0; i < numbers.size(); i++) {
        std::cout << numbers[i] << " ";
    }
    std::cout << "\n";
    try {
        std::cout << "Trying to access index 10: ";
        std::cout << numbers[10] << "\n";
    } catch (const std::exception& e) {
        std::cout << "Caught exception: " << e.what() << "\n";
    }
    
    // Test 4: Create empty array
    Array<float> empty;
    std::cout << "Empty array size: " << empty.size() << "\n";
    
    std::cout << "=== Tests Complete ===\n";
    return 0;
}
