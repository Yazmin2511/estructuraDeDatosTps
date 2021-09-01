#include<iostream>
#include<stdlib.h>

using namespace std;

typedef struct tnodo *pnodo;
typedef struct tnodo{
                        int dato;
                        pnodo sig;
};

typedef struct tlista{
                        int positivo;
                        int negativo;
                        pnodo inicio;
};

void iniciar_lista(tlista&lista)
{
    lista.inicio=NULL;

    lista.positivo=0;
    lista.negativo=0;

}

void crear(pnodo&nuevo)
{
    nuevo= new tnodo;
    if(nuevo!=NULL)
    {
        cout<<"Ingrese valor: "<<endl;
        cin>>nuevo->dato;
        nuevo->sig=NULL;
    }
    else
        cout<<"MEMORIA INSUFICIENTE"<<endl;
}

void agregar_inicio(tlista&lista, pnodo nuevo)
{
    nuevo->sig=lista.inicio;
    lista.inicio=nuevo;

    if(nuevo->dato<0)
        lista.negativo++;
    else
        lista.positivo++;

}

pnodo quitar_final(tlista&lista)
{pnodo aux,i;
    if(lista.inicio!=NULL)
    {
        if(lista.inicio->sig==NULL) // Si la lista tiene un solo elemnto
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

        if(aux->dato<0)
            lista.negativo++;
        else
            lista.positivo++;
    }
    else
        aux=NULL;

}

void mostrar(tlista lista)
{pnodo i;
    for(i=lista.inicio;i->sig!=NULL; i=i->sig)
        cout<<"Valor: "<< i->dato<<endl;

    cout<<"Positivos: "<< lista.positivo<<endl;
    cout<<"Negativos: "<< lista.negativo<<endl;
}

void menu (int&opcion)
{

    cout<<"*********Menu Principal***********"<<endl;
    cout<<"1. Iniciar lista"<<endl;
    cout<<"2. Crear nodo"<<endl;
    cout<<"3. Agregar"<<endl;
    cout<<"4. Mostrar"<<endl;
    cout<<"5. Quitar"<<endl;
    cout<<"6. Salir"<<endl;

    cout<<"Elija opcion "<<endl;
    cin>>opcion;


}

main()
{int opcion=0;
    tlista lista;
    pnodo nuevo;

    do{
        menu(opcion);
        switch(opcion)
        {
            case 1: iniciar_lista(lista);
                break;
            case 2: crear(nuevo);
                break;
            case 3: agregar_inicio(lista,nuevo);
                break;
            case 4: mostrar(lista);

                break;
            case 5: quitar_final(lista);
                break;
        }
    cin.get();
    cin.clear();
   // system("clear");
    }while(opcion!=6);



}
