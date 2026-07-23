#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    const int N = 200;
    bool cisla[N];

    for (int i = 0; i < N; i++){
            cisla[i] = true;
    }
    for (int i = 0; i < N; i++){
        if(i<2){
            cisla[i] = false;
        } else if (cisla[i] == true) {
            for (int j = 2*i; j < N; j += i){
                cisla[j] = false;
            }
        }
    }
    for (int i = 0; i < N; i++){
            cout << cisla[i];
    }


    ofstream soubor;
    soubor.open("prvocisla.txt");
    for (int i = 0; i < N; i++){
            if (cisla[i]){
                soubor << i << " ";
            }
    }
    soubor.close();
}
