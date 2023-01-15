#include <iostream>
#include <fstream>
#include <stdlib.h>
#include "Header.h"
using namespace std;

Locatie* locatii=nullptr;
Eveniment* evenimente=nullptr;
Bilet* bilete=nullptr;
int nr_l=0, nr_ev=0, nr_b=0;

void sub21()//introducere de locatie in program
{
    if (nr_l == 0)
    {
        nr_l = 1;
        locatii = new Locatie[nr_l];
        cin >> locatii[0];
    }
    else
    {
        nr_l++;
        Locatie* cp_loc = new Locatie[nr_l];
        for (int i = 0; i < nr_l - 1; i++)
        {
            cp_loc[i] = locatii[i];
        }
        cin >> cp_loc[nr_l - 1];
        delete[] locatii;
        locatii = cp_loc;
        cp_loc = nullptr;
    }
}

void sub22()//introducere de eveniment in program
{
    if (nr_ev == 0)
    {
        nr_ev = 1;
        evenimente = new Eveniment[nr_ev];
        cin >> evenimente[0];
    }
    else
    {
        nr_ev++;
        Eveniment* cp_ev = new Eveniment[nr_ev];
        for (int i = 0; i < nr_ev - 1; i++)
        {
            cp_ev[i] = evenimente[i];
        }
        cin >> cp_ev[nr_l - 1];
        delete[] evenimente;
        evenimente = cp_ev;
        cp_ev = nullptr;
    }
}


void sub24()//afisare locatii
{
    if (nr_l <= 0 || locatii==nullptr)
    {
        cout <<endl<< "Nu exista locatii de afisat. Va rugam sa introduceti locatii inainte de a le vizualiza cu aceasta optiune." << endl;
    }
    else
    {
        for (int i = 0; i < nr_l; i++)
        {
            cout << i+1 << ')' <<"ID locatie: "<<locatii[i].getID()<<"- adresa locatiei: " << locatii[i].getAdresa() << "- capacitate de locuri: " << locatii[i].getNr_locuri_total() << " dintre care sunt libere: " << locatii[i].nr_locuri_libere() << endl;
            /*for (int i = 0; i < locatii[i].getNr_zone(); i++)
            {
                for (int j = 0; j < locatii[i].getNr_randuri(); j++)
                {
                    for (int g = 0; g < locatii[i].getNr_locuri(); g++)
                    {
                        cout << "  " << '[' << i + 1 << j + 1 << g + 1 << ']' << "  ";
                    }
                    cout << endl;
                    for (int g = 0; g < locatii[i].getNr_locuri(); g++)
                    {
                        cout << "   " << '[' << locatii[i].getScaun(g, j, i) % 10 << ']' << "   ";
                    }
                    cout << endl;
                }
                cout << endl;
            }
            cout << "-----------------------------------------------------------------------------------------------" << endl;*/
        }
    }
}

void sub25()//afisare evenimente
{
    if (nr_ev <= 0 || evenimente==nullptr)
    {
        cout << endl << "Nu exista evenimente de afisat. Va rugam sa introduceti evenimente inainte de a le vizualiza cu aceasta optiune." << endl;
    }
    else
    {
        for (int i = 0; i < nr_ev; i++)
        {
            cout << i + 1 << ')' << "ID eveniment: "<<evenimente[i].getID()<<' '<< evenimente[i].getDenumire_ev() << " - de tip: " << evenimente[i].getTip_ev() << " - pe data de: " << evenimente[i].getData_ev() << " - la ora: " << evenimente[i].getOra_ev() << " - cu durata de: " << evenimente[i].getDurata_ev() << " minute" << endl << endl;
            /*cout << "Zonele acestui eveniment:" << endl;
            for (int i = 0; i < evenimente[i].getNr_zone(); i++)
            {
                cout << i << ')' << evenimente[i].getNume_zona(i)<<endl;
            }
            cout << "-----------------------------------------------------------------------------------------" << endl << endl;*/
        }
    }
}

void sub26()//afisare bilete
{
    if (nr_l > 0 && nr_ev > 0 && nr_b > 0 && locatii!=nullptr && evenimente!=nullptr && bilete!=nullptr)
    {
        cout << "Bilete introduse: " << endl;
        cout << "------------------" << endl<<endl;
        for (int i = 0; i < nr_b; i++)
        {
            cout << "Cod bilet: "<<bilete[i].getID()<<" - detinut de "<<bilete[i].getNume()<<' '<<bilete[i].getPrenume()<<" - nr zona, rand si loc: "<< bilete[i].getNr_zonaB()<<'-'<< bilete[i].getNr_randB() << '-' << bilete[i].getNr_locB() << endl << endl;
        }
    }
    else
    {
        cout << endl<<"Nu exista bilete introduse." << endl;
    }
}

