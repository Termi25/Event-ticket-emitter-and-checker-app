#pragma once
//proiect realizat de Rusu MC Marius-Ioan pentru ASE CSIE Anul 2, semestrul 1 in anul 2022
#include <cstdlib>
#include <stdlib.h>
#include<iostream>
#include<fstream>
#include<string>
using namespace std;

class ObiectIdentitate
{
public:
	virtual int creareID() = 0;
};

class Locatie : public ObiectIdentitate {
private:
	int nr_locuri, nr_randuri, nr_zone, nr_locuri_total;
	int*** scaun=nullptr;
	string adresa;
	const int ID;

public:

	int creareID()
	{
		srand((unsigned)time(NULL));
		return rand();
	}

	Locatie() :ID(creareID())
	{
		nr_locuri_total = 0;
		nr_locuri = 0;
		nr_randuri = 0;
		nr_zone = 0;
		scaun = nullptr;
		adresa = 'P';
	}

	Locatie(int Nr_loc, int Nr_rand, int Nr_zone, int nr_locuri_total, int*** Scaune, string adresa) :ID(creareID())
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
		this->adresa = adresa;
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

	Locatie(const Locatie& locatie) :ID(creareID())
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
		this->adresa = locatie.adresa;
	}

	/*
		int nr_locuri,nr_randuri,nr_zone,nr_locuri_total;
		int*** scaun;
		string adresa;
		const int ID;
	*/
	int getNr_locuri()
	{
		return this->nr_locuri;
	}

	int getNr_randuri()
	{
		return this->nr_randuri;
	}

	int getNr_zone()
	{
		return this->nr_zone;
	}

	int getNr_locuri_total()
	{
		return this->nr_locuri_total;
	}

	int getScaun(int zona, int rand, int loc)
	{
		if (zona < 0 || rand < 0 || loc < 0)
		{
			throw exception("Coordonatele scaunului sunt gresite, incercati din nou.");
		}
		else
		{
			if (scaun != nullptr && zona<nr_zone && rand<nr_randuri && loc < nr_locuri)
			{
				int status_scaun = 0;
				status_scaun=scaun[zona][rand][loc];
				return status_scaun;
			}
			else
			{
				return -1;
				cout << "Tablou locuri inexistent";
			}
		}
	}

	string getAdresa()
	{
		return this->adresa;
	}

	int getID()
	{
		return this->ID;
	}
	/*
		int nr_locuri,nr_randuri,nr_zone,nr_locuri_total;
		int*** scaun;
		string adresa;
		const int ID;
	*/

	void setNr_locuri(int x)
	{
		if (x > 0)
		{
			this->nr_locuri = x;
			cout << "Setat" << endl;
		}
		else
		{
			cout << " Valoarea introdusa este invalida" << endl;
		}
	}

	void setNr_randuri(int x)
	{
		if (x > 0)
		{
			this->nr_randuri = x;
			cout << "Setat" << endl;
		}
		else
		{
			cout << " Valoarea introdusa este invalida" << endl;
		}
	}

	void setNr_zone(int x)
	{
		if (x > 0)
		{
			this->nr_zone = x;
			cout << "Setat" << endl;
		}
		else
		{
			cout << " Valoarea introdusa este invalida" << endl;
		}
	}

	void setNr_locuri_total(int x)
	{
		if (x > 0)
		{
			this->nr_locuri_total = x;
			cout << "Nr locuri total setat la " << nr_locuri_total<< endl;
		}
		else
		{
			cout << " Valoarea introdusa este invalida" << endl;
		}
	}

	void setScaun(int z, int r, int l, int status)
	{
		if (z >= 0 && z < nr_zone && r >= 0 && r < nr_randuri && l >= 0 && l < nr_locuri && scaun!=nullptr)
		{
			scaun[z][r][l] = status;
		}
		else
		{
			cout << "Date invalide" << endl;
		}
	}

	void setScaune(int*** vector, int z, int r, int l)
	{
		if (vector == nullptr || z < 0 || r < 0 || l < 0)
		{
			cout << "Valori gresite" << endl;
		}
		else
		{
			if (this->scaun != nullptr && nr_locuri>0 && nr_zone>0 && nr_randuri>0)
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

			this->nr_zone=z;
			this->nr_randuri=r;
			this->nr_locuri=l;

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

	void setAdresa(string dcp)
	{
		this->adresa = dcp;
	}

	/*
		int nr_locuri,nr_randuri,nr_zone,nr_locuri_total;
		int*** scaun;
		string adresa;
	*/

	int nr_locuriVerificare()
	{
		if (nr_locuri <= 0 || nr_randuri <= 0 || nr_zone <= 0 || nr_locuri_total <= 0)
		{
			return 0;
		}
		else
		{
			if (nr_locuri * nr_randuri * nr_zone == nr_locuri_total)
			{
				return 1;
			}
			else
			{
				return 0;
			}
		}
	}

	int nr_locuri_totalGenerare()
	{
		if (nr_locuri <= 0 || nr_randuri <= 0 || nr_zone <= 0)
		{
			return 0;
		}
		else
		{
			return nr_randuri * nr_locuri * nr_zone;
		}
	}

	int nr_locuri_libere()
	{
		if (nr_locuri <= 0 || nr_randuri <= 0 || nr_zone <= 0 || scaun == nullptr)
		{
			cout << endl << "Nu exista tabel de scaune pentru aceasta locatie." << endl;
			return -1;
		}
		else
		{
			int k = 0;
			for (int i = 0; i < nr_zone; i++)
			{
				for (int j = 0; j < nr_randuri; j++)
				{
					for (int g = 0; g < nr_locuri; g++)
					{
						if (scaun[i][j][g] == 0)
						{
							k=k+1;
						}
					}
				}
			}
			return k;
		}
	}


	Locatie operator=(const Locatie& locatie)
	{
		nr_locuri = locatie.nr_locuri;
		nr_randuri = locatie.nr_randuri;
		nr_zone = locatie.nr_zone;
		nr_locuri_total = locatie.nr_locuri_total;
		if (nr_zone > 0 && nr_locuri > 0 && nr_randuri > 0)
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
			cout << "Datele copiate din clasa data nu genereaza tabloul de scaune ale locatiei" << endl;
		}
		this->adresa = locatie.adresa;
		return *this;
	}

	bool operator!()
	{
		return nr_locuri_total != 0;
	}

	friend Locatie operator+(int, Locatie);
	friend ostream& operator<<(ostream&, Locatie);
	friend istream& operator>>(istream&, Locatie&);
};

