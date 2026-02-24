/*
Autores: David Armando Angulo Gil, Isaac Espinoza Hernández
*/
#include "Pila.hpp"
#include <iostream>
#include <string>

using namespace std;

int main()
{
    // Aqui probamos la Pila pero con ENTEROS
    cout << "Pila de enteros: " << endl;
    try {
        Pila<int> p;
        for(int i = 0; i < 15; ++i){
            p.Agregar(i);
        }
        p.Imprimir();
        cout << p.ObtenerCapacidad() << endl;
        p.Agregar(67);
        cout << p.ObtenerCapacidad() << endl;
        for(int i = 0; i < 15; ++i){
            p.Agregar(i);
        }
        cout << p.ObtenerCapacidad();

        return 0;




    } catch (const char *error) { // Este cacha el p.agregar().
        cerr << "Error: " << error << endl;
    } catch (Pila<int>::PilaVacia &error) { // Este cacha la clase PilaVacia
        cerr << "Error: " << error.what() << endl;
    } catch (...) {
        cerr << "Ocurri\242 un error inesperado" << endl;
    }
    cout << endl;

    return 0;
}
