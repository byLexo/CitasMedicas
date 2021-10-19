#include "sistema.h"

int clean_db() {

  sqlite3 *db = NULL;
  int rc = 0;
  char *sql = "";
  char *err_msg = 0; // Variable para guardar mensajes de error de sqlite3

  rc = sqlite3_open("db/proyecto.db", &db);

  if (rc != SQLITE_OK) {
    fprintf(stderr, "Error al abrir la base de datos: %s\n", sqlite3_errmsg(db));
    sqlite3_close(db);
    return -1;
  }

  // Eliminamos las tablas y las volvemos a crear
  sql = "DROP TABLE IF EXISTS Pacientes;"
        "DROP TABLE IF EXISTS Doctores;"
        "CREATE TABLE Pacientes(dni varchar(9) NOT NULL primary key, password varchar(50) NOT NULL);"
        "CREATE TABLE Doctores(dni varchar(9) NOT NULL primary key, password varchar(50) NOT NULL);";

  rc = sqlite3_exec(db, sql, 0, 0, &err_msg);

  if (rc != 0) {

    fprintf(stderr, "Error al ejecutar la consulta: %s\n", err_msg);
    sqlite3_free(err_msg);
    sqlite3_close(db);
    return -1;
  }

  printf("Base de datos limpiada\n");
  sqlite3_close(db);
  return 0;
}

int insert_user_db(char type_user, char *dni, char *pass) {

  sqlite3 *db = NULL;
  int rc = 0;
  char *sql = "";
  char *err_msg = 0; // Variable para guardar mensajes de error de sqlite3

  rc = sqlite3_open("db/proyecto.db", &db);

  if (rc != SQLITE_OK) {
    fprintf(stderr, "Error al abrir la base de datos: %s\n", sqlite3_errmsg(db));
    sqlite3_close(db);
    return -1;
  }

  // Dependiendo del valor de type_user insertaremos en una tabla u otra
  if (type_user == PACIENTE)
    sprintf(sql, "INSERT INTO Pacientes VALUES ('%s', '%s');", dni, pass);
  else
    sprintf(sql, "INSERT INTO Doctores VALUES ('%s', '%s');", dni, pass);

  rc = sqlite3_exec(db, sql, 0, 0, &err_msg);

  if (rc != 0) {

    fprintf(stderr, "Error al ejecutar la consulta: %s\n", err_msg);
    sqlite3_free(err_msg);
    sqlite3_close(db);
    return -1;
  }

  printf("Usuario insertado\n");
  sqlite3_close(db);
  return 0;
}

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
  
  insert_user_db(type_user, dni, password);
  
  free(dni);
  free(password);

  // Aqui llamariamos a SQLite para iniciar sesion
  // type_login nos indica si es paciente o usuario
  return 0;

}
