#include <iostream>

using namespace std;

int nsd (int a, int b){
    //eukliduv algoritmus
    while(b != 0){
        if(a > b) a -= b;
        else b -= a;
    }
    return a;
}

int main(){
    int n, a, b;
    cout << "Zadejte pocet cisel: ";
    cin >> n;
    cout << "Zadejte cislo: ";
    cin >> a;
    for (int i = 0; i < n-1; i++){
        cout << "Zadejte cislo: ";
        cin >> b;
        a = nsd(a, b);
    }
    cout << "------------\n\nVysledek: " << a << endl;
    return 0;
}