void sub23()//introducere de bilet in program
{
    if (nr_l == 0 || locatii == nullptr || nr_ev==0 || evenimente == nullptr)
    {
        cout << "Inainte de a introduce bilete, este nevoie sa introduceti minim o locatie si un eveniment" << endl;
    }
    else
    {
        if (nr_b == 0)
        {

            nr_b = 1;
            
            cout << endl;
            cout << "Ce locatie doriti pentru bilet ?" << endl;
            sub24();

            cout << endl;
            cout << "Ce eveniment doriti pentru bilet ?" << endl;
            sub25();

            bilete = new Bilet[nr_b];
            cin >> bilete[0];
            int valid = 0;
            for (int i = 0; i < nr_l; i++)
            {
                if (locatii[i].getID() == bilete[0].getID_loc())
                {
                    valid = i;
                }
            }
            bilete[0].validarebilet(locatii[valid]);
        }
        else
        {
            nr_b++;
            Bilet* cp_b = new Bilet[nr_b];
            for (int i = 0; i < nr_b - 1; i++)
            {
                cp_b[i] = bilete[i];
            }
            cout << endl;
            cout << "Ce locatie doriti pentru bilet ?" << endl;
            sub24();

            cout << endl;
            cout << "Ce eveniment doriti pentru bilet ?" << endl;
            sub25();

            cin >> cp_b[nr_b - 1];
            delete[] bilete;
            bilete = cp_b;
            cp_b = nullptr;

            int valid = 0;
            for (int i = 0; i < nr_l; i++)
            {
                if (locatii[i].getID() == bilete[nr_b-1].getID_loc())
                {
                    valid = i;
                }
            }
            bilete[nr_b-1].validarebilet(locatii[valid]);
        }
    }
}

void sub1()
{
    ifstream f;
    f.open("date.txt", ios::in);
    if (f.is_open())
    {
        f >> nr_l;
        locatii = new Locatie[nr_l];
        for (int i = 0; i < nr_l; i++)
        {
            f >> locatii[i];
        }

        f >> nr_ev;
        evenimente = new Eveniment[nr_ev];
        for (int i = 0; i < nr_ev; i++)
        {
            f >> evenimente[i];
        }
        f.close();
    }
    else
    {
        cout << "ERROR!";
    }
}

void sub3()
{
    ifstream f;
    f.open("bilete.bin", ios::binary);
    if (f.is_open())
    {
        f.read((char*)&nr_b, sizeof(int));
        unsigned int dim = nr_b * sizeof(Bilet);
        for (int i = 0; i < nr_b; i++)
        {
            f.read(reinterpret_cast<char* const>(bilete), dim);
        }
        cout << endl << "Restaurare finalizata!" << endl;
    }
    
}

void sub4()
{
    ofstream f,g,h;
    if (nr_l > 0)
    {
        f.open("locatii.bin", ios::binary);
        if (f.is_open())
        {
            f.write((char *)&nr_l, sizeof(int));
            f.write(reinterpret_cast<char* const>(locatii), nr_l * sizeof(Locatie));
            f.close();
        }
        else
        {
            cout << "ERROR!";
        }
    }
    if (nr_ev > 0)
    {
        g.open("evenimente.bin", ios::binary);
        if (g.is_open())
        {
            g.write(reinterpret_cast<char* const>(&nr_ev), sizeof(int));
            g.write(reinterpret_cast<char* const>(evenimente), nr_ev * sizeof(Eveniment));
            g.close();
        }
    }
    if (nr_b > 0)
    {
        h.open("bilete.bin", ios::binary);
        if (h.is_open())
        {
            h.write(reinterpret_cast<char* const>(&nr_b), sizeof(int));
            h.write(reinterpret_cast<char* const>(bilete), nr_b * sizeof(Bilet));
            h.close();
        }
    }
    cout << endl << "Salvare finalizata!"<< endl;
}

void sub5()
{
    ofstream f;
    f.open("date.txt", ios::trunc);
    if (f.is_open())
    {
        if (nr_l > 0)
        {
            f << nr_l << endl;
            for (int i = 0; i < nr_l; i++)
            {
                f << locatii[i]<<endl;
            }
            cout << endl;
        }
        if (nr_ev > 0)
        {
            f << nr_ev << endl;
            for (int i = 0; i < nr_ev; i++)
            {
                f << evenimente[i]<<endl;
            }
        }
        f.close();
    }
    else
    {
        cout << "ERROR!";
    }
}

