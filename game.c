/** 
 * @brief It implements the game interface and all the associated calls
 * for each command
 * 
 * @file game.c
 * @author Profesores PPROG
 * @version 2.0 
 * @date 29-11-2021 
 * @copyright GNU Public License
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "game.h"
#include "game_reader.h"

/**
   Private functions
*/
STATUS game_add_space(Game *game, Space *space);
Id game_get_space_id_at(Game *game, int position);
STATUS game_set_player_location(Game *game, Id id);
STATUS game_set_object_location(Game *game, Id id);

void game_command_unknown(Game *game);
void game_command_exit(Game *game);
void game_command_next(Game *game);
void game_command_back(Game *game);
void game_command_take(Game *game);
void game_command_drop(Game *game);
void game_command_right(Game *game);
void game_command_left(Game *game);

/**
   Game interface implementation
*/
/*
  Con un bucle for va creando espacios (llamando a la estructura espacios dentro de game). 
  Al salir crea un jugador y un objeto vacio y returnea OK.
*/
STATUS game_create(Game *game)
{
  int i;

  for (i = 0; i < MAX_SPACES; i++)
  {
    game->spaces[i] = NULL;
  }

  game->player_location = NO_ID;
  game->object_location = NO_ID;
  game->last_cmd = NO_CMD;

  return OK;
}
/*
  Mira si hay errores en la apertura del puntero y del archivo. Si no hay llama a otra 
  funcion que crea el espacio 1 y situa al jugador y al objeto dentro y returnea OK
*/
/*
  Con un bucle for va destruyendo cada uno de los espacios 
  llamando a la funcion destruir espacio
*/
STATUS game_destroy(Game *game)
{
  int i = 0;

  for (i = 0; i < MAX_SPACES && game->spaces[i] != NULL; i++)
  {
    space_destroy(game->spaces[i]);
  }

  return OK;
}
/*
  Primero compreba si el puntero a la estructura space funciona correctamente.
  Despues va recorriendo todos los espacios del juego para ver si estan todos creados.
  Si estan todos creados return ERROR y si no le crea en la siguiente posicion (i).
*/
STATUS game_add_space(Game *game, Space *space)
{
  int i = 0;

  if (space == NULL)
  {
    return ERROR;
  }

  while (i < MAX_SPACES && game->spaces[i] != NULL)
  {
    i++;
  }

  if (i >= MAX_SPACES)
  {
    return ERROR;
  }

  game->spaces[i] = space;

  return OK;
}
/*
   Si la posicion no existe (es menor que 0 o es mayor que el numero de espacios 
   posibles) return que no hay ID. Si no llama a la funcion get Id para obtenerla.
*/
Id game_get_space_id_at(Game *game, int position)
{

  if (position < 0 || position >= MAX_SPACES)
  {
    return NO_ID;
  }

  return space_get_id(game->spaces[position]);
}
/*
  Si no hay ID asociada return NULL. Si no, entra en un bucle (que se acaba cuando no hay
  mas posibles espacios o cuando el espacio es nulo). Si el Id es igual a otro (obtenido
  con otra funcion) el Id returnea el espacio que quieres.
*/
Space *game_get_space(Game *game, Id id)
{
  int i = 0;

  if (id == NO_ID)
  {
    return NULL;
  }

  for (i = 0; i < MAX_SPACES && game->spaces[i] != NULL; i++)
  {
    if (id == space_get_id(game->spaces[i]))
    {
      return game->spaces[i];
    }
  }

  return NULL;
}
/*
  Si no hay Id identificada devuele ERROR. Si esta identificada la iguala a un puntero 
  a una estructura de tipo game y devuelve OK.
*/
STATUS game_set_player_location(Game *game, Id id)
{

  if (id == NO_ID)
  {
    return ERROR;
  }

  game->player_location = id;

  return OK;
}
/*
  Si no hay Id identificada devuele ERROR. Si esta identificada la iguala a un puntero 
  a una estructura de tipo game y devuelve OK.
*/
STATUS game_set_object_location(Game *game, Id id)
{

  

  if (id == NO_ID)
  {
    return ERROR;
  }

  game->object_location = id;

  return OK;
}

