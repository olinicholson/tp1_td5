#include <vector>
#include <iostream>
#include <algorithm> // Para std::max

using namespace std;

// Función para calcular el beneficio total de una combinación válida
int calcular_beneficio(const vector<vector<int>>& s, const vector<int>& beneficios) {
    int beneficio_total = 0;
    size_t n = s.size(); // Número de instancias
    size_t m = s[0].size(); // Número de máquinas

    // Calcular el beneficio total
    for (size_t i = 0; i < n; i++) {
        for (size_t j = 0; j < m; j++) {
            if (s[i][j] == 1) { // Si la instancia i está asignada a la máquina j
                beneficio_total += beneficios[i];
                break; // Solo contamos el beneficio una vez por instancia
            }
        }
    }
    
    return beneficio_total;
}

// Función para verificar si una combinación es válida
bool es_valida(const vector<vector<int>>& s, const vector<int>& gpus_solicitadas, vector<int> gpus_por_maquina) {
    size_t n = s.size(); // Número de instancias
    size_t m = s[0].size(); // Número de máquinas

    // Verificar si la combinación es válida
    for (size_t i = 0; i < n; i++) {
        for (size_t j = 0; j < m; j++) {
            if (s[i][j] == 1) {
                if (gpus_por_maquina[j] >= gpus_solicitadas[i]) {
                    gpus_por_maquina[j] -= gpus_solicitadas[i];
                } else {
                    return false; // La combinación no es válida
                }
            }
        }
    }
    return true;
}

// Función recursiva para explorar todas las combinaciones posibles
void resolver_arbol(size_t instancia, size_t m, vector<int>& gpus_solicitadas, vector<int>& beneficios, vector<int>& gpus_por_maquina, vector<vector<int>>& s, int& max_beneficio) {
    // Caso base: si hemos considerado todas las instancias
    if (instancia == s.size()) {
        vector<int> gpus_disponibles = gpus_por_maquina;
        if (es_valida(s, gpus_solicitadas, gpus_disponibles)) {
            // Calcular el beneficio total
            int beneficio = calcular_beneficio(s, beneficios);
            max_beneficio = max(max_beneficio, beneficio);
        }
        return;
    }

    // Intentar asignar la instancia actual a cada máquina
    for (size_t j = 0; j < m; j++) {
        // Asignar la instancia a la máquina j
        s[instancia][j] = 1;
        resolver_arbol(instancia + 1, m, gpus_solicitadas, beneficios, gpus_por_maquina, s, max_beneficio);
        // Deshacer la asignación para probar la siguiente máquina
        s[instancia][j] = 0;
    }

    // Opción de no asignar la instancia a ninguna máquina
    resolver_arbol(instancia + 1, m, gpus_solicitadas, beneficios, gpus_por_maquina, s, max_beneficio);
}

int main() {
    int n = 5; // Número de instancias
    int m = 3; // Número de máquinas
    vector<int> beneficios = {10, 2, 3, 4, 5}; // Beneficios por instancia
    vector<int> gpus_solicitadas = {1, 4, 4, 4, 4}; // GPUs solicitadas por instancia
    vector<int> gpus_por_maquina = {10, 10, 10}; // GPUs disponibles por máquina
    vector<vector<int>> s(n, vector<int>(m, 0)); // Matriz de asignaciones

    int max_beneficio = 0;
    resolver_arbol(0, m, gpus_solicitadas, beneficios, gpus_por_maquina, s, max_beneficio);

    cout << "El beneficio maximo es: " << max_beneficio << endl;

    return 0;
}
