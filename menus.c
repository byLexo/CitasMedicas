#include <stdio.h>
#include <string.h>

#include "menus.h"

void menu_principal() {

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
        register_user();
        break;
      case '2':
        login_user();
        break;
      case '3':
        break;
      default:
        break;
    }
  } while (option != '3');

  return;

}

void menu_paciente() {

  char option = '*';

  printf("Bienvenido\n\n. Seleccione una opción:\n");

  printf("1. Pedir cita\n");
  printf("2. Mostrar citas\n");
  printf("3. Cancelar cita\n");
  printf("4. Ver información\n");
  printf("5. Salir\n");

}

void menu_doctor() {

  char option = '*';

  printf("Bienvenido\n\n. Seleccione una opción:\n");

  printf("1. Pedir cita\n");
  printf("2. Mostrar citas\n");
  printf("3. Cancelar cita\n");
  printf("4. Ver información\n");
  printf("5. Salir\n");

}


