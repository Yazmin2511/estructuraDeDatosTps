#include<iostream>
#include<stdlib.h>      // Librerias necesarias
#include<time.h>

using namespace std;

const int FILAS=3;      // Constantes que especifican el tamaño de filas y columnas de la matriz
const int COLS=3;
typedef int t_matriz[FILAS][COLS];  //Creacion de un nuevo tipo matriz

//Declaracion de los metodos que se utilizaran
void elegir_opcion(int&opcion);
void cargar_matriz_aleatoriamente(t_matriz&matrizN);
void mostrar_matriz(t_matriz matrizN);
void multiplicar_matrices(t_matriz matriz_a,t_matriz matriz_b);
bool matrices_iguales(t_matriz matriz_a,t_matriz matriz_b);
void diagonal_principal(t_matriz&matriz_n);
int menor_elemento(t_matriz matriz_n);
main()
{   //Variables
    int opcion;
    t_matriz matriz_a, matriz_b;
    int matriz_elegida;

    srand(time(NULL));      //inicializa el generador de números aleatorios
    do
    {
        elegir_opcion(opcion);  //Procedimiento que muestra y permite elegir la opcion que se realizara
        system("clear");    //Limpiar pantalla "cls" tambien puede funcionar, depende el sistema operativo

        switch(opcion)      //Estructura selectiva
        {
            case 1:
                cout<<"- MATRIZ A -"<<endl;
                cargar_matriz_aleatoriamente(matriz_a);
                mostrar_matriz(matriz_a);
                cout<<"- MATRIZ B -"<<endl;
                cargar_matriz_aleatoriamente(matriz_b);
                mostrar_matriz(matriz_b);
                break;
            case 2:
                multiplicar_matrices(matriz_a,matriz_b);
                break;
            case 3:
                if(matrices_iguales(matriz_a,matriz_b)==true)
                    cout<<"MATRICES IGUALES"<<endl;
                else
                    cout<<"MATRICES DESIGUALES"<<endl;
                break;
            case 4:
                cout<<"Elija una matriz *1/2* ";
                cin>>matriz_elegida;
                if(matriz_elegida==1)
                {
                    diagonal_principal(matriz_a);
                    mostrar_matriz(matriz_a);
                }
                else
                {
                    diagonal_principal(matriz_b);
                    mostrar_matriz(matriz_b);
                }
                break;
            case 5:
                cout<<"El menor elemento de la matriz A es: "<<menor_elemento(matriz_a)<<endl;
                break;
            case 6:
                cout<<"El menor elemento de la matriz B es: "<<menor_elemento(matriz_b)<<endl;
                break;
            case 7: cout<<"Saliendo"<<endl;
                break;
            default: cout<<"Error, opcion incorrecta"<<endl;
                break;
        }

    }while(opcion!=7);      // No se sale del menu de opciones hasta que se seleccione la opcion 5

}


void elegir_opcion(int&opcion)
{
    cout<<"***************************MENU****************************"<<endl;
    cout<<"Opcion 1: Mostrar matrices cargadas aleatoriamente "<<endl;
    cout<<"Opcion 2: Multiplicar y mostrar ambas matrices "<<endl;
    cout<<"Opcion 3: Determinar si las matrices son iguales "<<endl;
    cout<<"Opcion 4: Elegir matriz que se modificara y luego mostrarla "<<endl;
    cout<<"Opcion 5: Mostrar el menor elemento de la matriz A "<<endl;
    cout<<"Opcion 6: Mostrar el menor elemento de la matriz B "<<endl;
    cout<<"Opcion 7: Salir "<<endl;

    cout<<"Elegir opcion:  ";
    cin>>opcion;
}

void cargar_matriz_aleatoriamente(t_matriz&matrizN)
{  // srand(time(NULL)); //Descomentar para comprobar
    int num ,f ,c;

    for(f=0;f<FILAS;f++)              // Con estos 2 for, se logra recorrer la matriz
    {
        for(c=0;c<COLS;c++)
        {
            num = rand()%51;           // Numeros aleatorios entre 0 y 50
            matrizN[f][c]=num;
        }
    }
}

void mostrar_matriz(t_matriz matrizN)
{int f,c;
    for(f=0;f<FILAS;f++)              // Con estos 2 for, se logra recorrer la matriz
    {
        for(c=0;c<COLS;c++)
        {
            cout<<matrizN[f][c]<<" ";
        }
        cout<<endl;
    }
}

void multiplicar_matrices(t_matriz matriz_a,t_matriz matriz_b)
{int f,c;
    for(f=0;f<FILAS;f++)              // Con estos 2 for, se logra recorrer la matriz
    {
        for(c=0;c<COLS;c++)
        {
            cout<<matriz_a[f][c]*matriz_b[f][c]<<" ";
        }
        cout<<endl;
    }
}

bool matrices_iguales(t_matriz matriz_a,t_matriz matriz_b)
{
    int f,c;
    bool iguales=true;

    for(f=0;f<FILAS;f++)
    {
        for(c=0;c<COLS;c++)
        {
            if(matriz_a[f][c]!=matriz_b[f][c])
            {
                iguales=false;
                f=FILAS;            // Filalizar el bucle al comprobar que hay aunque sea 1 elemento distinto
                c=COLS;
            }
        }
    }

    return iguales;
}

void diagonal_principal(t_matriz&matriz_n)
{int f,c;
    for(f=0;f<FILAS;f++)
    {
        for(c=0;c<COLS;c++)
        {
            if(f==c)
                matriz_n[f][c]=1;   //Comprueba que las coordenadas del elemento correspondan a las de la diagonal principal
            else
                matriz_n[f][c]=0;   //Si no es parte de la diagonal principal, se cambia el valor a 0
        }
    }
}

int menor_elemento(t_matriz matriz_n)
{int f,c, menor= matriz_n[0][0];
    for(f=0;f<FILAS;f++)
    {
        for(c=0;c<COLS;c++)
        {
            if(matriz_n[f][c]<menor)
                menor=matriz_n[f][c];
        }
    }

    return menor;
}






