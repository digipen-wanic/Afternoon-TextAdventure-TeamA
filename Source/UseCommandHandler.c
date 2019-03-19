/******************************************************************************
filename    UseCommandHandler.c
author      Matthew Picioccio
DP email    mattpic@digipen.edu
course      GAM100 ** Do not use this code in your team project

Brief Description:
This file defines functions that handle the "use" user command, which calls
an item-specific function on a given item

******************************************************************************/
#include "stdafx.h" /* NULL, printf */
#include "UseCommandHandler.h" /* Function declarations */
#include "CommandData.h" /* struct CommandData, CommandContext */
#include "GameState.h" /* struct GameState */
#include "WorldData.h" /* WorldData_GetRoom */
#include "Room.h" /* Room_GetItemList */
#include "ItemList.h" /* ItemList_FindItem */
#include "Item.h" /* ItemFunc, Item_GetUseFunc */


/* Handles the "use" command, which calls an item-specific function on a given item */
void HandleUseCommand(CommandData* command, GameState* gameState, WorldData* worldData)
{
	Item* usedItem; /* the item to be used */
	Room* room; /* the current room */
	ItemList** roomItemsPtr; /* the list of items in the current room */
	ItemFunc useFunc; /* The function to be called for the given item when it is used */
	CommandContext useContext = CommandContext_User; /* the context used for the "use" function*/

	/* safety check on the parameters */
	if ((command == NULL) || (command->noun == NULL) || (gameState == NULL) || (worldData == NULL))
	{
		return;  /* take no action if the parameters are invalid */
	}

	/* search for the item in the user's inventory, which takes precedence over the current room */
	usedItem = ItemList_FindItem(gameState->inventory, command->noun);
	if (usedItem != NULL)
	{
		/* the item was found in the user's inventory, so we're going to use the Inventory context*/
		useContext = CommandContext_Item_Inventory;
	}
	else
	{
		/* retrieve the current room */
		room = WorldData_GetRoom(worldData, gameState->currentRoomIndex);
		/* retrieve the set of items in the current room */
		roomItemsPtr = Room_GetItemList(room);
		/* retrieve the item from the list of items in teh current room */
		if (roomItemsPtr != NULL)
		{
			usedItem = ItemList_FindItem(*roomItemsPtr, command->noun);
		}
		if (usedItem != NULL)
		{
			/* the item was found in the room, so we're going to use the Room context */
			useContext = CommandContext_Item_Room;
		}
	}

	/* check if the item has been found anywhere */
	if (usedItem == NULL)
	{
		/* the item was not found - inform the user of the problem and take no action */
		printf("You do not see a %s here.", command->noun);
		return;
	}

	/* get the "use" function for this item, if any */
	useFunc = Item_GetUseFunc(usedItem);
	if (useFunc == NULL)
	{
		/* no "use" function was defined, so the item cannot be used - inform the user of the problem and take no action*/
		printf("You cannot use a %s here.", command->noun);
		return;
	}

	/* call the "use" function with the appropriate context */
	useFunc(useContext, gameState, worldData);
}