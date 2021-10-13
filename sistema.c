#include "sistema.h"

int login_user () {


  char *dni;
  char *password;

  dni = (char*)malloc(sizeof(char)*DNI_SIZE);
  if (dni == NULL)
    return -1;


  password = (char*)malloc(sizeof(char)*PASS_SIZE);
  if (password == NULL)
    return -1;

  printf("Introduce DNI: ");
  fgets(dni, DNI_SIZE+1, stdin);

  printf("Introduce la contraseña: ");
  fgets(password, PASS_SIZE+1, stdin);

  printf("DNI: %s\n", dni);
  printf("PASS: %s\n", password);
  
  
  free(dni);
  free(password);

  // Aqui llamariamos a SQLite para iniciar sesion
  // type_login nos indica si es paciente o usuario
  return 0;

}


int register_user () {


  char *dni;
  char *password;
  char type_user = '*';

  dni = (char*)malloc(sizeof(char)*DNI_SIZE);
  if (dni == NULL)
    return -1;


  password = (char*)malloc(sizeof(char)*PASS_SIZE);
  if (password == NULL)
    return -1;

  do {
    printf("Introduce DNI: ");
    fgets(dni, DNI_SIZE+1, stdin);
    if (strlen(dni) != DNI_SIZE )
      printf("DNI incorrecto\n");
  } while (strlen(dni) != DNI_SIZE);

  do {
    printf("Introduce la contraseña (max 50 caract.): ");
    fgets(password, PASS_SIZE+1, stdin);
    if (strlen(password) < 1 || strlen(password) > PASS_SIZE)
      printf("Tamaño de la contraseña incorrecto\n");
  } while(strlen(password) < 1 || strlen(password) > PASS_SIZE);
  
  do {
    printf("¿Es doctor o paciente (D/P)?: ");
    type_user = fgetc(stdin);
    printf("%c", type_user);
    if (type_user != 'D' && type_user != 'P')
      printf("Opcion invalida\n");
  } while(type_user != 'D' && type_user != 'P');


  printf("DNI: %s\n", dni);
  printf("PASS: %s\n", password);
  printf("Type: %c\n", type_user);
  
  
  free(dni);
  free(password);

  // Aqui llamariamos a SQLite para iniciar sesion
  // type_login nos indica si es paciente o usuario
  return 0;

}
