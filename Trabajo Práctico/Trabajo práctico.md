# Trabajo Práctico: Tópicos de Programación
---
## Resúmen: 
El programa está compuesto por 2 header y 3 archivos fuente: uno para preparar los datos obtenidos del archivo, otro para generar los archivos de texto y un archivo principal. Estos archivos leen y obtienen datos de un archivo externo, el cual se llama "Telemetria.bin", el cual guarda la información según el PDF que está dentro de la carpeta con el proyecto.  

### Manejo de archivos
Primero se debe chequear la integridad del archivo "Telemetria.bin", el cual posee registros de 4000 bytes. Es por esto que la función ExaminarIntegridad abre el archivo, posiciona el puntero al final de este y chequea que el tamaño del archivo sea divisible por 4000, de lo contrario hay registros dañados.
Luego, en la función LecturaArchivo, se va recorriendo registro a registro, tomando la información correspondiente a la fecha y el voltaje registrado. Esto es procesado por una función que se encuentra en el archivo "manejoDatos.c". 
Una vez realizadas las operaciones, el dato se carga en el archivo correspondiente, generando 2 archivos que almacenarán, por un lado las fechas, y por el otro los registros del voltaje obtenido. Una vez finalizada la lectura, pasa a ejecutarse la fusion entre estos dos archivos, generando un tercero que me permitirá analizar, en este caso por medio de excel, con un gráfico la variación en el tiempo que hubo.

## Manejo de datos
Se utilizan las librerías de stdint y time. Por un lado, stdint me permite moverme byte a byte, pudiendo trabajar mejor con el archivo binario en cuestión, por el otro, time.h me brinda una forma simple de transformar los datos obtenidos (segundos desde el 1-6-1980) a una fecha por medio de mktime y gmtime, utilizando el struct tm.  En el caso del voltaje, se debe realizar una operación para transformar el entero registrado a un float que oscila entre 30 y 35. 
Para facilitar la creación de los archivos, utilizo un string llamado "mensaje", el cual tiene el espacio suficiente como para almacenar el dato en cuestión. Una vez generado el dato, utilizo la función sprintf para almacenarlo con el formato esperado.

