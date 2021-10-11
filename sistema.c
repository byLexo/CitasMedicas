#include "sistema.h"

int login_user () {


  char *dni;
  char *password;
  char *p;

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
