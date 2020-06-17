#include "CaptainAmerica.h"
#include "CaptainSpider.h"

CaptainAmerica::CaptainAmerica() : ProfessionBasedSuperHero()
{
	_ageIncludingFreezing = 0;
}

CaptainAmerica::CaptainAmerica(const char* name, double age, bool radioactive, const char* profession,
	int yearsExperience, double ageIncludingFreezing) : ProfessionBasedSuperHero(profession, yearsExperience)
{
	SuperHero::	setName(name);
	SuperHero::	setAge(age);
	SuperHero::setRadioactive(radioactive);
	if (ageIncludingFreezing > age)
		_ageIncludingFreezing = ageIncludingFreezing;
	else 
		_ageIncludingFreezing = 0;
}

CaptainAmerica::CaptainAmerica(const char* profession, int yearsExperience, double ageIncludingFreezing)
	: ProfessionBasedSuperHero(profession, yearsExperience) 
{
	if (ageIncludingFreezing > 0)
		_ageIncludingFreezing = ageIncludingFreezing;
	else
		_ageIncludingFreezing = 0;
}

CaptainAmerica::CaptainAmerica(double ageIncludingFreezing) : ProfessionBasedSuperHero()
{
	if (ageIncludingFreezing > 0)
		_ageIncludingFreezing = ageIncludingFreezing;
	else
		_ageIncludingFreezing = 0;
}

CaptainAmerica::CaptainAmerica(const CaptainAmerica& captainAmerica): ProfessionBasedSuperHero(captainAmerica)
{
	_ageIncludingFreezing = captainAmerica._ageIncludingFreezing;
}

CaptainAmerica::~CaptainAmerica()
{

}

double CaptainAmerica:: getAgeIncludingFreezing() const
{
	return _ageIncludingFreezing;
}

void CaptainAmerica::setAgeIncludingFreezing(double ageIncludingFreezing)
{
	if (ageIncludingFreezing > _age)
		_ageIncludingFreezing = ageIncludingFreezing;
}

void CaptainAmerica::load(ifstream& in_file)
{
	ProfessionBasedSuperHero::load(in_file);
	in_file.read((char*)&_ageIncludingFreezing, sizeof(_ageIncludingFreezing));

	in_file.close();
}

void CaptainAmerica::save(ofstream& outfile) const
{
	ProfessionBasedSuperHero::save(outfile);
	outfile.write((char*)&_ageIncludingFreezing, sizeof(_ageIncludingFreezing));

	outfile.close();
}
