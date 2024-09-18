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
    size_t m = 4; // Número de máquinas
    vector<int> gpus_solicitadas = {1, 20, 2};
    vector<int> beneficios = {1, 20, 30};
    vector<int> gpus_por_maquina = {50,50, 50,50};
    vector<vector<int>> s(n, vector<int>(m, 0));
    int max_beneficio = 0;

    // Iniciar el cronómetro
    auto start_fb = high_resolution_clock::now();

    // Llamar a la función fuerza_bruta desde tp1.cpp
    fuerza_bruta(0, m, gpus_solicitadas, beneficios, gpus_por_maquina, s, max_beneficio);

    // Detener el cronómetro
    auto stop_fb = high_resolution_clock::now();

    // Calcular la duración en milisegundos
    auto duration_fb = duration_cast<microseconds>(stop_fb - start_fb);

    // Iniciar el cronómetro
    auto start_back = high_resolution_clock::now();

    // Llamar a la función fuerza_bruta desde tp1.cpp
    backtracking(0, m, gpus_solicitadas, beneficios, gpus_por_maquina, s, max_beneficio);

    // Detener el cronómetro
    auto stop_back = high_resolution_clock::now();

    // Calcular la duración en milisegundos
    auto duration_back = duration_cast<microseconds>(stop_back - start_back);




    vector<vector<vector<vector<vector<int>>>>> memo( n, vector<vector<vector<vector<int>>>>(  gpus_por_maquina[0] + 1, vector<vector<vector<int>>>(gpus_por_maquina[1] + 1, 
    vector<vector<int>>(gpus_por_maquina[2] + 1,  vector<int>(gpus_por_maquina[3] + 1, -1)) ) ));
    
    // Iniciar el cronómetro
    auto start_dp = high_resolution_clock::now();
    prog_dinamica_4(0, m, gpus_solicitadas, beneficios, gpus_por_maquina[0], gpus_por_maquina[1],gpus_por_maquina[2],gpus_por_maquina[3], s, max_beneficio, memo);
  

    // Detener el cronómetro
    auto stop_dp = high_resolution_clock::now();

    // Calcular la duración en milisegundos
    auto duration_dp = duration_cast<microseconds>(stop_dp - start_dp);

    // Mostrar el tiempo de ejecución y el máximo beneficio
    cout << "Tiempo de ejecucion fuerza bruta: " << duration_fb.count() << " microsec" << endl;
    cout << "Tiempo de ejecucion back: " << duration_back.count() << " microsec" << endl;
    cout << "Tiempo de ejecucion dp: " << duration_dp.count() << " microsec" << endl;
    cout << "Maximo beneficio: " << max_beneficio << endl;

    return 0;
}
