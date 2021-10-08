#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {

  char option = '0';

  printf("¡Bienvenido al Hospital de Kolinar!\n");
  printf("Seleccione una opción:\n");
  printf("1. Registrarse\n");
  printf("2. Acceder\n");
  printf("3. Salir\n");

  do {
    scanf(" %c", &option);
    switch(option){
      case '1':
        printf("Has seleccionado resgistrarte\n");
        break;
      case '2':
        printf("Has seleccionado acceder\n");
        break;
      case '3':
        printf("Has seleccionado salir\n");
        break;
      default:
        break;
    }
  } while (strcmp(&option, "3") != 0);

  return 0;

}
