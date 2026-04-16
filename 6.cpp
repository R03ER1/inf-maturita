#include <iostream>

using namespace std;

void prevod10do2(unsigned char vstup, char *vystup){
    for(int i=7; i>=0; i--){
        vystup[i] = (vstup % 2) + 48; // převod na znak '0' nebo '1'
        vstup /= 2;
    }
    vystup[8] = 0; // ukončovací znak řetězce
}

void prevod2do10(char *vstup, unsigned char *vystup){
    int soucet = 0;
    int mocina = 1; // 2^0
    for(int i=7; i>=0; i--){
        if(vstup[i] == '1'){
            soucet += mocina;
        }
        mocina *= 2; // zvyšujeme mocninu dvou
    }
    *vystup = soucet;
}

int main() {
    char binarka[9]; // 8 bitů + ukončovací znak
    unsigned char cislo = 173; // příklad čísla v desítkové soustavě

    prevod10do2(cislo, binarka);
    cout << "Číslo " << (int)cislo << " v binárním tvaru je: " << binarka << endl;
    prevod2do10(binarka, &cislo);
    cout << "Binární číslo " << binarka << " v desítkovém tvaru je: " << (int)cislo << endl;
    return 0;
}