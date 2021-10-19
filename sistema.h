#ifndef SISTEMA_H 
#define SISTEMA_H 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sqlite3.h>

#define DNI_SIZE 10
#define PASS_SIZE 51
#define PACIENTE '0'
#define DOCTOR '1'

int login_user (); 
int register_user();
int clean_db();
int insert_user_db(char type_user, char *dni, char *pass);

#endif
