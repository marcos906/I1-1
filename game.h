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
    @Autor: Profesores PPROG
    @Paramentros: Estructura game.
    @Return: Ok o NULL
    @Descripcion: Inicializa el juego
  STATUS game_create_from_file(Game *game, char *filename)
    @Autor: Profesores PPROG
    @Paramentros: Estructura game y archivo.
    @Return: Ok o NULL
    @Descripcion: Situa al objeto y jugador en el espacio 1
  STATUS game_update(Game *game, T_Command cmd)
    @Autor: Profesores PPROG
    @Paramentros: Estructura game y llamada al ultimo comando.
    @Return: Ok o NULL
    @Descripcion: actualiza el juego con el ultimo comando
  STATUS game_destroy(Game *game)
    @Autor: Profesores PPROG
    @Paramentros: Estructura game.
    @Return: Ok o NULL
    @Descripcion: destruye el juego
  BOOL game_is_over(Game *game)
    @Autor: Profesores PPROG
    @Paramentros: True y False
    @Return: True o False
    @Descripcion: Falta por hacer
  void game_print_data(Game *game)
    @Autor: Profesores PPROG
    @Paramentros: Estructura game.
    @Return: No hay return
    @Descripcion: enseña por pantalla los datos del juego
  Space *game_get_space(Game *game, Id id)
    @Autor: Profesores PPROG
    @Paramentros: Estructura game
    @Return: Uno de los datos de la estructura Space
    @Descripcion: Da el espacio en donde se encuentra el jugador
  Id game_get_player_location(Game *game)
    @Autor: Profesores PPROG
    @Paramentros: Estructura game
    @Return: un long de tipo Id
    @Descripcion: Obtiene la posicion del jugador

  Id game_get_object_location(Game *game);
    @Autor: Profesores PPROG
    @Paramentros: Estructura game
    @Return: un long de tipo Id
    @Descripcion: Obtiene la posicion del objeto

  T_Command game_get_last_command(Game *game);
    @Autor: Profesores PPROG
    @Paramentros: Estructura game
    @Return: un dato de estructura T_command 
    @Descripcion: Nos da el ultimo comando ejecutado

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
