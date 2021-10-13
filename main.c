#include <stdio.h>
#include <string.h>

#include "sistema.h"

int main(int argc, char *argv[]) {

  char option = '*';

  printf("¡Bienvenido al Hospital de Kolinar!\n");
  printf("Seleccione una opción:\n");
  printf("1. Registrarse\n");
  printf("2. Acceder\n");
  printf("3. Salir\n");

  do {
    option = fgetc(stdin);
    switch(option){
      case '1':
        printf("Has seleccionado resgistrarte\n");
        register_user();
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
  } while (option != '3');

  return 0;

}
