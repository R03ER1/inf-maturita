#include <iostream>
#include <fstream>

using namespace std;

struct slovo {
    string zneni = "";
    int cetnost = 0;
    slovo* dalsi = NULL;
};

int main()
{
    ifstream soubor;
    string nacteneSlovo;
    soubor.open("zprava.txt");
    slovo* prvni = new slovo;
    while (soubor >> nacteneSlovo){
        if (prvni->zneni==""){
            prvni->zneni = nacteneSlovo;
            prvni->cetnost += 1;
        } else {
            slovo* hledaneslovo = prvni;
            bool nalezeno = false;
            while (hledaneslovo!=NULL){
                if (hledaneslovo->zneni != nacteneSlovo){
                    hledaneslovo = hledaneslovo->dalsi;
                } else {
                    hledaneslovo->cetnost += 1;
                    nalezeno = true;
                    break;
                }
            }
            if(!nalezeno){
                slovo* noveslovo = new slovo;
                noveslovo->zneni = nacteneSlovo;
                noveslovo->cetnost = 1;
                noveslovo->dalsi = prvni;
                prvni = noveslovo;
            }
        }
    }
    slovo* cteneSlovo = prvni;
    while (cteneSlovo != NULL){
        cout << cteneSlovo->zneni << cteneSlovo->cetnost << endl;
        cteneSlovo = cteneSlovo->dalsi;
    }
    delete prvni;
    soubor.close();
    return 0;
}
