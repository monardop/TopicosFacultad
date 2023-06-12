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

# Ahora los ordeno
def ordenar_lineas(lineas):
    lineas.sort(key=lambda x: (x[1], x[2], x[0]))  # Ordenar por Apellido, Nombre, DNI
    return lineas

def leer_archivo(nombre_archivo):
    lineas = []
    with open(nombre_archivo, 'r') as archivo:
        for linea in archivo:
            linea = linea.strip()
            if linea:
                dni = int(linea[:10])
                apellido = linea[10:30].strip()
                nombre = linea[30:50].strip()
                valor = float(linea[50:])
                lineas.append((dni, apellido, nombre, valor))
    return lineas

def escribir_archivo(lineas, nombre_archivo):
    with open(nombre_archivo, 'w') as archivo:
        for linea in lineas:
            archivo.write(f"{linea[0]:<10}{linea[1]:<20}{linea[2]:<20}{linea[3]:.2f}\n")

# Leer y ordenar el primer archivo
archivo1 = "empleados_promedio.txt"
lineas1 = leer_archivo(archivo1)
lineas1 = ordenar_lineas(lineas1)
escribir_archivo(lineas1, archivo1)

# Leer y ordenar el segundo archivo
archivo2 = "empleados_sueldo.txt"
lineas2 = leer_archivo(archivo2)
lineas2 = ordenar_lineas(lineas2)
escribir_archivo(lineas2, archivo2)