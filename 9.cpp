#include<iostream>
#include<fstream>
#include<cstring>

using namespace std;

struct Clovek{
    char jmeno[30], prijmeni[30];
    char rodneCislo[11];
};

void vytvorSoubor(){
    ofstream soubor;
    soubor.open("lide.bin");
    soubor.close();
    cout << "Soubor lide.bin byl vytvoren." << endl;
}

void pridejCloveka(){
    Clovek clovek;
    cout << "Zadejte jmeno: ";
    cin >> clovek.jmeno;
    cout << "Zadejte prijmeni: ";
    cin >> clovek.prijmeni;
    cout << "Zadejte rodne cislo: ";
    cin >> clovek.rodneCislo;
    fstream soubor;
    soubor.open("lide.bin", ios::binary | ios::out | ios::app); //PAMATOVAT
    soubor.write((char*)&clovek, sizeof(Clovek));
    soubor.close();
    cout << "Clovek byl pridan do souboru." << endl;
}

void tiskniLidi(){
    Clovek clovek;

    ifstream soubor;
    soubor.open("lide.bin", ios::binary | ios::in);
    while(soubor.read((char*)&clovek, sizeof(Clovek))){
        cout << "Jmeno: " << clovek.jmeno << ", Prijmeni: " << clovek.prijmeni << ", Rodne cislo: " << clovek.rodneCislo << endl;
        cout << "Datum narozeni: " << clovek.rodneCislo[4] << clovek.rodneCislo[5]<<". ";
        if(clovek.rodneCislo[2]>'1'){
            clovek.rodneCislo[2] -= 5;
        }
        cout << clovek.rodneCislo[2] << clovek.rodneCislo[3] << ". ";
        if(strlen(clovek.rodneCislo)==9){
            cout << "19";
        } else {
            cout << "20";
        }
        cout << clovek.rodneCislo[0] << clovek.rodneCislo[1] << endl;
    }
    soubor.close();
    cout << "Tisk ukončen." << endl;
}

int main(){
    //vytvorSoubor();
    pridejCloveka();
    tiskniLidi();
    return 0;
}