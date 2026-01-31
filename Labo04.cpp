#include <iostream>

using namespace std;

struct Nodo
{
    int id;
    string nombre;
    float peso;
    Nodo *sig;
    Nodo *ant;
};

/*
Funcion para verifica si la lista está vacía
 Retorna true si no hay nodos
*/
bool listaVacia(Nodo *head)
{
    return head == NULL;
}

/* Fuicion para buscar paquete por su id */

bool buscarPorId(Nodo* head, int id) {
    Nodo* aux = head;
    while (aux != NULL) {
        if (aux->id == id)
            return true;
        aux = aux->sig;
    }
    return false;
    
}


int main()
{

    return 0;
}