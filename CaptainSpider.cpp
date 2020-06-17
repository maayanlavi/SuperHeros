#include "CaptainSpider.h"

CaptainSpider::CaptainSpider() : Spiderman(), CaptainAmerica()
{

}

CaptainSpider::CaptainSpider(const char* name, double age, bool radioactive, const char* profession,
	int yearsExperience, double ageIncludingFreezing, const char* animal, double webSize) :
	Spiderman(animal, webSize), CaptainAmerica(profession,yearsExperience, ageIncludingFreezing)
{
	SuperHero::setName(name);
	SuperHero::setAge(age);
	SuperHero::setRadioactive(radioactive);

}

CaptainSpider::CaptainSpider(const char* profession, int yearsExperience, double ageIncludingFreezing, 
	const char* animal, double webSize) : Spiderman(animal, webSize), CaptainAmerica(profession,
		yearsExperience, ageIncludingFreezing)
{
	
}

CaptainSpider::CaptainSpider(double ageIncludingFreezing, double webSize) : Spiderman(webSize),
CaptainAmerica(ageIncludingFreezing)
{

}

CaptainSpider::CaptainSpider(const CaptainSpider& captainSpider) : Spiderman(getName(),getAge(), getRadioactive(), getAnimal(), getWebSize()), 
CaptainAmerica(getProfession(), getYearsExperience(),
		getAgeIncludingFreezing())
{

}

CaptainSpider::~CaptainSpider() 
{

}

void CaptainSpider::load(ifstream& in_file)
{
	SuperHero::load(in_file);
	CaptainAmerica::load(in_file);
	Spiderman::load(in_file);

	cout << _name << _age;

	in_file.close();
}

void CaptainSpider::save(ofstream& out_file) const
{
	SuperHero::save(out_file);
	CaptainAmerica::save(out_file);
	Spiderman::save(out_file);

	out_file.close();
}




