#include <stdio.h>

// Ejercicio # 1 

int main() {
    // Declarar un arreglo y llenarlo con datos
    int arreglo[12] = {10, 23, 45, 67, 43, 53, 34, 755, 67, 23, 345, 34};
    int medida = sizeof(arreglo) / sizeof(arreglo[0]); // Calcular el tamaño del arreglo

    // Imprimir el arreglo y las posiciones de memoria
    for (int i = 0; i < medida; i++) {
        printf("Elemento: %d, Posición de memoria: %p\n", arreglo[i], (void*)&arreglo[i]);
    }

    return 0;
}
    

// Ejercicios practicos

//ejercicio 1

int main(){
    // Declarar un arreglo de 10 enteros
    int arreglo[10] ={11, 12, 13, 14, 15, 16, 17, 18, 19, 20};

    // Imprimir el arreglo en orden descendente
    printf("Números en orden descendente:\n");
    for (int i = 9; i >= 0; i--) {
        printf("%d\n", arreglo[i]);
    }

    return 0;
}


//ejercicio 2

int main() {
    int arreglo[] = {2, 4, 6, 8, 10};

    printf("Números pares del 2 al 10 en orden ascendente:\n");
    for (int i = 0; i < 5; i++) {
        printf("%d\n", arreglo[i]);
    }

    return 0;
} 

//ejercicio 3

int main() {
    int numeros[10];
    int suma = 0;
    int resta = 0;
    int multiplicacion = 1; 

    printf("Introduce 10 números:\n");
    for (int i = 0; i < 10; i++) {
        printf("Número %d: ", i + 1);
        scanf("%d", &numeros[i]);
    }

    for (int i = 0; i < 10; i++) {
        suma += numeros[i];
        if (i == 0) {
            resta = numeros[i]; 
        } else {
            resta -= numeros[i];
        }
        multiplicacion *= numeros[i];
    }

    printf("Suma: %d\n", suma);
    printf("Resta: %d\n", resta);
    printf("Multiplicación: %d\n", multiplicacion);

    return 0;
}

//ejercicios 4

int main() {
    int arreglo1[5]; 
    int arreglo2[5];  
    int arreglo3[10]; 

    printf("Introduce 10 números:\n");
    for (int i = 0; i < 10; i++) {
        printf("Número %d: ", i + 1);
        if (i < 5) {
            scanf("%d", &arreglo1[i]); 
        } else {
            scanf("%d", &arreglo2[i - 5]); 
    }

    // Combinar ambos arreglos en el arreglo combinado
    for (int i = 0; i < 5; i++) {
        arreglo3[i] = arreglo1[i]; // Copiar primeros 5
        arreglo3[i + 5] = arreglo2[i]; // Copiar últimos 5
    }

    // Imprimir el contenido del arreglo combinado
    printf("Contenido del arreglo combinado:\n");
    for (int i = 0; i < 10; i++) {
        printf("%d\n", arreglo3[i]);
    }

    return 0;
}

//ejercicios adicionales 

// ejercicio 5

int main() {
    float notas[24];
    float suma = 0;
    int aprobados = 0, reprobados = 0, mayores_igual_4 = 0;

    for (int i = 0; i < 24; i++) {
        printf("Ingrese la nota del estudiante %d: ", i + 1);
        scanf("%f", &notas[i]);
        suma += notas[i];

        if (notas[i] >= 3.0) {
            aprobados++;
        } else {
            reprobados++;
        }

        if (notas[i] >= 4.0) {
            mayores_igual_4++;
        }
    }

    float promedio = suma / 24;

    printf("\n--- Resultados ---\n");
    printf("Promedio general del curso: %.2f\n", promedio);
    printf("Cantidad de estudiantes aprobados (nota ≥ 3): %d\n", aprobados);
    printf("Cantidad de estudiantes reprobados (nota < 3): %d\n", reprobados);
    printf("Cantidad de estudiantes con nota ≥ 4: %d\n", mayores_igual_4);

    return 0;
}


// ejercicio 6

#include <stdio.h>

int main() {
    int columnas, estudiantes;

    printf("¿Cuántas calificaciones tendrá cada estudiante?: ");
    scanf("%d", &columnas);

    printf("¿Cuántos estudiantes hay?: ");
    scanf("%d", &estudiantes);

    float porcentajes[columnas];
    printf("Ingrese los porcentajes de cada actividad (suman 100):\n");
    for (int i = 0; i < columnas; i++) {
        printf("Porcentaje %d: ", i + 1);
        scanf("%f", &porcentajes[i]);
        porcentajes[i] /= 100.0; // Convertimos a decimal
    }

    float notas[estudiantes][columnas];

    for (int i = 0; i < estudiantes; i++) {
        printf("\nIngrese las notas del estudiante %d:\n", i + 1);
        for (int j = 0; j < columnas; j++) {
            printf("Nota %d: ", j + 1);
            scanf("%f", &notas[i][j]);
        }
    }

    printf("\n--- Notas Definitivas ---\n");
    for (int i = 0; i < estudiantes; i++) {
        float definitiva = 0;
        for (int j = 0; j < columnas; j++) {
            definitiva += notas[i][j] * porcentajes[j];
        }
        printf("Estudiante %d: Nota definitiva = %.2f\n", i + 1, definitiva);
    }

    return 0;
}

// Ejercicios propuestos 

// 1. Calcular promedio

float calcular_promedio(int arr[], int tamaño) {
    int suma = 0;
    for (int i = 0; i < tamaño; i++) {
        suma += arr[i];
    }
    return (float)suma / tamaño;
}

// 2. Ordenar burbujas

void ordenar_burbuja(int arr[], int tamaño) {
    for (int i = 0; i < tamaño - 1; i++) {

     for (int j = 0; j < tamaño - i - 1; j++) {

         if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
         }
    }
}

}

// 3. Valor máximo 

int valor_maximo(int arr[], int tamaño) {
    int max = arr[0];
    for (int i = 1; i < tamaño; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}
