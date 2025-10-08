#include "iter.hpp"

void add_one_number(int &num)
{
    num += 1;
    std::cout << num << std::endl;
}

int main( void )
{
    int arr[] = {1, 2, 3, 4, 5};
    iter(arr, 5, add_one_number);
}
