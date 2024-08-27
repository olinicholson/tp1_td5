#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;



//FUERZA BRUTA
//1. [1,0,0][1,1,1][1,0,0] (todas la combinaciones posibles  -> que sea posible)
//2. funcion beneficio y guardo en una lista todos los resultados
//3. calcular todas las opciones
//4. si se pasa de cantidad las saco
//5. busco el beneficio maximo entre las posbles 

// funcion calcular benficio total para una combinacion de instancias solicitadas
int calcular_beneficio(const vector<int>& combinacion, const vector<int>& gpus_solicitadas, const vector<int>& beneficios, vector<int> gpus_por_maquina) {
    int beneficio_total = 0;

    // Crea una copia del vector de GPUs por máquina para modificarlo durante la validación
    vector<int> uso_gpus = gpus_por_maquina;

    for (int i = 0; i < combinacion.size(); i++) {
        if (combinacion[i] == 1) { // Si la instancia está asignada
            bool asignado = false;

            // Intentar asignar la instancia a alguna máquina
            for (int j = 0; j < uso_gpus.size(); j++) {
                if (uso_gpus[j] >= gpus_solicitadas[i]) {
                    uso_gpus[j] -= gpus_solicitadas[i];
                    beneficio_total += beneficios[i];
                    asignado = true;
                    break;
                }
            }

            // Si la instancia no se pudo asignar, la combinación no es válida
            if (!asignado) {
                return -1; // Indica que la combinación no es válida
            }
        }
    }

    return beneficio_total; // Retorna el beneficio total de la combinación válida
}





void resolver_instancia(int n, int m, vector<int> &gpus_solicitadas, vector<int> &beneficios, vector<int> &gpus_por_maquina)
{
    // Greedy approach to fill m knapsacks
    int solucion = 0;
    ;
    int j = 0;
    for (int i = 0; i < m; i++)
    {
        while (j < n)
        {
            if (gpus_solicitadas[j] <= gpus_por_maquina[i])
            {
                solucion += beneficios[j];
                j++;
                break;
            }
            j++;
        }
    }
    cout << solucion << endl;
}

int main()
{
    int n, m, cantidad_gpus; // Cantidad de instancias, cantidad de maquinas, capacidad de maquinas
    cin >> n >> m >> cantidad_gpus;

    vector<int> gpus_solicitadas(n);
    vector<int> beneficios(n);
    vector<int> gpus_por_maquina(m, cantidad_gpus);

    for (int i = 0; i < n; i++)
    {
        cin >> gpus_solicitadas[i] >> beneficios[i];
    }

    resolver_instancia(n, m, gpus_solicitadas, beneficios, gpus_por_maquina);
}

