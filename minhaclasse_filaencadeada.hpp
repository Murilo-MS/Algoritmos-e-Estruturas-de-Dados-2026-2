#pragma once    

#include <string>

class Node{

        Node *next;
        int X;
};

class FilaEncadeada{

    private:

        Node *primeiro;
        Node *ultimo;


    public:

        FilaEncadeada() {

            primeiro = nullptr;
            ultimo = nullptr;
            
        };

        bool insere(int X);
        int remove();
        void mostraFila();
        
        bool vazia(){

            return primeiro == nullptr;
        };    

       
};