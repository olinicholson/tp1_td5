import time
from programacion_dinamica import prog_dinamica, prog_dinamica_2, prog_dinamica_3, prog_dinamica_4
def test_ejemplo_1():
    print("Ejemplo 1: La segunda instancia no puede ser asignada")

    n = 5  # Número de instancias
    m = 4  # Número de máquinas
    gpus_solicitadas = [20, 100, 30, 20]  # GPUs solicitadas por instancia
    beneficios = [10, 20, 30, 25]  # Beneficios por instancia
    gpus_por_maquina = [50, 50, 50, 50]  # GPUs disponibles por máquina
    s = [[0 for _ in range(m)] for _ in range(n)]  # Matriz de asignaciones
    max_beneficio = 0

    # Inicializar la tabla de memoización
    memo = [[[[[-1 for _ in range(gpus_por_maquina[3] + 1)] 
            for _ in range(gpus_por_maquina[2] + 1)] 
            for _ in range(gpus_por_maquina[1] + 1)] 
            for _ in range(gpus_por_maquina[0] + 1)] 
            for _ in range(n)]

    # Variables para promediar tiempos
    total_dinamica = 0

    # Ejecutar 10 veces para programación dinámica
    for _ in range(10):
        # Ejecutar la función antes de medir el tiempo para evitar que el tiempo de configuración afecte la medición
        prog_dinamica_4(0, m, gpus_solicitadas, beneficios, gpus_por_maquina[0], gpus_por_maquina[1], gpus_por_maquina[2], gpus_por_maquina[3], s, max_beneficio, memo)
        
        start = time.time()
        max_beneficio = prog_dinamica_4(0, m, gpus_solicitadas, beneficios, gpus_por_maquina[0], gpus_por_maquina[1], gpus_por_maquina[2], gpus_por_maquina[3], s, max_beneficio, memo)
        stop = time.time()
        total_dinamica += (stop - start) * 1e6  # Convertir a microsegundos

    # Mostrar promedios
    print(f"Promedio tiempo programación dinámica: {total_dinamica / 10} microsegundos")
    print(f"Máximo beneficio: {max_beneficio}")


def test_ejemplo_2():
    print("Ejemplo 2: Todas las instancias pueden ser asignadas")

    n = 5  # Número de instancias
    m = 4  # Número de máquinas
    gpus_solicitadas = [10, 20]  # GPUs solicitadas por instancia
    beneficios = [10, 20]  # Beneficios por instancia
    gpus_por_maquina = [50, 50]  # GPUs disponibles por máquina
    s = [[0 for _ in range(m)] for _ in range(n)]  # Matriz de asignaciones
    max_beneficio = 0

    # Inicializar la tabla de memoización
    memo = [[[-1 for _ in range(gpus_por_maquina[1] + 1)] 
            for _ in range(gpus_por_maquina[0] + 1)]
            for _ in range(n)]

    # Variables para promediar tiempos
    total_dinamica = 0

    # Ejecutar 10 veces para programación dinámica
    for _ in range(10):
        start = time.time()
        prog_dinamica_2(0, m, gpus_solicitadas, beneficios, gpus_por_maquina[0], gpus_por_maquina[1], s, max_beneficio, memo)
        stop = time.time()
        total_dinamica += (stop - start) * 1e6  # Convertir a microsegundos

    # Mostrar promedios
    print(f"Promedio tiempo programación dinámica (ejemplo 2): {total_dinamica / 10:.2f} microsegundos")

def test_ejemplo_3():
    print("Ejemplo 3: Se asignan las tres instancias en 1")

    n = 3  # Número de instancias
    m = 3  # Número de máquinas
    gpus_solicitadas = [100, 2000, 2]  # GPUs solicitadas por instancia
    beneficios = [1, 20, 30]  # Beneficios por instancia
    gpus_por_maquina = [0, 2102, 0]  # GPUs disponibles por máquina
    s = [[0 for _ in range(m)] for _ in range(n)]  # Matriz de asignaciones
    max_beneficio = 0

    # Inicializar la tabla de memoización
    memo = [[[[-1 for _ in range(gpus_por_maquina[2] + 1)] 
            for _ in range(gpus_por_maquina[1] + 1)] 
            for _ in range(gpus_por_maquina[0] + 1)]
            for _ in range(n)]

    # Variables para promediar tiempos
    total_dinamica = 0

    # Ejecutar 10 veces para programación dinámica
    for _ in range(10):
        start = time.time()
        prog_dinamica_3(0, m, gpus_solicitadas, beneficios, gpus_por_maquina[0], gpus_por_maquina[1], gpus_por_maquina[2], s, max_beneficio, memo)
        stop = time.time()
        total_dinamica += (stop - start) * 1e6  # Convertir a microsegundos

    # Mostrar promedios
    print(f"Promedio tiempo programación dinámica (ejemplo 4): {total_dinamica / 10:.2f} microsegundos")

# Ejecutar los tests
test_ejemplo_1()
test_ejemplo_2()
test_ejemplo_3()