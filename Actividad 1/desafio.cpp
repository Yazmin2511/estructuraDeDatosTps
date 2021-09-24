#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;
//Define la cantidad maxima de jugadores registrados permitidos
const int MAX = 30;

//Define la cantidad de numeros por carton
const int MAX_NUM = 15;

// ****************************************
// Definicion de estructuras para Carton
typedef struct tnodo2 *pnodo2;

typedef struct tnodo2
{
    int numero;
    pnodo2 sig;
    pnodo2 ant;
};
typedef struct tlista_numeros
{
    pnodo2 inicio;
    int cantidad;
};

typedef struct t_carton
{
    tlista_numeros lista_numeros;
};
// ****************************************
// Definicion de estructuras para Jugador
typedef char tcad[30];
typedef struct t_jugador
{
    tcad nombre;
    tcad apellido;
    long dni;
    int bingos_ganados;
    int puntaje;
    t_carton carton;
};
typedef struct tnodo *pnodo;
typedef struct tnodo
{
    t_jugador jugador;
    pnodo sig;
};
typedef struct tlista_jugador
{
    pnodo inicio;
    int cantidad;
};

// Jugadores
//Metodos encargados de gestionar el menu de jugador

void iniciar_lista(tlista_jugador &lista_jugador)
{
    lista_jugador.inicio = NULL;
    lista_jugador.cantidad = 0;
}

void crear_jugador(pnodo &nuevo)
{
    nuevo = new tnodo;

    if (nuevo != NULL)
    {
        cout << "Nombre del jugador: ";
        cin >> nuevo->jugador.nombre;

        cout << "Apellido del jugador: ";
        cin >> nuevo->jugador.apellido;

        cout << "DNI del jugador: ";
        cin >> nuevo->jugador.dni;

        nuevo->jugador.bingos_ganados = 0;
        nuevo->jugador.puntaje = 0;

        nuevo->sig = NULL;
    }
    else
        cout << "" << endl;
}

void agregar_jugador_lista(tlista_jugador &lista_jugador, pnodo nuevo)
{
    pnodo i;
    if (lista_jugador.cantidad != MAX)
    {
        crear_jugador(nuevo);
        if (lista_jugador.inicio == NULL)
        {
            lista_jugador.inicio = nuevo;
            nuevo->sig = lista_jugador.inicio;
        }
        else
        {
            for (i = lista_jugador.inicio; i->sig != lista_jugador.inicio; i = i->sig)
                ;

            i->sig = nuevo;
            nuevo->sig = lista_jugador.inicio;
        }

        lista_jugador.cantidad++;
    }
    else
        cout << "No se pueden crear mas de " << MAX << " jugadores" << endl;
}

void mostrar_jugadores(tlista_jugador lista_jugador)
{
    pnodo i;
    for (i = lista_jugador.inicio; i->sig != lista_jugador.inicio; i = i->sig)
    {
        cout << "Nombre: " << i->jugador.nombre << endl;
        cout << "Apellido: " << i->jugador.apellido << endl;
        cout << "DNI: " << i->jugador.dni << endl;
        cout << "Bingos ganados: " << i->jugador.bingos_ganados << endl;
        cout << "Puntaje: " << i->jugador.puntaje << endl;
        cout << "*****************" << endl;
    }
    cout << "Nombre: " << i->jugador.nombre << endl;
    cout << "Apellido: " << i->jugador.apellido << endl;
    cout << "DNI: " << i->jugador.dni << endl;
    cout << "Bingos ganados: " << i->jugador.bingos_ganados << endl;
    cout << "Puntaje: " << i->jugador.puntaje << endl;
    cout << "*****************" << endl;
}

