#include<iostream>
#include<stdlib.h>
#include<time.h>

using namespace std;

const int MAX=5;
typedef int t_vector[MAX];

// DECLARACION DE METODOS
void menu(int&opcion);
void insertarElementos(t_vector&vector1);
void mostrarElementos(t_vector vector1);
int impar1 (int num1 , t_vector vector1);
bool multiplo(int numero);
void comprobacion(t_vector vector1);

int main()
{
  int opcion, random;
  t_vector vector1;
    do
    {
        menu(opcion);

        switch(opcion)
        {
            case 1:
                    insertarElementos(vector1);
                    mostrarElementos(vector1);
                break;
            case 2:
                break;
            case 3: comprobacion(vector1);
                break;
            case 4:
                    cout<<"Saliendo ..."<<endl;
                break;

        }
    }while(opcion!=4);
}

void menu(int&opcion)
{
    cout<<"******************MENU*****************"<<endl;
    cout<<"1. Insertar valores al arreglo"<<endl;
    cout<<"2. Determinar si el arreglo contiene solo valores impares"<<endl;
    cout<<"3. Contar valores multiplos de 11"<<endl;
    cout<<"4. Salir"<<endl;

    cout<<"Ingrese opcion deseada: "<<endl;
    cin>>opcion;
}

void insertarElementos(t_vector&vector1)
{
    int random, i=0;
    bool primero=true;

    srand((unsigned)time(0));

    do
    {   random= 1+rand()%(10501-1);

        if(i==0)
        {
                vector1[i]=random;
                i++;
        }
         else
        {
            if(vector1[i-1]>random)
            {
                vector1[i]=random;
                i++;
            }
        }

    }while(i<MAX);

}

void mostrarElementos(t_vector vector1)
{
    for(int i=0;i<MAX;i++)
    {
       cout<<vector1[i]<<endl;
    }

}

int impar1 (int num1 , t_vector vector1)
{
    bool impar;
    int i=0;

        if(i==MAX-1)
        {
            return vector1[i];
        }
        else
        {
            return impar1(1, vector1);
        }

}

void comprobacion(t_vector vector1)
{int contador=0;
    for(int i=0;i<MAX;i++)
    {
       if( multiplo(vector1[i])==true)
       {
            cout<<"Multiplo de 11: "<<vector1[i]<<endl;
            contador++;
       }
    }

    if(contador==0)
        cout<<"No hay multiplos de 11"<<endl;
}

bool multiplo(int numero)
{
    bool multiplo=false;
    int impar=0 , par=0 , contador=1,resto;

    while(numero>0)
    {
        resto=numero%10;
        numero=numero/10;
        if(contador%2==0)
        {
            par+=resto;
        }
        else
        {
            impar+=resto;

        }

        contador++;
    }

    if(par-impar==0 || (par-impar)%11==0 )
    multiplo=true;

    return multiplo;

}



