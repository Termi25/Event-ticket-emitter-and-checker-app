#pragma once
#include <cstdlib>
#include<iostream>
#include<fstream>
#include<string>
using namespace std;


class Locatie {
protected: 
	int nr_locuri,nr_randuri,nr_zone,nr_locuri_total;
	int*** scaun;

public:

	Locatie()
	{
		nr_locuri_total = 0;
		nr_locuri = 0;
		nr_randuri = 0;
		nr_zone = 0;
		scaun = nullptr;
	}

	Locatie(int Nr_loc, int Nr_rand, int Nr_zone, int nr_locuri_total, int*** Scaune)
	{
		this->nr_locuri = Nr_loc;
		this->nr_randuri = Nr_rand;
		this->nr_zone = Nr_zone;
		this->nr_locuri_total = nr_locuri_total;
		if (Nr_zone > 0 && Nr_loc > 0 && Nr_rand > 0 && Scaune != nullptr)
		{
			scaun = new int** [Nr_zone];
			for (int i = 0; i < Nr_zone; i++)
			{
				scaun[i] = new int* [Nr_rand];
			}
			for (int i = 0; i < Nr_zone; i++)
			{
				for (int j = 0; j < Nr_rand; j++)
				{
					scaun[i][j] = new int[Nr_loc];
				}
			}
			for (int i = 0; i < Nr_zone; i++)
			{
				for (int j = 0; j < Nr_rand; j++)
				{
					for (int g = 0; g < Nr_loc; g++)
					{
						scaun[i][j][g] = Scaune[i][j][g];
					}
				}
			}
		}
		else
		{
			scaun = nullptr;
			cout << "Datele introduse pentru locatie sunt eronate." << endl;
		}
	}

	~Locatie()
	{
		if (nr_zone > 0 && nr_locuri > 0 && nr_randuri > 0 && scaun != nullptr)
		{
			for (int i = 0; i < nr_zone; i++)
			{
				for (int j = 0; j < nr_randuri; j++)
				{
					delete[] scaun[i][j];
				}
			}
			for (int i = 0; i < nr_zone; i++)
			{
				delete[] scaun[i];
			}
			delete[] scaun;
			scaun = nullptr;
		}
	}

	Locatie(const Locatie& locatie)
	{
		this->nr_locuri = locatie.nr_locuri;
		this->nr_randuri = locatie.nr_randuri;
		this->nr_zone = locatie.nr_zone;
		this->nr_locuri_total = locatie.nr_locuri_total;
		if (nr_zone > 0 && nr_locuri > 0 && nr_randuri > 0 && locatie.scaun != nullptr)
		{
			scaun = new int** [nr_zone];
			for (int i = 0; i < nr_zone; i++)
			{
				scaun[i] = new int* [nr_randuri];
			}
			for (int i = 0; i < nr_zone; i++)
			{
				for (int j = 0; j < nr_randuri; j++)
				{
					scaun[i][j] = new int[nr_locuri];
				}
			}
			for (int i = 0; i < nr_zone; i++)
			{
				for (int j = 0; j < nr_randuri; j++)
				{
					for (int g = 0; g < nr_locuri; g++)
					{
						scaun[i][j][g] = locatie.scaun[i][j][g];
					}
				}
			}
		}
		else
		{
			scaun = nullptr;
			cout << "Datele copiate din clasa data nu genereaza tabloul de scaune ale locatiei" << endl;
		}
	}

/*
 	int nr_locuri,nr_randuri,nr_zone;
	int*** scaun;
*/
	int getNr_locuri()
	{
		return nr_locuri;
	}

	int getNr_randuri()
	{
		return nr_randuri;
	}

	int getNr_zone()
	{
		return nr_zone;
	}

	int getScaun(int zona, int rand,int loc)
	{
		if (zona < 0 || rand < 0 || loc < 0)
		{
			throw exception("Coordonatele scaunului sunt gresite, incercati din nou.");
		}
		else
		{
			int status_scaun = scaun[zona][rand][loc];
			return status_scaun;
		}
	}

/*
	int nr_locuri,nr_randuri,nr_zone;
	int*** scaun;
*/

	void setNr_locuri(int x)
	{
		this->nr_locuri = x;
		cout << "Setat" << endl;
	}

	void setNr_randuri(int x)
	{
		this->nr_randuri = x;
		cout << "Setat" << endl;
	}

	void setNr_zone(int x)
	{
		this->nr_zone = x;
		cout << "Setat" << endl;
	}

	void setScaune(int*** vector, int z, int r, int l)
	{
		if (vector == nullptr || z < 0 || r < 0 || l < 0)
		{
			cout << "Valori gresite" << endl;
		}
		else
		{
			for (int i = 0; i < nr_zone; i++)
			{
				for (int j = 0; j < nr_randuri; j++)
				{
					delete[] scaun[i][j];
				}
			}
			for (int i = 0; i < nr_zone; i++)
			{
				delete[] scaun[i];
			}
			delete[] scaun;

			this->nr_zone = z;
			this->nr_randuri = r;
			this->nr_locuri = l;

			scaun = new int** [nr_zone];
			for (int i = 0; i < nr_zone; i++)
			{
				scaun[i] = new int* [nr_randuri];
			}
			for (int i = 0; i < nr_zone; i++)
			{
				for (int j = 0; j < nr_randuri; j++)
				{
					scaun[i][j] = new int[nr_locuri];
				}
			}
			for (int i = 0; i < nr_zone; i++)
			{
				for (int j = 0; j < nr_randuri; j++)
				{
					for (int g = 0; g < nr_locuri; g++)
					{
						scaun[i][j][g] = vector[i][j][g];
					}
				}
			}
			cout << "Setat" << endl;
		}
		
	}

};

class Eveniment : public Locatie
{
protected:
	string data_eveniment, ora_eveniment, denumire,tip_eveniment;
	float durata;
	string* nume_zone;

public:

	Eveniment()
	{

		data_eveniment = "";
		ora_eveniment = "";
		denumire = "";
		tip_eveniment = "";
		durata = 0.0f;
		nume_zone = nullptr;
	}

	Eveniment(string data_eveniment, string ora_eveniment, string denumire, string tip_eveniment, char* cod_eveniment)
	{
		this->data_eveniment = data_eveniment;
		this->ora_eveniment = ora_eveniment;
	}
	
};

class Bilet: public Eveniment
{
private:
	int nr_locB, nr_randB, nr_zonaB;
	string nume;
	string prenume;
	const int ID;

	int creareID()
	{
			srand((unsigned)time(NULL));
			return rand();
	}

public:

	Bilet() :ID(creareID()) {

		nr_locB = 0;
		nr_randB = 0;
		nr_zonaB = 0;
		nume = "";
		prenume = "";
	}

	Bilet(int Nr_locB, int Nr_randB, int Nr_zonaB, string Nume, string Prenume) :ID(creareID()) {
		this->nr_locB = Nr_locB;
		this->nr_randB = Nr_randB;
		this->nr_zonaB = Nr_zonaB;
		this->nume = Nume;
		this->prenume = Prenume;
	}

	static float IDMediu_Bilet(Bilet* bilete, int nrBilete)
	{
		float mediu = 0.0f;
		for (int i = 0; i < nrBilete; i++)
		{
			mediu = mediu + bilete[i].ID;
		}
		return mediu / nrBilete;
	}
};