#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

// Estructura para representar cada objeto
struct Objeto {
    string nombre;
    double valor;
    double peso;
};

// Funcion para comparar objetos por su densidad (Greedy)
bool compararDensidad(const Objeto& a, const Objeto& b) {
    double densidadA = a.valor / a.peso;
    double densidadB = b.valor / b.peso;
    return densidadA > densidadB;
}