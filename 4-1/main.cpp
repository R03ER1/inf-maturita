#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int i=0, j=1;

void nahodnacisla(int *cislo, int poradi){
    cislo[poradi] = (rand()%1000) + 1;
    cout << cislo[poradi] << endl;
    if(poradi < 99){
        nahodnacisla(cislo, poradi+1);
    }
}


void serazeni(int *cislo, int poradi, bool upraveno = false){
    if(poradi<99){
        if (cislo[poradi] > cislo[poradi+1]){
            int pom = cislo[poradi];
            cislo[poradi] = cislo[poradi+1];
            cislo[poradi+1] = pom;
            serazeni(cislo, poradi+1, true);
        } else {
            serazeni(cislo, poradi+1, upraveno);
    }
    } else if (upraveno == true){
        serazeni(cislo, 0, false);
    }
}

int main()
{
    srand(time(0));
    int cisla[100];
    nahodnacisla(&cisla[0], 0);
    serazeni(&cisla[0], 0);
    cout << "serazenepole:\n";
    for (int i = 0; i < 100; i++){
        cout << cisla[i] << endl;
    }
}
