#include "automato.h"
#include <iostream>
#include <string.h>
#include <string>
#include <vector>
#include <math.h>

using namespace std;

Automato::~Automato() {}

void Automato::lerAteChaveEsquerda(FILE *f) {
    char c[2];
    while(fread(c, sizeof(char), 1, f) != EOF && *c != '{');
}

void Automato::lerAlfabeto(FILE *f) {
    char c[2], separador[2];
    separador[0] = 'a';
    while(separador[0] != '}') {
        fread(c, sizeof(char), 1, f);
        this->alfabeto.push_back(c[0]);
        fread(separador, sizeof(char), 1, f);
    }
}

void Automato::lerEstados(FILE *f) {
    char c[3], separador[2];
    int numVirgulas = 0;
    separador[0] = 'b';
    while(separador[0] != '}') {
        fread(c, sizeof(char), 2, f);
        fread(separador, sizeof(char), 1, f);
        if (separador[0]==',') numVirgulas++;
    }
    this->qntdEstados = numVirgulas+1;

    this->transicoes.resize(this->qntdEstados);
}

void Automato::lerEstadosFinais(FILE *f) {
    char c[3], separador[2], numero[10];
    separador[0] = 'c';
    while(separador[0] != '}') {
        fscanf(f, "%[^,}]", numero);
        fread(separador, sizeof(char), 1, f);
        int num = 0;
        for(int i = strlen(numero)-1, j=0; i > 0; i--, j++) {
            num += (numero[i] - '0') * pow(10, j);
        }
        this->estadosFinais.push_back(num);
    }
}

void Automato::lerTransicoes(FILE *f) {
    char entrada[10], transicao[2], saida[10];
    while(fscanf(f, " ( %[^,] , %c ) = %s", entrada, transicao, saida) == 3) {
        int e = 0, s = 0;
        for(int i = strlen(entrada)-1, k=0; i > 0; i--, k++) {
            e += (entrada[i] - '0') * pow(10, k);
        }
        for(int i = strlen(saida)-1, k=0; i > 0; i--, k++) {
            s += (saida[i] - '0') * pow(10, k);
        }
        this->transicoes[e].push_back({s, transicao[0]});
    }
}

Automato::Automato() {
    printf("Digite o nome do arquivo: ");
    
    char arqBuffer[MAXBUFFER+1];
    cin >> arqBuffer;

    FILE *f = fopen(arqBuffer, "r");
    lerAteChaveEsquerda(f);
    lerAlfabeto(f);  
    lerAteChaveEsquerda(f);
    lerEstados(f);
    lerAteChaveEsquerda(f);
    lerEstadosFinais(f);
    lerTransicoes(f);

    fclose(f);
}