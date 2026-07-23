#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

class SetridenePole{
private:
    int* polePrvku;
    int pocetPrvku;
    int maxPocet;
public:
    SetridenePole(int max){
        polePrvku = new int[max];
        pocetPrvku = 0;
        maxPocet = max;
    }
    int vlozDoPole(int cislo){
        if (pocetPrvku >= maxPocet){
            return 0;
        } else {
            int pozice = 0;
            while (polePrvku[pozice]<cislo&&pozice<pocetPrvku){pozice++;}
            int pomocna;
            for(int i = pozice; i <= pocetPrvku; i++){
                pomocna = polePrvku[i];
                polePrvku[i] = cislo;
                cislo = pomocna;
            }
            pocetPrvku++;
            return 1;
        }
    }
    void tiskniPole(){
        for (int i = 0; i < pocetPrvku; i++){
            cout << polePrvku[i] << " ";
        }
    }
    ~SetridenePole(){
        delete[] polePrvku;
    }
};

int main()
{
    srand(time(NULL));
    SetridenePole pole(50);
    int i = 1;
    while (pole.vlozDoPole(rand()%1000)){
        i++;
    }
    pole.tiskniPole();
    return 0;
}
