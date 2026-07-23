#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    ifstream vstup;
    vstup.open("text.txt");
    if(!vstup.is_open()){
        cout << "soubor nenalezen";
        return 1;
    } else {
        cout << "soubor nalezen\n";
    }
    ofstream vystup;
    vystup.open("vysledek.txt");
    if(!vystup.is_open()){
        cout << "soubor nenalezen";
        return 1;
    } else {
        cout << "soubor nalezen\n";
    }
    string slovo;

    while(vstup >> slovo){
        vystup << slovo;
        cout << slovo;
        if(slovo.length() == 1){
            vystup << "&nbsp";
        } else {
            vystup << " ";
        }
    }

    vstup.close();
    vystup.close();
    return 0;
}
