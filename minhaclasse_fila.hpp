#pragma once    

#include <string>


class Fila{

    private:

        int primeiro;
        int elementos;
        int tamanho;
        int* conteudo;


    public:

        Fila(int TAMANHO_MAX) {
            tamanho = TAMANHO_MAX;
            primeiro = NULL;
            elementos = 0;
            conteudo = new int(tamanho);
        };

        bool enfilera(int X);
        int desenfilera();
        void mostraFila();
        
        bool vazia(){

            return elementos == 0;
        };

        bool cheia(){

            return elementos == tamanho;
        };
    
    

       
};