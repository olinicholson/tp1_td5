#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;



//FUERZA BRUTA
//1. [1,0,0][1,1,1][1,0,0] (todas la combinaciones posibles  -> que sea posible)
//2. funcion beneficio y guardo en una lista todos los resultados
//3. calcular todas las opciones
//4. si se pasa de cantidad las saco (todas las que tienen beneficio = -1)
//5. busco el beneficio maximo entre las posbles 

// funcion calcular benficio total para una combinacion de instancias solicitadas
int calcular_beneficio(const vector<int>& combinacion,  const vector<int>& beneficios) {
    int beneficio_total = 0;

    for (int i = 0; i < combinacion.size(); i++) {
        if (combinacion[i] == 1) { // Si la instancia está asignada
            beneficio_total += beneficios[i];

        }
    }
    return beneficio_total; // Retorna el beneficio total de la combinación válida
            
    }


/* 
    if (uso_gpus[j] >= gpus_solicitadas[i]) {
        uso_gpus[j] -= gpus_solicitadas[i];
Si la instancia no se pudo asignar, la combinación no es válida
if (!asignado) {
    return -1; // Indica que la combinación no es válida
    */


//Sea xij una variable binaria que indica si la instancia i es asignada a la máquina j
//n= 5
//m= 3
//beneficio= [1,2,3,4,5] 
//gpus_solictadas= [4,4,4,4,4]
//=> instancia = [(4,1),(4,2),(4,3),(4,4),(4,5)]

//gpu_por_maquina= [3,3,3]

//s : [[0,0,0,1,1], [0,1,1,0,0], [1,0,0,0,0]]


//s : asigno la instancia i a la maquina j -> tamaño n*m
// s= [1,1,0],[0,0,1],

void resolver_instancia(int n, int m, vector<int> &gpus_solicitadas, vector<int> &beneficios, vector<int> &gpus_por_maquina, vector<vector <int>> s)
{

    //caso base: si la cantidad de gpus por maquina <=  y el beneficio de lo que estamos haciendo > b 
    if ((gpus_por_maquina).size()==0){
        //devolver el beneficio total de s que seria 0
        return ben;
    
    }
    else{
        //lo mete
        int beneficio= calcular_beneficio(s)
        resolver_instancia()
        //no lo mete
        int beneficio= calcular_beneficio(s)
        resolver_instancia()
    }


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

