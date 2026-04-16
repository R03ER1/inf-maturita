#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    int pole[25];
    int pom;
    bool upraveno;
    srand(time(NULL));
    for (int i = 0; i < 25; i++){
        pole[i] = rand()%100;
    }
    for (int i = 0; i < 25; i++){
        cout << pole[i] << " ";
    }
    cout << endl << endl;
    do{
            upraveno = false;
            for (int i = 0; i < 24; i++){

                if(pole[i]>pole[i+1]){
                    pom = pole[i];
                    pole[i] = pole[i+1];
                    pole[i+1] = pom;
                    upraveno = true;
                }
            }
    }while(upraveno == true);
    cout << "Serazene pole:\n";
    for (int i = 0; i < 25; i++){
        cout << pole[i] << " ";
    }
    cout << endl << endl;
    int start=0, konec=24, stred;
    bool nalezeno;
    do{
        cout << "Zadejte hledane cislo: ";
        cin >> pom;

        do{
            stred = (start+konec)/2;
            if (stred==pom){
                cout << "Cislo nalezeno na pozici " << stred << ".\n";
                nalezeno = true;
            } else if (stred > pom){
                konec = stred-1;
            }else {
                start = stred+1;
            }
        }while (nalezeno == false);
    }while(true);
}
