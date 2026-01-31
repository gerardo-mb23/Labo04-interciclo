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

/* Funcion para buscar paquete por su id */

bool buscarPorId(Nodo *head, int id)
{
    Nodo *aux = head;
    while (aux != NULL)
    {
        if (aux->id == id)
            return true;
        aux = aux->sig;
    }
    return false;
}
/*
 Funcion para insertar un paquete al inicio de la lista.
 Maneja lista vacía y valida ID repetido
*/
void insertarInicio(Nodo *&head, Nodo *&tail,
                    int id, string nombre, float peso)
{

    // No permitir IDs repetidos
    if (buscarPorId(head, id))
    {
        cout << "ID repetido.\n";
        return;
    }

    Nodo *nuevo = new Nodo();
    nuevo->id = id;
    nuevo->nombre = nombre;
    nuevo->peso = peso;
    nuevo->ant = NULL;
    nuevo->sig = head;

    // Lista vacía
    if (listaVacia(head))
    {
        head = nuevo;
        tail = nuevo;
    }
    // Lista con elementos
    else
    {
        head->ant = nuevo;
        head = nuevo;
    }
}

int main()
{

    return 0;
}