Locatie operator+(int x, Locatie t2)
{
	if (x >= 0)
	{
		t2.setNr_zone(t2.getNr_zone() + x);
		return t2;
	}
	return t2;
}


/*
	int nr_locuri,nr_randuri,nr_zone,nr_locuri_total;
	int*** scaun;
	string adresa;
*/

ostream& operator<<(ostream& out, Locatie t2)
{
	out << "Adresa locatiei: " << t2.getAdresa() << endl;
	out << "Numar locuri total locatie: " << t2.getNr_locuri_total() << endl;
	out << "Numar locuri per rand locatie: " << t2.getNr_locuri() << endl;
	out << "Numar randuri locatie: " << t2.getNr_randuri() << endl;
	out << "Numar zone locatie: " << t2.getNr_zone() << endl;
	out << "Tablou status locuri: " << endl;
	for (int i = 0; i < t2.getNr_zone(); i++)
	{
		for (int j = 0; j < t2.getNr_randuri(); j++)
		{
			for (int g = 0; g < t2.getNr_locuri(); g++)
			{
				out <<"  "<<'['<< i + 1 << j + 1 << g + 1 << ']'<<"  ";
			}
			out << endl;
			for (int g = 0; g < t2.getNr_locuri(); g++)
			{
				out << "   " <<'['<< t2.getScaun(g, j, i) % 10 <<']'<< "   ";
			}
			out << endl;
		}
		return out;
	}
	return out;
}

