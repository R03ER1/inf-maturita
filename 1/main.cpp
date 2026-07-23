#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s1, s2;
    int pomocne = 0;
    string vysledek = "";
    cin >> s1;
    cin >> s2;
    int pozice1 = s1.length()-1;
    int pozice2 = s2.length()-1;
    while ((pozice1>=0 && pozice2>=0) || pomocne!=0){
        cout << pozice1 << endl;
        cout << pozice2 << endl;
        int a, b;
        if (pozice1 < 0){
            a = 0;
        } else {
            a = s1[pozice1] - '0';
        }
        if (pozice2 < 0){
            b = 0;
        } else {
            b = s2[pozice2] - '0';
        }
        char novyznak = ((a+b+pomocne)%10) + '0';
        vysledek = novyznak + vysledek;
        cout << vysledek << endl;
        pomocne = ((a + b + pomocne) - ((a + b + pomocne) % 10))/10;
        pozice1--;
        pozice2--;
    }
}
