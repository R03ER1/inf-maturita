#include <iostream>
#include <fstream>
using namespace std;

/*
Příklad
Vytvořte v C/C++ následující funkce:
• funkci pro načtení hodnot matice (typu 5 x 5) z textového souboru
• funkci, která sečte dvě matice (typu 5 x 5) a výsledek uloží do třetí matice
• funkci, která uloží hodnoty matice do textového souboru.
Poznámka: matice předávejte do funkcí jako parametr.
Tyto funkce použijte v programu, který z textového souboru MATA.TXT načte hodnoty do matice A,
z textového souboru MATB.TXT načte hodnoty do matice B, matice A a B sečte a výsledek uloží do
textového souboru MATC.TXT. Soubory MATA.TXT a MATB.TXT najdete na ve složce
C:\maturita\soubory\.
Povolený online zdroj: www.cplusplus.com, www.cpprefernce.com
 */

//

 /*
 prace se soubory = knihovna fstream
 funkce kde je parametr dvourozměrné pole!
 */

// parametr: soubor, pole
// parametr pole se zapisuje třemi (stejnými) způsoby: char *nazevSouboru, char nazevSouboru[], char nazevSouboru[200] string nazevSouboru
// nejcastěji se používá char *nazevSouboru
// vice rozměrné pole: int matice[5][5] - nutné uvést všechny rozměry kromě prvního -> int matice [][5] je ok, int matice[][] není ok
void nactiMatici(char *nazevSouboru, int matice[5][5]){
    ifstream vstup; // vytvoření objektu pro práci se souborem
    vstup.open(nazevSouboru); // otevření souboru
    if(!vstup){ // pokud se soubor nepodařilo otevřít
        cout << "Soubor " << nazevSouboru << " se nepodarilo otevrit!" << endl;
        return; // ukončení funkce
    }
    for(int radek=0; radek<5; radek++){
        for(int sloupec=0; sloupec<5; sloupec++){
            vstup >> matice[radek][sloupec]; // načtení hodnoty do matice
        }
    }
    vstup.close(); // zavření souboru
}

void zapisMatici(char *nazevSouboru, int matice[5][5]){
    ofstream vystup; // vytvoření objektu pro práci se souborem
    vystup.open(nazevSouboru); // otevření souboru
    if(!vystup){ // pokud se soubor nepodařilo otevřít
        cout << "Soubor " << nazevSouboru << " se nepodarilo otevrit!" << endl;
        return; // ukončení funkce
    }
    for(int radek=0; radek<5; radek++){
        for(int sloupec=0; sloupec<5; sloupec++){
            vystup << matice[radek][sloupec] << " "; // zapsání hodnoty do souboru
        }
        vystup << endl; // nový řádek po každém řádku matice
    }
    vystup.close(); // zavření souboru
}

void sectiMatice(int maticeA[5][5], int maticeB[5][5], int maticeC[5][5]){

}

void tiskniMatici(int matice[5][5]){
    for(int i=0; i<5; i++){
        for(int j=0; j<5; j++){
            cout << matice[i][j] << " "; // zapsání hodnoty do souboru
        }
        cout << endl; // nový řádek po každém řádku matice
    }
    cout << endl;
}

int main(){
    int A[5][5], B[5][5], C[5][5];
    nactiMatici("mata.txt", A);
    tiskniMatici(A);
    nactiMatici("matb.txt", B);
    tiskniMatici(B);
    sectiMatice(A, B, C);
    tiskniMatici(C);
    zapisMatici("matc.txt", C);
    return 0;
}