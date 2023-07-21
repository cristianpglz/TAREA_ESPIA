/*

    ESTO ES UNA TAREA DE LA ACADEMIA MASTERMIND
    
    titulo: ESPIA

    EXPLICACION:consiste en hacer un codificador y descodificador del alcoritmo CESAR

    NECESARIO: las letras tanto en minuscula como mayuscula
    */
#include <stdio.h>
#include <ctype.h>
#include <string.h>


//COMIENZO DE LAS FUNCIONES

  // Función para cifrar el mensaje
void cifrarCesar(char mensaje[], int desplazamiento) {
 // Asegurarnos de que el desplazamiento esté en el rango de 0 a 25
    desplazamiento = (desplazamiento % 26 + 26) % 26;

    // Resto del código de cifrarCesar...
    int i = 0;
    char caracter;

    while (mensaje[i] != '\0') {
        caracter = mensaje[i];

        // Comprobar si el caracter es una letra mayúscula
        if (isupper(caracter)) {
            caracter = (caracter - 'A' + desplazamiento) % 26 + 'A';
        }
        // Comprobar si el caracter es una letra minúscula
        else if (islower(caracter)) {
            caracter = (caracter - 'a' + desplazamiento) % 26 + 'a';
        }

        mensaje[i] = caracter;
        i++;
    }
}

  // Función para descifrar el mensaje y mostrar todas las posibles combinaciones
void descifrarCesar(char mensaje[]) {
    printf("Posibles mensajes descifrados:\n");

    // Ciclo para mostrar las 26 posibles combinaciones (de 0 a 25)
    for (int i = 0; i < 26; i++) {
        char mensajeTemporal[100];
        strcpy(mensajeTemporal, mensaje);

        cifrarCesar(mensajeTemporal, -i);
        
        printf("Desplazamiento %d: %s\n\n", i, mensajeTemporal);
    }
}

  // Función para mostrar el menú de opciones y leer la elección del usuario

int menu(){
    int opcion;
    
    printf("Seleccione una opción:\n");
    printf("1. Cifrar un mensaje\n");
    printf("2. Descifrar un mensaje\n");
    printf("Ingrese el número de la opción: ");
    scanf("%d", &opcion);

    return opcion;
}


//COMIENZO DEL CODIGO BASE
int main() {
    char mensaje[100];
    int desplazamiento;
    int opcion;

    opcion = menu();

    printf("Ingrese el mensaje: ");
    scanf(" %[^\n]", mensaje); // Leemos el mensaje como una cadena con espacios incluidos

    if (opcion == 1) {
        printf("Ingrese el desplazamiento (numero entero entre 0 y 26): ");
        scanf("%d", &desplazamiento);
        cifrarCesar(mensaje, desplazamiento % 26); // Asegurarnos de que el desplazamiento esté entre 0 y 25
        printf("Mensaje cifrado: %s\n", mensaje);
    } else if (opcion == 2) {
        descifrarCesar(mensaje);
    } else {
        printf("Opcion invalida\n");
    }

    return 0;
}
