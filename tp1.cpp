#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// No resuelve bien, trata de poner una instancia en cada maquina
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

    return 0;
}
