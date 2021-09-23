#include<iostream>
#include<stdlib.h>
#include<time.h>

using namespace std;
//Define la cantidad maxima de jugadores registrados permitidos
const int MAX = 30;


// Definicion de estructuras para Jugador
typedef char tcad[30];
typedef struct t_jugador{
                tcad nombre;
                tcad apellido;
                long dni;
                int bingos_ganados;
                int puntaje;

};
typedef struct tnodo *pnodo;
typedef struct tnodo{
                t_jugador jugador;
                pnodo sig;
};
typedef struct tlista_jugador{
                pnodo inicio;
                int cantidad;
};

// Definicion de estructuras para Carton
typedef struct tnodo2 *pnodo2;

typedef struct tnodo2{
                int numero;
                pnodo sig;
                pnodo ant;
};
typedef struct tlista_carton{
                pnodo2 inicio;
                int cantidad;
};


// Jugadores
//Metodos encargados de gestionar el menu de jugador

void iniciar_lista(tlista_jugador&lista_jugador)
{
    lista_jugador.inicio=NULL;
    lista_jugador.cantidad=0;
}

void crear_jugador(pnodo&nuevo)
{
    nuevo = new tnodo;

    if(nuevo!=NULL)
    {
        cout<<"Nombre del jugador: ";
        cin>>nuevo->jugador.nombre;
        
        cout<<"Apellido del jugador: ";
        cin>>nuevo->jugador.apellido;
        
        cout<<"DNI del jugador: ";
        cin>>nuevo->jugador.dni;

        nuevo->jugador.bingos_ganados=0;
        nuevo->jugador.puntaje=0;

        nuevo->sig=NULL;

    }
    else
        cout<<""<<endl;
}

void agregar_jugador_lista(tlista_jugador&lista_jugador, pnodo nuevo)
{pnodo i;
    if (lista_jugador.cantidad!=MAX)
    {
        crear_jugador(nuevo);   
        if(lista_jugador.inicio == NULL)
        {
            lista_jugador.inicio=nuevo;
            nuevo->sig=lista_jugador.inicio;
        }
        else
        {
            for(i=lista_jugador.inicio;i->sig!=lista_jugador.inicio;i=i->sig);

            i->sig = nuevo;
            nuevo->sig = lista_jugador.inicio;
        }
    
        lista_jugador.cantidad++;
    }
    else
        cout<<"No se pueden crear mas de "<<MAX <<" jugadores"<<endl;
    

                 
}

void mostrar_jugadores(tlista_jugador lista_jugador)
{pnodo i;
    for(i=lista_jugador.inicio;i->sig!=lista_jugador.inicio;i=i->sig)
    {
        cout<<"Nombre: " << i->jugador.nombre <<endl;
        cout<<"Apellido: " << i->jugador.apellido <<endl;
        cout<<"DNI: "<< i->jugador.dni<<endl;
        cout<<"Bingos ganados: "<< i->jugador.bingos_ganados<<endl;
        cout<<"Puntaje: "<< i->jugador.puntaje<<endl;
        cout<<"*****************"<<endl;
    }
        cout<<"Nombre: " << i->jugador.nombre <<endl;
        cout<<"Apellido: " << i->jugador.apellido <<endl;
        cout<<"DNI: "<< i->jugador.dni<<endl;
        cout<<"Bingos ganados: "<< i->jugador.bingos_ganados<<endl;
        cout<<"Puntaje: "<< i->jugador.puntaje<<endl;
        cout<<"*****************"<<endl;
}

void menu_jugadores(tlista_jugador& lista_jugador)
{int opcion;
 pnodo nuevo;
    cout<<"*********************************"<<endl;
    cout<<"_______ADMINISTRAR JUGADOR_______"<<endl;
    cout<<"1. Agregar jugadores"<<endl;
    cout<<"2. Listar jugadores"<<endl;
    cout<<"Seleccione la opcion deseada: "<<endl;
    cin>>opcion;

    switch (opcion)
    {
    case 1: agregar_jugador_lista(lista_jugador,nuevo);
        break;
    case 2: mostrar_jugadores(lista_jugador);
        break;
    
    default: cout<<"Opcion invalida ..."<<endl;
        break;
    }
}

// Cartones

void iniciar_lista_cartones(tlista_carton&lista_carton)
{
    lista_carton.inicio=NULL;
    lista_carton.cantidad=0;
}

void agregar_numeros_carton(tlista_carton&lista_carton){
pnodo2 i=lista_carton.inicio;
int num;
    srand(time(NULL));
    
    do
    {
        num=1+rand()%(91-1);

    } while (i->sig!=NULL);
    
    
    
}

bool comprobacion(tlista_carton lista, int num){
    pnodo2 j;
    bool existe=false;
    for(j=lista.inicio;j!=NULL || existe=true; j ){
        if(j->numero == num)
            existe=true;
    }

}
//Juego



void menu(int&opcion)
{
    cout<<"****************************"<<endl;
    cout<<"_______MENU PRINCIPAL_______"<<endl;
    cout<<"1. Administrar jugadores"<<endl;
    cout<<"2. Generar cartones"<<endl;
    cout<<"3. Iniciar bingo"<<endl;
    cout<<"4. Ranking ganadores"<<endl;
    cout<<"5. Salir"<<endl;
    cout<<"Seleccione la opcion deseada: "<<endl;
    cin>>opcion;
}




int main()
{   //Variables
    int opcion;
    tlista_jugador lista_jugador;
    iniciar_lista(lista_jugador);
    
    bool condicion_jugadores = lista_jugador.cantidad>1;
    bool condicion_cartones;

    do{
        menu(opcion);
        switch (opcion)
        {
        case 1: system("clear");
                menu_jugadores(lista_jugador);
            break;
        case 2: 
            break;
        case 3: if(condicion_jugadores&&condicion_cartones)
                {

                }
                else
                    cout<<"Jugadores insuficientes , o cartones no generados ..."<<endl;
            break;
        case 4:
            break;
        case 5: cout<<"Gracias por jugar ... "<<endl;
            break;
        
        default: cout<<"Opcion invalida"<<endl;
            break;
        }

    }while(opcion!=5);

}