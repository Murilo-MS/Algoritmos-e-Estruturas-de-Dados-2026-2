#include <string>
#include <iostream>

using namespace std;

class Node{

    public:
        Node *next;
        int X;
};

class FilaEncadeada{

    private:

        Node *primeiro;
        Node *ultimo;
        int tamanho;

    public:

        FilaEncadeada() {

            primeiro = nullptr;
            ultimo = nullptr;
            tamanho = 0;
            
        }

        bool insere(int valor){

            Node *aux = new Node;
            aux->X = valor;
            aux->next = nullptr;
            
            if (vazia()){
                primeiro = aux;
                ultimo = aux;
            }
            else{
                ultimo->next = aux;
                ultimo = aux;
            }
            tamanho++;
            return true;
        }
        int remove(){

            int valor;
            Node *aux = primeiro;
            
            valor = aux->X;
            primeiro = aux->next;
            delete aux;

            if(primeiro == nullptr){
                ultimo = nullptr;
            }

            tamanho --;
            return valor;
            
        }
        void mostraFila();
        
        bool vazia(){

            return primeiro == nullptr;
        };    

       
};