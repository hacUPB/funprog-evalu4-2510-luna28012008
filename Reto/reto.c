#include <stdio.h>
#include <stdlib.h>

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
  

    printf("Nombre del archivo (.txt): ");
    if (!fgets(nombrearchivo, sizeof(nombrearchivo), stdin)) {
        printf("Error al leer nombre.\n");
        return;
    }

//eso retorna un puntero entonces lo niega para que entre al if y asi pueda decir que es falso.

    nombrearchivo[strcspn(nombrearchivo, "\n")] = 0;

    FILE *archivo = fopen(nombrearchivo, "r");
    
    if (!archivo) {
        printf("No se pudo abrir el archivo: %s\n", nombrearchivo);
        return;
    }
  
    long tamaño = 0; 
    int caracter; 
    
    while ((caracter = fgetc(archivo)) != EOF) {
        tamaño++; 
    }
    
    char *contenido = (char *)malloc(tamaño + 1); 
    if (!contenido) {
        printf("Error al asignar memoria.\n");
        fclose(archivo); 
        return; 
    }
   
}

void calcular_estadisticas() {
    printf("Función para calcular estadísticas.\n");
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

