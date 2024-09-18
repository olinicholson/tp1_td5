// experimentacion.cpp
#include <iostream>
#include <vector>
#include <chrono> // Para medir el tiempo
#include "tp1.cpp" // Incluir el archivo tp1.cpp donde está definida la función fuerza_bruta

using namespace std;
using namespace std::chrono;

int main() {
    // Definir tus variables, por ejemplo:
    size_t n = 3; // Número de instancias
    size_t m = 2; // Número de máquinas
    vector<int> gpus_solicitadas = {1, 2, 3};
    vector<int> beneficios = {10, 20, 30};
    vector<int> gpus_por_maquina = {5, 5};
    vector<vector<int>> s(n, vector<int>(m, 0));
    int max_beneficio = 0;

    // Iniciar el cronómetro
    auto start = high_resolution_clock::now();

    // Llamar a la función fuerza_bruta desde tp1.cpp
    backtracking(0, m, gpus_solicitadas, beneficios, gpus_por_maquina, s, max_beneficio);

    // Detener el cronómetro
    auto stop = high_resolution_clock::now();

    // Calcular la duración en milisegundos
    auto duration = duration_cast<microseconds>(stop - start);

    // Mostrar el tiempo de ejecución y el máximo beneficio
    cout << "Tiempo de ejecucion: " << duration.count() << " microsec" << endl;
    cout << "Maximo beneficio: " << max_beneficio << endl;

    return 0;
}
