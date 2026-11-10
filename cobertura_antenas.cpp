#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void coberturaAntenas(vector<int>& casas, int r) {
    // 1. Ordenamos las posiciones de las casas de menor a mayor
    sort(casas.begin(), casas.end());

vector<int> antenasColocadas;
    int i = 0;
    int n = casas.size();
    
    // 2. Recorremos todas las casas
    while (i < n) {
        int casaActual = casas[i];
        
        //greedy: colocamos la antena lo más a la derecha posible para que siga cubriendo la casaActual + R
        int posicionAntena = casaActual + r;
        antenasColocadas.push_back(posicionAntena);
        
        // El alcance máximo hacia la derecha de esta antena será posicionAntena + R
        int rangoMaximo = posicionAntena + r;
        
        // 3. Saltamos todas las casas que ya quedaron cubiertas por esta antena
        while (i < n && casas[i] <= rangoMaximo) {
            i++;
        }
    }
    cout << "Antenas colocadas aproximadamente en:\n";
    for (int antena : antenasColocadas) {
        cout << antena << "\n";
    }
    cout << "Cantidad total: " << antenasColocadas.size() << "\n";
}

int main() {
    // Ejemplo 1
    cout << " Ejemplo 1 \n";
    vector<int> casas1 = {5, 8, 12, 25, 26, 27, 40};
    int r1 = 4;
    coberturaAntenas(casas1, r1);
    
    // Ejemplo 2
    cout << "\n Ejemplo 2 \n";
    vector<int> casas2 = {2, 3, 4, 15, 16, 17, 30};
    int r2 = 2;
    coberturaAntenas(casas2, r2);
    
    return 0;
}