import unittest
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

    # Variables para promediar tiempos
    total_dinamica = 0

    # Ejecutar 10 veces para programación dinámica
    for i in range(10):
        start = time.time()
        max_beneficio = prog_dinamica(n, m, gpus_solicitadas, beneficios, gpus_por_maquina, s, max_beneficio)
        stop = time.time()
        total_dinamica += (stop - start) * 1e6  # Convertir a microsegundos

    # Mostrar promedios
    print(f"Promedio tiempo programación dinámica: {total_dinamica / 10} microsegundos")
    print(f"Máximo beneficio: {max_beneficio}")

test_ejemplo_1()

def test_ejemplo_2():
    print("Ejemplo 2: Todas las instancias pueden ser asignadas")

    n = 5  # Número de instancias
    m = 4  # Número de máquinas
    gpus_solicitadas = [10, 20, 30, 20]  # GPUs solicitadas por instancia
    beneficios = [10, 20, 30, 25]  # Beneficios por instancia
    gpus_por_maquina = [50, 50, 50, 50]  # GPUs disponibles por máquina
    s = [[0 for _ in range(m)] for _ in range(n)]  # Matriz de asignaciones
    max_beneficio = 0

    # Variables para promediar tiempos
    total_dinamica = 0

    # Ejecutar 10 veces para programación dinámica
    for i in range(10):
        start = time.time()
        max_beneficio = prog_dinamica(n, m, gpus_solicitadas, beneficios, gpus_por_maquina, s, max_beneficio)
        stop = time.time()
        total_dinamica += (stop - start) * 1e6  # Convertir a microsegundos

    # Mostrar promedios
    print(f"Promedio tiempo programación dinámica: {total_dinamica / 10} microsegundos")
    print(f"Máximo beneficio: {max_beneficio}")

test_ejemplo_2()

def test_ejemplo_3():
    print("\nEjemplo 3: Ninguna instancia puede ser asignada")

    n = 5  # Número de instancias
    m = 4  # Número de máquinas
    gpus_solicitadas = [100, 200, 300, 200]  # GPUs solicitadas por instancia
    beneficios = [10, 20, 30, 25]  # Beneficios por instancia
    gpus_por_maquina = [50, 50, 50, 50]  # GPUs disponibles por máquina
    s = [[0 for _ in range(m)] for _ in range(n)]  # Matriz de asignaciones
    max_beneficio = 0

    # Variables para promediar tiempos
    total_dinamica = 0

    # Ejecutar 10 veces para programación dinámica
    for i in range(10):
        start = time.time()
        max_beneficio = prog_dinamica(n, m, gpus_solicitadas, beneficios, gpus_por_maquina, s, max_beneficio)
        stop = time.time()
        total_dinamica += (stop - start) * 1e6  # Convertir a microsegundos

    # Mostrar promedios
    print(f"Promedio tiempo programación dinámica: {total_dinamica / 10} microsegundos")
    print(f"Máximo beneficio: {max_beneficio}")

test_ejemplo_3()


def test_ejemplo_4():
    print("\nEjemplo 4: Se asignan las tres instancias en 1")

    n = 3  # Número de instancias
    m = 3  # Número de máquinas
    gpus_solicitadas = [100, 2000, 2]  # GPUs solicitadas por instancia
    beneficios = [1, 20, 30]  # Beneficios por instancia
    gpus_por_maquina = [0, 2102, 0]  # GPUs disponibles por máquina
    s = [[0 for _ in range(m)] for _ in range(n)]
    max_beneficio = 0

    # Variables para promediar tiempos
    total_dinamica = 0

    # Ejecutar 10 veces para programación dinámica
    for i in range(10):
        start = time.time()
        max_beneficio = prog_dinamica(n, m, gpus_solicitadas, beneficios, gpus_por_maquina, s, max_beneficio)
        stop = time.time()
        total_dinamica += (stop - start) * 1e6  # Convertir a microsegundos

    # Mostrar promedios
    print(f"Promedio tiempo programación dinámica: {total_dinamica / 10} microsegundos")
    print(f"Máximo beneficio: {max_beneficio}")

test_ejemplo_4()