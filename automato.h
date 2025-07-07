#ifndef AUTOMATO_H
#define AUTOMATO_H

#include <string>
#include <vector>

#define MAXBUFFER 200

using namespace std;

class Automato { 
    private:
        int qntdEstados;
        vector<char> alfabeto;
        vector<int> estadosFinais;
    
    public:
        Automato();
        ~Automato();
        void lerAteChaveEsquerda(FILE *f);
        void lerAlfabeto(FILE *f);
        void lerEstados(FILE *f);
        void lerEstadosFinais(FILE *f);
};

#endif