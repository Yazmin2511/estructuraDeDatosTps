#include <iostream>
#include <stdlib.h>

using namespace std;

typedef struct tnodo *pnodo;
typedef struct tnodo{
                    double dato;
                    pnodo sig;
};

typedef struct tlista{
                    pnodo inicio;
};

void iniciar_lista(tlista&lista)
{
    lista.inicio=NULL;
}

void crear_nodo(pnodo&nuevo)
{
    nuevo = new tnodo;
    if(nuevo!=NULL)
    {
        cout<<"Ingrese nuevo valor"<<endl;
        cin>>nuevo->dato;
        nuevo->sig=NULL;
    }
    else
        cout<<"MEMORIA INSUFICIENTE"<<endl;

}

void agregar(tlista&lista, pnodo nuevo)
{
    crear_nodo(nuevo);
    if(lista.inicio==NULL)
        lista.inicio=nuevo;
    else
    {
        nuevo->sig=lista.inicio;
        lista.inicio=nuevo;
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

void minimo_valor(tlista lista)
{
    double minimo=lista.inicio->dato;
    pnodo i;

    for(i=lista.inicio;i->sig!=NULL;i=i->sig)
    {
        if((minimo-i->dato)>0)
            minimo=i->dato;
    }

    cout<<"Minimo valor de la lista: "<<minimo<<endl;
}

void mostrar_recursivo(tlista lista,pnodo i)
{
    if(i->sig==NULL)
    {
        cout<<i->dato<<endl;
    }
    else
    {
        mostrar_recursivo(lista, i->sig);
        cout<<i->dato<<endl;
    }

}

void mostrar_recursivo_alrevez(tlista lista,pnodo i)
{   
    if(i->sig!=NULL)
    { cout<<i->dato<<endl;
       
    }
    else
    {
        cout<<i->dato<<endl;
        mostrar_recursivo(lista, i->sig);
        
    }

}

int contar(tlista lista,pnodo i , double valor)
{
    if(i==NULL)
        return 0;
    else
    {   
        if(i->dato>valor)
        return 1+ contar(lista,i->sig,valor);
        else
        return 0+ contar(lista,i->sig,valor);
    }    
        
}

void quitar(pnodo &lis)

{   pnodo p, q=NULL;

        if(lis==NULL || lis->sig==NULL)

            q=NULL;

       else

         if(lis->sig->sig==lis)

            {q=lis;

             lis=lis->sig;

             lis->sig=lis;

             q->sig=NULL; }

          else

         {   for(q=lis; lis!=q->sig->sig; q=q->sig);

              p=q;

              p->sig=q->sig;

              q->sig=NULL;

          }

  cout<<q->dato<<endl;

}

void mostrar_opcion(tlista lista)
{ system("clear");
    int opcion;
    pnodo i;
    cout<<"_________________________"<<endl;
    cout<<"1) Mostrar desde primer nodo"<<endl;
    cout<<"2) Mostrar desde ultimo nodo"<<endl;

    cout<<"Elija opcion: "<<endl;
    cin>>opcion;

    switch (opcion)
    {
        case 1:
            i=lista.inicio;
            mostrar_recursivo(lista,i);
            break;
        case 2:
            i=lista.inicio;
            mostrar_recursivo_alrevez(lista,i);
            break;
        
        default:
            break;
    }

}

void menu (int&opcion)
{
    cout<<"̣̣̣̣̣___________________________________"<<endl;
    cout<<"*********Menu Principal***********"<<endl;
    cout<<"1. Iniciar lista"<<endl;
    cout<<"2. Crear y agregar nodo"<<endl;
    cout<<"3. Mostrar"<<endl;
    cout<<"4. Obtener el minimo valor"<<endl;
    cout<<"5. Cantidad de valores mayores a..."<<endl;
    cout<<"6. Salir"<<endl;

    cout<<"Elija opcion "<<endl;
    cin>>opcion;

    system("clear");

}

int main()
{
     int opcion=0;
    tlista lista;
    pnodo nuevo,i=lista.inicio;

    do{
        menu(opcion);
        switch(opcion)
        {
            case 1: iniciar_lista(lista);
                break;
            case 2: agregar(lista,nuevo);        
                break;
            case 3: mostrar_opcion(lista);
                break;
            case 4: minimo_valor(lista);
                break; 
            case 5: //quitar();
             /*cout<<contar(lista,i,3); */
                break;
            case 6: cout<<"Saliendo..."<<endl;
                break;
        }
    }while(opcion!=6);


}