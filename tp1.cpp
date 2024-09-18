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
void fuerza_bruta(size_t instancia, size_t m, vector<int>& gpus_solicitadas, vector<int>& beneficios, vector<int>& gpus_por_maquina, vector<vector<int>>& s, int& max_beneficio) {
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
        fuerza_bruta(instancia + 1, m, gpus_solicitadas, beneficios, gpus_por_maquina, s, max_beneficio);
        // Deshacer la asignación para probar la siguiente máquina
        s[instancia][j] = 0;
    }

    // Opción de no asignar la instancia a ninguna máquina
    fuerza_bruta(instancia + 1, m, gpus_solicitadas, beneficios, gpus_por_maquina, s, max_beneficio);
}

void backtracking(size_t instancia, size_t m, vector<int>& gpus_solicitadas, vector<int>& beneficios, vector<int>& gpus_por_maquina, vector<vector<int>>& s, int& max_beneficio) {
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
        if(gpus_solicitadas[instancia] <= gpus_por_maquina[j]){
        // Asignar la instancia a la máquina j
        s[instancia][j] = 1;
        backtracking(instancia + 1, m, gpus_solicitadas, beneficios, gpus_por_maquina, s, max_beneficio);
        // Deshacer la asignación para probar la siguiente máquina
        s[instancia][j] = 0;
    }
    }

    // Opción de no asignar la instancia a ninguna máquina tal vez no hace falta
    backtracking(instancia + 1, m, gpus_solicitadas, beneficios, gpus_por_maquina, s, max_beneficio);
}



/*

int main() {
    int n = 5; // Número de instancias
    int m = 3; // Número de máquinas
    vector<int> beneficios = {10, 2, 3, 4, 5}; // Beneficios por instancia
    vector<int> gpus_solicitadas = {1, 4, 4, 4, 4}; // GPUs solicitadas por instancia
    vector<int> gpus_por_maquina= {1, 1, 1 }; // GPUs disponibles por máquina
    vector<vector<int>> s(n, vector<int>(m, 0)); // Matriz de asignaciones

    int max_beneficio = 0;
    backtracking(0, m, gpus_solicitadas, beneficios, gpus_por_maquina, s, max_beneficio);

    cout << "El beneficio maximo es: " << max_beneficio << endl;

    return 0;
}
*/

                    


int prog_dinamica_2(size_t instancia, size_t m, vector<int>& gpus_solicitadas, vector<int>& beneficios, 
                    int gpus_por_maquina1, int gpus_por_maquina2, vector<vector<int>>& s, 
                    int& max_beneficio, vector<vector<vector<int>>>& memo) {
    
    // Caso base: cuando hemos considerado todas las instancias
    if (instancia == gpus_solicitadas.size()) {
        return 0;  //el beneficio es 0
    }

    // Si ya hemos calculado este subproblema, devolver el resultado almacenado
    if (memo[instancia][gpus_por_maquina1][gpus_por_maquina2] != -1) {
        return memo[instancia][gpus_por_maquina1][gpus_por_maquina2];
    }


        // Opción 1: No asignar la instancia actual a ninguna máquina
    int beneficio_no_asignar = prog_dinamica_2(instancia + 1, m, gpus_solicitadas, beneficios, 
                                               gpus_por_maquina1, gpus_por_maquina2, s, 
                                               max_beneficio, memo);

    // Opción 2: Asignar la instancia a la máquina 1 si es posible
    int beneficio_asignar_maquina1 = 0;
    if (gpus_solicitadas[instancia] <= gpus_por_maquina1) {
        beneficio_asignar_maquina1 = beneficios[instancia] + 
            prog_dinamica_2(instancia + 1, m, gpus_solicitadas, beneficios, 
                            gpus_por_maquina1 - gpus_solicitadas[instancia], gpus_por_maquina2, s, 
                            max_beneficio, memo);
    }

    // Opción 3: Asignar la instancia a la máquina 2 si es posible
    int beneficio_asignar_maquina2 = 0;
    if (gpus_solicitadas[instancia] <= gpus_por_maquina2) {
        beneficio_asignar_maquina2 = beneficios[instancia] + 
            prog_dinamica_2(instancia + 1, m, gpus_solicitadas, beneficios, 
                            gpus_por_maquina1, gpus_por_maquina2 - gpus_solicitadas[instancia], s, 
                            max_beneficio, memo);
    }

    // el máximo entre las opciones
    int mejor_beneficio = max({beneficio_no_asignar, beneficio_asignar_maquina1, beneficio_asignar_maquina2});

    // Guardamos el resultado 
    memo[instancia][gpus_por_maquina1][gpus_por_maquina2] = mejor_beneficio;

    // Actualizamos el maximo beneficio encontrado
    max_beneficio = max(max_beneficio, mejor_beneficio);

    return mejor_beneficio;
}



