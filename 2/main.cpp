#include <iostream>
#include <string>

using namespace std;

int main()
{
    string zprava;
    string klic;
    string sifra = "";
    cout << "Zprava: ";
    cin >> zprava;
    cout << "Klic: ";
    cin >> klic;

    for (int i = 0; i < zprava.length(); i++){
        int posun = klic[i%klic.length()] - 'A' + 1;
        cout << "Posun " << i << ". pismena: o " << posun << " pismen.\n";
        char novepismeno = ((zprava[i] - 'A' + posun)%26)+'A';
        cout << zprava[i] << " ---> " << novepismeno << "\n";
        sifra = sifra + novepismeno;
    }
    cout << "\n\n\n------\n\nSifrovana zprava: " << sifra << endl;
}
