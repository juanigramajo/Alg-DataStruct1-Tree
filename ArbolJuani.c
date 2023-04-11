#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<limits.h>
#include<string.h>


typedef char item;
const char indefinido = '#';


struct arbol {
    item raiz;
    struct arbol *izq;
    struct arbol *der;
};
typedef struct arbol *AB;



AB ABVacio();
AB armarAB(AB I, item x, AB D);
bool esABVacio(AB A);
item raiz(AB A);
AB izquierdo(AB A);
AB derecho(AB A);
bool pertenece(AB A, item x);
bool esHoja(AB A);
void preorden(AB A);
void postorden(AB A);
void enorden(AB A);





int main(){

    return 0;
}



AB ABVacio()
{
    AB A;
    A = NULL;

    return A;
}

AB armarAB(AB I, item x, AB D)
{
    AB nodo = (AB)malloc(sizeof(struct arbol));

    nodo->izq = I;
    nodo->raiz = x;
    nodo->der = D;

    return nodo;
}

bool esABVacio(AB A)
{
    if (A==NULL)
    {
        return(true);
    } else
    {
        return(false);
    }
}

item raiz(AB A)
{
    if (esABVacio(A))
    {
        return indefinido;
    } else
    {
        return A->raiz;
    }
}

AB izquierdo(AB A)
{
    if (esABVacio(A))
    {
        return ABVacio();
    } else
    {
        return A->izq;
    }
}

AB derecho(AB A)
{
    if (esABVacio(A))
    {
        return ABVacio();    
    } else
    {
        return A->der;
    }
}

bool pertenece(AB A, item x)
{
    if (esABVacio(A))
    {
        return false;
    } else if (raiz(A) == x)
    {
        return true;
    } else
    {
        return pertenece(A->der, x), pertenece(A->izq, x);
    }
}

bool esHoja(AB A)
{

    if (izquierdo(A) == NULL && derecho(A) == NULL)
    {
        return true;
    } else
    {
        return false;
    }
}

void preorden(AB A)
{
    if (!esABVacio(A))
    {
        printf("%c | ", raiz(A));
        preorden(izquierdo(A));
        preorden(derecho(A));
    }
}

void postorden(AB A)
{

    if(!esABVacio(A))
    {
        postorden(izquierdo(A));
        postorden(derecho(A));
        printf("%c | ", raiz(A));
    }
}

void enorden(AB A)
{
    if(!esABVacio(A))
    {
        enorden(izquierdo(A));
        printf("%c | ", raiz(A));
        enorden(derecho(A));
    }
}
