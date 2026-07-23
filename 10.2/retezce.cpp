#include "retezce.h"
#include <iostream>
#include <cstring>

void strdel(char *s, int pozice, int pocet){
    char novyRetezec[strlen(s) - pocet];
    for (int i = 0; i < strlen(novyRetezec); i++){
        if (i < pozice){
            novyRetezec[i] = s[i];
        } else {
            novyRetezec[i] = s[i + pocet];
        }
    }
    strcpy(s, novyRetezec);
}
void strins(char *s1, char *s2, int pozice){
    for (int i = strlen(s1)+strlen(s2); i >= pozice; i--){
        s1[i] = s1[i-strlen(s2)];
    }
    for (int i = pozice; i < pozice + strlen(s2); i++){
        s1[i] = s2[i-pozice];
    }

}
