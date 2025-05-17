#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// Prototipos de funciones
char* ingresar_archivo();
void calcular_estadisticas(const char *contenido, long *caracteres, int *palabras, int *espacios, int *lineas);
void calcular_frecuencia_vocales(const char *contenido, int vocales[5]);
char* reemplazar_palabra(char *contenido);
void guardar_resultados(const char *nombre_archivo, const char *contenido, long caracteres, int palabras, int espacios, int lineas, int vocales[5]);

int main() {
    int opcion = 0;
    char nombre_archivo_salida[100] = "resultados.txt";
    char *contenido = NULL;
    long caracteres = 0;
    int palabras = 0;
    int espacios = 0;
    int lineas = 0;
    int vocales[5] = {0};

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
                free(contenido); // Liberar si ya existía
                contenido = ingresar_archivo();
                break;
            case 2:
                if (contenido) {
                    calcular_estadisticas(contenido, &caracteres, &palabras, &espacios, &lineas);
                } else {
                    printf("Primero debes ingresar el archivo.\n");
                }
                break;
            case 3:
                if (contenido) {
                    calcular_frecuencia_vocales(contenido, vocales);
                } else {
                    printf("Primero debes ingresar el archivo.\n");
                }
                break;
            case 4:
                if (contenido) {
                    contenido = reemplazar_palabra(contenido);
                } else {
                    printf("Primero debes ingresar el archivo.\n");
                }
                break;
            case 5:
                if (contenido) {
                    guardar_resultados(nombre_archivo_salida, contenido, caracteres, palabras, espacios, lineas, vocales);
                } else {
                    printf("Primero debes ingresar el archivo.\n");
                }
                break;
            case 0:
                printf("Saliendo del programa.\n");
                free(contenido);
                break;
            default:
                printf("Opción no válida. Intente de nuevo.\n");
        }
    } while (opcion != 0);

    return 0;
}

char *ingresar_archivo() {
    char nombrearchivo[100];
    printf("Nombre del archivo (.txt): ");
    if (!fgets(nombrearchivo, sizeof(nombrearchivo), stdin)) {
        printf("Error al leer nombre.\n");
        return NULL;
    }
    nombrearchivo[strcspn(nombrearchivo, "\n")] = 0;

    FILE *archivo = fopen(nombrearchivo, "r");
    if (!archivo) {
        printf("No se pudo abrir el archivo: %s\n", nombrearchivo);
        return NULL;
    }

    fseek(archivo, 0, SEEK_END);
    long magnitud = ftell(archivo);
    rewind(archivo);

    char *contenido_final = (char *)malloc(magnitud + 1);
    if (!contenido_final) {
        printf("Error al asignar memoria.\n");
        fclose(archivo);
        return NULL;
    }

    size_t leidos = fread(contenido_final, 1, magnitud, archivo);
    contenido_final[leidos] = '\0';
    fclose(archivo);

    if (leidos == magnitud) {
        printf("Archivo leído correctamente.\n");
    } else {
        printf("Advertencia: solo se leyó parcialmente el archivo.\n");
    }

    return contenido_final;
}

void calcular_estadisticas(const char *contenido, long *caracteres, int *palabras, int *espacios, int *lineas) {
    *caracteres = 0;
    *palabras = 0;
    *espacios = 0;
    *lineas = 0;

    int en_palabra = 0;
    for (long i = 0; contenido[i] != '\0'; i++) {
        char c = contenido[i];
        if (c != '\n') (*caracteres)++;
        if (c == ' ') (*espacios)++;
        if (c == '\n') (*lineas)++;

        if (!isspace(c) && !en_palabra) {
            en_palabra = 1;
            (*palabras)++;
        } else if (isspace(c)) {
            en_palabra = 0;
        }
    }

    if (strlen(contenido) > 0 && contenido[strlen(contenido) - 1] != '\n') {
        (*lineas)++;
    }

    printf("Caracteres: %ld\nPalabras: %d\nEspacios: %d\nLíneas: %d\n", *caracteres, *palabras, *espacios, *lineas);
}

