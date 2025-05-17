# Ejercicios de Arreglos de Datos.

## Ejercicio 1

Declara un arreglo, y llénalo con datos. Puedes utilizar el ejemplo anterior. Luego imprime en pantalla las posiciones de memoria correspondientes a cada posición.

>int main() {
    
    int arreglo[12] = {10, 23, 45, 67, 43, 53, 34, 755, 67, 23, 345, 34};

    int medida = sizeof(arreglo) / sizeof(arreglo[0]); 

    for (int i = 0; i < medida; i++) {
        printf("Elemento: %d, Posición de memoria: %p\n", arreglo[i], (void*)&arreglo[i]);
    }

    return 0;
}

## Preguntas de control

1. ¿Qué valor contiene el siguiente dato: `dato[5]`, si el arreglo se inicializa de la siguiente manera: `int datos[6] = {5, 82, 41};`?

- Ese dato contiene un valor de 0 pues en C los arreglos se inicializan desde la posicion 0 hasta el número de espacios correspondientes, entonces como el dato en la posicion #5 no existe se rellena automaticamente con 0, seria como 5 = 0, 82 = 1, 41 = 2, 0, 0, 0.

2. ¿Cómo determinar el número de elementos en un arreglo cuando su tamaño no se especifica explícitamente?

- Para saber cuántos elementos tiene un arreglo en C, se puede usar la fórmula sizeof(arreglo) / sizeof(arreglo[0]). Esto funciona porque sizeof(arreglo) nos da el tamaño total en memoria del arreglo, y sizeof(arreglo[0]) nos dice cuánto ocupa un solo elemento. Al dividirlos, obtenemos el número exacto de elementos. Es importante hacerlo en la misma función donde se declara el arreglo, porque si se pasa a otra función, esa información se pierde.

## Ejercicios prácticos

### Ejercicio 1
- Crear un array de 10 números enteros.
- Rellenarlo con números consecutivos desde el 11 hasta el 20.
- Imprimirlos en pantalla en orden descendente.

### Ejercicio 2
- Crear un array que contenga números pares desde el 2 hasta el 10.
- Imprimir los valores en orden ascendente.

### Ejercicio 3
- Leer desde teclado 10 números.
- Calcular y mostrar la suma, resta y multiplicación acumulada de esos números.

#### Lo que me ha costado
- He tenido que investigar por qué tuve problemas pues estaba poniendo la multiplicación = 0
- También tuve que pensar en el bloque del for para pedir los 10 números de esa manera porque no me estaba funcionando un printf

### Ejercicio 4

- Leer 10 números desde teclado, almacenando los primeros 5 en un array y los últimos 5 en otro.
- Combinar ambos arrays en un tercer array e imprimir el contenido.

#### Lo que me ha costado

- se me ha complicado meter los últimos 5 números en el segundo arreglo asi que tuve que investigar como agregarle eso al bucle


## Ejercicios Adicionales

### Ejercicio 5

- Crear un arreglo unidimensional para almacenar notas de 24 estudiantes.
- Escribir una función para calcular:
    - El promedio general del curso.
    - La cantidad de estudiantes aprobados (nota ≥ 3).
    - La cantidad de estudiantes reprobados (nota < 3).
    - La cantidad de estudiantes con nota igual o superior a 4.

### Ejercicio 6

- Utilizar un arreglo bidimensional para calcular la nota definitiva de estudiantes, dados los porcentajes en la primera fila y las notas en filas sucesivas.
- Mostrar la nota definitiva en la última columna.


## Preguntas de comprensión

1. ¿Qué se pasa realmente a la función cuando enviamos un arreglo como parámetro?
- En realidad se esta enviando la dirección del primer elemento del arreglo, esto hace referencia a un puntero.

2. ¿Qué diferencia hay entre declarar el parámetro como `int arr[]` y `int *arr`?
- No existe ninguna diferencia a excepción del modo de escritura puesto que ambos parámetros son leídos como punteros dentro de la función.

3. ¿Qué implicaciones tiene esto sobre la modificación del arreglo dentro de la función?
- Podría decirse que es el echo de que se hace el cambio directamente sobre el arreglo principal y no una copia de este.

## Ejercicios propuestos

1. Crear una función que reciba un arreglo de enteros y su tamaño, y calcule el promedio de sus valores.
2. Escribir una función que reciba un arreglo y lo ordene en orden ascendente usando el método burbuja.
3. Crear una función que reciba un arreglo y devuelva el valor máximo contenido en él.

---

## Preguntas finales para reforzar el aprendizaje

1. ¿Cuál es exactamente la diferencia entre un arreglo y un puntero?
- Un arreglo es una zona fija de memoria; un puntero puede moverse y apuntar a cualquier parte. Pero en una función, se comportan casi igual.

2. ¿Cómo están almacenados en la memoria los elementos de una matriz?
- En forma lineal (contigua), fila por fila (row-major order).

3. ¿Qué precauciones se deben tomar al usar punteros para recorrer arreglos?
- Pues la mayor precaución que se debe tener es que al momento de realizar el puntero, el dato del arreglo al cúal este apuntando exista para así no generar errores con la memoria.
