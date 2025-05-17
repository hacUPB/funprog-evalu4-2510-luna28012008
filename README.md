# Unidad No. 
Ingresa a continuación tu información.
## Información del estudiante  
Nombre del estudiante:  Luna Michelle Torres Nuñez
Id.: 000568004
---
## Descripción del contenido del repositorio  

## Nombre del reto
Analizador de texto con menú interactivo en C

## Actividades realizadas
- Análisis del enunciado del reto para definir los requerimientos funcionales.
- Diseño de la estructura del programa basada en funciones para modularidad y claridad.
- Implementación de funcionalidades principales:
  - Lectura de archivos de texto utilizando memoria dinámica (`malloc`, `fread`).
  - Cálculo de estadísticas del texto: número de caracteres (sin saltos de línea), palabras, espacios y líneas.
  - Conteo de frecuencia de vocales, considerando mayúsculas y minúsculas como equivalentes.
  - Reemplazo de una palabra por otra en todo el texto, adaptando la memoria de forma dinámica.
  - Almacenamiento de resultados en un archivo de salida (`resultados.txt`) con estadísticas y texto modificado.
- Implementación de un menú interactivo para facilitar la navegación del usuario.
- Pruebas con distintos archivos para verificar el correcto funcionamiento del programa.

## Logros alcanzados
- Se logró leer, analizar y modificar un archivo de texto completo, sin importar su extensión.
- El reemplazo de palabras fue funcional en múltiples casos, sin pérdidas de datos ni errores de lectura.
- El sistema de estadísticas operó correctamente y los resultados se almacenaron de forma ordenada en el archivo de salida.

## Dificultades enfrentadas
- Gestión de memoria dinámica, especialmente en el reemplazo de palabras con diferente longitud.
- Manejo de errores al abrir archivos y control de flujos de entrada del usuario.
- Evitar conflictos al usar funciones como `fgets` después de `scanf`, lo cual requería limpiar el búfer de entrada.

## Aprendizajes obtenidos
- Dominio del uso de funciones como `fopen`, `fread`, `fgets`, `strstr`, `strncpy`, `fprintf` y `free`.
- Importancia del control de errores y validaciones en programas interactivos.
- Organización del código en funciones como buena práctica para proyectos de mayor escala.
- Correcta manipulación de cadenas y uso de memoria dinámica para operaciones no triviales en C.
