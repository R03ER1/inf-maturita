#include <iostream>
#include <string>
#include "retezce.h"

using namespace std;

int main()
{
    char ahoj[] = "Hellllo world\n";
    cout << ahoj;
    strdel(ahoj, 2, 2);
    cout << ahoj;
    strins(ahoj, " hello", 5);
    cout << ahoj;
    return 0;

}
