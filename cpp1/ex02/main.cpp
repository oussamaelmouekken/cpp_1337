#include <iostream>

int main()
{
    std::string text = "HI THIS IS BRAIN";
    std::string *stringPTR = &text;
    std::string &stringREF = text;
    std::cout<<"address string variable  : "<<&text<<"\n";
    std::cout<<"address held by stringPTR: "<<&stringPTR<<"\n";
    std::cout<<"address held by stringREF: "<<&stringREF<<"\n";
    std::cout<<"       ------------------"<<"\n";
    std::cout<<"value string variable  : "<<text<<"\n";
    std::cout<<"value held by stringPTR: "<<*stringPTR<<"\n";
    std::cout<<"value held by stringREF: "<<stringREF<<"\n";
    return 0;
}
