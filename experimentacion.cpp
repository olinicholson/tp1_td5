// experimentacion.cpp
#include <iostream>
#include <vector>
#include <chrono> // Para medir el tiempo
#include "tp1.cpp" // Incluir el archivo tp1.cpp donde está definida la función fuerza_bruta
#include <cassert>

using namespace std;
using namespace std::chrono;


//FUERZA BRUTA VS BACKTRACKING#include <iostream>
#include <vector>
#include <chrono>

using namespace std;
using namespace std::chrono;

void test_ejemplo_1() {
    cout << "Ejemplo 1: La segunda instancia no puede ser asignada" << endl;

    int n = 5; // Numero de instancias
    int m = 4; // Numero de máquinas
    vector<int> gpus_solicitadas = {20, 100, 30, 20};
    vector<int> beneficios = {10, 20, 30, 25};
    vector<int> gpus_por_maquina = {50, 50, 50, 50}; // 4 máquinas

    vector<vector<int>> s(n, vector<int>(m, 0)); // Matriz de asignaciones
    int max_beneficio = 0;

    // Variables para promediar tiempos
    long long total_fuerza_bruta = 0;
    long long total_backtracking = 0;

    // Ejecutar 10 veces para fuerza bruta
    for (int i = 0; i < 10; ++i) {
        auto start = high_resolution_clock::now();
        fuerza_bruta(0, gpus_por_maquina.size(), gpus_solicitadas, beneficios, gpus_por_maquina, s, max_beneficio);
        auto stop = high_resolution_clock::now();
        total_fuerza_bruta += duration_cast<microseconds>(stop - start).count();
    }

    // Ejecutar 10 veces para backtracking
    for (int i = 0; i < 10; ++i) {
        auto start = high_resolution_clock::now();
        backtracking(0, gpus_por_maquina.size(), gpus_solicitadas, beneficios, gpus_por_maquina, s, max_beneficio);
        auto stop = high_resolution_clock::now();
        total_backtracking += duration_cast<microseconds>(stop - start).count();
    }

    // Mostrar promedios
    cout << "Promedio tiempo fuerza bruta: " << total_fuerza_bruta / 10 << " microsec" << endl;
    cout << "Promedio tiempo backtracking: " << total_backtracking / 10 << " microsec" << endl;
    cout << "maximo beneficio: " << max_beneficio << endl;
}

void test_ejemplo_2() {
    cout << "\nEjemplo 2: Todas las instancias pueden ser asignadas" << endl;

    int n = 5; // Numero de instancias
    int m = 4; // Numero de máquinas
    vector<int> gpus_solicitadas = {10, 20, 30, 20};
    vector<int> beneficios = {10, 20, 30, 25};
    vector<int> gpus_por_maquina = {50, 50, 50, 50}; // 4 máquinas

    vector<vector<int>> s(n, vector<int>(m, 0)); // Matriz de asignaciones
    int max_beneficio = 0;

    // Variables para promediar tiempos
    long long total_fuerza_bruta = 0;
    long long total_backtracking = 0;

    // Ejecutar 10 veces para fuerza bruta
    for (int i = 0; i < 10; ++i) {
        auto start = high_resolution_clock::now();
        fuerza_bruta(0, gpus_por_maquina.size(), gpus_solicitadas, beneficios, gpus_por_maquina, s, max_beneficio);
        auto stop = high_resolution_clock::now();
        total_fuerza_bruta += duration_cast<microseconds>(stop - start).count();
    }

    // Ejecutar 10 veces para backtracking
    for (int i = 0; i < 10; ++i) {
        auto start = high_resolution_clock::now();
        backtracking(0, gpus_por_maquina.size(), gpus_solicitadas, beneficios, gpus_por_maquina, s, max_beneficio);
        auto stop = high_resolution_clock::now();
        total_backtracking += duration_cast<microseconds>(stop - start).count();
    }

    // Mostrar promedios
    cout << "Promedio tiempo fuerza bruta: " << total_fuerza_bruta / 10 << " microsec" << endl;
    cout << "Promedio tiempo backtracking: " << total_backtracking / 10 << " microsec" << endl;
    cout << "Beneficio maximo: " << max_beneficio << endl;
}

