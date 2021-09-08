#include<iostream>
#include<stdlib.h>

using namespace std;

typedef struct tnodo *pnodo;

typedef struct tnodo{
                    int dato;
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

void agregar_inicio(tlista&lista, pnodo nuevo)
{
    if(lista.inicio==NULL)
        lista.inicio=nuevo;
    else
    {
        nuevo->sig=lista.inicio;
        lista.inicio=nuevo;
    }

}

void agregar_final(tlista&lista, pnodo nuevo)
{pnodo i;
    if(lista.inicio==NULL)
        lista.inicio=nuevo;
    else
    {   
        for(i=lista.inicio;i->sig!=NULL;i=i->sig);    
            i->sig=nuevo;
            nuevo->sig=NULL;
    }
}

void agregar(tlista&lista, pnodo nuevo)
{   int opcion;
    system("clear");
        crear_nodo(nuevo);
        
        cout<<"_________________________________"<<endl;
        cout<<"1) Agregar al inicio "<<endl;
        cout<<"2) Agregar al final "<<endl;
        cout<<"Ingrese opcion"<<endl;
        cin>>opcion;

        switch(opcion)
        {
            case 1: agregar_inicio(lista,nuevo);
                break;
            case 2: agregar_final(lista,nuevo);
                break;
            default:    cout<<" Opcion incorrecta "<<endl;
                break;
        }
}

void agregar_valor(tlista&lista , pnodo nuevo)
{pnodo i;
    if( lista.inicio != NULL  )
    {
        if(lista.inicio->dato > nuevo->dato)
        {
            agregar_inicio(lista,nuevo);
        }
        else
        {   
            for(i=lista.inicio; i->sig != NULL ; i++ );
            if(i->dato < nuevo->dato)
                agregar_final(lista,nuevo);
            else
                delete(nuevo);
        }
    }
    else
        agregar_inicio(lista,nuevo);
}

int voltearNumero(int num)
{
    int inv=0;

    inv = inv*10 + (num % 10);
    num= num/10;

    return inv;
}

void buscar(tlista&lista)
{   system("clear");
    int buscado , inv;
    pnodo i;

    cout<<"_______________________________"<<endl;
    cout<<"Ingrese el valor que desea buscar: "<<endl;
    cin>>buscado;
    inv= voltearNumero(buscado);    
    
    for(i=lista.inicio;i->sig!=NULL&& i->dato!=buscado && i->dato!=inv;i++);
    
    if(i->dato==buscado || i->dato == inv)
        cout<<"Valor encontrado"<<endl;
    else
        cout<<"Valor no encontrado "<<endl;


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
    cout<<"5. Buscar"<<endl;
    cout<<"6. Salir"<<endl;

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
                    agregar_valor(lista,nuevo);
                break;
            case 3: mostrar_lista(lista);
                break;
            case 4: buscar(lista);
                break;
            case 5:
                break;
            case 6: cout<<"Saliendo..."<<endl;
                break;
        }
    }while(opcion!=6);

    return 0;
}