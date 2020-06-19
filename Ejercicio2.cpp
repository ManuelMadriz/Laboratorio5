#include "iostream"

using namespace std;

string hora(int, int, int);
/*Funcion que recibe horas,  minutos y segundos, corrige desfaces de +1 segundo, y devuelve un string con toda la informacion */
void cin_rango(int*, int, int);
/*Procedimiento que pide un dato al usuario, y si este no se encuentra en un determinado rango lo vuelve a pedir*/

int main()
{
    int hh, mm, ss;

    cout << endl << "Este programa predice el pasado, el presente y el futuro, no me crees? Pruebalo" << endl;

    cout << endl << "Ingresa los siguientes valores, procura ser exacto e ingresar datos en el modo tradicional de 24 hrs" << endl;

    cout << endl << "Ingresa la hora actual" << endl;
    cin_rango(&hh, 0, 23);/*23 horas es el limite, no se aceptan 24 horas, teniendose que ingresar 00 en su lugar*/

    cout << endl << "Ahora ingresa el minuto" << endl;
    cin_rango(&mm, 0, 59);/*No se pueden ingresar 60 minutos*/

    cout << endl << "Y por ultimo, ingresa el segundo actual" << endl;
    cin_rango(&ss, 0, 59);/*No se pueden ingresar 6o segundos*/

    cout << endl  << "El programa predice que, en el presente, son las: " << hora(hh, mm, ss) << endl;
    /*Mostramos el tiempo actual*/

    cout << endl  << "El programa predice que en el futuro, dentro de exactamente un segundo seran las: " << hora(hh, mm, ++ss);
    /*Mostramos el tiempo con 1 segundo mas*/
}

void cin_rango (int *ingreso, int inicio, int fin)
{
    cin >> *ingreso;/*Leemos la variable por referencia*/

    while(*ingreso < inicio || *ingreso > fin)/*Notese que es un intervalo abierto*/
    /*Si, en el caso de las horas, se ingresan 23 no se ejecuta lo siguiente, pero a partir de 24 se solicitara que se vuelva a ingresar el dato*/
    {
        cout << "El programa predice que en el pasado has cometido un error:" << endl;
        cout << "El valor que acabas de ingresar se sale de rango, ingresa uno nuevo" << endl;

        cin >> *ingreso;
        /*Con esto nos evitamos que se ingresen, por ejemplo 25 horas, 101 segndos, etc*/
    }
}

string hora(int hh, int mm, int ss)
{
    if(ss == 60)
    /*Si los segundos eran originalmente 59, al sumarles 1 pasarian a ser 60*/
    {
        ss = 0;/*Por los que los segundos pasan a ser 0*/

        ++mm; /*Y sumamos 1 a los minutos*/
        
        if(mm  == 60)
        /*Si los minutos tambien eran 59, con el caso anterior ahora serian 60 por lo que hacemos el mismo procedimiento*/
        {
            mm = 0;
        
            ++hh;
            
            if(hh == 24)/*Mas de lo mismo, pero con las horas con maximo de 24*/
            {
                hh = 0;
            }   
        }
    }
    /*Con los desfases posibles corregidos, concatenamos todo*/
    
    return to_string(hh) + " hrs " + to_string(mm) + " min y " + to_string(ss) + " secs";
}