int main()
{
    int x = -1, y,z=-1,w;
    while (x)
    {
        system("cls");
        cout << "Cum doriti sa porniti programul de generare de bilete?" << endl << endl;
        cout << "------------------------------------------------------" << endl << endl;
        cout << "Tastati '0' daca doriti sa inchideti programul." << endl << endl;
        cout << "-----------------------------------------------------------------------------------------" << endl << endl;
        cout << "Tastati '1' daca cititi datele urmatoare (locatii si evenimente) din fisierul 'date.txt'." << endl << endl;
        cout << "-----------------------------------------------------------------------------------------" << endl << endl;
        cout << "Tastati '2' daca doriti sa introduceti manual datele (locatii si evenimente)." << endl << endl;
        cout << "-----------------------------------------------------------------------------------------------" << endl << endl;
        cout << "Tastati '3' daca salvati biletele in fisier binar." << endl << endl;
        cout << "-----------------------------------------------------------------------------------------------" << endl << endl;
        cout << "Tastati '4' daca vreti sa salvati datele introduse in fisiere binare." << endl << endl;
        cout << "-------------------------------------------------------------------------" << endl << endl;
        cout << "Tastati '5' daca vreti sa salvati locatii si evenimentele in fisier text." << endl << endl;
        cout << "-------------------------------------------------------------------------" << endl << endl;
        cout << "Optiune (0-5) introduceti valoare: ";
        cin >> x;
        y = 1;
        switch (x)
        {
        case 1:
            while (y)
            {
                system("cls");
                sub1();
                cout << "Refolositi optiunea? (1/0): ";
                cin >> y;
            }
            break;
        case 2:
            while (y)
            {
                system("cls");
                cout << "LISTA OPTIUNI DE CREARE, AFISARE SI CAUTARE DE BILETE, EVENIMENTE SI LOCATII" << endl << endl;
                cout << "----------------------------------------------------------------------------" << endl << endl;
                cout << "0) Reveniti la meniul precedent" << endl << endl;
                cout << "1) Introducere de locatie" << endl << endl;
                cout << "2) Introducere de eveniment" << endl << endl;
                cout << "3) Introducere de bilet" << endl << endl;
                cout << "4) Afisare locatii" << endl << endl;
                cout << "5) Afisare evenimente" << endl << endl;
                cout << "6) Afisare bilete" << endl << endl;
                cout << "----------------------------------------------------------------------------" << endl << endl;
                cout << "Optiune (0-6) introduceti valoare: ";
                cin >> z;
                w = 1;
                switch (z)
                {
                case 1:
                    while (w)
                    {
                        system("cls");
                        sub21();
                        cout << "Refolositi optiunea? (1/0): ";
                        cin >> w;
                    }
                    break;
                case 2:
                    while (w)
                    {
                        system("cls");
                        sub22();
                        cout << "Refolositi optiunea? (1/0): ";
                        cin >> w;
                    }
                    break;
                case 3:
                    while (w)
                    {
                        system("cls");
                        sub23();
                        cout << "Refolositi optiunea? (1/0): ";
                        cin >> w;
                    }
                    break;
                case 4:
                    while (w)
                    {
                        system("cls");
                        sub24();
                        cout << "Refolositi optiunea? (1/0): ";
                        cin >> w;
                    }
                    break;
                case 5:
                    while (w)
                    {
                        system("cls");
                        sub25();
                        cout << "Refolositi optiunea? (1/0): ";
                        cin >> w;
                    }
                    break;
                case 6:
                    while (w)
                    {
                        system("cls");
                        sub26();
                        cout << "Refolositi optiunea? (1/0): ";
                        cin >> w;
                    }
                    break;
                }
                system("cls");
                cout << "Doriti sa mai utilizati optiunile de editare? (1/0): ";
                cin >> y;
                system("cls");
            }
            break;
        case 3:
            while (y)
            {
                system("cls");
                sub3();
                cout << "Refolositi optiunea? (1/0): ";
                cin >> y;
            }
            break;
        case 4:
            while (y)
            {
                system("cls");
                sub4();
                cout << "Refolositi optiunea? (1/0): ";
                cin >> y;
            }
            break;
        case 5:
            while (y)
            {
                system("cls");
                sub5();
                cout << "Refolositi optiunea? (1/0): ";
                cin >> y;
            }
            break;
        default:
            system("cls");
            break;
        }
    }
    cout << endl << endl << "Executie incheiata cu succes!" << endl << endl;
	return 0;
}