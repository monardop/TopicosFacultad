import random

def generar_nombre():
    nombres = ["Juan", "Maria", "Pedro", "Luis", "Ana", "Carlos", "Laura", "Marta", "Diego", "Sofia"]
    return random.choice(nombres)

def generar_apellido():
    apellidos = ["Perez", "Lopez", "Gomez", "Rodriguez", "Gonzalez", "Fernandez", "Torres", "Hernandez", "Rios", "Silva"]
    return random.choice(apellidos)

def generar_dni():
    return random.randint(5000000, 9999999)

def generar_sueldo():
    return round(random.uniform(2000, 4000), 2)

def generar_promedio():
    return round(random.uniform(1, 9.99), 2)

# Generar archivo empleados_sueldo.txt
with open("empleados_sueldo.txt", "a") as archivo_sueldo :
    for _ in range(20):
        nombre = generar_nombre()
        apellido = generar_apellido()
        dni = generar_dni()
        sueldo = generar_sueldo()
        linea = f"{nombre:<20}{apellido:<20}{dni:<10}{sueldo}\n"
        archivo_sueldo.write(linea)

# Generar archivo empleados_promedio.txt
with open("empleados_promedio.txt", "a") as archivo_promedio:
    for _ in range(20):
        nombre = generar_nombre()
        apellido = generar_apellido()
        dni = generar_dni()
        promedio = generar_promedio()
        linea = f"{nombre:<20}{apellido:<20}{dni:<10}{promedio}\n"
        archivo_promedio.write(linea)