istream& operator>>(istream& in, Locatie& t2)
{
	int x=0,z=0,w=0,k=0;
	string y;
	cout << "Adresa locatiei: ";
	in >> ws;
	getline(in,y);
	t2.setAdresa(y);


	cout << " Numar locuri per rand locatie: ";
	in >> x;
	while (x <= 0)
	{
		cout << " Numar locuri per rand locatie: ";
		in >> x;
		if (x <= 0)
		{
			cout << "Valoare gresita, introduceti din nou";
		}
		system("cls");
	}
	if (x > 0)
	{
		t2.setNr_locuri(x);
	}
	cout << endl;

	cout << " Numar randuri locatie: ";
	in >> w;
	while (w <= 0)
	{
		cout << " Numar randuri locatie: ";
		in >> w;
		if (w <= 0)
		{
			cout << "Valoare gresita, introduceti din nou";
		}
		system("cls");
	}
	if (w > 0)
	{
		t2.setNr_randuri(w);
	}
	cout << endl;

	cout << " Numar zone locatie: ";
	in >> z;
	while (z <= 0)
	{
		cout << " Numar zone locatie: ";
		in >> z;
		if (z <= 0)
		{
			cout << "Valoare gresita, introduceti din nou";
		}
		system("cls");
	}
	if (z > 0)
	{
		t2.setNr_zone(z);
	}
	cout << endl;

	k = t2.nr_locuri_totalGenerare();
	t2.setNr_locuri_total(k);

	cout << endl <<"Doriti sa adaugati un tablou gol sau sa introduceti manual biletele deja generate ?" << endl;
	cout << "1) Tablou gol" << endl << "2) Tablou generat" << endl;
	cout << "Scrieti aici optiunea (1/2): ";
	cin >> x;

	int*** input_tablou = new int** [t2.getNr_zone()];
	for (int i = 0; i < t2.getNr_zone(); i++)
	{
		*(input_tablou + i) = new int* [t2.getNr_randuri()];
	}
	for (int i = 0; i < t2.getNr_zone(); i++)
	{
		for (int j = 0; j < t2.getNr_randuri(); j++)
		{
			*(*(input_tablou + i) + j) = new int[t2.getNr_locuri()];
		}
	}

	if (x == 2)
	{
		cout << "Tablou status locuri (daca un loc nu are un bilet asociat, se va introduce valoarea 0): " << endl;
	
		for (int i = 0; i < t2.getNr_zone(); i++)
		{
			for (int j = 0; j < t2.getNr_randuri(); j++)
			{
				for (int g = 0; g < t2.getNr_locuri(); g++)
				{
					cout << "   " << '[' << i + 1 << j + 1 << g + 1 << ']' << "- bilet asociat:";
					in >> *(*(*(input_tablou + i) + j) + g);
				}
				cout << endl;
			}
			cout << endl;
		}
	}
	else
	{
		cout << "Tablou status locuri: " << endl;
		for (int i = 0; i < t2.getNr_zone(); i++)
		{
			for (int j = 0; j < t2.getNr_randuri(); j++)
			{
				for (int g = 0; g < t2.getNr_locuri(); g++)
				{
					cout << "   " << '[' << i + 1 << j + 1 << g + 1 << ']' << "    ";
					input_tablou[i][j][g] =(int) 0;
				}
				cout << endl;
				for (int g = 0; g < t2.getNr_locuri(); g++)
				{
					cout << "    " << '[' << '0' << ']' << "    ";
				}
				cout << endl;
			}
			cout << endl;
		}
	}
	
	t2.setScaune(input_tablou,t2.getNr_zone(), t2.getNr_randuri(), t2.getNr_locuri());
	return in;
}

class Eveniment : public ObiectIdentitate
{
private:
	string data_eveniment, ora_eveniment, denumire, tip_eveniment;
	float durata;
	string* nume_zone;
	int nr_zone;
	const int ID;

public:

	int creareID()
	{
		srand((unsigned)time(NULL));
		return rand();
	}

	Eveniment():ID(creareID())
	{

		data_eveniment = "";
		ora_eveniment = "";
		denumire = "";
		tip_eveniment = "";
		durata = 0.0f;
		nume_zone = nullptr;
	}
/*string data_eveniment, ora_eveniment, denumire,tip_eveniment;
	float durata;
	string* nume_zone;
*/
	Eveniment(string data_eveniment, string ora_eveniment, string denumire, string tip_eveniment, float durata, string* nume_zoneB,int nr_zone):ID(creareID())
	{
		this->data_eveniment = data_eveniment;
		this->ora_eveniment = ora_eveniment;
		this->denumire = denumire;
		this->tip_eveniment = tip_eveniment;
		this->durata = durata;
		if (nr_zone > 0 && nume_zoneB!=nullptr)
		{
			this->nr_zone=nr_zone;
			this->nume_zone = new string[nr_zone];
			for (int i = 0; i < nr_zone; i++)
			{
				nume_zone[i] = nume_zoneB[i];
			}
		}
		else
		{
			if (nr_zone > 0)
			{
				this->nr_zone=nr_zone;
			}
			this->nume_zone = nullptr;
		}
	}

