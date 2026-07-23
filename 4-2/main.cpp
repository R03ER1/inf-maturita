#include <iostream>

using namespace std;

int euklides(int a, int b){
    while (b!=0){
        if(a>b){
            a-=b;
        }else {
            b-=a;
        }
    }
    return a;
}

int main()
{
    int n, nsd;
    cout << "Zadejte pocet prvku: " << endl;
    cin >> n;
    int cisla[n];
    for (int i = 0; i < n; i++){
        cout << "zadejte " << i+1 << ". cislo: ";
        cin >> cisla[i];
    }
    nsd = cisla[0];
    for (int i = 1; i < n; i++){
        nsd = euklides(nsd, cisla[i]);
    }
    cout << "nsd: " << nsd;
    return 0;
}
