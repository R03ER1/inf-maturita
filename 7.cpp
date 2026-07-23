#include <iostream>

using namespace std;

double mocnina(double zaklad, int exponent){
    if (exponent == 0){
        return 1.0;
    }
    return zaklad * mocnina(zaklad, exponent - 1);
}

int factorial(int n){
    if (n == 0)
        return 1;
    return n * factorial(n - 1);
}

int main() {
    //vypocet e na x
    double e = 0;
    double x = 1.0;
    cin >> x;
    int i = 0;
    do{
        e += mocnina(x, i) / factorial(i);
        i++;
    }while(mocnina(x, i) / factorial(i) > 0.00001);
    cout << "e^" << x << " = " << e << endl;
    return 0;
}
