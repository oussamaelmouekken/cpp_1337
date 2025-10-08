#include <iostream>
#include "Serializer.hpp"

int main(void)
{

	Data *data = new Data;
	data->name = "oussama";
	data->age = 42;

	std::cout<<"------initial data \n";
	std::cout << data->age << std::endl;
	std::cout << data->name << std::endl;

	uintptr_t raw = Serializer::serialize(data);
	Data *serialized = Serializer::deserialize(raw);

	std::cout<<"------after deserialize \n";
	std::cout << "intger : " <<raw << std::endl;
	std::cout << serialized->age << std::endl;
	std::cout << serialized->name << std::endl;

	delete data;
	return (0);
}
