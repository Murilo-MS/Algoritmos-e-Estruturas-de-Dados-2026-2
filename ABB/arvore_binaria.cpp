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
        cout << "Não existe " << v << " na árvore" << endl;
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

void print(node* r){
    cout << r->esq->valor << " <- " << r->valor  << " -> " << r->dir->valor << endl;
}

int main(){

    node* raiz = nullptr;

    cria(raiz, 10);
    cria(raiz, 11);
    cria(raiz, 8);

    print(raiz);

    busca(raiz, 3);

    return 0;
}