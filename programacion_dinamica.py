from typing import List
def prog_dinamica_2 (instancia, m, gpus_solicitadas,beneficios, gpus_por_maquina1, gpus_por_maquina2, s, max_beneficio, memo):
    
    # Caso base: cuando hemos considerado todas las instancias
    if instancia == len(gpus_solicitadas):
        return 0  #el beneficio es 0

    # Si ya hemos calculado este subproblema, devolver el resultado almacenado
    elif memo[instancia][gpus_por_maquina1][gpus_por_maquina2] != -1:
        return memo[instancia][gpus_por_maquina1][gpus_por_maquina2]


        # Opción 1: No asignar la instancia actual a ninguna máquina
    beneficio_no_asignar = prog_dinamica_2(instancia + 1, m, gpus_solicitadas, beneficios, gpus_por_maquina1, gpus_por_maquina2, s, max_beneficio, memo)

    # Opción 2: Asignar la instancia a la máquina 1 si es posible
    beneficio_asignar_maquina1 = 0
    if gpus_solicitadas[instancia] <= gpus_por_maquina1:
        beneficio_asignar_maquina1 = beneficios[instancia] + prog_dinamica_2(instancia + 1, m, gpus_solicitadas, beneficios, 
                            gpus_por_maquina1 - gpus_solicitadas[instancia], gpus_por_maquina2, s, 
                            max_beneficio, memo)

    # Opción 3: Asignar la instancia a la máquina 2 si es posible
    beneficio_asignar_maquina2 = 0
    if gpus_solicitadas[instancia] <= gpus_por_maquina2:
        beneficio_asignar_maquina2 = beneficios[instancia] + prog_dinamica_2(instancia + 1, m, gpus_solicitadas, beneficios, 
                            gpus_por_maquina1, gpus_por_maquina2 - gpus_solicitadas[instancia], s, 
                            max_beneficio, memo)

    # el máximo entre las opciones
    mejor_beneficio = max({beneficio_no_asignar, beneficio_asignar_maquina1, beneficio_asignar_maquina2})

    # Guardamos el resultado 
    memo[instancia][gpus_por_maquina1][gpus_por_maquina2] = mejor_beneficio

    # Actualizamos el maximo beneficio encontrado
    max_beneficio = max(max_beneficio, mejor_beneficio)

    return mejor_beneficio

def prog_dinamica_3(instancia, m, gpus_solicitadas, beneficios, 
                    gpus_por_maquina1, gpus_por_maquina2, gpus_por_maquina3, s, 
                    max_beneficio, memo):
    
    #Caso base: cuando hemos considerado todas las instancias
    if instancia == len(gpus_solicitadas):
        return 0;  #el beneficio es 0
    

    #Si ya hemos calculado este subproblema, devolver el resultado almacenado
    elif memo[instancia][gpus_por_maquina1][gpus_por_maquina2] [gpus_por_maquina3]!= -1:
        return memo[instancia][gpus_por_maquina1][gpus_por_maquina2][gpus_por_maquina3]
    

    #Opción 1: No asignar la instancia actual a ninguna máquina
    beneficio_no_asignar = prog_dinamica_3(instancia + 1, m, gpus_solicitadas, beneficios, gpus_por_maquina1, gpus_por_maquina2, gpus_por_maquina3, s, max_beneficio, memo)

    #Opción 2: Asignar la instancia a la máquina 1 si es posible
    beneficio_asignar_maquina1 = 0
    
    if gpus_solicitadas[instancia] <= gpus_por_maquina1:
        beneficio_asignar_maquina1 = beneficios[instancia] + prog_dinamica_3(instancia + 1, m, gpus_solicitadas, beneficios, 
                                gpus_por_maquina1 - gpus_solicitadas[instancia], gpus_por_maquina2, gpus_por_maquina3, s, 
                                max_beneficio, memo)

    #Opción 3: Asignar la instancia a la máquina 2 si es posible
    beneficio_asignar_maquina2 = 0
    if gpus_solicitadas[instancia] <= gpus_por_maquina2:
        beneficio_asignar_maquina2 = beneficios[instancia] + prog_dinamica_3(instancia + 1, m, gpus_solicitadas, beneficios, 
                            gpus_por_maquina1, gpus_por_maquina2 - gpus_solicitadas[instancia], gpus_por_maquina3,s, 
                            max_beneficio, memo)
        
    #Opción 4: Asignar la instancia a la máquina 3 si es posible
    beneficio_asignar_maquina3 = 0
    if gpus_solicitadas[instancia] <= gpus_por_maquina3:
        beneficio_asignar_maquina3 = beneficios[instancia] + prog_dinamica_3(instancia + 1, m, gpus_solicitadas, beneficios, 
                            gpus_por_maquina1, gpus_por_maquina2, gpus_por_maquina3  - gpus_solicitadas[instancia],s, 
                            max_beneficio, memo)

    # El máximo entre las opciones
    mejor_beneficio = max({beneficio_no_asignar, beneficio_asignar_maquina1, beneficio_asignar_maquina2,  beneficio_asignar_maquina3})

    # Guardamos el resultado 
    memo[instancia][gpus_por_maquina1][gpus_por_maquina2][gpus_por_maquina3]  = mejor_beneficio

    # Actualizamos el máximo beneficio encontrado
    max_beneficio = max(max_beneficio, mejor_beneficio)

    return mejor_beneficio



