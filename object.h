/**
    @Descripcion: Nombra las funciones que se van a utilizar en el object.c
    @Nombre: object.h
    @Autor: Héctor Labrador Gómez
    @date 14-02-2022
    @copyright GNU Public License
 */

#ifndef OBJECT_H
#define OBJECT_H

#include "types.h"

typedef struct _Object Object;

#define MAX_SPACES 100
#define FIRST_SPACE 1

/**
  * @brief It creates a new space
  * @author Profesores PPROG
  *
  * space_create allocates memory for a new space
  *  and initializes its members
  * @param id the identification number for the new space
  * @return a new space, initialized
  */
Object* object_create(Id id);

/**
  * @brief It destroys a space
  * @author Profesores PPROG
  *
  * space_destroy frees the previous memory allocation 
  *  for a space
  * @param space a pointer to the space that must be destroyed  
  * @return OK, if everything goes well or ERROR if there was some mistake
  */
STATUS object_destroy(Object* object);

/**
  * @brief It gets the id of a space
  * @author Profesores PPROG
  * 
  * @param space a pointer to the space  
  * @return the id of space
  */
Id object_get_id(Object* object);

/**
  * @brief It sets the name of a space
  * @author Profesores PPROG
  * 
  * @param space a pointer to the space
  * @param name a string with the name to store
  * @return OK, if everything goes well or ERROR if there was some mistake 
  */
STATUS object_set_name(Object* object, char* name);

/**
  * @brief It gets the name of a space
  * @author Profesores PPROG
  * 
  * @param space a pointer to the space
  * @return  a string with the name of the space
  */
const char* object_get_name(Object* object;

/**
  * @brief It prints the space information
  * @author Profesores PPROG
  *
  * This fucntion shows the id and name of the space, the spaces that surrounds it and wheter it has an object or not.
  * @param space a pointer to the space
  * @return OK, if everything goes well or ERROR if there was some mistake
  */
STATUS object_print(Object* object);

#endif
