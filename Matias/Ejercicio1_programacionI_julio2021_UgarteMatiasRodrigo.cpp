#include<iostream>
#include<stdlib.h>

using namespace std;

const int MAX=3;            // Constantes que especifica el tamaño de los vectores
typedef int t_vector[MAX];

void elegir_opcion(int&opcion);
void cargar_vector(t_vector&vector1);
void mostrar_vector(t_vector vector1);
void mulplicar_vectores(t_vector vector1, t_vector vector2, t_vector vector3);
void mostrar_suma_elementos(t_vector vector1, t_vector vector2, t_vector vector3);
int sumar(t_vector vector_n);
bool determinar_igual(t_vector vectorA,t_vector vectorB);
main()
{   //Variables
    int opcion;
    t_vector vector1, vector2, vector3;
    do
    {
        elegir_opcion(opcion);  //Procedimiento que muestra y permite elegir la opcion que se realizara
        system("clear");    //Limpiar pantalla "cls" tambien puede funcionar, depende el sistema operativo

        switch(opcion)      //Estructura selectiva
        {
            case 1: cout<<"... Cargando Vector 1 ... "<<endl;
                    cargar_vector(vector1);                             //Carga del vector1
                    cout<<"... Cargando Vector 2 ... "<<endl;
                    cargar_vector(vector2);                             //Carga del vector2
                    cout<<"... Mostrando Vector 1 ... "<<endl;
                    mostrar_vector(vector1);                            //Muestra elementos del vector1
                    cout<<"... Mostrando Vector 2 ... "<<endl;
                    mostrar_vector(vector2);                            //Muestra elementos del vector2
                break;
            case 2: mulplicar_vectores(vector1, vector2, vector3);      //Procedimiento que multiplica vectorA*vectorB
                    cout<<"Multiplicando vectores: HECHO"<<endl;
                    cout<<"... Mostrando resultado ... "<<endl;
                    mostrar_vector(vector3);                            //Muestra el vector3, que contiene el resultado de la multiplicacion
                break;
            case 3:
                    mostrar_suma_elementos(vector1, vector2, vector3);  //Permite elegir un vector y sumar sus elementos
                break;
            case 4:
                if(determinar_igual(vector1,vector2)==false)        // Comprueba el resultado de la funcion "determinal_igual" y de acuerdo al resultado
                    cout<<"Arreglos desiguales"<<endl;             // Muestra distintos mensajes
                else
                    cout<<"Arreglos iguales"<<endl;
                break;
            case 5: cout<<"Saliendo"<<endl;
                break;
            default: cout<<"Error, opcion incorrecta"<<endl;
                break;
        }

    }while(opcion!=5);      // No se sale del menu de opciones hasta que se seleccione la opcion 5

}

void elegir_opcion(int&opcion)
{
    cout<<"*************MENU**************"<<endl;
    cout<<"Opcion 1: Cargar vectores y mostrar "<<endl;
    cout<<"Opcion 2: Multiplicar ambos vectores "<<endl;
    cout<<"Opcion 3: Sumar elementos de un vector "<<endl;
    cout<<"Opcion 4: Determinar si VectorA y VectorB son iguales "<<endl;
    cout<<"Opcion 5: Salir "<<endl;

    cout<<"Elegir opcion:  ";
    cin>>opcion;
}

void cargar_vector(t_vector&vector1)
{
    for(int i=0; i<MAX; i++)
    {
        cout<<"Ingrese un numero: ";
        cin>>vector1[i];
    }
}

void mostrar_vector(t_vector vector1)
{
    for(int i=0; i<MAX; i++)
      cout<<vector1[i]<<" ";

    cout<<endl;
}

void mulplicar_vectores(t_vector vector1, t_vector vector2, t_vector vector3)
{
    for(int i=0;i<MAX;i++)
        vector3[i]=vector1[i]*vector2[i];
}

void mostrar_suma_elementos(t_vector vector1, t_vector vector2, t_vector vector3)
{
int opcion;
    cout<<"Elija el vector que desea sumar *1/2/3* "<<endl;
    cin>>opcion;

    cout<<"Se sumara los siguientes elementos: "<<endl;

    switch(opcion)      //Estructura selectiva
        {
            case 1:
                mostrar_vector(vector1);    //Funcion auxiliar
                cout<<"El resultado de la suma es: "<<sumar(vector1)<<endl;
                break;
            case 2:
                mostrar_vector(vector2);
                cout<<"El resultado de la suma es: "<<sumar(vector2)<<endl;
                break;
            case 3:
                mostrar_vector(vector3);
                cout<<"El resultado de la suma es: "<<sumar(vector3)<<endl;
                break;
            default: cout<<"Error, opcion incorrecta"<<endl;
                break;
        }

}

int sumar(t_vector vector_n)
{
    int total=0;

    for(int i=0;i<MAX;i++)
        total=total+vector_n[i];

    return total;
}

bool determinar_igual(t_vector vectorA,t_vector vectorB)
{
    bool iguales=true;
    int i=0;
    while(iguales==true && i<MAX )
    {
        if(vectorA[i]!=vectorB[i])
            iguales=false;
        else
            i++;
    }

    return iguales;
}


