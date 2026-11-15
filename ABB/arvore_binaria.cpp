#include <iostream>
#include <algorithm>
using namespace std;

struct node{
    int valor;
    int nivel = 0;
    node* esq = nullptr;
    node* dir = nullptr; 

    node(int v) : valor(v) {}
};

typedef node* NodePtr;

bool vazia(NodePtr r)
{
    return r == nullptr;
}

void cria(NodePtr& r, int v, int n = 0)
{
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

NodePtr busca(NodePtr r,int v)
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

bool estaNaArvore(NodePtr r, int v)
{
    return (busca(r, v) != nullptr);
}

int const maiorNivel(NodePtr r, int nivelAtual = 0)
{
    if(vazia(r)){
        return -1;
    }
   
    int nivelEsquerdo = maiorNivel(r->esq, nivelAtual + 1);
    int nivelDireito = maiorNivel(r->dir, nivelAtual + 1);
        
    return max(nivelDireito, nivelEsquerdo);   
}

/*
void apaga(NodePtr& r, int v, NodePtr pai = nullptr){

    NodePtr aux = busca(r, v); 

    if(vazia(r)){
        return;
    }
    else{
        if(pai == nullptr) delete(aux);

        else{
            
        }
    }
}
*/

void print(NodePtr r)
{
    if (r == nullptr) return;

    if (r->esq != nullptr) cout << r->esq->valor;
    else cout << "null";

    cout << " <- " << r->valor << " -> ";

    if (r->dir != nullptr) cout << r->dir->valor;
    else cout << "null";

    cout << endl;
}

int main()
{
    NodePtr raiz = nullptr;

    cria(raiz, 10);
    cria(raiz, 11);
    cria(raiz, 8);

    print(raiz);

    //busca(raiz, 3);

    //apaga(raiz, 8);
    //apaga(raiz, 7);

    print(raiz);

    return 0;
}