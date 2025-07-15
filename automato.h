#ifndef AUTOMATO_H
#define AUTOMATO_H

#include <string>
#include <vector>
#include <utility>

#define MAXBUFFER 200

using namespace std;

class Automato { 
    private:
        int qntdEstados;
        vector<char> alfabeto;
        vector<int> estadosFinais;
        vector<vector<pair<int, char>>> transicoes;
    
    public:
        Automato();
        ~Automato();
        void lerAteChaveEsquerda(FILE *f);
        void lerAlfabeto(FILE *f);
        void lerEstados(FILE *f);
        void lerEstadosFinais(FILE *f);
        void lerTransicoes(FILE *f);
        void processaCadeia(string cadeia, int iterador = 0);
};

#endif