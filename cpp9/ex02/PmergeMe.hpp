#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <algorithm>
#include <iostream>
#include <iterator>
#include <numeric>
#include <climits>
#include <stdexcept>
#include <string>
#include <cstdlib>
#include <sys/time.h>

class PmergeMe
{
private:
    std::vector<int> vec;
    std::deque<int> deq;
    double vec_time;
    double deq_time;
    void parseInput(int size, char **argv);
    void mergeInsertSortVector(std::vector<int> &v);
    void mergeInsertSortDeque(std::deque<int> &d);
public:
    PmergeMe(char **av);
    PmergeMe(const PmergeMe &other);
    PmergeMe &operator=(const PmergeMe &other);
    ~PmergeMe();

    void sort();
    void printResults();
};
#endif