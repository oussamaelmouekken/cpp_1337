#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
// #include "WrongCat_Animal.hpp"

int	main(void)
{
	const Animal	*meta = new Animal("dddd");
	const Animal	*j = new Dog();
	const Animal	*i = new Cat();

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound();
	j->makeSound();
	meta->makeSound();

	
    delete i;

	// const WrongAnimal	*meta = new WrongAnimal("dddd");
	// const WrongAnimal	*j = new WrongCat();
	// meta->makeSound();
	// j->makeSound();


    delete j;
	delete meta;
	return (0);
}
