#include "PmergeMe.hpp"

PmergeMe::PmergeMe(char **av)
{
    int size = 0;
    while (av[size])
        size++;

    if (size == 0)
    {
        throw std::invalid_argument("Error: no input provided");
    }
    std::cout << "PmergeMe: Constructor called" << std::endl;
    parseInput(size, av);
}

PmergeMe::PmergeMe(const PmergeMe &other) : vec(other.vec), deq(other.deq)
{
    std::cout << "PmergeMe: Copy constructor called" << std::endl;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
    std::cout << "PmergeMe: Assignment operator called" << std::endl;
    if (this != &other)
    {
        vec = other.vec;
        deq = other.deq;
    }
    return *this;
}

PmergeMe::~PmergeMe()
{
    std::cout << "PmergeMe: Destructor called" << std::endl;
}

void PmergeMe::parseInput(int size, char **argv)
{
    for (int i = 0; i < size; i++)
    {
        char *endptr;
        long num = std::strtol(argv[i], &endptr, 10);
        if (*endptr != '\0' || endptr == argv[i])
        {
            throw std::invalid_argument("Error: invalid input '" + std::string(argv[i]) + "'");
        }
        if (num < 0)
        {
            throw std::invalid_argument("Error: only positive integers are allowed");
        }
        if (num > INT_MAX)
        {
            throw std::invalid_argument("Error: number too large");
        }
        int intNum = static_cast<int>(num);
        vec.push_back(intNum);
        deq.push_back(intNum);
    }
    std::cout << "Before : ";
    for (size_t i = 0; i < vec.size(); i++)
    {
        std::cout << vec[i];
        if (i != vec.size() - 1)
            std::cout << " ";
    }
    std::cout << std::endl;
}
double getTime()
{
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return tv.tv_sec * 1000000.0 + tv.tv_usec;
}
void PmergeMe::sort()
{
    std::vector<int> vec_copy = vec; // Work on copy to preserve original
    double start = getTime();
    mergeInsertSortVector(vec_copy);
    double end = getTime();
    vec_time = end - start;

    std::deque<int> deq_copy = deq; // Work on copy to preserve original
    start = getTime();
    mergeInsertSortDeque(deq_copy);
    end = getTime();
    deq_time = end - start;
    
    // Update original containers with sorted results
    vec = vec_copy;
    deq = deq_copy;
}

void PmergeMe::printResults()
{
    std::cout << "After  : ";
    for (size_t i = 0; i < vec.size(); i++)
    {
        std::cout << vec[i];
        if (i != vec.size() - 1)
            std::cout << " ";
    }
    std::cout << std::endl;
    std::cout << std::fixed;
    std::cout << "Time to process a range of " << vec.size() << " elements with std::vector : " << vec_time / 1000000.0 << " us" << std::endl;
    std::cout << "Time to process a range of " << deq.size() << " elements with std::deque  : " << deq_time / 1000000.0 << " us" << std::endl;
}

// Generate Jacobsthal numbers up to n
size_t *generateJacobsthal(size_t n, size_t &count)
{
    static size_t jacob[64];
    jacob[0] = 0; // start index at 0 for easier mapping
    jacob[1] = 1;
    size_t i = 2;
    count = 2;

    while (true)
    {
        size_t j = jacob[i - 1] + 2 * jacob[i - 2];
        if (j >= n || i >= 64)
            break;
        jacob[i] = j;
        i++;
        count++;
    }

    return jacob;
}

void PmergeMe::mergeInsertSortVector(std::vector<int> &v)
{
    if (v.size() <= 1)
        return;
    std::vector<std::pair<int, int> > pairs;
    for (size_t i = 0; i + 1 < v.size(); i += 2)
    {
        int a = v[i];
        int b = v[i + 1];
        if (a > b)
            std::swap(a, b);
        pairs.push_back(std::make_pair(a, b));
    }
    bool hasLeftover = (v.size() % 2 != 0);
    int leftover;
    if (hasLeftover)
        leftover = v[v.size() - 1];
    else
        leftover = 0;
    std::vector<int> mainChain;
    for (size_t i = 0; i < pairs.size(); i++)
        mainChain.push_back(pairs[i].second);
    mergeInsertSortVector(mainChain);
    size_t jacobsthal_count;
    size_t *jacobsthal = generateJacobsthal(pairs.size(), jacobsthal_count);
    std::vector<bool> inserted(pairs.size(), false);

    for (size_t j = 1; j < jacobsthal_count; j++)
    {
        size_t end = jacobsthal[j];
        size_t start = jacobsthal[j - 1] + 1;
        for (size_t idx = start; idx <= end && idx < pairs.size(); idx++)
        {
            if (!inserted[idx])
            {
                std::vector<int>::iterator pos =
                    std::lower_bound(mainChain.begin(), mainChain.end(), pairs[idx].first);
                mainChain.insert(pos, pairs[idx].first);
                inserted[idx] = true;
            }
        }
    }

    // Insert any remaining elements
    for (size_t i = 0; i < pairs.size(); i++)
    {
        if (!inserted[i])
        {
            std::vector<int>::iterator pos =
                std::lower_bound(mainChain.begin(), mainChain.end(), pairs[i].first);
            mainChain.insert(pos, pairs[i].first);
        }
    }

    if (hasLeftover)
    {
        std::vector<int>::iterator pos =
            std::lower_bound(mainChain.begin(), mainChain.end(), leftover);
        mainChain.insert(pos, leftover);
    }
    v = mainChain;
}
void PmergeMe::mergeInsertSortDeque(std::deque<int> &d)
{
    if (d.size() <= 1)
        return;
    std::deque<std::pair<int, int> > pairs;
    for (size_t i = 0; i + 1 < d.size(); i += 2)
    {
        int a = d[i];
        int b = d[i + 1];
        if (a > b)
            std::swap(a, b);
        pairs.push_back(std::make_pair(a, b));
    }
    bool hasLeftover = (d.size() % 2 != 0);
    int leftover;
    if (hasLeftover)
        leftover = d[d.size() - 1];
    else
        leftover = 0;
    std::deque<int> mainChain;
    for (size_t i = 0; i < pairs.size(); i++)
        mainChain.push_back(pairs[i].second);
    mergeInsertSortDeque(mainChain);
    size_t jacobsthal_count;
    size_t *jacobsthal = generateJacobsthal(pairs.size(), jacobsthal_count);
    std::deque<bool> inserted(pairs.size(), false);

    for (size_t j = 1; j < jacobsthal_count; j++)
    {
        size_t end = jacobsthal[j];
        size_t start = jacobsthal[j - 1] + 1;
        for (size_t idx = start; idx <= end && idx < pairs.size(); idx++)
        {
            if (!inserted[idx])
            {
                std::deque<int>::iterator pos =
                    std::lower_bound(mainChain.begin(), mainChain.end(), pairs[idx].first);
                mainChain.insert(pos, pairs[idx].first);
                inserted[idx] = true;
            }
        }
    }

    // Insert any remaining elements
    for (size_t i = 0; i < pairs.size(); i++)
    {
        if (!inserted[i])
        {
            std::deque<int>::iterator pos =
                std::lower_bound(mainChain.begin(), mainChain.end(), pairs[i].first);
            mainChain.insert(pos, pairs[i].first);
        }
    }

    if (hasLeftover)
    {
        std::deque<int>::iterator pos =
            std::lower_bound(mainChain.begin(), mainChain.end(), leftover);
        mainChain.insert(pos, leftover);
    }
    d = mainChain;
}
