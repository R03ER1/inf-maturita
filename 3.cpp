/*
---ZADANI---

Je dáno přirozené číslo N (v programu deklarováno jako konstanta). Vytvořte program, který určí
a do textového souboru vypíše všechna prvočísla menší než dané N.

Poznámka: K výpočtu můžete použít tzv. Eratosthenovo síto.

Povolený online zdroj: www.cplusplus.com, www.cpprefernce.com
*/
#include <iostream>
#include <fstream>

using namespace std;



int main(){
    const int N = 100;
    //C způsob: #define N 100
    //C++ způsob: const int N = 100;
    /*
    eratosthenovo síto: postupné vyškrtávání násobků prvočísel

    2|3|4|5|6
    T|T|F|T|F

    potřeboujeme pole boolů
    */

    bool numbers[N];
    //naplníme true
    for(int i = 0; i < N; i++){
        numbers[i] = true;
    }
    
    //založíme soubor
    ofstream prvocisla;
    prvocisla.open("prvocisla.txt");
    /*
    v případě fstream:

    , fstream::out | fstream::in | fstream::app

    in	input	File open for reading: the internal stream buffer supports input operations.
    out	output	File open for writing: the internal stream buffer supports output operations.
    binary	binary	Operations are performed in binary mode rather than text.
    ate	at end	The output position starts at the end of the file.
    app	append	All output operations happen at the end of the file, appending to its existing contents.
    trunc	truncate	Any contents that existed in the file before it is open are discarded.
    */

    for(int i = 2; i < N; i++){
        if(numbers[i]){
            prvocisla << i << " ";
            cout << "zapsano: " << i << ",\n";
            for(int j = 2; j*i < N; j++){
                    numbers[i*j] = false;
            }
        }
    }

    prvocisla.close();
}