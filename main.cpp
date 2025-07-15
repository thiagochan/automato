#include "automato.h"
#include <iostream>
using namespace std;

int main() {
    Automato *aut = new Automato();

    string cadeia;

    cout << "Digite a cadeia a ser processada: ";
    cin >> cadeia;

    aut->processaCadeia(cadeia);

    delete aut;
}