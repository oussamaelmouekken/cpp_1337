#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int	main(void)
{
    Animal* dog = new Dog();
    Animal* cat = new Cat();
    //dog->makeSound();
    //cat->makeSound();
    dog->getType();
    dog->makeSound();
    cat->getType();
    cat->makeSound();
    delete dog;
    delete cat;

    // Animal* meta = new Animal();
    // meta->makeSound();
    // delete meta;
	return (0);
}
