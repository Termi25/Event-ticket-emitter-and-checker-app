#pragma once
#include <cstdlib>
#include<iostream>
#include<fstream>
#include<string>
using namespace std;


class Locatie {
private: 
	int nr_locuri,nr_randuri,nr_zone,nr_locuri_total;
	int*** scaun;
	string adresa;

public:

	Locatie()
	{
		nr_locuri_total = 0;
		nr_locuri = 0;
		nr_randuri = 0;
		nr_zone = 0;
		scaun = nullptr;
		adresa = "";
	}

	Locatie(int Nr_loc, int Nr_rand, int Nr_zone, int nr_locuri_total, int*** Scaune,string adresa)
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
		this->adresa = locatie.adresa;
	}

/*
 	int nr_locuri,nr_randuri,nr_zone,nr_locuri_total;
	int*** scaun;
	string adresa;
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

	int getScaun(int zona, int rand,int loc)
	{
		if (zona < 0 || rand < 0 || loc < 0)
		{
			throw exception("Coordonatele scaunului sunt gresite, incercati din nou.");
		}
		else
		{
			if (scaun != nullptr)
			{
				int status_scaun = this->scaun[zona][rand][loc];
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

/*
	int nr_locuri,nr_randuri,nr_zone,nr_locuri_total;
	int*** scaun;
	string adresa;
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
			cout << "Setat" << endl;
		}
		else
		{
			cout << " Valoarea introdusa este invalida" << endl;
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

	void setAdresa(string adresa)
	{
		this->adresa = adresa;
	}

/*
	int nr_locuri,nr_randuri,nr_zone,nr_locuri_total;
	int*** scaun;
	string adresa;
*/

	int nr_locuriVerificare()
	{
		if (nr_locuri <= 0 || nr_randuri <= 0 || nr_locuri_total <= 0)
		{
			return 0;
		}
		else
		{
			if (nr_locuri * nr_randuri == nr_locuri_total)
			{
				return 1;
			}
			else
			{
				return 0;
			}
		}
	}

	void nr_locuri_totalGenerare()
	{
		if (nr_locuri <= 0 || nr_randuri <= 0 || nr_locuri_total <= 0)
		{
			nr_locuri_total = 0;
		}
		else
		{
			nr_locuri_total = nr_randuri * nr_locuri;
		}
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
	out << " Numar locuri per rand locatie: " << t2.getNr_locuri() << endl;
	out << " Numar randuri locatie: " << t2.getNr_randuri() << endl;
	out << " Numar zone locatie: " << t2.getNr_zone() << endl;
	out << " Tablou status locuri: " << endl;
	for (int i = 0; i < t2.getNr_zone(); i++)
	{
		for (int j = 0; j < t2.getNr_randuri()*2; j++)
		{
			for (int g = 0; g < t2.getNr_locuri(); g++)
			{
				out << i+1 << j+1 << g+1 << " ";
			}
			out << endl;
			for (int g = 0; g < t2.getNr_locuri(); g++)
			{
				out << " " << t2.getScaun(g, j, i) << "  ";
			}
			out << endl;
		}
		return out;
	}
	return out;
}

istream& operator>>(istream& in, Locatie& t2)
{
	int x;
	string y;
	cout << "Adresa locatiei: ";
	in >> ws;
	getline(in,y);
	t2.setAdresa(y);
	cout <<endl<< "Numar locuri total locatie: ";
	in >> x;
	while (x < 1)
	{
		in >> x;
		if (x < 1)
		{
			cout << "Valoare gresita, introduceti din nou";
		}
	}
	if (x > 0)
	{
		t2.setNr_locuri_total(x);
	}
	cout << endl;

	cout << " Numar locuri per rand locatie: ";
	in >> x;
	while (x < 1)
	{
		in >> x;
		t2.setNr_locuri(x);
		if (x < 1)
		{
			cout << "Valoare gresita, introduceti din nou";
		}
	}
	if (x > 0)
	{
		t2.setNr_locuri(x);
	}
	cout << endl;

	cout << " Numar randuri locatie: ";
	in >> x;
	while (x < 1)
	{
		in >> x;
		t2.setNr_randuri(x);
		if (x < 1)
		{
			cout << "Valoare gresita, introduceti din nou";
		}
	}
	if (x > 0)
	{
		t2.setNr_randuri(x);
	}
	cout << endl;

	cout << " Numar zone locatie: ";
	in >> x;
	while (x < 1)
	{
		in >> x;
		if (x < 1)
		{
			cout << "Valoare gresita, introduceti din nou";
		}
	}
	if (x > 0)
	{
		t2.setNr_zone(x);
	}
	cout << endl;

	cout << " Tablou status locuri: " << endl;
	int*** input_tablou = new int** [t2.getNr_zone()];
	for (int i = 0; i < t2.getNr_zone(); i++)
	{
		input_tablou[i] = new int* [t2.getNr_randuri()];
	}
	for (int i = 0; i < t2.getNr_zone(); i++)
	{
		for (int j = 0; j < t2.getNr_randuri(); j++)
		{
			input_tablou[i][j] = new int[t2.getNr_locuri()];
		}
	}
	for (int i = 0; i < t2.getNr_zone(); i++)
	{
		for (int j = 0; j < t2.getNr_randuri() * 2; j++)
		{
			for (int g = 0; g < t2.getNr_locuri(); g++)
			{
				cout << i+1 << j+1 << g+1 << " = ";
				in >> x;
				while (x != 0 && x != 1)
				{
					cout << i+1 << j+1 << g+1 << " = ";
					in >> x;
					if (x != 0 && x != 1)
					{
						cout << "Valoare gresita, introduceti din nou";
					}
				}
				if (x == 0 || x == 1)
				{
					input_tablou[i][j][g] = x;
				}
				cout << endl;
			}
			cout << endl;
		}
		t2.setScaune(input_tablou,t2.getNr_zone(), t2.getNr_randuri(), t2.getNr_locuri());
		return in;
	}
	return in;
}

