#include <iostream>
#include <fstream>

using namespace std;

struct Clovek {
    char jmeno[30], prijmeni[30];
    char rodneCislo[11];
 };

 void novyBin(char *nazevSouboru){
     fstream soubor;
     soubor.open(nazevSouboru, ios::out | ios::binary | ios::app);
     soubor.close();
 }

 void novaStruktura(char *nazevSouboru){
    Clovek novyclovek;
    cin >> novyclovek.jmeno;
    cin >> novyclovek.prijmeni;
    cin >> novyclovek.rodneCislo;

    ofstream soubor;
    soubor.open(nazevSouboru, ios::out | ios::app | ios::binary);
    soubor.write((char*)&novyclovek, sizeof(novyclovek));
    soubor.close();
 }

 void vypisBinSouboru(char *nazevSouboru){
    Clovek clovek;
    ifstream soubor;
    soubor.open(nazevSouboru, ios::in | ios::binary);
    while(soubor.read((char*)&clovek, sizeof(clovek))){
        cout << clovek.jmeno << endl << clovek.prijmeni << endl << clovek.rodneCislo << endl;
    }
    soubor.close();
 }

int main()
{
    cout << "Hello world!" << endl;
    novyBin("soubor.bin");
    novaStruktura("soubor.bin");
    vypisBinSouboru("soubor.bin");
    return 0;
}
