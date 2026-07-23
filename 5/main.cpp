#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void nacteniMatice(int mat[5][5], char nazevSouboru[]){
    ifstream soubor;
    soubor.open(nazevSouboru);
    for (int i = 0; i < 5; i++){
        for (int j = 0; j < 5; j++){
            soubor >> mat[i][j];
        }
    }
    soubor.close();
}

void vypsaniMatice(int mat[5][5], char nazevSouboru[]){
    ofstream soubor;
    soubor.open(nazevSouboru);
    for (int i = 0; i < 5; i++){
        for (int j = 0; j < 5; j++){
            soubor << mat[i][j] << " ";
        }
        soubor << "\n";
    }
    soubor.close();
}

void soucetMatic(int A[][5], int B[][5], int C[][5]){
    for (int i = 0; i < 5; i++){
        for (int j = 0; j < 5; j++){
            C[i][j] = A[i][j] + B[i][j];
        }
    }
}

int main()
{
    int A[5][5], B[5][5], C[5][5];
    nacteniMatice(A, "mata.txt");
    nacteniMatice(B, "matb.txt");
    soucetMatic(A, B, C);
    vypsaniMatice(C, "matc.txt");
    return 0;
}
