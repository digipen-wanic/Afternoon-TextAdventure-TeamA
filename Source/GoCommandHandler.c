/******************************************************************************
filename    GoCommandHandler.c
author      Matthew Picioccio
DP email    mattpic@digipen.edu
course      GAM100 ** Do not use this code in your team project

Brief Description:
This file defines functions that handle the "go" user command, which moves
the user from one room to another using defined exits.

******************************************************************************/
#include "stdafx.h" /* NULL, printf */
#include "GoCommandHandler.h" /* Function declarations */
#include "CommandData.h" /* struct CommandData */
#include "GameState.h" /* struct GameState */
#include "WorldData.h" /* WorldData_GetRoom */
#include "Room.h" /* Room_GetNextRoomIndex, Room_Print, INVALID_DIRECTION_ID */


/* Handles the "go" command, which moves the user to another room */
void HandleGoCommand(CommandData *command, GameState *gameState, WorldData *worldData)
{
	Room* currentRoom; /* the room we are currently in */
	int nextRoomIndex; /* the index of hte next room */

	/* safety check on the parameters */
	if ((command == NULL) || (command->noun == NULL) || (gameState == NULL) || (worldData == NULL)) 
	{
		return; /* take no action if the parameters are invalid */
	}

	/* get the current room, based on the user state */
	currentRoom = WorldData_GetRoom(worldData, gameState->currentRoomIndex);

	/* get the next room index, based on the noun used with "go" */
	if (Room_GetNextRoomIndex(currentRoom, command->noun, &nextRoomIndex) == false)
	{
		/* there is no exit in that direction, so let the user know and take no other action */
		printf("You cannot move %s.\n", command->noun);
		return;
	}

	/* update the game state to move to the new room */
	gameState->currentRoomIndex = nextRoomIndex;

	/* output the successful action */
	printf("You move %s.\n\n", command->noun);

	/* get the new room */
	currentRoom = WorldData_GetRoom(worldData, gameState->currentRoomIndex);

	/* print the description of the new room */
	Room_Print(currentRoom);
}