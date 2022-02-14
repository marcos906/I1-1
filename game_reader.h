/** 
 * @brief Define las funciones utilizadas en el .h
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
        @Descripcion: Crea el juego en la file
    STATUS game_load_spaces(Game *game, char *filename)  
        @Autor: Profesores PPROG
        @Paramentros: Estructura game y archivo.
        @Return: Ok o NULL
        @Descripcion: Situa al objeto y jugador en el espacio 1 

*/
STATUS game_create_from_file(Game *game, char *filename);
STATUS game_load_spaces(Game *game, char *filename);


#endif