#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    fstream souborCteni;
    souborCteni.open("text.txt");
    char text[200];
    souborCteni.seekg(0, fstream::end);
    int delka = souborCteni.tellg();
    char pismeno;
    int pozice = 0;

    for (int i = 0; i < delka; i++){
        souborCteni.seekg(i, fstream::beg);
        pismeno = souborCteni.get();
        cout << pismeno << endl;
        if(pismeno == ' '){
            text[pozice] = '&';
            pozice ++;
            text[pozice] = 'n';
            pozice ++;
            text[pozice] = 'b';
            pozice ++;
            text[pozice] = 's';
            pozice ++;
            text[pozice] = 'p';
            pozice ++;

        } else {
            text[pozice] = pismeno;
            pozice ++;
        }

    }
    souborCteni.seekp(0);
    souborCteni.write(text, pozice);


}
