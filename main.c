#include <stdio.h>
#include <string.h>

#include "sistema.h"

int main(int argc, char *argv[]) {

  char option[3] = "";

  printf("¡Bienvenido al Hospital de Kolinar!\n");
  printf("Seleccione una opción:\n");
  printf("1. Registrarse\n");
  printf("2. Acceder\n");
  printf("3. Salir\n");

  do {
    fgets(option, 3, stdin);
    switch(option[0]){
      case '1':
        printf("Has seleccionado resgistrarte\n");
        break;
      case '2':
        printf("Has seleccionado acceder\n");
        login_user();
        break;
      case '3':
        printf("Has seleccionado salir\n");
        break;
      default:
        break;
    }
  } while (option[0] != '3');

  return 0;

}