class Eveniment : public Locatie
{
private:
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

	Eveniment(string data_eveniment, string ora_eveniment, string denumire, string tip_eveniment, float durata, string* nume_zoneB, int nr_loc, int nr_rand, int nr_zone, int nr_locuri_total, int*** Scaune, string adresa) : Locatie(nr_loc, nr_rand, nr_zone, nr_locuri_total, Scaune,adresa)
	{
		this->data_eveniment = data_eveniment;
		this->ora_eveniment = ora_eveniment;
		this->denumire = denumire;
		this->tip_eveniment = tip_eveniment;
		this->durata = durata;
		if (nr_zone > 0 && nume_zoneB!=nullptr)
		{
			this->setNr_zone(nr_zone);
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
				this->setNr_zone(nr_zone);
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

	Eveniment(const Eveniment& eveniment) :Locatie(eveniment)
	{
		this->data_eveniment =eveniment.data_eveniment;
		this->ora_eveniment = eveniment.ora_eveniment;
		this->denumire = eveniment.denumire;
		this->tip_eveniment = eveniment.tip_eveniment;
		this->durata = eveniment.durata;
		if (eveniment.nume_zone != nullptr && getNr_zone()>0)
		{
			delete[] nume_zone;
			this->nume_zone = new string[getNr_zone()];
			for (int i = 0; i < getNr_zone(); i++)
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
		if (index >= 0 && index < getNr_zone())
		{
			return this->nume_zone[index];
		}
	}
/*
	string data_eveniment, ora_eveniment, denumire,tip_eveniment;
	float durata;
	string* nume_zone;
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
			cout << "Ora invalida, utillizati formatul xx:yy sau xxyy, unde x este ora in sistem de 24 de ore, iar y este minutele" << endl;
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

	void setNume_zoneEv(string* nume_z, int nr_zoneC)
	{
		if (nr_zoneC == getNr_zone()&& nume_z!=nullptr)
		{
			for (int i = 0; i < nr_zoneC; i++)
			{
				this->nume_zone[i] = nume_z[i];
			}
		}
		else
		{
			if (nr_zoneC != getNr_zone() && nume_z != nullptr)
			{
				setNr_zone(nr_zoneC);
				delete[]nume_zone;
				nume_zone = new string[nr_zoneC];
				for (int i = 0; i < nr_zoneC; i++)
				{
					this->nume_zone[i] = nume_z[i];
				}
			}
			else
			{
				cout << "Nume zone nemodificat, vector nume zone este inexistent." << endl;
			}
		}
	}

/*
	string data_eveniment, ora_eveniment, denumire, tip_eveniment;
	float durata;
	string* nume_zone;
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

	int durataOre()
	{
		if (durata >= 0.0f)
		{
			return durata / 60;
		}
		return 0.0f;
	}

	friend ostream& operator<<(ostream&, Eveniment);
	friend istream& operator>>(istream&, Eveniment&);
};

/*
	string data_eveniment, ora_eveniment, denumire, tip_eveniment;
	float durata;
	string* nume_zone;
*/

ostream& operator<<(ostream& out, Eveniment ev)
{
	out << (Locatie)ev << endl;
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
*/

istream& operator>>(istream& in, Eveniment& ev)
{
	string y;
	in >> (Locatie&)ev;

	cout << "Data evenimentului: ";
	in >> ws;
	getline(in, y);
	ev.setData_ev(y);
	cout << endl;

	cout << "Ora evenimentului: ";
	in >> ws;
	getline(in, y);
	ev.setOra_ev(y);
	cout << endl; 
	
	cout << "Denumirea evenimentului: ";
	in >> ws;
	getline(in, y);
	ev.setDenumire_ev(y);
	cout << endl;

	cout << "Tipul evenimentului: ";
	in >> ws;
	getline(in, y);
	ev.setTip_ev(y);
	cout << endl;

	cout << "Durata eveniimentului: ";
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

	if (ev.getNr_zone() > 0)
	{
		cout << "Numele zonelor evenimentului: " << endl;
		string* nume_z = new string[ev.getNr_zone()];
		for (int i = 0; i < ev.getNr_zone(); i++)
		{
			cout << "Zona " << i + 1 << " : ";
			in >> nume_z[i];
			cout << endl;
		}
		ev.setNume_zoneEv(nume_z, ev.getNr_zone());
	}
	return in;
}

class Bilet: public Eveniment
{
private:
	static string tipBilet;
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
string Bilet::tipBilet = "Bilet pentru eveniment";