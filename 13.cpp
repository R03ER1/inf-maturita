#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

class SetridenePole{
    private:
    int *polePrvku;
    int pocetPrvku;
    int maxPocet;
    public:
    SetridenePole(int max);
    int vlozDoPole(int cislo);
    void tiskniPole();
};

SetridenePole::SetridenePole(int max){
    polePrvku = new int[max];
    maxPocet = max;
    pocetPrvku = 0;
    cout << "Pole o " << max << " prvcich bylo vytvoreno.";
}

void SetridenePole::tiskniPole(){
    for(int i = 0; i < pocetPrvku; i++){
        cout << polePrvku[i] << " ";
    }
    cout << endl << endl;
}

int SetridenePole::vlozDoPole(int cislo){
    if(pocetPrvku != maxPocet){
        polePrvku[pocetPrvku] = cislo;
        pocetPrvku++;

        int poziceCisla = pocetPrvku-1;
        int pomocneCislo;
        while(poziceCisla!=0 && polePrvku[poziceCisla]<polePrvku[poziceCisla-1]){
            pomocneCislo = polePrvku[poziceCisla];
            polePrvku[poziceCisla] = polePrvku[poziceCisla - 1];
            polePrvku[poziceCisla - 1] = pomocneCislo;
            poziceCisla--;
        }
        cout << "prvek pridan\n";
        return 1;
    }
    cout << "V poli neni misto.\n";
    return 0;
}

int main() {
    SetridenePole pole(10);
    srand(time(NULL));
    for(int i = 10; i > 0; i--){
        pole.vlozDoPole(rand()%50);
        pole.tiskniPole();
    }

}