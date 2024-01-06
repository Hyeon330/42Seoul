#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

#define	ANIMAL_SIZE 6

void	leak_test() {
	system("leaks ex01");
}

void	test1() {
	std::cout << "==================== test1 ====================" << std::endl;
	Animal *animals[ANIMAL_SIZE];

	for (int i = 0; i < ANIMAL_SIZE; i++) {
		if (i % 2)
			animals[i] = new Dog();
		else
			animals[i] = new Cat();
	}

	std::cout << std::endl;

	for (int i = 0; i < ANIMAL_SIZE; i++)
		animals[i]->makeSound();

	std::cout << std::endl;

	for (int i = 0; i < ANIMAL_SIZE; i++)
		delete animals[i];
}

void	test2() {
	std::cout << "==================== test2 ====================" << std::endl;
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << std::endl;

	delete j;//should not create a leak
	delete i;
}

void	test3() {
	std::cout << "==================== test3 ====================" << std::endl;
	// 깊은 복사 테스트
	Dog* dog = new Dog();
	Cat* cat = new Cat();

	std::cout << std::endl;

	for (int i = 0; i < 10; i++)
		std::cout << dog->getBrain()->getIdea(i) << ":";
	std::cout << std::endl;
	for (int i = 0; i < 10; i++)
		std::cout << cat->getBrain()->getIdea(i) << ":";
	std::cout << std::endl;

	std::cout << std::endl;

	dog->getBrain()->setIdea("BowBow!!", 3);
	dog->getBrain()->setIdea("WowWow!!", 5);
	cat->getBrain()->setIdea("me~", 1);
	cat->getBrain()->setIdea("ow~", 4);

	for (int i = 0; i < 10; i++)
		std::cout << dog->getBrain()->getIdea(i) << ":";
	std::cout << std::endl;
	for (int i = 0; i < 10; i++)
		std::cout << cat->getBrain()->getIdea(i) << ":";
	std::cout << std::endl;

	std::cout << std::endl;

	Dog* copyDog = new Dog(*dog);

	std::cout << std::endl;

	copyDog->getBrain()->setIdea("haha!!", 3);

	for (int i = 0; i < 10; i++)
		std::cout << dog->getBrain()->getIdea(i) << ":";
	std::cout << std::endl;
	for (int i = 0; i < 10; i++)
		std::cout << cat->getBrain()->getIdea(i) << ":";
	std::cout << std::endl;

	std::cout << std::endl;

	for (int i = 0; i < 10; i++)
		std::cout << copyDog->getBrain()->getIdea(i) << ":";
	std::cout << std::endl;

	std::cout << std::endl;

	delete copyDog;
	delete cat;
	delete dog;
}

int main() {
	// atexit(leak_test);
	test1();

	std::cout << std::endl;
	
	test2();

	std::cout << std::endl;

	test3();

	return 0;
}
