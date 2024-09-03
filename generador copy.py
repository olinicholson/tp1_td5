import random
import sys
import random


class TestDataGenerator:
    def __init__(self, n, m, w, v, name=None):
        self.n = n  # Cantidad de items
        self.m = m  # Cantidad de mochilas
        self.w = w  # Peso de cada mochila
        self.v = v  # Máximo valor de los items
        self.max_weight = int(
            max(1, (m * w * 2) / n)
        )  # Cantidad esperada de items por mochila, tratamos de que haya items que no entren
        if name is None:
            name = f"{n}_{m}_{w}_{v}"
        self.name = name
        self.instances = []

    def create_test_data(self):
        items = []
        for _ in range(self.n):
            items.append(
                (
                    random.randint(1, self.max_weight),
                    random.randint(1, self.v),
                )
            )
        self.instances.append(items)

    def create_multiple_tests(self, num_tests):
        for _ in range(num_tests):
            items = self.create_test_data()

    def write_test_data(self):
        for i, instance in enumerate(self.instances):
            filename = f"{self.name}_{i}"
            with open(filename, "w") as file:
                file.write(f"{self.n} {self.m} {self.w}\n")
                for item in instance:
                    file.write(f"{item[0]} {item[1]}\n")


def alternative_two_knapsacks():
    for i in range(1, 21):
        tests = TestDataGenerator(i * 5, 2, 1000, 1000, f"caso_2_{i*5}")
        tests.create_multiple_tests(10)
        tests.write_test_data()


def alternative_four_knapsacks():
    for i in range(1, 21):
        tests = TestDataGenerator(i * 5, 4, 500, 1000, f"caso_4_{i*5}")
        tests.create_multiple_tests(10)
        tests.write_test_data()


if __name__ == "__main__":
    alternative_four_knapsacks()
    alternative_two_knapsacks()
