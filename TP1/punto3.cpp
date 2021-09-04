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
{pnodo i;
    if(lista.inicio==NULL)
    {
        lista.inicio=nuevo;
    }
    else
    {
        bool existe=buscar_nodo(lista, nuevo->dato);
        if(existe==false)
        {
            if(lista.inicio==NULL)
            {
                lista.inicio = nuevo;
            }        
            else
            {   if(nuevo->dato < lista.inicio->dato)
                {
                    nuevo->sig =lista.inicio;
                    lista.inicio=nuevo;
                }
                else
                {
                    for(i=lista.inicio; i->sig!=NULL && nuevo->dato > (i->sig)->dato ; i=i->sig );
                    nuevo->sig=i->sig;
                    i->sig = nuevo;
                }       
            }

        }
        else
            delete(nuevo);

    }
}

tlista quitar_inicio(tlista&lista)
{pnodo extraido;
    if(lista.inicio!= NULL)
    {   
        if(lista.inicio->sig=NULL)
            lista.inicio=NULL;
        else
        {
            lista.inicio=lista.inicio->sig;
            extraido->sig=NULL;
        }
    }

    return lista;

}
tlista quitar_final(tlista&lista)
{    pnodo i;
    if(lista.inicio!=NULL)
    {
        if(lista.inicio->sig==NULL) 
        {
            lista.inicio=NULL;
        }
        else
        {
            for(i=lista.inicio; (i->sig)->sig!=NULL; i=i->sig);
            i->sig=NULL;
        }

    }


    return lista;
}

void quitar_opcion(tlista&lista)
{int opcion;
    system("clear");
    cout<<"__________________Quitar _________________"<<endl;
    cout<<"1) Quitar inicio "<<endl;
    cout<<"2) Quitar final "<<endl;

    cout<<"Elija opcion: "<<endl;
    cin>>opcion;

    switch (opcion)
    {
    case 1: lista = quitar_inicio(lista);
        break;
    case 2: lista = quitar_final(lista);
        break;
    
    default: cout<<" Opcion incorrecta "<<endl;  
        break;
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
            case 4: quitar_opcion(lista);
                break;
            case 5: cout<<"Saliendo..."<<endl;
                break;
        }
    }while(opcion!=5);

}
