# TopicosFacultad

## Descripción del proyecto de clases

Proyecto donde voy a ir guardando las distintas funciones que haya hecho en la materia programación.

### TDAFechas

Es una biblioteca con funciones relacionadas a fechas, una especie de time que próximamente tendrá cosas relacionadas a tiempo.

### Vector

Tendrá funciones de carácter genérico para trabajar con vectores. Muchos serán implementaciónes propias de funciones ya existentes.

## Trabajo práctico
Se trata de un archivo sobre telemetría del cual me interesa obtener el voltaje promedio obtenido durante distintas fechas y horas.  El proyecto consta de dos archivos .c que tienen las operaciones necesarias para leer el archivo binario y luego operar con los datos que voy obteniendo.

### Datos importantes
- Cada registro consta de 4000 bytes.
- En esos 4000 bytes tendre desde el byte 100 a 104 la información en segundos sobre la fecha. 
- El 2354 y 2355 contienen el promedio de voltaje utilizado. Para obtener el valor real debo aplicar una operación. 
### Fecha y hora
Para estas operaciones utilicé time.h, librería que me permite setear una fecha base y sumarle la cantidad de segundos obtenidos de la lectura. Estos segundos se le agregan a una fecha inicial que es 1-6-1980. 

### Promedio de voltaje
Luego de obtener los dos bytes correspondientes, se pasan a un entero que tras aplicarle una operación me dará un numero que varía entre 30 y 35.