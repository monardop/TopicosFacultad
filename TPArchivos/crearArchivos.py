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
def agregar_registros():
    with open("empleados_sueldo.txt", "a") as archivo_sueldo :
        for _ in range(random.randint(10,50)):
            nombre = generar_nombre()
            apellido = generar_apellido()
            dni = generar_dni()
            sueldo = generar_sueldo()
            linea = f"{dni:<10}{apellido:<20}{nombre:<20}{sueldo}\n"
            archivo_sueldo.write(linea)

    # Generar archivo empleados_promedio.txt
    with open("empleados_promedio.txt", "a") as archivo_promedio:
        for _ in range(random.randint(10,50)):
            nombre = generar_nombre()
            apellido = generar_apellido()
            dni = generar_dni()
            promedio = generar_promedio()
            linea = f"{dni:<10}{apellido:<20}{nombre:<20}{promedio}\n"
            archivo_promedio.write(linea)

def crear_archivos():
    arch_promedio = open("empleados_promedio.txt", "w")
    arch_sueldo = open("empleados_sueldo.txt", "w")
    for _ in range(random.randint(20, 60)):
        nombre = generar_nombre()
        apellido = generar_apellido()
        dni = generar_dni()
        promedio = generar_promedio()
        sueldo = generar_sueldo()
        linea1 = f"{dni:<10}{apellido:<20}{nombre:<20}{promedio}\n"
        linea2 = f"{dni:<10}{apellido:<20}{nombre:<20}{sueldo}\n"
        arch_promedio.write(linea1)
        arch_sueldo.write(linea2)
    arch_promedio.close()
    arch_sueldo.close()

crear_archivos()
agregar_registros()