#include <iostream>

char *to_upper(char *str)
{
    int i = 0;
    while(str[i])
    {
        if(str[i] >= 'a' && str[i] <= 'z')
        {
            str[i] -= 32;
        }
        i++;
    }
    return str;
}

int main(int ac ,char **av)
{
    int  i = 0;
    char *n = NULL;
    if(ac == 1)
     std::cout<< "* LOUD AND UNBEARABLE FEEDBACK NOISE * ";
    else 
    {
        i = 1;
        while(i < ac)
        {
            n = to_upper(av[i]);
            std::cout << n;
            i++;
        }
    }
    std::cout << "\n";
}
