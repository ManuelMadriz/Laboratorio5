#include "iostream"

using namespace std;

string fecha(int, int, int);
/*Funcion que recibe año, mes y dia, corrige desfaces de +1 dia, y devuelve un string con toda la informacion */

void cin_rango(int*, int, int);/*Procedimiento que pide un dato al usuario, y si este no se encuentra en un determinado rango lo vuelve a pedir*/

int max_dd(int,int);/*Funcion que regresa la cantidad maxima de dias que tiene el numero(mes) ingresado*/

bool bisiesto(int); /*Funcion que devolvera TRUE si el numero ingresado corresponde a un año bisiesto y FALSE si no*/

string name_mm(int);/*Funcion que devuelve el nombre de un mes correspondiente al numero ingresado*/

int main()
{
    int aa, dd, mm;/*año, mes y dia respectivamente*/

    cout << endl << "Dime que fecha es hoy y te dire que dia es mañana" << endl;

    cout << endl << "Por favor, ingresa el año actual" << endl;
    cin >> aa; /*Los años son infinitos, asi que no hace falta establecer un rango*/

    cout << endl << "Ahora, ingresa el numero del mes contemporaneo" << endl;
    cin_rango(&mm, 1, 12);/*12 meses*/

    cout << endl << "Y para finalizar, ingresa el dia(fecha) de hoy" << endl;
    cin_rango(&dd, 1, max_dd(mm, aa));/*varia dependiendo de la cantidad maxima de dias del mes, y si es año bisiesto. Por lo que usamos la funcion diseñada pra ello*/

    cout << endl  << "Hoy es " << fecha(dd, mm, aa);
    /*Mostramos la fecha actual*/

    cout << endl  << "Entonces mañana sera " << fecha(++dd, mm, aa);
    /*Mostramos la fecha del dia siguiente*/
}

void cin_rango (int *ingreso, int inicio, int fin)/*Es basicamente lo mismo que en el ejercicio 2*/
{
    cin >> *ingreso;/*Leemos la variable por referencia*/

    while(*ingreso < inicio || *ingreso > fin)/*Notese que es un intervalo abierto*/
    {
        cout << "Has ingresado una fecha no valida:" << endl;
        cout << "Por favor, corrige el ultimo dato" << endl;

        cin >> *ingreso;
    }
}

string fecha(int dd, int mm, int aa)/*Muy similar a la funcion hora del ejercicio 2*/
{
    /*En caso de que el dia original ingresado por el usuario fuese fin de mes, se ejecutaria el siguiente trozo de codigo*/

    if(dd == max_dd(mm, aa) + 1)/*Ej: si hoy fuese 31, al sumar un dia nos queda 32*/
    {
        dd = 1;/*Entonces, decimos que mañana es primero*/

        ++mm;/*del mes siguiente*/

        /*Si el mes originalmente era diciembre, nos quedara 13*/
        if(mm  == 13)
        {
            mm = 1;/*Entonces decimos que es enero*/
        
            ++aa;  /*Del año nuevo*/
        }
    }
    /*Con los posibles desfases corregidos, concatenamos todo*/
    
    return to_string(dd) + " de " + name_mm(mm) + " del año " + to_string(aa);
}

int max_dd(int mm, int aa)
{    
    if( mm == 4 || mm == 6 || mm == 9 || mm == 11)
    /*Abril, junio, septiembre, y noviembre respectivamente*/
    {
        return 30;
    }
    else
    {
        if( mm == 1 || mm == 3 || mm == 5 || mm == 7 || mm == 8 || mm == 10 || mm == 12)
        /*Enero, marzo, mayo, julio, agosto, octubre y diciembre respectivamente*/
        {
            return 31;
        }
        else
        {
            if(mm == 2)/*Febrero*/
            {
                if( bisiesto(aa))/*Se comprueba si es un año bisiesto*/
                {
                    return 29;
                }
                else
                {
                    return 28;
                }
            }
        }    
    }
}

bool bisiesto ( int anno)/*Exactamente lo mismo que  en el ejercicio 3*/
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

string name_mm(int mm)
{
    switch (mm)
    {
    case 1:
        return "Enero";
        break;
    case 2:
        return "Febrero";
        break;
    case 3:
        return "Marzo";
        break;
    case 4:
        return "Abril";
        break;
    case 5:
        return "Mayo";
        break;
    case 6:
        return "Junio";
        break;
    case 7:
        return "Julio";
        break;
    case 8:
        return "Agosto";
        break;
    case 9:
        return "Septiembre";
        break;
    case 10:
        return "Octubre";
        break;
    case 11:
        return "Noviembre";
        break;
    case 12:
        return "Diciembre";
        break;
    
    default:
        return "Mes no encontrado";
        break;
    }
}