int prog_dinamica_3(size_t instancia, size_t m, vector<int>& gpus_solicitadas, vector<int>& beneficios, 
                    int gpus_por_maquina1, int gpus_por_maquina2,int gpus_por_maquina3, vector<vector<int>>& s, 
                    int& max_beneficio, vector<vector<vector<vector<int>>>>& memo) {
    // Caso base: cuando hemos considerado todas las instancias
    if (instancia == gpus_solicitadas.size()) {
        return 0;  //el beneficio es 0
    }

    // Si ya hemos calculado este subproblema, devolver el resultado almacenado
    if (memo[instancia][gpus_por_maquina1][gpus_por_maquina2] [gpus_por_maquina3]!= -1) {
        return memo[instancia][gpus_por_maquina1][gpus_por_maquina2][gpus_por_maquina3];
    }

    // Opción 1: No asignar la instancia actual a ninguna máquina
    int beneficio_no_asignar = prog_dinamica_3(instancia + 1, m, gpus_solicitadas, beneficios, 
                                               gpus_por_maquina1, gpus_por_maquina2, gpus_por_maquina3, s, 
                                               max_beneficio, memo);

    // Opción 2: Asignar la instancia a la máquina 1 si es posible
    int beneficio_asignar_maquina1 = 0;
    if (gpus_solicitadas[instancia] <= gpus_por_maquina1) {
        beneficio_asignar_maquina1 = beneficios[instancia] + 
            prog_dinamica_3(instancia + 1, m, gpus_solicitadas, beneficios, 
                            gpus_por_maquina1 - gpus_solicitadas[instancia], gpus_por_maquina2, gpus_por_maquina3, s, 
                            max_beneficio, memo);
    }

    // Opción 3: Asignar la instancia a la máquina 2 si es posible
    int beneficio_asignar_maquina2 = 0;
    if (gpus_solicitadas[instancia] <= gpus_por_maquina2) {
        beneficio_asignar_maquina2 = beneficios[instancia] + 
            prog_dinamica_3(instancia + 1, m, gpus_solicitadas, beneficios, 
                            gpus_por_maquina1, gpus_por_maquina2 - gpus_solicitadas[instancia], gpus_por_maquina3,s, 
                            max_beneficio, memo);
    }

     // Opción 4: Asignar la instancia a la máquina 3 si es posible
    int beneficio_asignar_maquina3 = 0;
    if (gpus_solicitadas[instancia] <= gpus_por_maquina3) {
        beneficio_asignar_maquina3 = beneficios[instancia] + 
            prog_dinamica_3(instancia + 1, m, gpus_solicitadas, beneficios, 
                            gpus_por_maquina1, gpus_por_maquina2, gpus_por_maquina3  - gpus_solicitadas[instancia],s, 
                            max_beneficio, memo);
    }

    // El máximo entre las opciones
    int mejor_beneficio = max({beneficio_no_asignar, beneficio_asignar_maquina1, beneficio_asignar_maquina2,  beneficio_asignar_maquina3});

    // Guardamos el resultado 
    memo[instancia][gpus_por_maquina1][gpus_por_maquina2][gpus_por_maquina3]  = mejor_beneficio;

    // Actualizamos el máximo beneficio encontrado
    max_beneficio = max(max_beneficio, mejor_beneficio);

    return mejor_beneficio;
}



