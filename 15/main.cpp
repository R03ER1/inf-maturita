#include <iostream>
#include <cmath>

using namespace std;

float f(float x){
    float y = x*x*x*x*x - 3*x*x*x*x - 23*x*x*x + 51*x*x + 94*x - 120;
    return y;
}

float puleni (float a, float b, float presnost){
    float c = (a+b)/2;
    if (f(a)*f(c)<0){
            if (c-a > presnost){
                return puleni(a, c, presnost);
            } else {
                return c;
            }
    } else {
        if (b-c > presnost){
            return puleni(c, b, presnost);
        } else {
            return c;
        }
    }
}

void hledaniX(float minimum, float maximum, float krok, float presnost) {
    for(float i = minimum; i < maximum; i += krok){
        if(f(i)*f(i+krok)<0){
            cout << "nalezen koren na intervalu <" << i << ";" << i+krok << ">.\n";
            cout << "koren se nachazi na pozici " << puleni(i, i+krok, presnost) << "\n";
        }
    }

}

int main()
{
    float minimum, maximum, krok, presnost;
    cout << "Minimum: ";
    cin >> minimum;
    cout << "Maximum: ";
    cin >> maximum;
    cout << "Krok: ";
    cin >> krok;
    cout << "Presnost: ";
    cin >> presnost;
    hledaniX(minimum, maximum, krok, presnost);
    return 0;
}