	~Eveniment()
	{
		if (nume_zone != nullptr)
		{
			delete[] nume_zone;
			nume_zone = nullptr;
		}
	}

	Eveniment(const Eveniment& eveniment) :ID(creareID())
	{
		this->data_eveniment =eveniment.data_eveniment;
		this->ora_eveniment = eveniment.ora_eveniment;
		this->denumire = eveniment.denumire;
		this->tip_eveniment = eveniment.tip_eveniment;
		this->durata = eveniment.durata;
		if (eveniment.nume_zone != nullptr && eveniment.nr_zone>0)
		{
			delete[] nume_zone;
			this->nr_zone = eveniment.nr_zone;
			this->nume_zone = new string[eveniment.nr_zone];
			for (int i = 0; i < nr_zone; i++)
			{
				this->nume_zone[i] = eveniment.nume_zone[i];
			}
		}
		else
		{
			this->nume_zone=nullptr;
		}
	}
/*
	string data_eveniment, ora_eveniment, denumire,tip_eveniment;
	float durata;
	string* nume_zone;
	int nr_zone;
*/
	string getData_ev()
	{
		return this->data_eveniment;
	}

	string getOra_ev()
	{
		return this->ora_eveniment;
	}

	string getDenumire_ev()
	{
		return this->denumire;
	}

	string getTip_ev()
	{
		return this->tip_eveniment;
	}

	float getDurata_ev()
	{
		return this->durata;
	}

	string getNume_zona(int index)
	{
		if (index >= 0 && index < nr_zone)
		{
			return this->nume_zone[index];
		}
		return "INVALID";
	}

	int getNr_zone()
	{
		return nr_zone;
	}

	const int getID()
	{
		return ID;
	}
/*
	string data_eveniment, ora_eveniment, denumire,tip_eveniment;
	float durata;
	string* nume_zone;
	int nr_zone;
	const int ID;
*/

	void setData_ev(string data_evC)
	{
		this->data_eveniment = data_evC;
	}

	void setOra_ev(string ora_evC)
	{
		if (ora_evC.length() >= 4 && ora_evC.length() <= 5)
		{
			this->ora_eveniment = ora_evC;
		}
		else
		{
			while (!(ora_evC.length() >= 4 && ora_evC.length() <= 5))
			{
				cout << "Ora invalida, utilizati formatul xx:yy sau xxyy, unde x este ora in sistem de 24 de ore, iar y este minutele" << endl;
				cout << endl << "Noua ora: ";
				cin >> ws;
				getline(cin, ora_evC);
			}
		}
	}

	void setDenumire_ev(string denumireC)
	{
		this->denumire = denumireC;
	}

	void setTip_ev(string tipEvC)
	{
		this->tip_eveniment = tipEvC;
	}

	void setDurata_ev(float durataC)
	{
		if (durataC >= 0.0f)
		{
			this->durata = durataC;
		}
		else
		{
			cout << "Imposibil ca durata unui eveniment sa fie negativa." << endl;
		}
	}

	void setNume_zonaEv(string* nume_z, int nr_zoneC)
	{;
		if (nume_z != nullptr && nr_zoneC > 0)
		{
			if (nume_zone != nullptr && nr_zone > 0)
			{
				delete[] nume_zone;
				nume_zone = nullptr;
			}
			nr_zone = nr_zoneC;
			nume_zone = new string[nr_zone];
			for (int i = 0; i < nr_zone; i++)
			{
				nume_zone[i] = nume_z[i];
			}
			cout << endl << "Setat" << endl;
		}
		else
		{
			cout << "Nume zone nemodificat, vector nume zone este inexistent." << endl;
		}
	}
	
