import random


def generar_nombre():
    nombres = ["Juan", "Maria", "Pedro", "Luis", "Ana", "Carlos", "Laura", "Marta", "Diego", "Sofia"]
    return random.choice(nombres)

def generar_apellido():
    apellidos = ["Perez", "Lopez", "Gomez", "Rodriguez", "Gonzalez", "Fernandez", "Torres", "Hernandez", "Rios", "Silva"]
    return random.choice(apellidos)

with open("palabras.txt", "w") as arch:
    for _ in range(100):
        texto = ""
        seed1 = random.randint(0,100)
        if seed1 % 4 == 0:
            texto += generar_nombre()
        else:
            texto += generar_apellido();
        if seed1 % 6 == 0:
            texto += ".\0"
        else:
            texto += "\0"
        arch.write(texto)
        
