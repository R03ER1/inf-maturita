#include <iostream>
#include <random>

using namespace std;

struct TPRVEK {
    int hodnota;
    TPRVEK *dalsi;
};

TPRVEK *start = NULL;

void pridejPrvek(int hodnota){
    TPRVEK *novyPrvek;
    novyPrvek = new TPRVEK;
    novyPrvek->hodnota = hodnota;
    
    if (start == NULL){
        start = novyPrvek;
        novyPrvek->dalsi = NULL;
    } else if (hodnota <= start->hodnota){
        novyPrvek->dalsi = start;
        start = novyPrvek;
    } else {
        TPRVEK *pom = start;
        while (pom->dalsi != NULL && pom->dalsi->hodnota < hodnota){
            pom = pom->dalsi;
        }
        novyPrvek->dalsi = pom->dalsi;
        pom->dalsi = novyPrvek;
    }
}

void tisk (){
    TPRVEK *pom = start;
    while(pom!=NULL){
        cout << pom->hodnota << endl;
        pom = pom->dalsi;
    }
    cout << "\n-----\n";
}

int main()
{
    
    srand(time(0));
    cout << "Hello world!" << endl;
    for(int i = 50; i > 0; i--){
        pridejPrvek(rand()%1000);
        tisk();
    }
    tisk();
}