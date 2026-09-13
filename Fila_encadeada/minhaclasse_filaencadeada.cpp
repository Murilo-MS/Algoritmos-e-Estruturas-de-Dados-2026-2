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

            if(tamanho == 0){

                
            }

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

        int buscaPosicao(int posicao) const{

            Node *atual = primeiro;
            
            for(int i = 0; i < posicao; i++){

                atual = atual->next;
                
            }

            return atual->X;
        }

        void mostraFila() const {

            for(int i = 0; i < tamanho; i++){
                
                cout << buscaPosicao(i) << endl;
            }
            
        
        }
        bool vazia() const {

            return primeiro == nullptr;
        };    

       
};

int main(){

    FilaEncadeada Fila1;

    Fila1.insere(5);
    Fila1.insere(2);
    
    Fila1.mostraFila();

    Fila1.remove();

    Fila1.mostraFila();
    return 1;
}