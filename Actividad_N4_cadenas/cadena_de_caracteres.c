// Ejercicios prácticos 

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

// ejercicio 1: Contar vocales
int contarVocales(char texto[]) {
    int contador = 0;
    for (int i = 0; texto[i] != '\0'; i++) {
        char letra = texto[i];
        if (letra == 'a' || letra == 'e' || letra == 'i' || letra == 'o' || letra == 'u' ||
            letra == 'A' || letra == 'E' || letra == 'I' || letra == 'O' || letra == 'U') {
            contador++;
        }
    }
    return contador;
}

// ejercicio 2: Invertir cadena
void invertirCadena(char original[], char invertida[]) {
    int longitud = strlen(original);
    for (int i = 0; i < longitud; i++) {
        invertida[i] = original[longitud - 1 - i];
    }
    invertida[longitud] = '\0';
}

// ejercicio 3: Detectar palíndromo
bool esPalindromo(char texto[]) {
    char limpio[100], letra;
    int j = 0;
    
    // Eliminar espacios, signos y pasar a minúscula
    for (int i = 0; texto[i] != '\0'; i++) {
        letra = tolower(texto[i]);
        if (letra >= 'a' && letra <= 'z') {
            limpio[j++] = letra;
        }
    }
    limpio[j] = '\0';

    // Verificar si es palíndromo
    int izquierda = 0, derecha = j - 1;
    while (izquierda < derecha) {
        if (limpio[izquierda] != limpio[derecha]) {
            return false;
        }
        izquierda++;
        derecha--;
    }
    return true;
}

// ejercicio 4: Conversión ASCII a mayúsculas
void convertirAMayusculas(char texto[]) {
    for (int i = 0; texto[i] != '\0'; i++) {
        if (texto[i] >= 'a' && texto[i] <= 'z') {
            texto[i] = texto[i] - 32;
        }
    }
}

// ejercicio 5: Tokenizador básico
bool esSeparador(char caracter) {
    return caracter == ' ' || caracter == ',' || caracter == ';';
}

void tokenizar(char texto[]) {
    char palabra[100];
    int j = 0;

    for (int i = 0; texto[i] != '\0'; i++) {
        if (!esSeparador(texto[i])) {
            palabra[j++] = texto[i];
        } else if (j > 0) {
            palabra[j] = '\0';
            printf("Token: %s\n", palabra);
            j = 0;
        }
    }
    if (j > 0) {
        palabra[j] = '\0';
        printf("Token: %s\n", palabra);
    }
}



int main() {
    // ejercicio 1
    char cadena1[] = "Hola mundo";
    int totalVocales = contarVocales(cadena1);
    printf("Cantidad de vocales: %d\n", totalVocales);

    // ejercicio 2
    char texto[] = "ingenieria";
    char textoInvertido[100];
    invertirCadena(texto, textoInvertido);
    printf("Cadena invertida: %s\n", textoInvertido);

    // ejercicio 3
    char frase[] = "Anita lava la tina";
    if (esPalindromo(frase)) {
        printf("Es un palíndromo.\n");
    } else {
        printf("No es un palíndromo.\n");
    }

    // ejercicio 4
    char cadena2[] = "electrica upb";
    convertirAMayusculas(cadena2);
    printf("Convertida a mayúsculas: %s\n", cadena2);

    // ejercicio 5
    char cadena3[] = "hola,esto;es una prueba";
    tokenizar(cadena3);

    return 0;
}
