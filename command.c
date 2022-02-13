/** 
 * @brief It implements the command interpreter
 * 
 * @file command.c
 * @author Profesores PPROG
 * @version 2.0 
 * @date 29-11-2021 
 * @copyright GNU Public License
 */

#include <stdio.h>
#include <strings.h>
#include "command.h"

#define CMD_LENGHT 30
/*
  
  Asocias a cada comando una letras. Puedes entrar al bucle if si pulas e, n o b. 
  Dentro del bucle va comparando con un bucle while para averiguar cual es el comando 
  (vale la lecheo la palabra), si no es ese la i aumenta (y hara lo mismo hhasta que 
  salga del bucle) y si es ese le returnea (restandole 1 porque empiezas por -1).

*/
char *cmd_to_str[N_CMD]
[N_CMDT] = {{"", "No command"},
			{"", "Unknown"},
			{"e", "Exit"},
			{"n", "Next"},
			{"b", "Back"}};

T_Command command_get_user_input()
{
  T_Command cmd = NO_CMD;
  char input[CMD_LENGHT] = "";
  int i = UNKNOWN - NO_CMD + 1;
  
  if (scanf("%s", input) > 0)
  {
    cmd = UNKNOWN;
    while (cmd == UNKNOWN && i < N_CMD)
    {
      if (!strcasecmp(input, cmd_to_str[i][CMDS]) || !strcasecmp(input, cmd_to_str[i][CMDL]))
      {
        cmd = i + NO_CMD;
      }
      else
      {
        i++;
      }
    }
  }
  
  return cmd;
}
