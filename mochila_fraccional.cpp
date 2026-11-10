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

void mochilaFraccional(double capacidadMaxima, vector<Objeto>& objetos) {
    //Ordenamos los objetos de mayor a menor densidad
    sort(objetos.begin(), objetos.end(), compararDensidad);
    
    double valorTotal = 0.0;
    cout << "Objetos seleccionados:\n";
    
    //Recorremos los objetos ya ordenados
    for (const auto& obj : objetos) {
        if (capacidadMaxima == 0) {
            break; // Si la mochila está llena, terminamos
        }
        
        if (obj.peso <= capacidadMaxima) {
            // El objeto cabe completo en la mochila
            cout << obj.nombre << " completo\n";
            valorTotal += obj.valor;
            capacidadMaxima -= obj.peso;
        } else {
            // El objeto no cabe completo, calculamos la fracción exacta
            double fraccion = capacidadMaxima / obj.peso;
            cout << capacidadMaxima << "/" << obj.peso << " Parte del objeto " << obj.nombre << "\n";
            valorTotal += obj.valor * fraccion;
            capacidadMaxima = 0; // La mochila se ha llenado
        }
    }
    
    cout << "Valor total aproximado: " << valorTotal << "\n";
}

int main() {
    double capacidad = 60;
    vector<Objeto> objetos = {
        {"X", 120, 30},
        {"Y", 100, 20},
        {"Z", 60, 20}
    };
    
    cout << "Capacidad maxima: " << capacidad << "\n\n";
    mochilaFraccional(capacidad, objetos);
    
    return 0;
}
