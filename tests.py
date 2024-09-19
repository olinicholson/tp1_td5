import time
from programacion_dinamica import prog_dinamica

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
    memo = [[[[-1 for _ in range(gpus_por_maquina[3] + 1)] 
            for _ in range(gpus_por_maquina[2] + 1)] 
            for _ in range(gpus_por_maquina[1] + 1)] 
            for _ in range(gpus_por_maquina[0] + 1)]

    # Variables para promediar tiempos
    total_dinamica = 0

    # Ejecutar 10 veces para programación dinámica
    for _ in range(10):
        start = time.time()
        prog_dinamica(n, m, gpus_solicitadas, beneficios, gpus_por_maquina, s, max_beneficio)
        stop = time.time()
        total_dinamica += (stop - start) * 1e6  # Convertir a microsegundos

    # Mostrar promedios
    print(f"Promedio tiempo programación dinámica (ejemplo 1): {total_dinamica / 10:.2f} microsegundos")

def test_ejemplo_2():
    print("Ejemplo 2: Todas las instancias pueden ser asignadas")

    n = 5  # Número de instancias
    m = 4  # Número de máquinas
    gpus_solicitadas = [10, 20, 30, 20]  # GPUs solicitadas por instancia
    beneficios = [10, 20, 30, 25]  # Beneficios por instancia
    gpus_por_maquina = [50, 50, 50, 50]  # GPUs disponibles por máquina
    s = [[0 for _ in range(m)] for _ in range(n)]  # Matriz de asignaciones
    max_beneficio = 0

    # Inicializar la tabla de memoización
    memo = [[[[-1 for _ in range(gpus_por_maquina[3] + 1)] 
            for _ in range(gpus_por_maquina[2] + 1)] 
            for _ in range(gpus_por_maquina[1] + 1)] 
            for _ in range(gpus_por_maquina[0] + 1)]

    # Variables para promediar tiempos
    total_dinamica = 0

    # Ejecutar 10 veces para programación dinámica
    for _ in range(10):
        start = time.time()
        prog_dinamica(n, m, gpus_solicitadas, beneficios, gpus_por_maquina, s, max_beneficio)
        stop = time.time()
        total_dinamica += (stop - start) * 1e6  # Convertir a microsegundos

    # Mostrar promedios
    print(f"Promedio tiempo programación dinámica (ejemplo 2): {total_dinamica / 10:.2f} microsegundos")

def test_ejemplo_3():
    print("Ejemplo 3: Ninguna instancia puede ser asignada")

    n = 5  # Número de instancias
    m = 4  # Número de máquinas
    gpus_solicitadas = [100, 200, 300, 200]  # GPUs solicitadas por instancia
    beneficios = [10, 20, 30, 25]  # Beneficios por instancia
    gpus_por_maquina = [50, 50, 50, 50]  # GPUs disponibles por máquina
    s = [[0 for _ in range(m)] for _ in range(n)]  # Matriz de asignaciones
    max_beneficio = 0

    # Inicializar la tabla de memoización
    memo = [[[[-1 for _ in range(gpus_por_maquina[3] + 1)] 
            for _ in range(gpus_por_maquina[2] + 1)] 
            for _ in range(gpus_por_maquina[1] + 1)] 
            for _ in range(gpus_por_maquina[0] + 1)]

    # Variables para promediar tiempos
    total_dinamica = 0

    # Ejecutar 10 veces para programación dinámica
    for _ in range(10):
        start = time.time()
        prog_dinamica(n, m, gpus_solicitadas, beneficios, gpus_por_maquina, s, max_beneficio)
        stop = time.time()
        total_dinamica += (stop - start) * 1e6  # Convertir a microsegundos

    # Mostrar promedios
    print(f"Promedio tiempo programación dinámica (ejemplo 3): {total_dinamica / 10:.2f} microsegundos")

def test_ejemplo_4():
    print("Ejemplo 4: Se asignan las tres instancias en 1")

    n = 3  # Número de instancias
    m = 3  # Número de máquinas
    gpus_solicitadas = [100, 2000, 2]  # GPUs solicitadas por instancia
    beneficios = [1, 20, 30]  # Beneficios por instancia
    gpus_por_maquina = [0, 2102, 0]  # GPUs disponibles por máquina
    s = [[0 for _ in range(m)] for _ in range(n)]  # Matriz de asignaciones
    max_beneficio = 0

    # Inicializar la tabla de memoización
    memo = [[[-1 for _ in range(gpus_por_maquina[2] + 1)] 
            for _ in range(gpus_por_maquina[1] + 1)] 
            for _ in range(gpus_por_maquina[0] + 1)]

    # Variables para promediar tiempos
    total_dinamica = 0

    # Ejecutar 10 veces para programación dinámica
    for _ in range(10):
        start = time.time()
        prog_dinamica(n, m, gpus_solicitadas, beneficios, gpus_por_maquina, s, max_beneficio)
        stop = time.time()
        total_dinamica += (stop - start) * 1e6  # Convertir a microsegundos

    # Mostrar promedios
    print(f"Promedio tiempo programación dinámica (ejemplo 4): {total_dinamica / 10:.2f} microsegundos")

# Ejecutar los tests
test_ejemplo_1()
test_ejemplo_2()
test_ejemplo_3()
test_ejemplo_4()
