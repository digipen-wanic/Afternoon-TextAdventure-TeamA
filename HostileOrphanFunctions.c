/******************************************************************************
filename    HostileOrphanFunctions.c
author      Christian Yan
DP email    c.yan@digipen.edu

Brief Description:
This file defines the functions to create a specific item, the "HostileOrphan".

******************************************************************************/
#include "stdafx.h" /* UNREFERENCED_PARAMETER, NULL*/
#include "HostileOrphanFunctions.h" /* Function declarations */
#include "GameState.h" /* struct GameState, GameState_ChangeScore */
#include "GameFlags.h" /* GameFlags_IsInList */
#include "WorldData.h" /* WorldData_GetRoom */
#include "Room.h" /* Room_GetItemList, Room_SetDescription */
#include "ItemList.h" /* ItemList_FindItem, ItemList_Remove, ItemList_Add */
#include "Item.h" /* Item_Create */
#include "KeyFunctions.h"
void HostileOrphan_Talk(CommandContext context, GameState* gameState, WorldData* worldData)
{
	/*TODO: Orphan talk*/
	UNREFERENCED_PARAMETER(context);
	UNREFERENCED_PARAMETER(gameState);
	UNREFERENCED_PARAMETER(worldData);
	Room *room;				 /* The current room */
	ItemList **roomItemsPtr; /* The list of items in the current room */
	Item *candy;			 /* The candy in the player's inventory */

	/* safety check on the parameters */
	if ((gameState == NULL) || (worldData == NULL))
	{
		return; /* take no action if the parameters are invalid */
	}



	/* check if we're in the right room to use the item */
	if (gameState->currentRoomIndex != 10)
	{
		/* we are not in the right room - inform the user of the problem and take no action */
		printf("There is no Orphan in this room to talk to.\n");
		return;
	}

	/* check if the cage has already been broken and scored */
	if (ItemList_FindItem(gameState->inventory, "candy") == NULL)
	{
		/* the player already used the candy - inform the user of the problem and take no action */
		printf("You do not have the candy anymore\n");
		return;
	}
	else
	{
		/* get the current room */
		room = WorldData_GetRoom(worldData, gameState->currentRoomIndex);
		
		/* get the list of items in the current room */
		roomItemsPtr = Room_GetItemList(room);
		if (roomItemsPtr == NULL)
		{
			return; /* take no action, as something is wrong - we should always have an item list */
		}

		/* Find the candy in the player's inventory - it should be there, since we are in the Inventory context */
		candy = ItemList_FindItem(gameState->inventory, "candy");

		/* Remove the candy from the user's inventory - they won't need it again */
		gameState->inventory = ItemList_Remove(gameState->inventory, candy);

		/* Tell the user what they did */
		printf("Orphan General Toby: “Wait… Is that the candy that i had on the counter…? Give me that!”\n");

		/* Add to the player's score */
		GameState_ChangeScore(gameState, 10);

		/* Update the room description to reflect the change in the room */
		/* Room_SetDescription(room, "TODO\n");

		/* Add a key to the current room, since the cage has been bashed open */
		/* *roomItemsPtr = ItemList_Add(*roomItemsPtr, Key_Build());

		/* the gold piece has not been scored, so mark the flag */

		/* 
		 * throw flag to remove orphan
		 * change room description to not mention the hostile orphan
		 * remove candy vrom inv
		 */
		ItemList_Remove(gameState->inventory, candy);
		Room_SetDescription(room, "This is the Hanger. A large Escape Plane sits in the center of the room. To the South, is a Staircase up to the Kitchen.");
		gameState->gameFlags = GameFlags_Add(gameState->gameFlags, "orphanGone");
	}
}
/* Build a "candy" object */
Item* HostileOrphan_Build()
{
	return Item_Create("hostileorphan", "Orphan General Toby: “I’m sorry but I can’t let you get into this Escape Plane. The Captain said not to let anyone use this plane, no matter who they are.”", false, NULL, NULL, NULL);
}