void menu_jugadores(tlista_jugador &lista_jugador)
{
    int opcion;
    pnodo nuevo;
    cout << "*********************************" << endl;
    cout << "_______ADMINISTRAR JUGADOR_______" << endl;
    cout << "1. Agregar jugadores" << endl;
    cout << "2. Listar jugadores" << endl;
    cout << "3. Volver al menu anterior" << endl;
    cout << "Seleccione la opcion deseada: " << endl;
    cin >> opcion;

    switch (opcion)
    {
    case 1:
        agregar_jugador_lista(lista_jugador, nuevo);
        break;
    case 2:
        mostrar_jugadores(lista_jugador);
        break;
    case 3:
        cout << "Volviendo..." << endl;
        break;
    default:
        cout << "Opcion invalida ..." << endl;
        break;
    }
}

// Cartones

void iniciar_lista_numeros(tlista_numeros &lista_numeros) // Va cuando se le asigna un carton a cada jugador
{
    lista_numeros.inicio = NULL;
    lista_numeros.cantidad = 0;
}

bool comprobacion(tlista_numeros lista, int num)
{
    pnodo2 j;

    bool existe = false;
    if (lista.inicio != NULL)
    {
        for (j = lista.inicio; existe == true || j->sig == NULL; j = j->sig)
        {
            if (j->numero == num)
                existe = true;
        }
    }
    return existe;
}

void crear_nodo(pnodo2 &nuevo)
{
    int num;
    nuevo = new tnodo2;
    nuevo->ant = NULL;
    nuevo->sig = NULL;
}

int generar_numero(tlista_numeros lista, int &num)
{
    srand(time(NULL));
    //srand((unsigned)time(0));
    do
    {
        num = 1 + rand() % (91 - 1);
    } while (comprobacion(lista, num) == true);

    return num;
}

void agregar_numero(tlista_numeros &lista_numeros, pnodo2 nuevo)
{
    pnodo2 j;
    int num, cont = 0;

    if (lista_numeros.inicio == NULL)
        lista_numeros.inicio = nuevo;
    else
    {
        for (j = lista_numeros.inicio; j->sig == NULL; j = j->sig)
            ;
        j->sig = nuevo;
        nuevo->ant = j;
    }
}

void llenar_carton(tlista_numeros &lista_numeros)
{
    int cont, num;
    pnodo2 i;
    for (cont = 0; cont -1 != MAX_NUM; cont++)
    {
       // crear_nodo(i);
        num = generar_numero(lista_numeros, num);
        i->numero = num;
        agregar_numero(lista_numeros, i);
    }
}

void mostrar_carton(tlista_numeros lista_numeros)
{
    pnodo2 i;
    for (i = lista_numeros.inicio; i != NULL; i = i->sig)
    {
        cout << "Nro: " << i->numero << endl;
    }
}

//Juego

void menu(int &opcion)
{
    cout << "****************************" << endl;
    cout << "_______MENU PRINCIPAL_______" << endl;
    cout << "1. Administrar jugadores" << endl;
    cout << "2. Generar cartones" << endl;
    cout << "3. Iniciar bingo" << endl;
    cout << "4. Ranking ganadores" << endl;
    cout << "5. Salir" << endl;
    cout << "Seleccione la opcion deseada: " << endl;
    cin >> opcion;
}

int main()
{ //Variables
    int opcion;
    tlista_jugador lista_jugador;
    tlista_numeros lista_numeros;
    iniciar_lista(lista_jugador);

    bool condicion_jugadores = lista_jugador.cantidad > 1;
    bool condicion_cartones;

    do
    {
        menu(opcion);
        switch (opcion)
        {
        case 1:
            system("clear");
            menu_jugadores(lista_jugador);
            break;
        case 2:
            if (condicion_jugadores == true)
            {
            }
            else
                cout << "Jugadores insuficientes" << endl;
            break;
        case 3:
            llenar_carton(lista_numeros);
            mostrar_carton(lista_numeros);
            /* if(condicion_jugadores&&condicion_cartones)
                {

                }
                else
                    cout<<"Jugadores insuficientes , o cartones no generados ..."<<endl; */
            break;
        case 4:
            break;
        case 5:
            cout << "Gracias por jugar ... " << endl;
            break;

        default:
            cout << "Opcion invalida" << endl;
            break;
        }

    } while (opcion != 5);
}