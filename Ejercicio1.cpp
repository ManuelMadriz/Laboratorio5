#include "iostream"

using namespace std;

int mcd(int, int);

int main(void)
{
    int v_uno, v_dos, resultado;

    cout << endl << "Este programa te servira para encontrar el Maximo Comun Divisor de dos numeros";

    cout << endl << "Por favor, Ingresa el primer numero" << endl;
    cin >> v_uno;

    cout  << endl << "Ahora, ingresa el segundo numero" << endl;
    cin >> v_dos;
    
    resultado = mcd(v_uno,v_dos);
    
    cout << endl << "El MCD entre " << v_uno << " y " <<  v_dos  <<  " es: " << resultado;
}

int mcd(int v1, int v2)
{
    int residuo;

    residuo = v1%v2;

    while ( residuo != 0)
    {
        v1 = v2;
        v2 = residuo;

        residuo = v1%v2;
    }
    
    return v2;
}