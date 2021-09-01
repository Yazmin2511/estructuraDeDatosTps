#include<iostream>
#include<stdlib.h>
#include <cstring>

using namespace std;

typedef struct tnodo *pnodo;
typedef struct tnodo {
                        char dato;
                        pnodo sig;
                     };
typedef struct tlista{
                        pnodo inicio;
                     };
void iniciar_lista( tlista&lista )
{
    lista.inicio=NULL;
}

void crear_nodo(pnodo&nuevo)
{
    nuevo = new tnodo;
    if(nuevo!=NULL)
    {
        cout<<"Ingrese nuevo valor: "<<endl;
        cin>>nuevo->dato;
        nuevo->sig=NULL;
    }
    else
        cout<<"MEMORIA INSUFICICENTE"<<endl;
}

bool buscar_nodo(tlista lista, char buscado)
{
    bool encontrado=false;
    pnodo i;

    if(lista.inicio!=NULL)
    {
        for(i=lista.inicio; i!=NULL && !encontrado; i= i->sig)
        {
            if(i->dato==buscado)
                encontrado=true;
        }
    }
    return encontrado;
}

void agregar_inicio(tlista&lista, pnodo&nuevo)
{
        nuevo->sig=lista.inicio;
        lista.inicio=nuevo;
}

void agregar_orden(tlista&lista, pnodo&nuevo)
{
    if(lista.inicio==NULL)
    {
        lista.inicio=nuevo;
    }
    else
    {
        bool existe=buscar_nodo(lista, nuevo->dato);
        if(existe==false)
        {
            if(lista.inicio->sig==NULL)
            {
                if(lista.inicio->dato<nuevo->dato)
                    agregar_inicio(lista,nuevo);
            }

        }
        else
            delete(nuevo);

    }
}

void mostrar_lista(tlista lista)
{
    pnodo i=lista.inicio;

            while(i!=NULL)
            {
                cout<<"Valor: "<< i->dato<<endl;
                i=i->sig;
            }
}

void menu (int&opcion)
{
    cout<<"̣̣̣̣̣___________________________________"<<endl;
    cout<<"*********Menu Principal***********"<<endl;
    cout<<"1. Iniciar lista"<<endl;
    cout<<"2. Crear y agregar nodo"<<endl;
    cout<<"3. Mostrar"<<endl;
    cout<<"4. Quitar"<<endl;
    cout<<"5. Salir"<<endl;

    cout<<"Elija opcion "<<endl;
    cin>>opcion;

    system("clear");

}


int main()
{
    int opcion=0;
    tlista lista;
    pnodo nuevo;

    do{
        menu(opcion);
        switch(opcion)
        {
            case 1: iniciar_lista(lista);
                break;
            case 2: crear_nodo(nuevo);
                    agregar_orden(lista, nuevo);
                break;
            case 3: mostrar_lista(lista);
                break;
            case 4: //quitar_final(lista);
                break;
            case 5: cout<<"Salilendo..."<<endl;
                break;
        }
    }while(opcion!=5);

}
