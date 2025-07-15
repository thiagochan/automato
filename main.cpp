#include "automato.h"
#include <iostream>
using namespace std;

int main() {

    int option = 0;
    Automato *aut = new Automato();
    while(option!=4){
        cout<<"Escolha uma das seguintes opcoes"<<endl;
        cout<<"1 - Imprimir Gramatica"<<endl;
        cout<<"2 - Processar Cadeia"<<endl;
        cout<<"3 - Mudar Automato"<<endl;
        cout<<"4 - Sair"<<endl;

        cin>>option;

        string cadeia;

        switch (option)
        {
        case 1:
            aut->imprimirGramatica();
            break;
        case 2:
            cout << "Digite a cadeia a ser processada: "<< endl;
            cin >> cadeia;
            aut->processaCadeia(cadeia);
            break;
        case 3:
            delete aut;
            aut = new Automato();
            break;
        case 4:
            cout<<"Sistema finalizado"<<endl;
            break;
        
        default:
            break;
        }
    }
  
    delete aut;
}