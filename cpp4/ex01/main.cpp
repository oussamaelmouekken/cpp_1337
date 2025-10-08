#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int	main(void)
{
    Animal *animal[100];
    int i =0;
    std::cout<<"------------first----------------\n";
    for(i = 0; i < 50 ; i++)
    {
        animal[i] = new Dog();
    }

    std::cout<<"------------second----------------\n";
    for(i = 50; i < 100 ; i++)
    {
        animal[i] = new Cat();
    }
    std::cout<<"---------------delete-----------------\n";
    for(i = 0; i <100;i++)
    {
        delete animal[i];
    }
	return (0);
}