void test_ejemplo_3() {
    cout << "\nEjemplo 3: Ninguna instancia puede ser asignada" << endl;

    int n = 5; // Numero de instancias
    int m = 4; // Numero de máquinas
    vector<int> gpus_solicitadas = {100, 200, 300, 200};
    vector<int> beneficios = {10, 20, 30, 25};
    vector<int> gpus_por_maquina = {50, 50, 50, 50}; // 4 máquinas

    vector<vector<int>> s(n, vector<int>(m, 0)); // Matriz de asignaciones
    int max_beneficio = 0;

    // Variables para promediar tiempos
    long long total_fuerza_bruta = 0;
    long long total_backtracking = 0;

    // Ejecutar 10 veces para fuerza bruta
    for (int i = 0; i < 10; ++i) {
        auto start = high_resolution_clock::now();
        fuerza_bruta(0, gpus_por_maquina.size(), gpus_solicitadas, beneficios, gpus_por_maquina, s, max_beneficio);
        auto stop = high_resolution_clock::now();
        total_fuerza_bruta += duration_cast<microseconds>(stop - start).count();
    }

    // Ejecutar 10 veces para backtracking
    for (int i = 0; i < 10; ++i) {
        auto start = high_resolution_clock::now();
        backtracking(0, gpus_por_maquina.size(), gpus_solicitadas, beneficios, gpus_por_maquina, s, max_beneficio);
        auto stop = high_resolution_clock::now();
        total_backtracking += duration_cast<microseconds>(stop - start).count();
    }

    // Mostrar promedios
    cout << "Promedio tiempo fuerza bruta: " << total_fuerza_bruta / 10 << " microsec" << endl;
    cout << "Promedio tiempo backtracking: " << total_backtracking / 10 << " microsec" << endl;
    cout << "maximo beneficio: " << max_beneficio << endl;
}

//PROGRAMACION DINAMICA VS BACKTRACKING 
// Tambien usamos estos tests de programacion dinamica para comparar con el codigo en python

void test_2_maquinas_vs_backtracking() {
    cout << "comparacion entre programacion Dinamica con 2 maquinas vs Backtracking" << endl;

    int n = 5; // Numero de instancias
    int m = 4; // Numero de maquinas
    vector<int> gpus_solicitadas = {10, 20, 30, 20};
    vector<int> beneficios = {10, 20, 30, 25};
    vector<int> gpus_por_maquina = {50, 50}; // 2 maquinas

    vector<vector<int>> s(n, vector<int>(m, 0)); // Matriz de asignaciones
    int max_beneficio = 0;

    // Medir tiempo para backtracking
    auto start = high_resolution_clock::now();
    backtracking(0, gpus_por_maquina.size(), gpus_solicitadas, beneficios, gpus_por_maquina, s, max_beneficio);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Tiempo backtracking: " << duration.count() << " microsec" << endl;

    // Medir tiempo para programacion Dinamica con 2 maquinas
    vector<vector<vector<int>>> memo(n, vector<vector<int>>(gpus_por_maquina[0] + 1, vector<int>(gpus_por_maquina[1] + 1, -1)));
    start = high_resolution_clock::now();
    prog_dinamica_2(0, 2, gpus_solicitadas, beneficios, gpus_por_maquina[0], gpus_por_maquina[1], s, max_beneficio, memo);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);
    cout << "Tiempo programacion Dinamica con 2 maquinas: " << duration.count() << " microsec" << endl;

    cout << "maximo beneficio: " << max_beneficio << endl;
}

