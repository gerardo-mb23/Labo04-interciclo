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

// Inserta un paquete al final de la lista

void insertarFinal(Nodo *&head, Nodo *&tail,
                   int id, string nombre, float peso)
{

    // Validar ID único
    if (buscarPorId(head, id))
    {
        cout << "ID repetido.\n";
        return;
    }

    Nodo *nuevo = new Nodo();
    nuevo->id = id;
    nuevo->nombre = nombre;
    nuevo->peso = peso;
    nuevo->sig = NULL;
    nuevo->ant = tail;

    // Lista vacía
    if (listaVacia(head))
    {
        head = nuevo;
        tail = nuevo;
    }
    // Lista con elementos
    else
    {
        tail->sig = nuevo;
        tail = nuevo;
    }
}

// Funcion para mostrar la lista desde el inicio hasta el final

void mostrarAdelante(Nodo *head)
{
    if (listaVacia(head))
    {
        cout << "La lista esta vacía.\n";
        return;
    }
    // Puntero auxiliar
    Nodo *aux = head;
    while (aux != NULL)
    {
        cout << "[ID: " << aux->id
             << ", Nombre: " << aux->nombre
             << ", Peso: " << aux->peso << "] <-> ";
        aux = aux->sig;
    }
    cout << "NULL\n";
}

// Funcion para mostrar la lista desde el final hasta el inicio
void mostrarAtras(Nodo* tail) {
    if (tail == NULL) {
        cout << "Lista vacía.\n";
        return;
    }

    Nodo* aux = tail;
    while (aux != NULL) {
        cout << "[ID: " << aux->id
             << ", Nombre: " << aux->nombre
             << ", Peso: " << aux->peso << "] <-> ";
        aux = aux->ant;
    }
    cout << "NULL\n";
}

int main()
{

    return 0;
}