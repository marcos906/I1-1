/** 
 * @brief It defines the game interface
 * 
 * @file game.h
 * @author Profesores PPROG
 * @version 2.0 
 * @date 29-11-2021 
 * @copyright GNU Public License
 */

#ifndef GAME_H
#define GAME_H

#include "command.h"
#include "space.h"
#include "types.h"

typedef struct _Game
{
  Id player_location;
  Id object_location;
  Space *spaces[MAX_SPACES];
  T_Command last_cmd;
} Game;
/*
  STATUS game_create(Game *game)
    Paramentros: Estructura game.
    Return: Ok o NULL
    Descripcion: Comienzo un bucle for y va creando espacios. Al salir crea un jugador y un objeto vacio y returnea OK.
  STATUS game_create_from_file(Game *game, char *filename)
    Paramentros: Estructura game y archivo.
    Return: Ok o NULL
    Descripcion: Mira haber si hay errores en la apertura del puntero y del archivo. Si no llama a otro funcion que crea el espacio 1 y situa al jugador y al objeto dentro
    y returnea OK
  STATUS game_update(Game *game, T_Command cmd)
    Paramentros: Estructura game y llamada al ultimo comando.
    Return: Ok o NULL
    Descripcion: Lee el comando anterior que se coge y con un swith le lleva a otras funciones
  STATUS game_destroy(Game *game)
    Paramentros: Estructura game.
    Return: Ok o NULL
    Descripcion: Con un bucle for va destruyendo cada uno de los espacios llamando a la funcion destruir espacio
  BOOL game_is_over(Game *game)
    Paramentros: True y False
    Return: False
    Descripcion: Falta por hacer
  void game_print_data(Game *game)
    Paramentros: Estructura game.
    Return: 
    Descripcion: enseña por pantalla los datos del juego
  Space *game_get_space(Game *game, Id id)
    Paramentros: Estructura game, 
    Return: 
    Descripcion: Si no hay ID asociada return NULL. Si no, entra en un bucle (que se acaba cuando no hay mas posibles espacios o cuando el espacio es nulo) que
    si el Id es igual a otra funciona que coge el Id returnea el espacio que quieres.
  Id game_get_player_location(Game *game)
    Return la posicion del jugador

  
    


*/
STATUS game_create(Game *game);
STATUS game_create_from_file(Game *game, char *filename);
STATUS game_update(Game *game, T_Command cmd);
STATUS game_destroy(Game *game);
BOOL game_is_over(Game *game);
void game_print_data(Game *game);
Space *game_get_space(Game *game, Id id);
Id game_get_player_location(Game *game);
Id game_get_object_location(Game *game);
T_Command game_get_last_command(Game *game);
#endif
