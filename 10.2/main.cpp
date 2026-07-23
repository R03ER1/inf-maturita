#include <iostream>
#include <cstring>
#include "retezce.h"

using namespace std;

int main()
{
    cout << "Hello world!" << endl;
    char retezec[] = "12345678";
    strdel(retezec, 4, 2);
    for (int i = 0; i < strlen(retezec); i++){
        cout << retezec[i];
    }
    cout << endl;
    strins(retezec, "abc", 2);
    for (int i = 0; i < strlen(retezec); i++){
        cout << retezec[i];
    }
    return 0;
}