	void setNr_zone(int x)
	{
		if (x > 0)
		{
			nr_zone = x;
		}
	}

/*
	string data_eveniment, ora_eveniment, denumire, tip_eveniment;
	float durata;
	string* nume_zone;
	int nr_zone;
*/
	void sablonizareOra5()
	{
		if (getOra_ev().length() == 4)
		{
			string intermediar = getOra_ev();
			intermediar[4] = intermediar[3];
			intermediar[3] = intermediar[2];
			intermediar[2] = ':';
			setOra_ev(intermediar);
		}
		else
		{
			if (getOra_ev().length() == 5 && getOra_ev()[2]==':')
			{
				cout << "Cuvantul este deja setata la formatul potrivit" << endl;
			}
			else
			{
				cout << "Ora a fost introdusa gresit" << endl;
			}
		}
	}

	float durataOre()
	{
		if (durata >= 0.0f)
		{
			return durata / 60;
		}
		return 0.0f;
	}

	Eveniment operator=(const Eveniment& eveniment)
	{
		this->data_eveniment = eveniment.data_eveniment;
		this->ora_eveniment = eveniment.ora_eveniment;
		this->denumire = eveniment.denumire;
		this->tip_eveniment = eveniment.tip_eveniment;
		this->durata = eveniment.durata;
		if (eveniment.nume_zone != nullptr && eveniment.nr_zone > 0)
		{
			delete[] this->nume_zone;
			this->nr_zone = eveniment.nr_zone;
			this->nume_zone = new string[eveniment.nr_zone];
			for (int i = 0; i < getNr_zone(); i++)
			{
				this->nume_zone[i] = eveniment.nume_zone[i];
			}
		}
		else
		{
			this->nume_zone = nullptr;
		}
		return *this;
	}

	string& operator[](int index)
	{
		if (index >= 0 && index < getNr_zone())
		{
			return nume_zone[index];
		}
	}

	operator float()
	{
		return durata;
	}

	operator string()
	{
		return denumire;
	}

	friend ostream& operator<<(ostream&, Eveniment);
	friend istream& operator>>(istream&, Eveniment&);
};

/*
	string data_eveniment, ora_eveniment, denumire, tip_eveniment;
	float durata;
	string* nume_zone;
	const int ID;
*/

ostream& operator<<(ostream& out, Eveniment ev)
{
	out << "ID eveniment: " << ev.getID() << endl;
	out << "Data evenimentului: " << ev.getData_ev() << endl;
	out << "Ora evenimentului: " << ev.getOra_ev() << endl;
	out << "Denumirea evenimentului: " << ev.getDenumire_ev() << endl;
	out << "Tip eveniment: " << ev.getTip_ev() << endl;
	out << "Durata evenimentului: " << ev.getDurata_ev() << endl;
	if (ev.getNr_zone() > 0 && ev.nume_zone != nullptr)
	{
		out << "Nume zone: " << endl;
		for (int i = 0; i < ev.getNr_zone(); i++)
		{
			out << i << '.' << ev.getNume_zona(i) << endl;
		}
	}
	else
	{
		out << "Vectorul de nume de zone este invalid." << endl;
	}
	return out;
}

/*
	string data_eveniment, ora_eveniment, denumire, tip_eveniment;
	float durata;
	string* nume_zone;
	int nr_zone;
*/

istream& operator>>(istream& in, Eveniment& ev)
{
	string y;

	cout << "Data evenimentului: ";
	in >> ws;
	getline(in, y);
	ev.setData_ev(y);
	cout << endl;
	cout << "Setat" << endl;

	cout << "Ora evenimentului (trebuie sa fie format xxyy): ";
	in >> ws;
	getline(in, y);
	ev.setOra_ev(y);
	cout << endl;
	cout << "Setat" << endl;
	
	cout << "Denumirea evenimentului: ";
	in >> ws;
	getline(in, y);
	ev.setDenumire_ev(y);
	cout << endl;
	cout << "Setat" << endl;

	cout << "Tipul evenimentului: ";
	in >> ws;
	getline(in, y);
	ev.setTip_ev(y);
	cout << endl;
	cout << "Setat" << endl;

	cout << "Durata evenimentului: ";
	float d;
	in >> d;
	while (d <= 0.0f)
	{
		cout << "Durata invalida, introduceti din nou aici: ";
		in >> d;
		cout << endl;
	}
	ev.setDurata_ev(d);
	cout << endl;

	int x;
	cout << "Numarul zonelor din cadrul acestui eveniment este de: ";
	in >> x;
	ev.setNr_zone(x);
	cout << endl;

	if (x > 0)
	{
		cout << "Numele zonelor evenimentului: " << endl;
		string nume;
		string* nume_z = new string[x];
		for (int i = 0; i < x; i++)
		{
			cout << "Zona " << i + 1 << " : ";
			in >> ws;
			getline(in, nume);
			nume_z[i] = nume;
			cout << endl;
		}
		ev.setNume_zonaEv(nume_z, x);
	}
	return in;
}

