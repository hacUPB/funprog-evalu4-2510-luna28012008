# Análisis de Programa en Lenguaje C: Analizador de Archivos `.txt`

## 📌 Funcionalidad General
Este programa en C permite leer un archivo `.txt`, analizar su contenido, mostrar estadísticas, realizar reemplazo de palabras y guardar los resultados en un nuevo archivo. Todo desde un menú interactivo por consola.


## 🧩 Función 1: Ingresar el nombre del archivo y leerlo

### Análisis paso a paso:
1. Pedir al usuario el nombre del archivo `.txt`.
2. Abrir el archivo con `fopen()`.
3. Usar `fseek()` y `ftell()` para determinar el tamaño.
4. Reservar memoria dinámica con `malloc()`.
5. Leer el archivo con `fread()` y almacenarlo en un arreglo de caracteres.
6. Retornar el puntero al contenido leído.

### 📥 Variables de entrada y salida

| Variable           | Tipo        | Rol                         |
|--------------------|-------------|------------------------------|
| `nombrearchivo`    | `char[]`    | Entrada del usuario          |
| `archivo`          | `FILE *`    | Puntero al archivo abierto   |
| `contenido_final`  | `char *`    | Texto completo leído         |

### Funciones usadas

- `fopen(nombre, "r")`: abre el archivo para lectura.
- `fseek()` + `ftell()`: determinan la longitud del archivo.
- `malloc(tamaño)`: reserva memoria dinámica.
- `fread()`: lee el archivo.
- `fgets()`: lee cadenas desde entrada estándar.

---

## 🧩 Función 2: Calcular estadísticas del texto

### Análisis paso a paso:
1. Recorrer el contenido caracter por caracter.
2. Contar caracteres (excluyendo `\n` si se desea).
3. Contar palabras detectando separaciones por espacios o saltos.
4. Contar espacios directamente.
5. Contar líneas usando `\n`.

### 📥 Variables de entrada y salida

| Variable       | Tipo        | Rol                            |
|----------------|-------------|---------------------------------|
| `contenido`    | `const char*` | Texto del archivo              |
| `caracteres`   | `long*`      | Salida: total de caracteres    |
| `palabras`     | `int*`       | Salida: total de palabras      |
| `espacios`     | `int*`       | Salida: total de espacios      |
| `lineas`       | `int*`       | Salida: total de líneas        |

### Funciones usadas

- `isspace(c)`: verifica si un caracter es espacio o salto.
- `strlen()`: determina la longitud del texto.

---

## 🧩 Función 3: Calcular frecuencia de vocales

### Análisis paso a paso:
1. Inicializar contador de vocales (`a, e, i, o, u`).
2. Recorrer el texto.
3. Convertir a minúsculas con `tolower()`.
4. Comparar y contar.

### 📥 Variables de entrada y salida

| Variable       | Tipo        | Rol                             |
|----------------|-------------|----------------------------------|
| `contenido`    | `const char*` | Texto a analizar                |
| `vocales[5]`   | `int[]`      | Salida: cantidad de cada vocal  |

### Funciones usadas

- `tolower(c)`: convierte el caracter a minúscula.
- `islower()` / `isupper()`: determina tipo de letra.

---

## 🧩 Función 4: Reemplazo de palabra

### Análisis paso a paso:
1. Solicitar al usuario la palabra a buscar y la de reemplazo.
2. Contar ocurrencias con `strstr()`.
3. Calcular el nuevo tamaño del texto final.
4. Reservar nueva memoria con `malloc()`.
5. Copiar texto con reemplazos usando `strncpy()` y `strcpy()`.
6. Liberar memoria del texto anterior.

### 📥 Variables de entrada y salida

| Variable       | Tipo        | Rol                                 |
|----------------|-------------|--------------------------------------|
| `contenido`    | `char*`     | Texto original (entrada y salida)   |
| `buscar`       | `char[]`    | Palabra a buscar                    |
| `reemplazo`    | `char[]`    | Palabra de reemplazo                |
| `nuevo_texto`  | `char*`     | Texto con palabras reemplazadas     |

### Funciones usadas

- `strstr(texto, buscar)`: busca subcadenas.
- `strncpy()`, `strcpy()`: copian texto.
- `malloc()`: asigna memoria nueva.

---

## 🧩 Función 5: Guardar resultados en un nuevo archivo

### Análisis paso a paso:
1. Solicitar el nombre del archivo de salida.
2. Abrir el archivo en modo escritura con `fopen()`.
3. Escribir estadísticas y frecuencia de vocales con `fprintf()`.
4. Escribir el contenido (con o sin reemplazo).
5. Cerrar archivo con `fclose()`.

### 📥 Variables de entrada y salida

| Variable           | Tipo       | Rol                                |
|--------------------|------------|-------------------------------------|
| `nombre_archivo`   | `const char*` | Archivo destino                   |
| `contenido`        | `const char*` | Texto a escribir                  |
| `caracteres`       | `long`     | Datos estadísticos                 |
| `palabras`, `espacios`, `lineas` | `int` | Datos estadísticos             |
| `vocales[5]`       | `int[]`    | Frecuencia de vocales              |

### Funciones usadas

- `fopen(nombre, "w")`: abre archivo para escritura.
- `fprintf()`: escribe texto con formato.
- `fclose()`: cierra el archivo.


