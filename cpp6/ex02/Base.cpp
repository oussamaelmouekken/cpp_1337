#include "Base.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>  
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base::~Base()
{
    std::cout<<"Base destructor\n";
}
Base* generate(void)
{
    //srand(std::time(0));
    
    int random = std::rand() % 3;
    
    switch (random) {
        case 0: return new A();
        case 1: return new B();
        case 2: return new C();
    }
    return NULL;
}

void identify(Base* p)
{
    if (dynamic_cast<A*>(p))
    std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(p))
    std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(p))
    std::cout << "C" << std::endl;
    else
    std::cout << "error in type" << std::endl;
}

void identify(Base& p) {
    try 
    {
        (void)dynamic_cast<A&>(p);
        std::cout << "A" << std::endl;
        return;
    } catch (const std::exception& e) {
        std::cerr << "Cast failed: " << e.what() << std::endl;
    }
    try
    {
        (void)dynamic_cast<B&>(p);
        std::cout << "B" << std::endl;
        return; 
    } catch (const std::exception& e) {
        std::cerr << "Cast failed: " << e.what() << std::endl;
    }
    
    try
    {
        (void)dynamic_cast<C&>(p);
        std::cout << "C" << std::endl;
        return;
    } catch (const std::exception& e) {
        std::cerr << "Cast failed: " << e.what() << std::endl;
    }
    
    std::cout << "Unknown type" << std::endl;
}

int main()
{
    // Test generate() and identify(Base*)
    srand(std::time(0));
    std::cout << "Testing pointer identification:\n";
    for (int i = 0; i < 3; i++) {
        Base* obj = generate();
        std::cout << "Object " << i+1 << ": ";
        identify(obj);
        delete obj;
    }

    // Test identify(Base&)
    std::cout << "\nTesting reference identification:\n";
    A a;
    B b;
    C c;
    
    Base& ref1 = a;
    Base& ref2 = b;
    Base& ref3 = c;
    
    std::cout << "Ref 1: ";
    identify(ref1);
    
    std::cout << "Ref 2: ";
    identify(ref2);
    
    std::cout << "Ref 3: ";
    identify(ref3);

    return 0;
}