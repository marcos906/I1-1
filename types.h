/**
 * @brief It defines common types for the whole project
 *
 * @file types.h
 * @author Profesores PPROG
 * @version 2.0
 * @date 29-11-2021
 * @copyright GNU Public License
 */

#ifndef TYPES_H
#define TYPES_H
/*
  Estructuras definidas en type.h:
    long Id: Para guardar la Id de los elementos del juego;
    enum Bool: Asigna el valor 0 a FALSE y 1 a TRUE;
    enum Status: Asigna el valor 0 a ERROR y 1 a OK;
    enum Direction: Asigna el valor 0 a N, 1 a S, 2 a E y 3 a W;
  Macros:
    NO_ID = -1
    WORD_SIZE = 1000

*/
#define WORD_SIZE 1000
#define NO_ID -1

typedef long Id;

typedef enum
{
  FALSE,
  TRUE
} BOOL;

typedef enum
{
  ERROR,
  OK
} STATUS;

typedef enum
{
  N,
  S,
  E,
  W
} DIRECTION;

#endif
