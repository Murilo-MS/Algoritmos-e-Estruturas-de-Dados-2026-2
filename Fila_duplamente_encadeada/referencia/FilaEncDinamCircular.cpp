/* FilaEncDinamCircular.cpp
   Programa principal para testar o TAD Fila (FilaEncDinamCircular.h).
   Assim como no F3, Imprime e Destroi sao operacoes NAO primitivas:
   sao construidas exclusivamente a partir das operacoes primitivas do
   TAD (Cria, Vazia, Cheia, Insere, Retira), sem acessar diretamente os
   campos internos de Node ou Fila. Por isso este mesmo programa
   principal funciona sem qualquer alteracao com qualquer implementacao
   do TAD Fila (sequencial/estatica ou encadeada/dinamica, linear ou
   circular) - esse e o teste de portabilidade pedido no NP4. */

#include "FilaEncDinamCircular.h"
#include <iostream>
using namespace std;

void Imprime(Fila *F) { // operacao NAO primitiva
    char X;
    Fila FAux;
    bool Ok;
    Cria(&FAux);
    while (!Vazia(F)) {           // esvazia F em FAux, preservando a ordem
        Retira(F, &X, &Ok);
        if (Ok) Insere(&FAux, X, &Ok);
    }
    cout << "\n F.Primeiro --> ";
    while (!Vazia(&FAux)) {       // devolve de FAux para F, imprimindo
        Retira(&FAux, &X, &Ok);
        if (Ok) {
            cout << X << " ";
            Insere(F, X, &Ok);
        }
    }
    cout << " <-- F.Ultimo\n";
}

void Destroi(Fila *F) { // operacao NAO primitiva
    char X;
    bool Ok;
    while (!Vazia(F)) {
        Retira(F, &X, &Ok);
    }
}

int main() {
    Fila F;
    Cria(&F);
    bool Ok;
    char Valor;
    char Op = 't';

    while (Op != 's') {
        cout << "digite: (i)inserir, (r)retirar, (s)sair [enter]" << endl;
        cin >> Op;
        switch (Op) {
            case 'i':
                cout << "digite um UNICO CARACTER para inserir [enter]" << endl;
                cin >> Valor;
                Insere(&F, Valor, &Ok);
                if (Ok) cout << "> valor inserido" << endl;
                else cout << "> nao conseguiu inserir" << endl;
                break;
            case 'r':
                Retira(&F, &Valor, &Ok);
                if (Ok) cout << "valor retirado = " << Valor << endl;
                else cout << "nao conseguiu retirar" << endl;
                break;
            default:
                cout << "saindo..." << endl;
                Op = 's';
                break;
        } // switch
        Imprime(&F);
    } // while

    Destroi(&F); // retira todos os elementos da fila
    cout << "a fila apos a operacao destroi..." << endl;
    Imprime(&F);

    return 0;
}
