#include "retezce.h"
#include <iostream>
#include <cstring>

using namespace std;

void pozdrav(){}
void pozdravSeJmenem(std::string jmeno){}
void strdel(char *s, int pozice, int pocet){
    int znak = pozice;
    while(s[znak] != 0){
        s[znak] = s[znak+pozice];
        znak++;
    }
}
void strins(char *s1, char *s2, int pozice){
    for (int i = strlen(s1)+strlen(s2); i >= pozice; i--){
        s1[i] = s1[i-strlen(s2)];
    }
    for (int i = pozice; i < pozice + strlen(s2); i++){
        s1[i] = s2[i-pozice];
    }
}
