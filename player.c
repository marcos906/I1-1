/*
    @Descripcion: Nombra las funciones que se van a utilizar en el object.c
    @Nombre: object.h
    @Autor: Héctor Labrador Gómez
    @date 14-02-2022
    @copyright GNU Public License
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "player.h"


struct _Player {
  Id id;                    /*!< Id number of the space, it must be unique */
  char name[WORD_SIZE + 1]; /*!< Name of the space */
  /*
  ?? location
  */
  BOOL object;              /*!< Whether the space has an object or not */
};

Player* space_create(Id id){
    
    Player *newPlayer = NULL;

    /* Error control */
  if (id == NO_ID)
    return NULL;

  newPlayer = (Player *) malloc(sizeof (Player));
  if (newPlayer == NULL) {
    return NULL;

    /* Initialization of an empty space*/
  newPlayer->id = id;
  newPlayer->name[0] = '\0';
  /*
  ?? location
  */
  newPlayer->object = FALSE;
  }

  return newPlayer;

}

STATUS player_destroy(Player* player){
    if (!player) {
    return ERROR;
  }

  free(player);
  player = NULL;
  return OK;
}

Id player_get_id(Player* player){
    if (!player) {
    return NO_ID;
  }
  return player->id;
}

STATUS player_set_name(Player* player, char* name){
    if (!player) {
    return NO_ID;
  }
  return player->id;

}

const char* player_get_name(Player* player, char* name){
    if (!player || !name) {
    return ERROR;
  }

  if (!strcpy(player->name, name)) {
    return ERROR;
  }
  return OK;
}

STATUS player_set_object(Player* player, BOOL value){
    if (!player) {
    return ERROR;
  }
  player->object = value;
  return OK;
}

BOOL player_get_object(Player* player){
    if (!player) {
    return FALSE;
  }
  return player->object;
}

STATUS player_print(Player* player){
    Id idaux = NO_ID;

  /* Error Control */
  if (!player) {
    return ERROR;
  }

  /* 1. Print the id and the name of the space */
  fprintf(stdout, "--> Space (Id: %ld; Name: %s)\n", player->id, player->name);
 
  /* 2. For each direction, print its link  
  idaux = space_get_north(space);
  if (NO_ID != idaux) {
    fprintf(stdout, "---> North link: %ld.\n", idaux);
  } else {
    fprintf(stdout, "---> No north link.\n");
  }
  idaux = space_get_south(space);
  if (NO_ID != idaux) {
    fprintf(stdout, "---> South link: %ld.\n", idaux);
  } else {
    fprintf(stdout, "---> No south link.\n");                                                   location
  }
  idaux = space_get_east(space);
  if (NO_ID != idaux) {
    fprintf(stdout, "---> East link: %ld.\n", idaux);
  } else {
    fprintf(stdout, "---> No east link.\n");
  }
  idaux = space_get_west(space);
  if (NO_ID != idaux) {
    fprintf(stdout, "---> West link: %ld.\n", idaux);
  } else {
    fprintf(stdout, "---> No west link.\n");
  }
    */
  /* 3. Print if there is an object in the space or not */
  if (player_get_object(player)) {
    fprintf(stdout, "---> Player owns an object.\n");
  } else {
    fprintf(stdout, "---> Player do not owns an object.\n");
  }

  return OK;
}

