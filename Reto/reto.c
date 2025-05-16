#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// Prototipos de funciones (se implementarán después)
void ingresar_archivo();
void calcular_estadisticas();
void calcular_frecuencia_vocales();
void reemplazar_palabra();
void guardar_resultados();

#define magnitud_entrada 100


int main() {
    int opcion = 0;

    do {
        printf("\n ANALIZADOR DE ARCHIVO \n");
        printf("1. Ingresar el nombre del archivo a leer\n");
        printf("2. Calcular estadísticas del texto\n");
        printf("3. Calcular la frecuencia de aparición de las vocales\n");
        printf("4. Cambiar una palabra del texto por otra (find & replace)\n");
        printf("5. Guardar los resultados en un nuevo archivo\n");
        printf("0. Salir\n");
        printf("Seleccione una opción: ");
        scanf("%d", &opcion);
        getchar(); 

        switch (opcion) {
            case 1:
                ingresar_archivo();
                break;
            case 2:
                calcular_estadisticas();
                break;
            case 3:
                calcular_frecuencia_vocales();
                break;
            case 4:
                reemplazar_palabra();
                break;
            case 5:
                guardar_resultados();
                break;
            case 0:
                printf("Saliendo del programa.\n");
                break;
            default:
                printf("Opción no válida. Intente de nuevo.\n");
        }
    } while (opcion != 0);

    return 0;
}


void ingresar_archivo() {
    printf("Función para ingresar el archivo.\n");
  
    char nombrearchivo[100];

    printf("Nombre del archivo (.txt): ");
    if (!fgets(nombrearchivo, sizeof(nombrearchivo), stdin)) {
        printf("Error al leer nombre.\n");
        return;
    }

    nombrearchivo[strcspn(nombrearchivo, "\n")] = 0;

    FILE *archivo = fopen(nombrearchivo, "r");
    
    if (!archivo) {
        printf("No se pudo abrir el archivo: %s\n", nombrearchivo);
        return;
    }
  
    long magnitud = 0; 
    int caracter; 
    
    while ((caracter = fgetc(archivo)) != EOF) {
        magnitud++; 
    }
    
    char *contenido = (char *)malloc(magnitud + 1); 
    if (!contenido) {
        printf("Error al asignar memoria.\n");
        fclose(archivo); 
        return; 
    }
   
     fread(contenido, 1, magnitud, archivo);
    contenido[magnitud] = '\0';

    size_t leidos = fread(contenido, 1, magnitud, archivo);
    contenido[magnitud] = '\0';

    if (leidos == magnitud) {
        printf("✅ Todo el archivo fue leído correctamente.\n");
    } else {
        printf("Error de lectura: se esperaban %ld bytes pero se leyeron %zu.\n", magnitud, leidos);
        printf("Rectifica tu código o revisa el archivo.\n");
        
}
    fclose(archivo);
    return contenido;
}

void calcular_estadisticas() {
    printf("Función para calcular estadísticas.\n");
    printf("%s\n", contenido);

    long caracteres = 0;
    int palabras = 0;
    int espacios = 0;
    int lineas = 0;

    int en_palabra = 0;

    for (long i = 0; contenido[i] != '\0'; i++) {
        char c = contenido[i];
        if (c != '\n') 
            caracteres++;

        if (c == ' ')
            espacios++;

        if (c == '\n')
            lineas++;

        if (!isspace(c) && !en_palabra) {
            en_palabra = 1;
            palabras++;
        } else if (isspace(c)) {
            en_palabra = 0;
        }
    }

    // Si el texto no termina con \n, hay una línea más
    if (strlen(contenido) > 0 && contenido[strlen(contenido) - 1] != '\n') {
       lineas++;
    }

    printf("Estadísticas del texto\n");
    printf("Cantidad total de caracteres (sin \\n): %ld\n", caracteres);
    printf("Cantidad total de palabras: %d\n", palabras);
    printf("Cantidad de espacios en el texto: %d\n", espacios);
    printf("Cantidad de líneas: %d\n", lineas);
}


void calcular_frecuencia_vocales() {
    printf("Función para contar vocales.\n");
}

void reemplazar_palabra() {
    printf("Función para buscar y reemplazar palabra.\n");
}

void guardar_resultados() {
    printf("Función para guardar los resultados en archivo.\n");
}

