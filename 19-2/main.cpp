#include <iostream>
#include <string>
#include <cstring>
#include <fstream>

using namespace std;

struct Pracovnik{
char jmeno[50];
int plat;
char funkce[30];
};

int main()
{
    string radek;
    ifstream csvSoubor;
    csvSoubor.open("data.csv");
    ofstream binSoubor;
    binSoubor.open("data.bin", ios::binary | ios::in);

    while(getline(csvSoubor, radek)){
        Pracovnik clovek;
        cout << radek << endl;
        radek.erase(0, radek.find(";")+1);
        cout << radek << endl;


        strcpy(clovek.jmeno, radek.substr(0, radek.find(";")).c_str());
        radek.erase(0, radek.find(";")+1);
        cout << radek << endl;
        cout << clovek.jmeno << endl;
        binSoubor.write((char *)&clovek.jmeno, sizeof(clovek.jmeno));


        clovek.plat = stoi(radek.substr(0, radek.find(";")));
        radek.erase(0, radek.find(";")+1);
        cout << radek << endl;
        cout << clovek.plat << endl;
        binSoubor.write((char *)&clovek.plat, sizeof(clovek.plat));

        strcpy(clovek.funkce, radek.substr(0, radek.find(";")).c_str());
        cout << clovek.funkce << endl;
        binSoubor.write((char *)&clovek.funkce, sizeof(clovek.funkce));

    }
    binSoubor.close();

    cout << "cteni:\n";
    ifstream binCteni;
    binCteni.open("data.bin", ios::out | ios::binary);

    Pracovnik ctenyClovek;
    while(binCteni.read((char *)&ctenyClovek, sizeof(ctenyClovek))){
        cout << ctenyClovek.jmeno << ctenyClovek.plat << ctenyClovek.funkce;
    }

    csvSoubor.close();
    binCteni.close();
}
