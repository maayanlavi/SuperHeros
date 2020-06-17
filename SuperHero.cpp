#include "SuperHero.h"
#include "AnimalBasedSuperHero.h"
#include "ProfessionBasedSuperHero.h"
#include "Spiderman.h"
#include "CaptainAmerica.h"
#include "CaptainSpider.h"

SuperHero::SuperHero()
{
	_name = NULL;
	_age = 0;
	_radioactive = true;
}

SuperHero::SuperHero(const char* name, double age, bool radioactive)
{
	if (name != nullptr)
	{
		int n = strlen(name);
		_name = new char[n + 1];
		_name[n]='\0';
		strcpy(_name, name);
	}
	if (age>=0)
		_age = age;
	_radioactive = radioactive;
}

SuperHero::SuperHero(const SuperHero& superHero)
{
	_age = superHero._age;
	_radioactive = superHero._radioactive;
	if (superHero._name != nullptr)
	{
		int n = strlen(superHero._name);
		_name = new char[n + 1];
		_name[n] = '\0';
		strcpy(_name, superHero._name);
	}
}

SuperHero::~SuperHero()
{
	delete[] _name;
}

const char* SuperHero::getName() const
{
	return _name;
}

double SuperHero::getAge() const
{
	return _age;
}

bool SuperHero::getRadioactive() const
{
	return _radioactive;
}

void SuperHero::setName(const char* Name)
{
	if (Name != _name && Name!= NULL)
	{
		int n = strlen(Name);
		_name = new char[n + 1];
		_name[n] = '\0';
		strcpy(_name, Name);
	}
}

void SuperHero::setAge(double age)
{
	if (age>=15 && age<=40)
		_age = age;
}

void SuperHero::setRadioactive(bool radioactive)
{
	_radioactive = radioactive;
}

void SuperHero::load(ifstream& in_file)	//virtual
{
	int n=strlen(_name);
	in_file.read((char*)&n, sizeof(n));
	_name = new char[n + 1];
	_name[n] = '\0';
	in_file.read(_name, n);
	_name[n] = '\0';
	in_file.read((char*)&_age, sizeof(_age));
	in_file.read((char*)&_radioactive, sizeof(_radioactive));

	in_file.close();
	delete[] _name;
}

void SuperHero::save(ofstream& out_file) const	//virtual
{
	int n = strlen(_name);
	out_file.write((const char*)&n, sizeof(n));
	out_file.write(_name, n);
	out_file.write((const char*)&_age, sizeof(_age));
	out_file.write((const char*)&_radioactive, sizeof(_radioactive));

	out_file.close();

}
