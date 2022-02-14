/** 
 * @brief It defines the game interface
 * 
 * @file game_reader.h
 * @author Hector Labrador Gomez y Guillermo Fernandez Larrubia
 
 * @date 14-02-2022
 * @copyright GNU Public License
 */

#ifndef GAME_READER_H
#define GAME_READER_H

#include "game.h"
/*
    STATUS game_create_from_file(Game *game, char *filename)
        @Autor: Profesores PPROG
        @Paramentros: Estructura game y archivo.
        @Return: Ok o NULL
        @Descripcion: Situa al objeto y jugador en el espacio 1    
  Mira si hay errores en la apertura del puntero y del archivo. Si no hay llama a otra 
  funcion que crea el espacio 1 y situa al jugador y al objeto dentro y returnea OK

*/
STATUS game_create_from_file(Game *game, char *filename);
STATUS game_load_spaces(Game *game, char *filename);


#endif