#include<iostream>
#include<stdlib.h>

using namespace std;

int cambiarSigno(int num2,int&total)
{   if(num2<0)
    total=-total;

return total;
}

int main()
{
    int num1,num2, total=0,auxiliar;
    bool bandera=false;

    cout<<"Ingrese el primer numero"<<endl;
    cin>>num1;
    cout<<"Ingrese el segundo numero"<<endl;
    cin>>num2;

    if(num2!=0)
    total=num1;

    auxiliar=num2;

    while(bandera==false)
    {
        if(num2<=1 )
        {   if(num2<0)
            {
                    num2++;
                    total=total+num1;

                    if(num2>=-1)
                    {
                        total=cambiarSigno(auxiliar,total);
                        bandera=true;

                    }

            }
            else
            {
                bandera=true;
            }
        }
        else
        {
            num2--;
            total=total+num1;
        }
    }

    cout<<"Total: "<<total<<endl;
}
