/******************************************************************************
filename    WorldData.c
author      Matthew Picioccio
DP email    mattpic@digipen.edu
course      GAM100 ** Do not use this code in your team project

Brief Description:
This file defines the WorldData interface, which is used to manage the entire
set of data in the game world.  This data is typically static, but it may
not entirely be so.

******************************************************************************/
#include "stdafx.h" /* NULL, malloc/free, printf, strcpy_s */
#include "WorldData.h" /* Function declarations */
#include "Room.h" /* Room_Print */


/* The maximum length of the game introduction string. */
#define MAX_INTRODUCTION_LENGTH 256


/* The world data for the game. */
typedef struct WorldData
{
	char introduction[MAX_INTRODUCTION_LENGTH]; /* The introduction to the game. */
	int numRooms; /* The number of rooms in the "rooms" array */
	Room** rooms; /* The array of references to all rooms in the game */
} WorldData;


/* Create a new WorldData object, using the provided parameters */
WorldData* WorldData_Create(const char* introduction, unsigned int numRooms)
{
	WorldData* worldData; /* The new WorldData object */
	
	/* safety check on the parameters */
	if (numRooms == 0)
	{
		return NULL; /* take no action if the parameters are invalid */
	}
	
	/* allocate the memory for the new WorldData object */
	worldData = (WorldData*)malloc(sizeof(WorldData));
	if (worldData == NULL)
	{
		return NULL; /* malloc can fail! */
	}

	/* copy the parameter data into the new object */
	worldData->numRooms = numRooms;
	if (introduction != NULL)
	{
		strcpy_s(worldData->introduction, MAX_INTRODUCTION_LENGTH, introduction);
	}

	/* allocate the room-reference array */
	worldData->rooms = (Room**)malloc(worldData->numRooms * sizeof(Room*));

	/* return the new object */
	return worldData;
}


/* Free the memory associated with the given WorldData object */
void WorldData_Free(WorldData** worldDataPtr)
{
	int i; /* the index of the Room object being freed */

	/* safety check on the parameters */
	if ((worldDataPtr == NULL) || (*worldDataPtr == NULL)) 
	{
		return; /* take no action if the parameters are invalid */
	}

	/* free each room from its reference in the array */
	for (i = 0; i < (*worldDataPtr)->numRooms; ++i)
	{
		Room_Free(&((*worldDataPtr)->rooms[i]));
	}

	/* free the room-reference array itself */
	free((*worldDataPtr)->rooms);

	/* free the WorldData object itself */
	free(*worldDataPtr);

	/* clear the provided pointer*/
	*worldDataPtr = NULL;
}


/* Get a room from the given WorldData by its room index */
Room* WorldData_GetRoom(WorldData* worldData, int roomIndex)
{
	/* safety check on the parameters */
	if ((worldData == NULL) || (roomIndex < 0) || (roomIndex >= worldData->numRooms))
	{
		return NULL; /* return NULL if the parameters are invalid */
	}

	/* retrieve the room reference out of the array */
	return worldData->rooms[roomIndex];
}


/* Set a room in the given WorldData by its index*/
void WorldData_SetRoom(WorldData* worldData, int roomIndex, Room* room)
{
	/* safety check on the parameters */
	if ((worldData == NULL) || (roomIndex < 0) || (roomIndex >= worldData->numRooms) || (room == NULL))
	{
		return; /* take no action if the parameters are invalid */
	}

	/* assign the room reference from the parameter data into the array */
	worldData->rooms[roomIndex] = room;
}


/* Print the introduction to the game to the standard output */
void WorldData_PrintIntroduction(WorldData* worldData, int initialRoomIndex)
{
	Room* initialRoom; /* the initial room */

	/* safety check on the parameters */
	if (worldData == NULL)
	{
		return; /* take no action if the parameters are invalid */
	}

	/* print the introduction */
	printf(worldData->introduction);

	/* retrieve the initial room based on the parameter index */
	initialRoom = WorldData_GetRoom(worldData, initialRoomIndex);

	/* print the description of the initial room */
	Room_Print(initialRoom);
}