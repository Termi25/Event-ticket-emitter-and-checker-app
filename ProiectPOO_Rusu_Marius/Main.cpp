#include <iostream>
#include <stdlib.h>
#include "Header.h"
using namespace std;

int main()
{
	int n = 0;
	cout << "Cum doriti sa porniti programul de generare de bilete?" << endl << endl;
	cout << "------------------------------------------------------" << endl << endl;
	cout << "Tastati '0' daca doriti sa inchideti programul." << endl << endl;
	cout << "-----------------------------------------------------------------------------------------" << endl << endl;
	cout << "Tastati '1' daca cititi datele urmatoare (locatii si evenimente) din fisierul 'date.txt'." << endl << endl;
	cout << "-----------------------------------------------------------------------------------------" << endl << endl;
	cout << "Tastati '2' daca doriti sa introduceti manual datele (locatii si evenimente)." << endl << endl;
	cout << "-----------------------------------------------------------------------------------------------" << endl << endl;
	cout << "Tastati '3' daca ati repornit aplicatia si vreti sa incarcati datele deja introduse si salvate." << endl << endl;
	cout << "-----------------------------------------------------------------------------------------------" << endl << endl;
	cout << "Introduceti aici optiunea aleasa: ";
	cin >> n;
	cout << endl << endl;
	system("cls");
	cout << "Console clear" << endl;
	return 0;
}