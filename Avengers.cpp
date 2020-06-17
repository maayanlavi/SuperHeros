#include "Avengers.h"

Avengers::Avengers()
{
	_superHeros = NULL;
	_numSuperHeros = 0;
}

Avengers::~Avengers()
{
	delete[] _superHeros;
}


void Avengers::saveType(ofstream& out, const SuperHero* hero) const
{
	char type[2];
	if (typeid(*hero) == typeid(SuperHero))
	{
		type[0] = 'S';
		type[1] = 'H';
		type[2] = '\0';
	}
	if (typeid(*hero) == typeid(ProfessionBasedSuperHero))
	{
		type[0] = 'P';
		type[1] = 'B';
		type[2] = '\0';
	}
	if (typeid(*hero) == typeid(AnimalBasedSuperHero))
	{
		type[0] = 'A';
		type[1] = 'B';
		type[2] = '\0';
	}
	if (typeid(*hero) == typeid(CaptainAmerica))
	{
		type[0] = 'C';
		type[1] = 'A';
		type[2] = '\0';
	}
	if (typeid(*hero) == typeid(Spiderman))
	{
		type[0] = 'S';
		type[1] = 'P';
		type[2] = '\0';
	}
	if (typeid(*hero) == typeid(CaptainSpider))
	{
		type[0] = 'C';
		type[1] = 'S';
		type[2] = '\0';
	}

	out.write((char*)&type, 2);
}

void Avengers::save(ofstream& out) const
{
	out.write((char*)&_numSuperHeros, sizeof(_numSuperHeros));
	for (int i = 0; i < _numSuperHeros; ++i)
	{
		saveType(out, _superHeros[i]);
		_superHeros[i]->save(out);
	}

	out.close();

}

void Avengers::load(ifstream& in)
{
	char type[2];
	in.read((char*)&_numSuperHeros, sizeof(_numSuperHeros));
	SuperHero** SuperHerosFronFile = new SuperHero * [_numSuperHeros];
	for (int i = 0; i < _numSuperHeros; ++i)
	{
		in.read((char*)type, 2);
		type[2] = '\0';
		if (strcmp(type, "SH") == 0)
			SuperHerosFronFile[i] = new SuperHero;
		if (strcmp(type, "AB") == 0)
			SuperHerosFronFile[i] = new AnimalBasedSuperHero;
		if (strcmp(type, "SP") == 0)
			SuperHerosFronFile[i] = new Spiderman;
		if (strcmp(type, "PB") == 0)
			SuperHerosFronFile[i] = new ProfessionBasedSuperHero;
		if (strcmp(type, "CA") == 0)
			SuperHerosFronFile[i] = new CaptainAmerica;
		if (strcmp(type, "CS") == 0)
			SuperHerosFronFile[i] = new CaptainSpider;

		SuperHerosFronFile[i]->load(in);
	}

	in.close();

}

void Avengers::setSuperHeros(SuperHero** superHeros, int size)
{
	_superHeros = new SuperHero * [size];
	for (int i = 0; i < size; ++i)
	{
		if (typeid(*superHeros[i]) == typeid(ProfessionBasedSuperHero))
		{
			ProfessionBasedSuperHero* t = dynamic_cast<ProfessionBasedSuperHero*>(superHeros[i]);
			_superHeros[i] = new ProfessionBasedSuperHero(*t);
		}

		if (typeid(*superHeros[i]) == typeid(AnimalBasedSuperHero))
		{
			AnimalBasedSuperHero* t = dynamic_cast<AnimalBasedSuperHero*>(superHeros[i]);
			_superHeros[i] = new AnimalBasedSuperHero(*t);
		}

		if (typeid(*superHeros[i]) == typeid(CaptainAmerica))
		{
			CaptainAmerica* t = dynamic_cast<CaptainAmerica*>(superHeros[i]);
			_superHeros[i] = new CaptainAmerica(*t);
		}

		if (typeid(*superHeros[i]) == typeid(Spiderman))
		{
			Spiderman* t = dynamic_cast<Spiderman*>(superHeros[i]);
			_superHeros[i] = new Spiderman(*t);
		}

		if (typeid(*superHeros[i]) == typeid(CaptainSpider))
		{
			CaptainSpider* t = dynamic_cast<CaptainSpider*>(superHeros[i]);
			_superHeros[i] = new CaptainSpider(*t);
		}
		
	}
}

SuperHero** Avengers::getSuperHeros() const
{
	return _superHeros;
}





