/**
 * @brief It implements the command interpreter interface
 *
 * @file command.h
 * @author Profesores PPROG
 * @version 2.0
 * @date 29-11-2021
 * @copyright GNU Public License
 */

#ifndef COMMAND_H
#define COMMAND_H

#define N_CMDT 2
#define N_CMD 5

/*
  Dia 9/02/22
  Estructuras definidas en command.h:
    enum_CmdType: Asigna un valor entero a CMDS y CMDL;
    enum_Command: Asigna un valor entero a NO_CMD, UNKKNOW, EXIT, NEXT y BACK empezando por -1;
  
  Funciones
    T_Command command_get_user_input();
      @Autor: Profesor PPROG
      @Parametros: No contiene parámetros;
      @Return: Devuelve un valor definido en la estructura enum_command;
      @Descripcion: Obtienes lo que el usuario esta tecleando

*/

typedef enum enum_CmdType {
  CMDS,
  CMDL} T_CmdType;

typedef enum enum_Command {
  NO_CMD = -1,
  UNKNOWN,
  EXIT,
  NEXT,
  BACK} T_Command;

T_Command command_get_user_input();

#endif