class Bilet : public ObiectIdentitate
{
private:
	static string tipBilet;
	int nr_locB, nr_randB, nr_zonaB;
	string nume;
	string prenume;
	const int ID;
	int ID_locatie, ID_eveniment;

public:

	int creareID()
	{
		srand((unsigned)time(NULL));
		return rand();
	}

	Bilet() :ID(creareID()) {

		nr_locB = 0;
		nr_randB = 0;
		nr_zonaB = 0;
		nume = "";
		prenume = "";
	}

	Bilet(string data_eveniment, string ora_eveniment, string denumire, string tip_eveniment, float durata, string* nume_zoneB, int nr_loc, int nr_rand, int nr_zone, int nr_locuri_total, int*** Scaune, string adresa,int Nr_locB, int Nr_randB, int Nr_zonaB, string Nume, string Prenume) :ID(creareID())
	{
		this->nr_locB = Nr_locB;
		this->nr_randB = Nr_randB;
		this->nr_zonaB = Nr_zonaB;
		this->nume = Nume;
		this->prenume = Prenume;
	}

	Bilet(const Bilet& bilet):ID(creareID())
	{
		this->nr_locB = bilet.nr_locB;
		this->nr_randB = bilet.nr_randB;
		this->nr_zonaB = bilet.nr_zonaB;
		this->nume = bilet.nume;
		this->prenume = bilet.prenume;
	}

/*
	static string tipBilet;
	int nr_locB, nr_randB, nr_zonaB;
	string nume;
	string prenume;
	const int ID;
	Locatie locatie;
	Eveniment ev;
*/

	int getNr_locB()
	{
		return this->nr_locB;
	}

	int getNr_randB()
	{
		return this->nr_randB;
	}

	int getNr_zonaB()
	{
		return this->nr_zonaB;
	}

	string getNume()
	{
		return this->nume;
	}

	string getPrenume()
	{
		return this->prenume;
	}

	const int getID()
	{
		return this->ID;
	}

	int getID_loc()
	{
		return this->ID_locatie;
	}

	int getID_ev()
	{
		return this->ID_eveniment;
	}

/*
	static string tipBilet;
	int nr_locB, nr_randB, nr_zonaB;
	string nume;
	string prenume;
	const int ID;
	int ID_locatie,ID_eveniment;
*/

	void setID_loc(int x)
	{
		this->ID_locatie = x;
	}

	void setID_ev(int x)
	{
		this->ID_eveniment = x;
	}

	void setNr_locB(int x)
	{
		nr_locB = x;
	}

	int validareNr_locB(int x, Locatie locatie)
	{
		if (x >= 0 && x < locatie.getNr_locuri() && locatie.getScaun(nr_zonaB, nr_randB, x) == 0)
		{
			locatie.setScaun(nr_zonaB, nr_randB, nr_locB, 0);
			locatie.setScaun(nr_zonaB, nr_randB, x, ID);
			nr_locB = x;
			return 1;
		}
		else
		{
			return 0;
		}
	}

	void setNr_randB(int x)
	{
		nr_randB = x;
	}

	int validareNr_randB(int x, Locatie locatie)
	{
		if (x >= 0 && x < locatie.getNr_randuri() && locatie.getScaun(nr_zonaB, x, nr_locB) == 0)
		{
			locatie.setScaun(nr_zonaB, nr_randB, nr_locB, 0);
			locatie.setScaun(nr_zonaB, x, nr_locB, ID);
			nr_randB = x;
			return 1;
		}
		else
		{
			return 0;
		}
	}

