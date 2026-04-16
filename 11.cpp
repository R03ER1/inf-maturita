//mozna prepsat 

#include <iostream>
#include<fstream>

using namespace std;


struct prvek {
    string slovo;
    int pocet;
    prvek *dalsi;
};

prvek *zacatek = NULL;

bool pridejDoPole(string slovo) {
    // cout << slovo << endl;
    prvek *p = zacatek;
    while (p != NULL) {
        // cout << p->slovo << ' ';
        if (p->slovo == slovo) {
            p->pocet += 1;
            cout << "Slovo plus 1" << endl;
            return true;
        }
        p = p->dalsi;
    }
    prvek *novy_prvek;
    novy_prvek = new prvek;
    novy_prvek->slovo = slovo;
    novy_prvek->pocet = 1;

    novy_prvek->dalsi = zacatek;
    zacatek = novy_prvek;

    return false;
}

int main()
{
    fstream soubor;
    soubor.open("text.txt.txt");
    string nove_slovo;
    while (soubor >> nove_slovo) {
        pridejDoPole(nove_slovo);
    }
    prvek *p = zacatek;
    while (p != NULL) {
        cout << p->slovo << ' ' << p->pocet << endl;
        p = p->dalsi;
    }

    cout << "Hello world!" << endl;
    return 0;
}