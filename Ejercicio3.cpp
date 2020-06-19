#include "iostream"

using namespace std;

bool bisiesto(int); /*Funcion que devolvera TRUE si el numero ingresado corresponde a un año bisiesto y FALSE si no*/

int main()
{
    int anno; /*Le puse anno porque no me aceptaba la ñ*/
    cout << endl << "Este programa te servira para calcular si un año es bisiesto o no";
    cout << endl << "Por favor, ingresa el año" << endl;

    cin >> anno;


    if(bisiesto(anno))
    {
        cout << endl << anno << " es un año bisiesto";
    }
    else
    {
        cout << endl << anno << " no es un año bisiesto";
    }
}/*Se que seria mas eficiente que la misma funcion bool imprimiera el resultado, pero me gusta mas de esta manera*/

bool bisiesto ( int anno)
{
    if(anno % 400 == 0)
    {
        return true;
    }
    else
    {
        if(anno % 4 == 0 && anno % 100 != 0 )
        {
            return true;
        }
        else
        {
            return false;
        }
    }   
}