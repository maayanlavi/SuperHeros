#include "AnimalBasedSuperHero.h"
#include "Spiderman.h"
#include "CaptainSpider.h"

AnimalBasedSuperHero::AnimalBasedSuperHero() : SuperHero()
{
	_animal = NULL;
}

AnimalBasedSuperHero::AnimalBasedSuperHero(const char* name, double age, bool radioactive,
	const char* animal) : SuperHero(name, age, radioactive)
{
	if (animal != nullptr)
	{
		int n = strlen(animal);
		_animal = new char[n + 1];
		_animal[n] = '\0';
		strcpy(_animal, animal);
	}
}


AnimalBasedSuperHero::AnimalBasedSuperHero(const char* animal) : SuperHero()
{
	if (animal != nullptr)
	{
		int n = strlen(animal);
		_animal = new char[n + 1];
		_animal[n] = '\0';
		strcpy(_animal, animal);
	}
}

AnimalBasedSuperHero::AnimalBasedSuperHero(const AnimalBasedSuperHero& animalBasedSuperHero)
	: SuperHero(animalBasedSuperHero)
{
	int n = strlen(animalBasedSuperHero._animal);
	_animal = new char[n + 1];
	_animal[n] = '\0';
	strcpy(_animal, animalBasedSuperHero._animal);

}

AnimalBasedSuperHero::~AnimalBasedSuperHero()
{
	delete[] _animal;
}

void AnimalBasedSuperHero::setAnimal(const char* animal)
{
	if (animal != _animal && _animal != NULL && animal != NULL)
	{
		int n = strlen(animal);
		_animal = new char[n + 1];
		_animal[n] = '\0';
		strcpy(_animal, animal);
	}
}

const char* AnimalBasedSuperHero::getAnimal() const
{
	return _animal;
}

void AnimalBasedSuperHero::load(ifstream& in_file)
{
	SuperHero::load(in_file);
	in_file.read((char*)&_animal, sizeof(_animal));

	in_file.close();
}

void AnimalBasedSuperHero::save(ofstream& out_file) const
{
	SuperHero::save(out_file);
	out_file.write((char*)&_animal, sizeof(_animal));
	out_file.close();
}
