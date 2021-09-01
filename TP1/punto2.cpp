
#include<iostream>
#include<stdlib.h>

using namespace std;

typedef struct tnodo *pnodo;
typedef struct tnodo {
                        float dato;
                        pnodo sig;
                     };

typedef struct tlista{
                        pnodo inicio;
                     };
void iniciar_lista( tlista&lista)
{
  lista.inicio=NULL;
}

void crear_nodo(pnodo&nuevo)
{
    nuevo= new tnodo;
    if(nuevo!=NULL)
    {
        cout<<"Ingreso valor: "<<endl;
        cin>>nuevo->dato;
        nuevo->sig=NULL;
    }
    else
        cout<<"MEMORIA INSUFICIENTE"<<endl;
}

void agregar_inicio(tlista&lista, pnodo&nuevo)
{
    nuevo->sig=lista.inicio;
    lista.inicio=nuevo;
}

pnodo quitar_final(tlista&lista)
{
    pnodo aux , i ;

    if(lista.inicio!=NULL)
    {
        if(lista.inicio->sig==NULL)
        {
            aux=lista.inicio;
            lista.inicio=NULL;
        }
        else
        {
            for(i=lista.inicio; (i->sig)->sig!=NULL; i=i->sig);
            aux=i->sig;
            i->sig=NULL;
        }
    }
    else
        aux=NULL;

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

main()
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
                    agregar_inicio(lista,nuevo);
                break;
            case 3: mostrar_lista(lista);
                break;
            case 4: quitar_final(lista);
                break;
            case 5: cout<<"Salilendo..."<<endl;
                break;
        }
    }while(opcion!=5);


}
