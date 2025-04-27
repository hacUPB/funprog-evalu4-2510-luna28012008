#include <stdio.h>
/*
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
    int multiplicacion = 1; //la multiplicación debe empezar en uno porqué sino cualquier resultado en cero se anularia

    printf("Introduce 10 números:\n");
    for (int i = 0; i < 10; i++) {
        printf("Número %d: ", i + 1);
        scanf("%d", &numeros[i]);
    }

    // Calcular la suma, resta y multiplicación acumulada
    for (int i = 0; i < 10; i++) {
        suma += numeros[i];
        if (i == 0) {
            resta = numeros[i]; // Inicializar la resta con el primer número
        } else {
            resta -= numeros[i];
        }
        multiplicacion *= numeros[i];
    }

    // Mostrar los resultados
    printf("Suma: %d\n", suma);
    printf("Resta: %d\n", resta);
    printf("Multiplicación: %d\n", multiplicacion);

    return 0;
}
*/
//ejercicios 4

int main() {
    int arreglo1[5]; // Arreglo para los primeros 5 números
    int arreglo2[5];  // Arreglo para los últimos 5 números
    int arreglo3[10]; // Arreglo para combinar ambos

    // Leer 10 números desde el teclado
    printf("Introduce 10 números:\n");
    for (int i = 0; i < 10; i++) {
        printf("Número %d: ", i + 1);
        if (i < 5) {
            scanf("%d", &arreglo1[i]); // Almacenar en el primer arreglo
        } else {
            scanf("%d", &arreglo2[i - 5]); // Almacenar en el segundo arreglo
        }
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