def prog_dinamica_4(instancia, m, gpus_solicitadas, beneficios, 
                    gpus_por_maquina1, gpus_por_maquina2, gpus_por_maquina3, gpus_por_maquina4, s, 
                    max_beneficio, memo):
    #Caso base: cuando hemos considerado todas las instancias
    if instancia == len(gpus_solicitadas):
        return 0 #el beneficio es 0

    #Si ya hemos calculado este subproblema, devolver el resultado almacenado
    if memo[instancia][gpus_por_maquina1][gpus_por_maquina2] [gpus_por_maquina3][gpus_por_maquina4]!= -1:
        return memo[instancia][gpus_por_maquina1][gpus_por_maquina2][gpus_por_maquina3][gpus_por_maquina4]

    #Opción 1: No asignar la instancia actual a ninguna máquina
    beneficio_no_asignar = prog_dinamica_4(instancia + 1, m, gpus_solicitadas, beneficios, gpus_por_maquina1, gpus_por_maquina2, gpus_por_maquina3,gpus_por_maquina4, s, max_beneficio, memo)

    #Opción 2: Asignar la instancia a la máquina 1 si es posible
    beneficio_asignar_maquina1 = 0
    if gpus_solicitadas[instancia] <= gpus_por_maquina1:
        beneficio_asignar_maquina1 = beneficios[instancia] + prog_dinamica_4(instancia + 1, m, gpus_solicitadas, beneficios, 
                            gpus_por_maquina1 - gpus_solicitadas[instancia], gpus_por_maquina2, gpus_por_maquina3,gpus_por_maquina4, s, 
                            max_beneficio, memo)

    #Opción 3: Asignar la instancia a la máquina 2 si es posible
    beneficio_asignar_maquina2 = 0
    if gpus_solicitadas[instancia] <= gpus_por_maquina2:
        beneficio_asignar_maquina2 = beneficios[instancia] + prog_dinamica_4(instancia + 1, m, gpus_solicitadas, beneficios, 
                            gpus_por_maquina1, gpus_por_maquina2 - gpus_solicitadas[instancia], gpus_por_maquina3,gpus_por_maquina4,s, 
                            max_beneficio, memo)

    #Opción 4: Asignar la instancia a la máquina 3 si es posible
    beneficio_asignar_maquina3 = 0
    if gpus_solicitadas[instancia] <= gpus_por_maquina3:
        beneficio_asignar_maquina3 = beneficios[instancia] + prog_dinamica_4(instancia + 1, m, gpus_solicitadas, beneficios, 
                            gpus_por_maquina1, gpus_por_maquina2, gpus_por_maquina3  - gpus_solicitadas[instancia],gpus_por_maquina4,s, 
                            max_beneficio, memo)
        
    #Opción 4: Asignar la instancia a la máquina 4 si es posible
    beneficio_asignar_maquina4 = 0
    if gpus_solicitadas[instancia] <= gpus_por_maquina4:
        beneficio_asignar_maquina4 = beneficios[instancia] + prog_dinamica_4(instancia + 1, m, gpus_solicitadas, beneficios, 
                            gpus_por_maquina1, gpus_por_maquina2, gpus_por_maquina3 ,gpus_por_maquina4  - gpus_solicitadas[instancia],s, 
                            max_beneficio, memo)

    #El máximo entre las opciones
    mejor_beneficio = max({beneficio_no_asignar, beneficio_asignar_maquina1, beneficio_asignar_maquina2,  beneficio_asignar_maquina3, beneficio_asignar_maquina4})

    #Guardamos el resultado 
    memo[instancia][gpus_por_maquina1][gpus_por_maquina2][gpus_por_maquina3][gpus_por_maquina4]  = mejor_beneficio

    #Actualizamos el máximo beneficio encontrado
    max_beneficio = max(max_beneficio, mejor_beneficio)

    return mejor_beneficio


