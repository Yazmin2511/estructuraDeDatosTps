#include<iostream>
#include<stdlib.h>

using namespace std;

main()
{
    int num1,num2, total=0;
    bool bandera=false;

    cout<<"Ingrese el primer numero"<<endl;
    cin>>num1;
    cout<<"Ingrese el segundo numero"<<endl;
    cin>>num2;

    if(num2!=0)
    total=num1;

    while(bandera==false)
    {
        if(num2<=1 )
        {
            bandera=true;
        }
        else
        {
            num2--;
            total=total+num1;

        }
    }

    cout<<"Total: "<<total<<endl;
}