int prog_dinamica_4(size_t instancia, size_t m, vector<int>& gpus_solicitadas, vector<int>& beneficios, 
                    int gpus_por_maquina1, int gpus_por_maquina2,int gpus_por_maquina3, int gpus_por_maquina4, vector<vector<int>>& s, 
                    int& max_beneficio, vector<vector<vector<vector<vector<int>>>>>& memo) {
    // Caso base: cuando hemos considerado todas las instancias
    if (instancia == gpus_solicitadas.size()) {
        return 0;  //el beneficio es 0
    }

    // Si ya hemos calculado este subproblema, devolver el resultado almacenado
    if (memo[instancia][gpus_por_maquina1][gpus_por_maquina2] [gpus_por_maquina3][gpus_por_maquina4]!= -1) {
        return memo[instancia][gpus_por_maquina1][gpus_por_maquina2][gpus_por_maquina3][gpus_por_maquina4];
    }

    // Opción 1: No asignar la instancia actual a ninguna máquina
    int beneficio_no_asignar = prog_dinamica_4(instancia + 1, m, gpus_solicitadas, beneficios, 
                                               gpus_por_maquina1, gpus_por_maquina2, gpus_por_maquina3,gpus_por_maquina4, s, 
                                               max_beneficio, memo);

    // Opción 2: Asignar la instancia a la máquina 1 si es posible
    int beneficio_asignar_maquina1 = 0;
    if (gpus_solicitadas[instancia] <= gpus_por_maquina1) {
        beneficio_asignar_maquina1 = beneficios[instancia] + 
            prog_dinamica_4(instancia + 1, m, gpus_solicitadas, beneficios, 
                            gpus_por_maquina1 - gpus_solicitadas[instancia], gpus_por_maquina2, gpus_por_maquina3,gpus_por_maquina4, s, 
                            max_beneficio, memo);
    }

    // Opción 3: Asignar la instancia a la máquina 2 si es posible
    int beneficio_asignar_maquina2 = 0;
    if (gpus_solicitadas[instancia] <= gpus_por_maquina2) {
        beneficio_asignar_maquina2 = beneficios[instancia] + 
            prog_dinamica_4(instancia + 1, m, gpus_solicitadas, beneficios, 
                            gpus_por_maquina1, gpus_por_maquina2 - gpus_solicitadas[instancia], gpus_por_maquina3,gpus_por_maquina4,s, 
                            max_beneficio, memo);
    }

     // Opción 4: Asignar la instancia a la máquina 3 si es posible
    int beneficio_asignar_maquina3 = 0;
    if (gpus_solicitadas[instancia] <= gpus_por_maquina3) {
        beneficio_asignar_maquina3 = beneficios[instancia] + 
            prog_dinamica_4(instancia + 1, m, gpus_solicitadas, beneficios, 
                            gpus_por_maquina1, gpus_por_maquina2, gpus_por_maquina3  - gpus_solicitadas[instancia],gpus_por_maquina4,s, 
                            max_beneficio, memo);
    }

     // Opción 4: Asignar la instancia a la máquina 4 si es posible
    int beneficio_asignar_maquina4 = 0;
    if (gpus_solicitadas[instancia] <= gpus_por_maquina4) {
        beneficio_asignar_maquina4 = beneficios[instancia] + 
            prog_dinamica_4(instancia + 1, m, gpus_solicitadas, beneficios, 
                            gpus_por_maquina1, gpus_por_maquina2, gpus_por_maquina3 ,gpus_por_maquina4  - gpus_solicitadas[instancia],s, 
                            max_beneficio, memo);
    }

    // El máximo entre las opciones
    int mejor_beneficio = max({beneficio_no_asignar, beneficio_asignar_maquina1, beneficio_asignar_maquina2,  beneficio_asignar_maquina3, beneficio_asignar_maquina4});

    // Guardamos el resultado 
    memo[instancia][gpus_por_maquina1][gpus_por_maquina2][gpus_por_maquina3][gpus_por_maquina4]  = mejor_beneficio;

    // Actualizamos el máximo beneficio encontrado
    max_beneficio = max(max_beneficio, mejor_beneficio);

    return mejor_beneficio;
}


