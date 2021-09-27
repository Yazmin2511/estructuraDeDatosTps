#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;
//Define la cantidad maxima de jugadores registrados permitidos
const int MAX = 30;

//Define el puntaje maximo por partida ganada
const int PUNTAJE = 50;

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
    pnodo2 final;
    int cantidad;
};
typedef struct t_carton
{
    int nro_carton;
    tlista_numeros lista_numeros;
};

typedef t_carton lista_cartones[MAX]; // Ya que se asigna un carton por jugador, se utiliza MAX

// ****************************************
// Definicion de estructuras para Jugador
typedef char tcad[30];
typedef struct t_jugador
{
    int nro_carton;
    tcad nombre;
    tcad apellido;
    long dni;
    int bingos_ganados;
    int puntaje;
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

// Cartones

void iniciar_lista_numeros(tlista_numeros &lista_numeros) // Va cuando se le asigna un carton a cada jugador
{
    lista_numeros.inicio = NULL;
    lista_numeros.final = NULL;
    lista_numeros.cantidad = 0;
}

bool comprobacion(tlista_numeros lista, int num)
{
    pnodo2 j;

    bool existe = false;
    if (lista.inicio != NULL)
    {
        for (j = lista.inicio; existe != true && j != lista.final; j = j->sig)
        {
            if (j->numero == num)
                existe = true;
        }
    }
    return existe;
}

void crear_nodo(pnodo2 &nuevo, int valor)
{
    nuevo = new tnodo2;
    if (nuevo != NULL)
    {
        nuevo->numero = valor;
        nuevo->ant = NULL;
        nuevo->sig = NULL;
    }
    else
        cout << "MEMORIA INSUFICIENTE" << endl;
}

int generar_numero(tlista_numeros lista)
{
    int num;
    do
    {
        num = 1 + rand() % (91 - 1);
    } while (comprobacion(lista, num) == true);

    return num;
}

void agregar_numero(tlista_numeros &lista_numeros, pnodo2 nuevo)
{
    pnodo2 j, i;

    int num, cont = 0;

    if (lista_numeros.inicio == NULL)
    {
        lista_numeros.inicio = nuevo;
        lista_numeros.final = nuevo;
    }
    else
    {
        if (nuevo->numero < lista_numeros.inicio->numero)
        {
            nuevo->sig = lista_numeros.inicio;
            lista_numeros.inicio->ant = nuevo;
            lista_numeros.inicio = nuevo;
        }
        else
        {
            if (lista_numeros.final->numero < nuevo->numero)
            {
                lista_numeros.final->sig = nuevo;
                nuevo->ant = lista_numeros.final;
                lista_numeros.final = nuevo;
            }
            else
            {
                for (i = lista_numeros.inicio; i->sig != NULL && nuevo->numero > (i->sig)->numero; i = i->sig)
                    ;
                nuevo->sig = i->sig;
                nuevo->ant = i;
                i->sig = nuevo;
            }
        }
    }

    lista_numeros.cantidad++;
}

void llenar_carton(tlista_numeros &lista_numeros)
{
    int cont = 0;
    pnodo2 i;
    for (cont = 0; cont != 15; cont++) // Cambiar 15 por una constante
    {
        crear_nodo(i, generar_numero(lista_numeros));
        agregar_numero(lista_numeros, i);
    }
}

void mostrar_carton(lista_cartones lista_cartones, tlista_jugador lista_jugadores) //Corregido
{
    pnodo2 i;
    int j;

    for (j = 0; j < lista_jugadores.cantidad; j = j + 1)
    {

        cout << "Carton N" << j << endl;

        for (i = lista_cartones[j].lista_numeros.inicio; i != NULL; i = i->sig)
        {
            cout << "Nro: " << i->numero << endl;
        }
    }
}

void asignar_carton(tlista_jugador &lista_jugadores, lista_cartones &lista)
{
    int cont, j, i;
    pnodo x = lista_jugadores.inicio;
    tlista_numeros lista_num;

    srand(time(NULL));
    for (j = 0; j < lista_jugadores.cantidad; j = j + 1) //
    {
        iniciar_lista_numeros(lista[j].lista_numeros);
        llenar_carton(lista[j].lista_numeros);
        lista[j].nro_carton = j;

        for (i = 0; i != j; i++)
        {
            x = x->sig;
        }
        x->jugador.nro_carton = j;
    }
}

//Jugar

void liberar_memoria(tlista_numeros &lista, pnodo2 x)
{
    pnodo2 aux;
    if (lista.inicio != NULL)
    {
        if (lista.inicio == lista.final)
        {
            aux = lista.inicio;
            lista.inicio = NULL;
            lista.final = NULL;
        }
        else
        {
            aux = lista.inicio;
            lista.inicio = lista.inicio->sig;
            lista.inicio->ant = NULL;
            aux->sig = NULL;
        }
    }

    delete (aux);
}

void mostrar_ganador(pnodo jugador)
{
    pnodo i;

    cout << "********************************" << endl;
    cout << "***********FELICIDADES**********" << endl;
    cout << "********************************" << endl;

    cout << "NOMBRE: " << jugador->jugador.nombre << " - PUNTAJE: " << jugador->jugador.puntaje << endl;
}

void agregar_numero_bingo(tlista_numeros &lista_numeros, pnodo2 nuevo)
{
    pnodo2 j, i;

    int num, cont = 0;

    if (lista_numeros.inicio == NULL)
    {
        lista_numeros.inicio = nuevo;
        lista_numeros.final = nuevo;
    }
    else
    {
        lista_numeros.final->sig = nuevo;
        nuevo->ant = lista_numeros.final;
        lista_numeros.final = nuevo;
    }
}

tlista_numeros generar_bingo(tlista_numeros &lista_numeros_bingo)
{
    int cont = 0;
    pnodo2 i;
    srand(time(NULL));
    for (cont = 0; cont != 90; cont++) //
    {
        crear_nodo(i, generar_numero(lista_numeros_bingo));
        agregar_numero_bingo(lista_numeros_bingo, i);
    }

    return lista_numeros_bingo;
}

void eliminar_pnodo(tlista_numeros &lista_numeros, int valor) 
{
    pnodo2 aux, i;
    if (lista_numeros.inicio == NULL)
    {
        aux = NULL;
    }
    else
    {
        if (lista_numeros.inicio->numero == valor)
        {
            if (lista_numeros.inicio == lista_numeros.final)
            {
                aux = lista_numeros.inicio;
                lista_numeros.inicio = NULL;
                lista_numeros.final = NULL;
                lista_numeros.cantidad--;
            }
            else
            {
                aux = lista_numeros.inicio;
                lista_numeros.inicio = lista_numeros.inicio->sig;
                lista_numeros.inicio->ant = NULL;
                aux->sig = NULL;
                lista_numeros.cantidad--;
            }
        }
        else
        {
            if (lista_numeros.final->numero == valor)
            {
                aux = lista_numeros.final;
                lista_numeros.final = lista_numeros.final->ant;
                lista_numeros.final->sig = NULL;
                aux->ant = NULL;
                lista_numeros.cantidad--;
            }
            else
            {
                for (i = lista_numeros.inicio; i != NULL && i->numero != valor; i = i->sig)
                    ;
                if (i != NULL)
                {
                    aux = i;
                    (i->ant)->sig = aux->sig;
                    (i->sig)->ant = aux->ant;
                    aux->sig = NULL;
                    aux->ant = NULL;
                    lista_numeros.cantidad--;
                }
            }
        }
    }
}

int verificar_ganadores(tlista_jugador lista_jugador, lista_cartones carton_jugador)
{
    int cantidad_ganadores = 1;

    for (int i = 0; i < lista_jugador.cantidad; i++)
    {
        if (carton_jugador[i].lista_numeros.cantidad<=0)
            cantidad_ganadores++;
    }
    return cantidad_ganadores;
}

void buscar_modificar_jugador(tlista_jugador &lista_jugador, lista_cartones &carton_jugador)
{
    int nro_carton = 0;
    int cantidad_ganadores = verificar_ganadores(lista_jugador, carton_jugador);
    pnodo k;

    for (int j = 0; j < lista_jugador.cantidad; j++)
    {

        if (carton_jugador[j].lista_numeros.cantidad <= 0 )
        {
            nro_carton = carton_jugador[j].nro_carton;
            for (k = lista_jugador.inicio; k->sig != lista_jugador.inicio && k->jugador.nro_carton != nro_carton; k = k->sig)
                ;
            k->jugador.bingos_ganados++;
            k->jugador.puntaje = PUNTAJE / cantidad_ganadores;
            mostrar_ganador(k);
        }
    }
}

void juego(lista_cartones &carton_jugador, tlista_jugador &jugadores, tlista_numeros bingo)
{
    int jug;
    pnodo2 j;
    bool terminar = false;

    for (j = bingo.inicio; j != NULL && terminar != true; j = j->sig) // Recorre la lista de 90 numeros
    {   jug=jugadores.cantidad-1;
        while(jug>=0)
        {
            eliminar_pnodo(carton_jugador[jug].lista_numeros, j->numero); // <-- No sirve, no se porque :,c
            if(verificar_ganadores(jugadores, carton_jugador) > 0)
            terminar = true;
            //cout<<carton_jugador[jug].lista_numeros.cantidad<<endl;

            jug--;
        }
             
    }

    if (terminar == true)
    {
        buscar_modificar_jugador(jugadores, carton_jugador);
    }
    else
    {
        system("clear");
        cout << "JUEGO DESIERTO" << endl;
    }
}

// ****************************************************
// Ranking

tlista_jugador lista_ranking(tlista_jugador lista_jugador)
{
    pnodo i, j;
    tlista_jugador aux;
    iniciar_lista(aux);
    j = aux.inicio;

    if (lista_jugador.inicio != NULL)
    {
        for (i = lista_jugador.inicio; i->sig != lista_jugador.inicio; i = i->sig)
        {
            if (i->jugador.puntaje > 0)
            {
                agregar_jugador_lista(aux, i);
            }
        }
    }

    return aux;
}

tlista_jugador ordenar_ranking(tlista_jugador &lista_jugador)
{
    return lista_jugador;
}

void mostrar_ranking(tlista_jugador lista_jugador)
{
    pnodo i;

    cout << "****************************** " << endl;
    cout << "*******RANKING JUGADORES****** " << endl;
    cout << "****************************** " << endl;

    if (lista_jugador.inicio == NULL)
    {
        cout << "****************************** " << endl;
        cout << "**Todavia no hay ganadores****" << endl;
        cout << "****************************** " << endl;
    }
    else
    {
        for (i = lista_jugador.inicio; i->sig != lista_jugador.inicio; i = i->sig)
        {
            cout << "Nombre: " << i->jugador.nombre << " - Puntaje: " << i->jugador.puntaje << endl;
        }
        cout << "Nombre: " << i->jugador.nombre << " - Puntaje: " << i->jugador.puntaje << endl;
    }
}

// MOSTRAR
void mostrar_jugadores(tlista_jugador lista_jugador)
{
    pnodo i;

    if (lista_jugador.cantidad > 0)
    {
        for (i = lista_jugador.inicio; i->sig != lista_jugador.inicio; i = i->sig)
        {
            cout << "Nombre: " << i->jugador.nombre << endl;
            cout << "Apellido: " << i->jugador.apellido << endl;
            cout << "DNI: " << i->jugador.dni << endl;
            cout << "Bingos ganados: " << i->jugador.bingos_ganados << endl;
            cout << "Puntaje: " << i->jugador.puntaje << endl;
            cout << "Numeros de carton : " << endl;
            cout << "*****************" << endl;
        }
        cout << "Nombre: " << i->jugador.nombre << endl;
        cout << "Apellido: " << i->jugador.apellido << endl;
        cout << "DNI: " << i->jugador.dni << endl;
        cout << "Bingos ganados: " << i->jugador.bingos_ganados << endl;
        cout << "Puntaje: " << i->jugador.puntaje << endl;
        cout << "*****************" << endl;
    }
    else
        cout << "No se ha creado ningun jugador" << endl;
}
void mostrar_bingo(tlista_numeros bingo)
{
    for (pnodo2 i = bingo.inicio; i != NULL; i = i->sig)
    {
        cout << "Valor " << i->numero << endl;
    }
}

//Menus
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

int main()
{ //Variables
    int opcion;
    lista_cartones lista_cartones;
    tlista_jugador lista_jugador;
    tlista_jugador l_ranking;
    tlista_numeros lista_numeros;
    tlista_numeros lista_bingo;
    iniciar_lista(lista_jugador);

    bool condicion_jugadores = lista_jugador.cantidad > 1;
    bool condicion_cartones = false;

    //srand(time(NULL));

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
            condicion_jugadores = lista_jugador.cantidad > 1;
            if (condicion_jugadores == true)
            {
                asignar_carton(lista_jugador, lista_cartones);
                //mostrar_carton(lista_cartones, lista_jugador);
                condicion_cartones = true;
            }
            else
                cout << "Jugadores insuficientes" << endl;
            break;
        case 3:
            if (condicion_jugadores && condicion_cartones == true)
            {
                iniciar_lista_numeros(lista_bingo);
                lista_bingo = generar_bingo(lista_bingo);
                //mostrar_bingo(lista_bingo);
                juego(lista_cartones, lista_jugador, lista_bingo);
            }
            else
                cout << "Jugadores insuficientes , o cartones no generados ..." << endl;
            break;
        case 4:
            if (condicion_jugadores && condicion_cartones == true)
            {
                iniciar_lista(l_ranking);
                l_ranking = lista_ranking(lista_jugador);
                mostrar_ranking(l_ranking);
            }

            break;
        case 5:
            //liberar_memoria(lista_jugador, lista_cartones);
            cout << "Liberando espacio en memoria ... " << endl;
            cout << "Gracias por jugar ... " << endl;
            break;

        default:
            cout << "Opcion invalida" << endl;
            break;
        }

    } while (opcion != 6); // Cambiar luego
}