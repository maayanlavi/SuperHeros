#include "ProfessionBasedSuperHero.h"
#include "CaptainAmerica.h"
#include "CaptainSpider.h"


ProfessionBasedSuperHero::ProfessionBasedSuperHero() : SuperHero()
{
	_yearsExperience = 0;
	_profession = NULL;
}

ProfessionBasedSuperHero::ProfessionBasedSuperHero(const char* name, double age, bool radioactive,
	const char* profession, int yearsExperience) : SuperHero(name, age, radioactive)
{
	_yearsExperience = yearsExperience;
	int n = strlen(profession);
	_profession = new char[n + 1];
	_profession[n] = '\0';
	strcpy(_profession, profession);
}

ProfessionBasedSuperHero::ProfessionBasedSuperHero(const char* profession, int yearsExperience)
	:SuperHero()
{
	_yearsExperience = yearsExperience;
	if (profession != nullptr)
	{
		int n = strlen(profession);
		_profession = new char[n + 1];
		_profession[n] = '\0';
		strcpy(_profession, profession);
	}

}

ProfessionBasedSuperHero::ProfessionBasedSuperHero(const ProfessionBasedSuperHero& ProfessionBasedSuperHero)
	:SuperHero(ProfessionBasedSuperHero)
{
	_yearsExperience = ProfessionBasedSuperHero._yearsExperience;
	int n = strlen(ProfessionBasedSuperHero._profession);
	_profession = new char[n + 1];
	_profession[n] = '\0';
	strcpy(_profession, ProfessionBasedSuperHero._profession);
}

ProfessionBasedSuperHero::~ProfessionBasedSuperHero()
{
	delete[] _profession;
}

void ProfessionBasedSuperHero::setProfession(const char* profession)
{
	if (_profession != NULL && profession != NULL && _profession != profession)
	{
		int n = strlen(profession);
		_profession = new char[n + 1];
		_profession[n] = '\0';
		strcpy(_profession, profession);
	}
}

void ProfessionBasedSuperHero::setYearsExperience(int yearsExperience)
{
	if (yearsExperience>=0)
	_yearsExperience = yearsExperience;
}

int ProfessionBasedSuperHero::getYearsExperience() const
{
	
return _yearsExperience;
}

void ProfessionBasedSuperHero::load(ifstream& in_file)
{
	SuperHero::load(in_file);
	in_file.read((char*)&_yearsExperience, sizeof(_yearsExperience));
	in_file.read((char*)&_profession, sizeof(_profession));

	in_file.close();
}

void ProfessionBasedSuperHero::save(ofstream& out_file) const
{
	SuperHero::save(out_file);
	out_file.write((char*)&_yearsExperience, sizeof(_yearsExperience));
	out_file.write((char*)&_profession, sizeof(_profession));

	out_file.close();
}