Id game_get_player_location(Game *game)
{
  return game->player_location;
}

Id game_get_object_location(Game *game)
{
  return game->object_location;
}
/*
  Guarda en una variable el ultimo comando leido y con un swith 
  lo manda a la funcion que corresponda

*/
STATUS game_update(Game *game, T_Command cmd)
{
  game->last_cmd = cmd;
  
  switch (cmd)
  {
    case UNKNOWN:
      game_command_unknown(game);
      break;

    case EXIT:
      game_command_exit(game);
      break;

    case NEXT:
      game_command_next(game);
      break;

    case BACK:
      game_command_back(game);
      break;
    
    case TAKE:
      game_command_take(game);
      break;

    case DROP:
      game_command_drop(game);
      break;

    case RIGHT:
      game_command_right(game);
      break;

    case LEFT:
      game_command_left(game);
      break;

    default:
      break;
  }

  return OK;
}
/*
  Obtiene el ultimo comando utilizado
*/
T_Command game_get_last_command(Game *game)
{
  return game->last_cmd;
}
/*
  enseña por pantalla los datos del juego
*/
void game_print_data(Game *game)
{
  int i = 0;

  printf("\n\n-------------\n\n");

  printf("=> Spaces: \n");
  for (i = 0; i < MAX_SPACES && game->spaces[i] != NULL; i++)
  {
    space_print(game->spaces[i]);
  }

  printf("=> Object location: %d\n", (int)game->object_location);
  printf("=> Player location: %d\n", (int)game->player_location);
}

BOOL game_is_over(Game *game)
{
  return FALSE;
}

/**
   Calls implementation for each action 
*/
void game_command_unknown(Game *game)
{
}

void game_command_exit(Game *game)
{
  
}

void game_command_next(Game *game)
{
  int i = 0;
  Id current_id = NO_ID;
  Id space_id = NO_ID;

  space_id = game_get_player_location(game);
  if (space_id == NO_ID)
  {
    return;
  }

  for (i = 0; i < MAX_SPACES && game->spaces[i] != NULL; i++)
  {
    current_id = space_get_id(game->spaces[i]);
    if (current_id == space_id)
    {
      current_id = space_get_south(game->spaces[i]);
      if (current_id != NO_ID)
      {
        game_set_player_location(game, current_id);
      }
      return;
    }
  }
}

void game_command_back(Game *game)
{
  int i = 0;
  Id current_id = NO_ID;
  Id space_id = NO_ID;

  space_id = game_get_player_location(game);

  if (NO_ID == space_id)
  {
    return;
  }

  for (i = 0; i < MAX_SPACES && game->spaces[i] != NULL; i++)
  {
    current_id = space_get_id(game->spaces[i]);
    if (current_id == space_id)
    {
      current_id = space_get_north(game->spaces[i]);
      if (current_id != NO_ID)
      {
        game_set_player_location(game, current_id);
      }
      return;
    }
  }
}
void game_command_take(Game *game)
{
  
}
void game_command_drop(Game *game)
{
  
}
void game_command_right(Game *game)
{
    int i = 0;
  Id current_id = NO_ID;
  Id space_id = NO_ID;

  space_id = game_get_player_location(game);

  if (NO_ID == space_id)
  {
    return;
  }

  for (i = 0; i < MAX_SPACES && game->spaces[i] != NULL; i++)
  {
    current_id = space_get_id(game->spaces[i]);
    if (current_id == space_id)
    {
      current_id = space_get_east(game->spaces[i]);
      if (current_id != NO_ID)
      {
        game_set_player_location(game, current_id);
      }
      return;
    }
  }
}
void game_command_left(Game *game)
{
    int i = 0;
  Id current_id = NO_ID;
  Id space_id = NO_ID;

  space_id = game_get_player_location(game);

  if (NO_ID == space_id)
  {
    return;
  }

  for (i = 0; i < MAX_SPACES && game->spaces[i] != NULL; i++)
  {
    current_id = space_get_id(game->spaces[i]);
    if (current_id == space_id)
    {
      current_id = space_get_west(game->spaces[i]);
      if (current_id != NO_ID)
      {
        game_set_player_location(game, current_id);
      }
      return;
    }
  }
}

