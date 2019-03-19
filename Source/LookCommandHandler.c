/******************************************************************************
filename    LookCommandHandler.c
author      Matthew Picioccio
DP email    mattpic@digipen.edu
course      GAM100 ** Do not use this code in your team project

Brief Description:
This file defines functions that handle the "look" user command, which outputs
a description of an item or the current room.

******************************************************************************/
#include "stdafx.h" /* NULL, printf, strnlen_s */
#include "LookCommandHandler.h" /* Function declarations */
#include "CommandData.h" /* struct CommandData */
#include "GameState.h" /* struct GameState */
#include "WorldData.h" /* WorldData_GetRoom */
#include "Room.h" /* Room_Print, Room_GetItemList */
#include "ItemList.h" /* ItemList_FindItem */
#include "Item.h" /* Item_Print */


/* Handles the "look" command, which outputs a description of an item or the current room */
void HandleLookCommand(CommandData* command, GameState* gameState, WorldData* worldData)
{
	Item* item; /* the item referred to by the command noun, if any */
	Room* room; /* the current room */
	ItemList** roomItemsPtr; /* the list of items in the room */

	/* safety check on the parameters */
	if ((command == NULL) || (gameState == NULL) || (worldData == NULL)) 
	{
		return; /* take no action if the parameters are invalid */
	}

	/* get the current room */
	room = WorldData_GetRoom(worldData, gameState->currentRoomIndex);

	/* if there is no noun specified, then the command refer to the room */
	if ((command->noun == NULL) || (strnlen_s(command->noun, MAX_COMMAND_NOUN_LENGTH) == 0))
	{
		/* if we have a room (and we always should), print its description */
		if (room != NULL)
		{
			printf("(looking at the room)\n"); /* clarify the target for the user */
			Room_Print(room);
		}
		return;
	}

	/* search for the item in the user's inventory, which takes precedence over the room */
	item = ItemList_FindItem(gameState->inventory, command->noun);
	if (item != NULL)
	{
		printf("(in your inventory)\n"); /* clarify the target for the user */
		/* an item matching the noun was found in the user's inventory - print its description */
		Item_Print(item);
		return;
	}

	/* retrieve the set of items in the room */
	roomItemsPtr = Room_GetItemList(room);
	if (roomItemsPtr == NULL)
	{
		return; /* the item list pointer is missing - something has gone wrong.  take no action */
	}

	/* search for the item in the current room */
	item = ItemList_FindItem(*roomItemsPtr, command->noun);
	if (item != NULL)
	{
		printf("(in the room)\n"); /* clarify the target for the user */
		/* an item matching the noun was found in the current room - print its description */
		Item_Print(item); 
		return;
	}

	/* the noun didn't match an available item, so inform the user that there is no match */
	printf("You do not see a %s here.", command->noun);
}