void calcular_frecuencia_vocales(const char *contenido, int vocales[5]) {
    int minusculas = 0, mayusculas = 0;
    for (int i = 0; i < 5; i++) vocales[i] = 0;

    for (long i = 0; contenido[i] != '\0'; i++) {
        char letra = contenido[i];
        if (islower(letra)) minusculas++;
        if (isupper(letra)) mayusculas++;

        char letra_min = tolower(letra);
        switch (letra_min) {
            case 'a': vocales[0]++; break;
            case 'e': vocales[1]++; break;
            case 'i': vocales[2]++; break;
            case 'o': vocales[3]++; break;
            case 'u': vocales[4]++; break;
        }
    }

    printf("Frecuencia de vocales:\na: %d\ne: %d\ni: %d\no: %d\nu: %d\n", vocales[0], vocales[1], vocales[2], vocales[3], vocales[4]);
    printf("Minúsculas: %d\nMayúsculas: %d\n", minusculas, mayusculas);
}

char* reemplazar_palabra(char *contenido) {
    char buscar[100], reemplazo[100];

    printf("Palabra a buscar: ");
    fgets(buscar, sizeof(buscar), stdin);
    buscar[strcspn(buscar, "\n")] = '\0';

    printf("Palabra para reemplazar: ");
    fgets(reemplazo, sizeof(reemplazo), stdin);
    reemplazo[strcspn(reemplazo, "\n")] = '\0';

    if (strlen(buscar) == 0) {
        printf("La palabra a buscar no puede estar vacía.\n");
        return contenido;
    }

    int ocurrencias = 0;
    char *ptr = contenido;
    while ((ptr = strstr(ptr, buscar)) != NULL) {
        ocurrencias++;
        ptr += strlen(buscar);
    }

    if (ocurrencias == 0) {
        printf("No se encontró la palabra \"%s\".\n", buscar);
        return contenido;
    }

    long nuevo_tam = strlen(contenido) + ocurrencias * (strlen(reemplazo) - strlen(buscar));
    char *nuevo_texto = malloc(nuevo_tam + 1);
    if (!nuevo_texto) {
        printf("Error al asignar memoria.\n");
        return contenido;
    }

    char *origen = contenido, *destino = nuevo_texto;
    while ((ptr = strstr(origen, buscar)) != NULL) {
        size_t len = ptr - origen;
        strncpy(destino, origen, len);
        destino += len;
        strcpy(destino, reemplazo);
        destino += strlen(reemplazo);
        origen = ptr + strlen(buscar);
    }
    strcpy(destino, origen);

    free(contenido);
    printf("Reemplazo realizado con éxito.\n");
    return nuevo_texto;
}

void guardar_resultados(const char *nombre_archivo, const char *contenido, long caracteres, int palabras, int espacios, int lineas, int vocales[5]) {
    FILE *archivo = fopen(nombre_archivo, "w");
    if (!archivo) {
        printf("No se pudo abrir el archivo de salida.\n");
        return;
    }

    fprintf(archivo, "Estadísticas del texto:\n");
    fprintf(archivo, "Caracteres (sin '\\n'): %ld\n", caracteres);
    fprintf(archivo, "Palabras: %d\n", palabras);
    fprintf(archivo, "Espacios: %d\n", espacios);
    fprintf(archivo, "Líneas: %d\n\n", lineas);

    fprintf(archivo, "Frecuencia de vocales:\n");
    fprintf(archivo, "a: %d\n", vocales[0]);
    fprintf(archivo, "e: %d\n", vocales[1]);
    fprintf(archivo, "i: %d\n", vocales[2]);
    fprintf(archivo, "o: %d\n", vocales[3]);
    fprintf(archivo, "u: %d\n\n", vocales[4]);

    fprintf(archivo, "Texto modificado:\n%s\n", contenido);

    fclose(archivo);
    printf("Resultados guardados en '%s'\n", nombre_archivo);
}