def prog_dinamica (n, m, gpus_solicitadas, beneficios, gpus_por_maquina, s, max_beneficio):

    if m == 2:
    # Inicializamos la tabla de memoización como una lista 3D: (instancia, GPUs máquina 1, GPUs máquina 2)
        memo = [[[-1 for _ in range(gpus_por_maquina[1] + 1)] 
                for _ in range(gpus_por_maquina[0] + 1)] 
                for _ in range(n)]
        
        return prog_dinamica_2(0, m, gpus_solicitadas, beneficios, 
                            gpus_por_maquina[0], gpus_por_maquina[1], s, max_beneficio, memo)

    

    elif (m==3):
        #Inicializamos memo: (instancia, GPUs máquina 1, GPUs máquina 2)
        memo = [[[[-1 for _ in range(gpus_por_maquina[2] + 1)] 
            for _ in range(gpus_por_maquina[1] + 1)] 
            for _ in range(gpus_por_maquina[0] + 1)] 
            for _ in range(n)]

        return prog_dinamica_3(0, m, gpus_solicitadas, beneficios, gpus_por_maquina[0], gpus_por_maquina[1],gpus_por_maquina[2], s, max_beneficio, memo)

    elif (m==4):
        #Inicializamos memo: (instancia, GPUs máquina 1, GPUs máquina 2)
        memo = [[[[[-1 for _ in range(gpus_por_maquina[3] + 1)] 
            for _ in range(gpus_por_maquina[2] + 1)] 
            for _ in range(gpus_por_maquina[1] + 1)] 
            for _ in range(gpus_por_maquina[0] + 1)] 
            for _ in range(n)]

        return prog_dinamica_4(0, m, gpus_solicitadas, beneficios, gpus_por_maquina[0], gpus_por_maquina[1],gpus_por_maquina[2],gpus_por_maquina[3], s, max_beneficio, memo)
    
    return 0


# Ejemplo con 2 máquinas
n = 3  # Número de instancias
m = 2  # Número de máquinas
gpus_solicitadas = [100, 2000, 2]  # GPUs solicitadas por instancia
beneficios = [1, 20, 30]  # Beneficios por instancia
gpus_por_maquina = [100, 100]  # GPUs disponibles por máquina
s = [[0 for _ in range(m)] for _ in range(n)]
max_beneficio = 0

# Llamamos a la función de programación dinámica
max_beneficio = prog_dinamica(n, m, gpus_solicitadas, beneficios, gpus_por_maquina, s, max_beneficio)
print(f'El beneficio máximo es: {max_beneficio}')

