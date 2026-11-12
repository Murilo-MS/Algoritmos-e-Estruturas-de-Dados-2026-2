/* FilaEncDinamCircular.h
   TAD Fila com alocacao Encadeada e Dinamica de memoria,
   implementada como uma Lista Encadeada Circular.
   Contem exclusivamente as Operacoes Primitivas: Cria, Vazia, Cheia,
   Insere e Retira. */

#include <cstddef> // define NULL

struct Node {
    char Info;
    Node *Next;
};
typedef Node* NodePtr;

struct Fila {
    NodePtr Primeiro;
    NodePtr Ultimo;
};

void Cria(Fila *F) {
    /* Cria a Fila F, inicializando como vazia - sem nenhum elemento */
    F->Primeiro = NULL;
    F->Ultimo = NULL;
}

bool Vazia(Fila *F) {
    /* Retorna verdadeiro se a Fila F estiver sem nenhum elemento */
    return (F->Primeiro == NULL);
}

bool Cheia(Fila *F) {
    /* Nesta implementacao, a fila so fica cheia se a memoria acabar;
       isso e detectado na propria operacao Insere */
    return false;
}

void Insere(Fila *F, char X, bool *DeuCerto) {
    /* Insere o elemento X no final da Fila F */
    NodePtr PAux = new Node;
    if (PAux == NULL) {
        // sem memoria disponivel -> fila esta "cheia"
        *DeuCerto = false;
    } else {
        *DeuCerto = true;
        PAux->Info = X;
        if (Vazia(F)) {
            F->Primeiro = PAux;
            PAux->Next  = PAux;             // aponta para si mesmo
        } else {
            PAux->Next      = F->Primeiro;  // fecha o ciclo com o Primeiro
            F->Ultimo->Next = PAux;         // o antigo ultimo aponta para PAux
        }
        F->Ultimo = PAux;
    }
}

void Retira(Fila *F, char *X, bool *DeuCerto) {
    /* Retira o primeiro elemento da Fila F e retorna seu valor em X */
    NodePtr PAux;
    if (Vazia(F)) {
        *DeuCerto = false;
    } else {
        *DeuCerto = true;
        *X = F->Primeiro->Info;
        PAux = F->Primeiro;
        if (F->Primeiro == F->Ultimo) {
            // caso especial: a fila tinha 1 unico elemento
            F->Primeiro = NULL;
            F->Ultimo   = NULL;
        } else {
            F->Primeiro     = F->Primeiro->Next;
            F->Ultimo->Next = F->Primeiro;  // reamarra o ciclo
        }
        delete PAux;
    }
}
