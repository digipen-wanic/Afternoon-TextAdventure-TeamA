/******************************************************************************
filename    WorldData.h
author      Matthew Picioccio
DP email    mattpic@digipen.edu
course      GAM100 ** Do not use this code in your team project

Brief Description:
This file declares the WorldData interface, which is used to manage the entire
set of data in the game world.  This data is typically static, but it may 
not entirely be so.

******************************************************************************/
#pragma once

typedef struct Room Room;


/* Forward declaration for the WorldData type */
typedef struct WorldData WorldData;


/* Create a new WorldData object, using the provided parameters */
WorldData* WorldData_Create(const char* introduction, unsigned int numRooms);

/* Free the memory associated with the given WorldData object */
void WorldData_Free(WorldData** worldDataPtr);

/* Get a room from the given WorldData by its room index */
Room* WorldData_GetRoom(WorldData* worldData, int roomIndex);

/* Set a room in the given WorldData by its index*/
void WorldData_SetRoom(WorldData* worldData, int roomIndex, Room* room);

/* Print the introduction to the game to the standard output */
void WorldData_PrintIntroduction(WorldData* worldData, int initialRoomIndex);