	void setNr_zonaB(int x)
	{
		nr_zonaB = x;
	}

	int validareNr_zonaB(int x, Locatie locatie)
	{
		if (x >= 0 && x < locatie.getNr_zone() && locatie.getScaun(x, nr_randB, nr_locB) == 0)
		{
			locatie.setScaun(nr_zonaB, nr_randB, nr_locB, 0);
			locatie.setScaun(x, nr_randB, nr_locB, ID);
			nr_zonaB = x;
			return 1;
		}
		else
		{
			return 0;
		}
	}

	void validarebilet(Locatie locatie)
	{
		int l=0, r=0, z=0;
		while (validareNr_locB(nr_locB, locatie) == 0)
		{
			cout << "Locul nu este disponibil, alegeti alt loc" << endl;
			cout << "Locul nou este: ";
			cin >> l;
			setNr_locB(l);
			cout << endl;
		}
		while (validareNr_randB(nr_randB, locatie) == 0)
		{
			cout << "Randul nu este disponibil, alegeti alt rand" << endl;
			cout << "Randul nou este: ";
			cin >> r;
			setNr_randB(r);
			cout << endl;
		}
		while (validareNr_zonaB(nr_zonaB, locatie) == 0)
		{
			cout << "Locul nu este disponibil, alegeti alt loc" << endl;
			cout << "Locul nou este: ";
			cin >> z;
			setNr_zonaB(z);
			cout << endl;
		}
	}

	void setNume(string nume)
	{
		this->nume = nume;
	}

	void setPrenume(string prenume)
	{
		this->prenume = prenume;
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

/*
	static string tipBilet;
	int nr_locB, nr_randB, nr_zonaB;
	string nume;
	string prenume;
	const int ID;
	int ID_locatie,ID_eveniment;
*/

	Bilet operator=(const Bilet& bilet)
	{
		this->nr_locB = bilet.nr_locB;
		this->nr_randB = bilet.nr_randB;
		this->nr_zonaB = bilet.nr_zonaB;
		this->nume = bilet.nume;
		this->prenume = bilet.prenume;
		return *this;
	}

	Bilet operator++()
	{
		nume = prenume;
		return *this;
	}

	Bilet operator++(int i)
	{
		Bilet copie = *this;
		this->nume = this->prenume;
		return copie;
	}


	Bilet operator--()
	{
		prenume = nume;
		return *this;
	}

	Bilet operator--(int i)
	{
		Bilet copie = *this;
		this->prenume = this->nume;
		return copie;
	}

	friend ostream& operator<<(ostream&, Bilet);
	friend istream& operator>>(istream&, Bilet&);
};
string Bilet::tipBilet = "Bilet pentru eveniment";

/*
	static string tipBilet;
	int nr_locB, nr_randB, nr_zonaB;
	string nume;
	string prenume;
	const int ID;
	int ID_locatie,ID_eveniment;
*/

ostream& operator<<(ostream& out, Bilet bilet)
{
	out << "ID bilet: " << bilet.getID() << endl;
	out << "Tip bilet: " << bilet.tipBilet << endl;
	out << "Numar loc, rand si zona biletului: " << bilet.getNr_locB() << ' ' << bilet.getNr_randB() << ' ' << bilet.getNr_zonaB()<< endl;
	out << "Nume si prenume beneficiar: " << bilet.getNume() << ' ' << bilet.getPrenume() << endl;
	return out;
}

istream& operator>>(istream& in, Bilet& bilet)
{
	int z, r, l,il,ie;
	cout << "ID locatie: ";
	in >> il;
	cout << "ID eveniment: ";
	in >> ie;

	bilet.setID_loc(il);
	bilet.setID_ev(ie);

	cout << "Numar zona aleasa: ";
	in >> z;
	cout << "Numar rand ales: ";
	in >> r;
	cout << "Numar loc ales: ";
	in >> l;


	bilet.setNr_locB(l);
	bilet.setNr_randB(r);
	bilet.setNr_zonaB(z);

	string np;

	cout << endl<<"Nume: ";
	in >> np;
	getline(in, np);
	bilet.setNume(np);

	cout << "Prenume: ";
	in >> np;
	getline(in, np);
	bilet.setPrenume(np);

	return in;
}