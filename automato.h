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
        // Inicializa o automato
        // Pré-condição: nenhum
        // Pós-condição: autômato é inicializado com dados do arquivo
        Automato();
        // Destrutor
        // Pré-condição: nenhum
        // Pós-condição: autômato é destruído
        ~Automato();
        // Imprime a gramática equivalente ao autômato em notação formal
        // Pré-condição: o autômato já foi inicializado com transições e estados finais
        // Pós-condição: exibe no terminal a gramática correspondente ao autômato
        void imprimirGramatica();
        // Avança o cursor do arquivo pro caracter logo depois de uma chave esquerda
        // Pré-condição: arquivo está aberto para leitura
        // Pós-condição: cursor do arquivo para no caracter logo depois de um {
        void lerAteChaveEsquerda(FILE *f);
        // Adiciona os símbolos do alfabeto ao autômato
        // Pré-condição: arquivo está aberto para leitura
        // Pós-condição: cursor do arquivo para logo depois de um } e automato contém
        // os símbolos do alfabeto
        void lerAlfabeto(FILE *f);
        // Lê a quantidade de estados e atualiza o automato
        // Pré-condição: arquivo está aberto para leitura
        // Pós-condição: quantidade de estados é inicializada no autômato
        void lerEstados(FILE *f);
        // Lê a quantidade de estados finais e atualiza o automato
        // Pré-condição: arquivo está aberto para leitura
        // Pós-condição: insere no automato os estados finais
        void lerEstadosFinais(FILE *f);
        // Lê as transições e atualiza o automato
        // Pré-condição: arquivo está aberto para leitura
        // Pós-condição:insere no automato as transições
        void lerTransicoes(FILE *f);
        // Processa uma cadeia de entrada e verifica se é aceita pelo autômato
        // Pré-condição: o autômato já foi inicializado com estados, alfabeto e transições
        // Pós-condição: imprime a transição de estados e informa se a cadeia foi aceita ou rejeitada
        void processaCadeia(string cadeia, int iterador = 0);
};

#endif