void test_3_maquinas_vs_backtracking() {
    cout << "\ncomparacion entre programacion Dinamica con 3 maquinas vs Backtracking" << endl;

    int n = 5; // Numero de instancias
    int m = 4; // Numero de maquinas
    vector<int> gpus_solicitadas = {10, 20, 30, 20};
    vector<int> beneficios = {10, 20, 30, 25};
    vector<int> gpus_por_maquina = {50, 50, 50}; // 3 maquinas

    vector<vector<int>> s(n, vector<int>(m, 0)); // Matriz de asignaciones
    int max_beneficio = 0;

    // Medir tiempo para backtracking
    auto start = high_resolution_clock::now();
    backtracking(0, gpus_por_maquina.size(), gpus_solicitadas, beneficios, gpus_por_maquina, s, max_beneficio);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Tiempo backtracking: " << duration.count() << " microsec" << endl;

    // Medir tiempo para programacion Dinamica con 3 maquinas
    vector<vector<vector<vector<int>>>> memo(n, vector<vector<vector<int>>>(  gpus_por_maquina[0] + 1, 
        vector<vector<int>>(gpus_por_maquina[1] + 1, vector<int>(gpus_por_maquina[2] + 1,  -1)) ) );
    start = high_resolution_clock::now();
    prog_dinamica_3(0, 3, gpus_solicitadas, beneficios, gpus_por_maquina[0], gpus_por_maquina[1], gpus_por_maquina[2], s, max_beneficio, memo);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);
    cout << "Tiempo programacion Dinamica con 3 maquinas: " << duration.count() << " microsec" << endl;

    cout << "maximo beneficio: " << max_beneficio << endl;
}

void test_4_maquinas_vs_backtracking() {
    cout << "\ncomparacion entre programacion Dinamica con 4 maquinas vs Backtracking" << endl;

    int n = 5; // Numero de instancias
    int m = 4; // Numero de maquinas
    vector<int> gpus_solicitadas = {10, 20, 30, 20};
    vector<int> beneficios = {10, 20, 30, 25};
    vector<int> gpus_por_maquina = {50, 50, 50, 50}; // 4 maquinas

    vector<vector<int>> s(n, vector<int>(m, 0)); // Matriz de asignaciones
    int max_beneficio = 0;

    // Medir tiempo para backtracking
    auto start = high_resolution_clock::now();
    backtracking(0, gpus_por_maquina.size(), gpus_solicitadas, beneficios, gpus_por_maquina, s, max_beneficio);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Tiempo backtracking: " << duration.count() << " microsec" << endl;

    // Medir tiempo para programacion Dinamica con 4 maquinas
    vector<vector<vector<vector<vector<int>>>>> memo( n, vector<vector<vector<vector<int>>>>(  gpus_por_maquina[0] + 1, vector<vector<vector<int>>>(gpus_por_maquina[1] + 1, 
        vector<vector<int>>(gpus_por_maquina[2] + 1,  vector<int>(gpus_por_maquina[3] + 1, -1)) ) ));
    start = high_resolution_clock::now();
    prog_dinamica_4(0, 4, gpus_solicitadas, beneficios, gpus_por_maquina[0], gpus_por_maquina[1], gpus_por_maquina[2], gpus_por_maquina[3], s, max_beneficio, memo);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);
    cout << "Tiempo programacin dinamica con 4 maquinas: " << duration.count() << " microsec" << endl;

    cout << "maximo beneficio: " << max_beneficio << endl;
}


