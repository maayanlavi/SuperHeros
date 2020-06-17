#include "Spiderman.h"
#include "CaptainSpider.h"

Spiderman::Spiderman() : AnimalBasedSuperHero()
{
	_webSize = 0;
}

Spiderman::Spiderman(const char* name, double age, bool radioactive, const char* animal, double webSize)
	: AnimalBasedSuperHero(animal)
{
	SuperHero::setName(name);
	SuperHero::setAge(age);
	SuperHero::setRadioactive(radioactive);
	_webSize = webSize;
}

Spiderman::Spiderman(const char* animal, double webSize) : AnimalBasedSuperHero(animal)
{
		_webSize = webSize;
}

Spiderman::Spiderman(double webSize) : AnimalBasedSuperHero()
{
		_webSize = webSize;
}

Spiderman::Spiderman(const Spiderman& spiderman):AnimalBasedSuperHero(spiderman)
{
	_webSize = spiderman._webSize;
}

Spiderman::~Spiderman()
{

}

double Spiderman::getWebSize() const
{
	return _webSize;
}

void Spiderman::setWebSize(double webSize)
{
	if (webSize >= 0)
		_webSize = webSize;
}

void Spiderman::load(ifstream& in_file)
{
	AnimalBasedSuperHero::load(in_file);
	in_file.read((char*)&_webSize, sizeof(_webSize));

	in_file.close();
}

void Spiderman::save(ofstream& out_file) const
{
	AnimalBasedSuperHero::save(out_file);
	out_file.write((char*)&_webSize, sizeof(_webSize));

	out_file.close();
}