int prog_dinamica (int n, int m, vector<int>& gpus_solicitadas, vector<int>& beneficios,  vector<int> gpus_por_maquina, vector<vector<int>>& s,  int& max_beneficio){

    if (m==2){
        // Inicializamos memo: (instancia, GPUs máquina 1, GPUs máquina 2)
        vector<vector<vector<int>>> memo(n, vector<vector<int>>(gpus_por_maquina[0] + 1, vector<int>(gpus_por_maquina[1] + 1, -1)));
        return prog_dinamica_2(0, m, gpus_solicitadas, beneficios, gpus_por_maquina[0], gpus_por_maquina[1], s, max_beneficio, memo);
        }
       
    

    else if (m==3){
        // Inicializamos memo: (instancia, GPUs máquina 1, GPUs máquina 2)
        vector<vector<vector<vector<int>>>> memo(n, vector<vector<vector<int>>>(  gpus_por_maquina[0] + 1, 
        vector<vector<int>>(gpus_por_maquina[1] + 1, vector<int>(gpus_por_maquina[2] + 1,  -1)) ) );
        return prog_dinamica_3(0, m, gpus_solicitadas, beneficios, gpus_por_maquina[0], gpus_por_maquina[1],gpus_por_maquina[2], s, max_beneficio, memo);
        }
       

    else if (m==4){
        // Inicializamos memo: (instancia, GPUs máquina 1, GPUs máquina 2)
        vector<vector<vector<vector<vector<int>>>>> memo( n, vector<vector<vector<vector<int>>>>(  gpus_por_maquina[0] + 1, vector<vector<vector<int>>>(gpus_por_maquina[1] + 1, 
        vector<vector<int>>(gpus_por_maquina[2] + 1,  vector<int>(gpus_por_maquina[3] + 1, -1)) ) ));
        return prog_dinamica_4(0, m, gpus_solicitadas, beneficios, gpus_por_maquina[0], gpus_por_maquina[1],gpus_por_maquina[2],gpus_por_maquina[3], s, max_beneficio, memo);
        }
    
    return 0;
    }


/*

// main con 2 maquinas

int main() {
    int n = 5; // Número de instancias
    int m = 2; // Número de máquinas
    vector<int> beneficios = {1, 1, 10, 5, 5}; // Beneficios por instancia
    vector<int> gpus_solicitadas = {5, 5, 5, 5, 5}; // GPUs solicitadas por instancia
    vector<int> gpus_por_maquina = {10, 10}; // GPUs disponibles por máquina 1 y 2
    vector<vector<int>> s(n, vector<int>(m, 0)); // Matriz de asignaciones
    int max_beneficio = 0;

    // Llamamos a la función de programación dinámica
    prog_dinamica(n, m, gpus_solicitadas, beneficios, gpus_por_maquina, s, max_beneficio);

    cout << "El beneficio maximo es: " << max_beneficio << endl;

    return 0;
}

*/
/*
//main con 4 maquinas
int main() {
    int n = 5; // Número de instancias
    int m = 4; // Número de máquinas
    vector<int> beneficios = {10, 10, 10, 5, 5}; // Beneficios por instancia
    vector<int> gpus_solicitadas = {5, 5, 5, 5, 5}; // GPUs solicitadas por instancia
    vector<int> gpus_por_maquina = {1, 1,13,13}; // GPUs disponibles por máquina 1 y 2
    vector<vector<int>> s(n, vector<int>(m, 0)); // Matriz de asignaciones
    int max_beneficio= 0;


    // Llamamos a la función de programación dinámica
    prog_dinamica(n, m, gpus_solicitadas, beneficios, gpus_por_maquina,s, max_beneficio);

    cout << "El beneficio maximo es: " << max_beneficio << endl;

    return 0;
}

*/