void test_algoritmos_con_mas_instancias() {
    cout << "Test de tiempo con incremento de instancias" << endl;
    
    // Parámetros iniciales
    vector<int> gpus_por_maquina = {50, 50}; // Para simplificar, probamos con 2 máquinas al inicio
    int m = gpus_por_maquina.size();         // Numero de máquinas
    
    for (int num_instancias = 2; num_instancias <= 6; num_instancias++) {
        vector<int> gpus_solicitadas(num_instancias);
        vector<int> beneficios(num_instancias);

        // Generar instancias con valores crecientes de GPUs solicitadas y beneficios
        for (int i = 0; i < num_instancias; i++) {
            gpus_solicitadas[i] = 10 + i * 10;  // GPU solicitada incremental
            beneficios[i] = 5 + i * 5;          // Beneficio incremental
        }

        vector<vector<int>> s(num_instancias, vector<int>(m, 0)); // Matriz de asignaciones
        int max_beneficio = 0;

        // Promediar los tiempos en 10 corridas
        long long tiempo_fuerza_bruta_total = 0;
        long long tiempo_backtracking_total = 0;
        long long tiempo_prog_dinamica_total = 0;

        for (int iter = 1; iter < 10; iter++) {
            // Medir tiempo para fuerza bruta
            auto start = high_resolution_clock::now();
            fuerza_bruta(0, m, gpus_solicitadas, beneficios, gpus_por_maquina, s, max_beneficio);
            auto stop = high_resolution_clock::now();
            tiempo_fuerza_bruta_total += duration_cast<microseconds>(stop - start).count();

            // Medir tiempo para backtracking
            start = high_resolution_clock::now();
            backtracking(0, m, gpus_solicitadas, beneficios, gpus_por_maquina, s, max_beneficio);
            stop = high_resolution_clock::now();
            tiempo_backtracking_total += duration_cast<microseconds>(stop - start).count();

            // Medir tiempo para programacion dinamica (con 2 máquinas para este caso)
            vector<vector<vector<int>>> memo(num_instancias, vector<vector<int>>(gpus_por_maquina[0] + 1, vector<int>(gpus_por_maquina[1] + 1, -1)));
            start = high_resolution_clock::now();
            prog_dinamica_2(0, m, gpus_solicitadas, beneficios, gpus_por_maquina[0], gpus_por_maquina[1], s, max_beneficio, memo);
            stop = high_resolution_clock::now();
            tiempo_prog_dinamica_total += duration_cast<microseconds>(stop - start).count();
        }

        // Promediar los tiempos
        cout << "Numero de instancias: " << num_instancias << endl;
        cout << "Promedio tiempo fuerza bruta: " << tiempo_fuerza_bruta_total / 10 << " microsegundos" << endl;
        cout << "Promedio tiempo backtracking: " << tiempo_backtracking_total / 10 << " microsegundos" << endl;
        cout << "Promedio tiempo programacion dinamica: " << tiempo_prog_dinamica_total / 10 << " microsegundos" << endl;
        cout << "maximo beneficio obtenido: " << max_beneficio << endl;
    }
}

// TEST PARA 4 MAQUINAS CON  500 GPUS CADA UNA
void test_4_maquinas_gpu500() {
    cout << "Test con 4 máquinas de 500 GPUs cada una" << endl;

    int n = 5; // Número de instancias
    int m = 4; // Número de máquinas
    vector<int> gpus_solicitadas = {100, 200, 150, 80, 50}; // GPUs solicitadas por cada instancia
    vector<int> beneficios = {50, 100, 75, 40, 20}; // Beneficio por cada instancia
    vector<int> gpus_por_maquina = {500, 500, 500, 500}; // GPUs disponibles por cada máquina

    vector<vector<int>> s(n, vector<int>(m, 0)); // Matriz de asignaciones (vacía para este ejemplo)
    int max_beneficio = 0;

    // Tabla de memoización inicializada en -1
    vector<vector<vector<vector<vector<int>>>>> memo(
        n, vector<vector<vector<vector<int>>>>(
            gpus_por_maquina[0] + 1, vector<vector<vector<int>>>(
                gpus_por_maquina[1] + 1, vector<vector<int>>(
                    gpus_por_maquina[2] + 1, vector<int>(gpus_por_maquina[3] + 1, -1)))));

    // Medir tiempo de ejecución
    auto start = high_resolution_clock::now();
    prog_dinamica_4(0, m, gpus_solicitadas, beneficios, gpus_por_maquina[0], gpus_por_maquina[1], gpus_por_maquina[2], gpus_por_maquina[3], s, max_beneficio, memo);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);

    cout << "Tiempo de ejecución: " << duration.count() << " microsegundos" << endl;
    cout << "Máximo beneficio obtenido: " << max_beneficio << endl;
}

int main() {
    test_2_maquinas_vs_backtracking();
    test_3_maquinas_vs_backtracking();
    test_4_maquinas_vs_backtracking();

    return 0;
}
