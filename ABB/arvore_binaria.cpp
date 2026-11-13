#include <iostream>
using namespace std;

struct node{
    int valor;
    int nivel = 0;
    node* esq = nullptr;
    node* dir = nullptr; 

    node(int v) : valor(v) {}
};

void cria(node*& r, int v, int n = 0){
    if (r == nullptr){
        r = new node(v);
        r->nivel = n;
    }
    else if(r->valor > v){
        cria(r->esq, v, r->nivel + 1);        
    }
    else if (r->valor < v)
    {
        cria(r->dir, v, r->nivel + 1);
    }
}

node* busca(node* r,int v)
{
    if(r == nullptr){
        //cout << "Não existe " << v << " na árvore" << endl;
        return nullptr;
    }
    else if(r->valor == v){
        return r;
    }
    else if (r->valor < v)
    {
        return busca(r->dir, v);
    }
    else
    {
        return busca(r->esq, v);
    }
}

int const maiorNivel(node* r, int nivelAtual = 0){
    if(r == nullptr){
        cout << "não há árvore"  << endl;
        return -1;
    }
    else if(r->dir == nullptr && r->esq == nullptr){
        return nivelAtual;
    }
    else if(r->esq != nullptr && r->dir != nullptr){
        int nivelEsquerdo = maiorNivel(r->esq, nivelAtual + 1);
        int nivelDireito = maiorNivel(r->dir, nivelAtual + 1);
        
        if(nivelEsquerdo > nivelDireito){
            return nivelEsquerdo;
        }
        else return nivelDireito;
    }
    else if(r->esq != nullptr){
        return maiorNivel(r->esq, nivelAtual + 1);
    }
    else{
        return maiorNivel(r->dir, nivelAtual + 1);
    }
    
}

void apaga(node*& r, int v){

    node* aux = busca(r, v); 

    if(aux != nullptr){
        delete(aux);
    }
    else{
        cout << "Não há o valor "<< v << " na árvore para ser deletado" << endl;
    }
}

void print(node* r) {
    if (r == nullptr) return;

    if (r->esq != nullptr) cout << r->esq->valor;
    else cout << "null";

    cout << " <- " << r->valor << " -> ";

    if (r->dir != nullptr) cout << r->dir->valor;
    else cout << "null";

    cout << endl;
}

int main(){

    node* raiz = nullptr;

    cria(raiz, 10);
    cria(raiz, 11);
    cria(raiz, 8);

    print(raiz);

    //busca(raiz, 3);

    apaga(raiz, 8);
    apaga(raiz, 7);

    print(raiz);

    return 0;
}