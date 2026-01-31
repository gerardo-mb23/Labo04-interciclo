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
void mostrarAtras(Nodo *tail)
{
    if (tail == NULL)
    {
        cout << "Lista vacía.\n";
        return;
    }

    Nodo *aux = tail;
    while (aux != NULL)
    {
        cout << "[ID: " << aux->id
             << ", Nombre: " << aux->nombre
             << ", Peso: " << aux->peso << "] <-> ";
        aux = aux->ant;
    }
    cout << "NULL\n";
}
/*
 Funcion para elimina un paquete por ID
 Maneja todos los casos posibles: borrar head, borrar tail, borrar en medio, lista vacía, id inexistente.
*/
bool eliminarPorId(Nodo *&head, Nodo *&tail, int id)
{

    if (listaVacia(head))
        return false;

    Nodo *act = head;

    while (act != NULL)
    {
        if (act->id == id)
        {

            // Caso: único nodo
            if (act == head && act == tail)
            {
                head = NULL;
                tail = NULL;
            }
            // Eliminar head
            else if (act == head)
            {
                head = head->sig;
                head->ant = NULL;
            }
            // Eliminar tail
            else if (act == tail)
            {
                tail = tail->ant;
                tail->sig = NULL;
            }
            // Eliminar nodo intermedio
            else
            {
                act->ant->sig = act->sig;
                act->sig->ant = act->ant;
            }

            delete act;
            return true;
        }
        act = act->sig;
    }
    return false;
}

int contarPaquetes(Nodo *head)
{
    int cont = 0;
    Nodo *aux = head;

    while (aux != NULL)
    {
        cont++;
        aux = aux->sig;
    }
    return cont;
}

// Funcion para liberar toda la memoria usada por la lista

void liberarLista(Nodo *&head, Nodo *&tail)
{
    while (head != NULL)
    {
        Nodo *borrar = head;
        head = head->sig;
        delete borrar;
    }
    tail = NULL;
}

int main()
{

    return 0;
}