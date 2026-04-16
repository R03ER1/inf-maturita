#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

struct Pracovnik{
    char jmeno[50];
    int plat;
    char funkce[30];
};

int main()
{
    ifstream tabulka;
    ofstream binsoubor;
    tabulka.open("lide.csv");
    binsoubor.open("lide.bin", ios::binary | ios::out);
    string radek;
    int pozice;
    string jmeno;
    string plat;
    string funkce;
    Pracovnik zamestnanec;
    //string=getline(tabulka,radek) char[]=tabulka.getline()
    while(getline(tabulka,radek)){
        cout << "Nacteno: " << radek << endl;

        pozice = radek.find(";");
        radek.erase(0, pozice+1);
        cout << "Zmeneno: " <<radek << endl;

        pozice = radek.find(";");
        jmeno=radek.substr(0, pozice);
        cout << "Zjistene jmeno: " << jmeno << endl;
        radek.erase(0, pozice+1);
        cout << "Zmeneno: " <<radek << endl;
        strcpy(zamestnanec.jmeno, jmeno.c_str());



        pozice = radek.find(";");
        plat=radek.substr(0, pozice);
        cout << "Zjisteny plat: " << plat << endl;
        radek.erase(0, pozice+1);
        cout << "Zmeneno: " <<radek << endl;
        zamestnanec.plat = stoi(plat);


        cout << "Zjistena funkce: " << radek;
        strcpy(zamestnanec.funkce, radek.c_str());



        cout << endl;

        binsoubor.write((char*)&zamestnanec,sizeof(Pracovnik));
    }
    binsoubor.close();
    tabulka.close();
}
