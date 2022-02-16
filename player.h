/**
    @Descripcion: Nombra las funciones que se van a utilizar en el player.c
    @Nombre: player.h
    @Autor: Guillermo Fernández Larrubia
    @date 15-02-2022
    @copyright GNU Public License
 */

#ifndef PLAYER_H
#define PLAYER_H

#include "types.h"

typedef struct _Player Player;

/**
  * @brief It creates a new space
  * @author Profesores PPROG
  *
  * player_create allocates memory for a new player
  *  and initializes its members
  * @param id the identification number for the new player
  * @return a new player, initialized
  */
Player* player_create(Id id);


/**
  * @brief It destroys a player
  * @author Profesores PPROG
  *
  * player_destroy frees the previous memory allocation 
  *  for a space
  * @param space a pointer to the player that must be destroyed  
  * @return OK, if everything goes well or ERROR if there was some mistake
  */
STATUS player_destroy(Player* player);

/**
  * @brief It gets the id of a player
  * @author Profesores PPROG
  * 
  * @param space a pointer to the space  
  * @return the id of space
  */
Id player_get_location(Player* player);


Id player_set_location(Player* player, Id id);

/**
  * @brief It sets the name of a space
  * @author Profesores PPROG
  * 
  * @param space a pointer to the space
  * @param name a string with the name to store
  * @return OK, if everything goes well or ERROR if there was some mistake 
  */
STATUS player_set_name(Player* player, char* name);

/**
  * @brief It gets the name of a space
  * @author Profesores PPROG
  * 
  * @param space a pointer to the space
  * @return  a string with the name of the space
  */
const char* player_get_name(Player* player, char* name);

/**
  * @brief It sets whether the space has an object or not
  * @author Profesores PPROG
  *
  * @param space a pointer to the space
  * @param value a boolean, specifying if in the space there is an object (TRUE) or not (FALSE)
  * @return OK, if everything goes well or ERROR if there was some mistake 
  */
STATUS player_set_object(Player* player, Object *obj);

/**
  * @brief It gets whether the space has an object or not
  * @author Profesores PPROG
  *
  * @param space a pointer to the space
  * @return a boolean, specifying if in the space there is an object (TRUE) or not (FALSE)
  */
Object player_get_object(Player* player);

/**
  * @brief It prints the space information
  * @author Profesores PPROG
  *
  * This fucntion shows the id and name of the space, the spaces that surrounds it and wheter it has an object or not.
  * @param space a pointer to the space
  * @return OK, if everything goes well or ERROR if there was some mistake
  */
STATUS player_print(Player* player);




#endif