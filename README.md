*Este proyecto ha sido creado como parte del currículo de 42 por javisan2.*

# ft_printf

## Descripción

`ft_printf` es una librería escrita en C que reimplementa parcialmente la función estándar `printf()` de la libc.
El objetivo principal del proyecto es comprender cómo funciona la impresión formateada, aprendiendo a trabajar con:

* Funciones variádicas (`stdarg.h`)
* Parsing de strings
* Conversión y representación de datos
* Diseño de código modular y extensible

La librería genera un archivo estático `libftprintf.a`, pensado para poder integrarse posteriormente dentro de `libft` y reutilizarse en futuros proyectos del cursus.

No se implementa el sistema de buffer interno del `printf()` original.

## Estructura del proyecto

El proyecto sigue una estructura clásica y clara:

* `includes/`

  * `ft_printf.h`
* `srcs/`

  * Archivos `.c` con la implementación de `ft_printf` y sus funciones auxiliares
* `libft/`

  * Copia completa de `libft`, utilizada como dependencia
* `Makefile`
* `README.md`

La librería `libft` se compila previamente desde su propio Makefile y se enlaza posteriormente con `ft_printf`.

## Prototipos y dependencias

El archivo `ft_printf.h` contiene los prototipos públicos del proyecto:

* `int ft_printf(const char *format, ...);`
* Funciones auxiliares para impresión de caracteres, strings, números y conversiones

Se utilizan exclusivamente las funciones autorizadas por el enunciado, junto con funciones propias de `libft`.

## Instrucciones de compilación

Para compilar el proyecto, ejecuta:

```bash
make
```

Reglas disponibles en el `Makefile`:

* `make` / `make all` : compila `libftprintf.a`
* `make clean`       : elimina los archivos objeto
* `make fclean`      : elimina los objetos y la librería
* `make re`          : recompila todo desde cero

La compilación se realiza usando `cc` con las flags:

```
-Wall -Wextra -Werror
```

La librería final `libftprintf.a` se genera en la raíz del repositorio usando `ar`.

## Uso

Incluye el header y enlaza la librería:

```c
#include "ft_printf.h"
```

Ejemplo de uso:

```c
ft_printf("Número: %d | Hex: %x | Puntero: %p\n", 42, 42, &var);
```

La función devuelve el número total de caracteres impresos, como el `printf()` original.

## Conversiones implementadas

La parte obligatoria implementa las siguientes conversiones:

* `%c` : carácter
* `%s` : string
* `%p` : puntero `void *` en hexadecimal
* `%d` / `%i` : entero decimal con signo
* `%u` : entero decimal sin signo
* `%x` : hexadecimal en minúsculas
* `%X` : hexadecimal en mayúsculas
* `%%` : carácter `%`

## Diseño y decisiones técnicas

El proyecto se basa en un enfoque modular:

* El string de formato se recorre secuencialmente.
* Cuando se detecta un `%`, se identifica el especificador siguiente.
* Cada tipo de conversión se gestiona mediante una función dedicada.
* Las funciones de impresión devuelven el número de caracteres escritos, permitiendo un control preciso del retorno total de `ft_printf`.

Se utiliza el tipo `uintptr_t` para la impresión de punteros, garantizando un comportamiento correcto independientemente de la arquitectura.

El uso de funciones simples y separadas facilita la depuración, la lectura del código y una futura ampliación (bonus).

Toda la memoria reservada dinámicamente se libera correctamente y no se producen fugas.

## Recursos

* `man 3 printf`
* `man stdarg`
* Documentación oficial de la libc
* Norma de 42

### Uso de IA

La IA se ha utilizado únicamente como herramienta de apoyo al aprendizaje:

* Comprensión de funciones variádicas
* Revisión conceptual del parsing del formato
* Detección de posibles errores o casos límite

Todo el código ha sido escrito, probado y comprendido por el autor.

## Bonus

La parte bonus, si está presente, se implementa en archivos separados (`*_bonus.c` / `*_bonus.h`) y no interfiere con la parte obligatoria, cumpliendo las normas del enunciado.

