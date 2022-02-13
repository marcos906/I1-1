/**
 * @brief It defines the textual graphic engine interface
 *
 * @file graphic_engine.h
 * @author Profesores PPROG
 * @version 2.0
 * @date 29-11-2021
 * @copyright GNU Public License
 */

#ifndef __GRAPHIC_ENGINE__
#define __GRAPHIC_ENGINE__

#include "game.h"
/*
  Graphic_engine *graphic_engine_create()
    @Autor: Profesores PPROG
    @Paramentros: No hay
    @Return: Estructura Graphic_engine
    @Descripcion: Crea la grafica
  void graphic_engine_destroy(Graphic_engine *ge)
    @Autor: Profesores PPROG
    @Paramentros: Estructura Graphic_engine
    @Return: No hay
    @Descripcion: Destruye la grafica
  void graphic_engine_paint_game(Graphic_engine *ge, Game *game)
    @Autor: Profesores PPROG
    @Paramentros: Estructura Graphic_engine y game
    @Return: No hay
    @Descripcion: Va pintado el juego
  void graphic_engine_write_command(Graphic_engine *ge, char *str)
    @Autor: Profesores PPROG
    @Paramentros: Estructura Graphic_engine y un puntero a un char
    @Return: No hay
    @Descripcion: Escribe los comandos


*/
typedef struct _Graphic_engine Graphic_engine;

Graphic_engine *graphic_engine_create();
void graphic_engine_destroy(Graphic_engine *ge);
void graphic_engine_paint_game(Graphic_engine *ge, Game *game);
void graphic_engine_write_command(Graphic_engine *ge, char *str);

#endif
