#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void coberturaAntenas(vector<int>& casas, int r) {
    // 1. Ordenamos las posiciones de las casas de menor a mayor
    sort(casas.begin(), casas.end());
