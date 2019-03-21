/******************************************************************************
filename    FriendlyOrphanFunctions.c
author      Nico Hickman
DP email    nicholas.hickman@digipen.edu

Brief Description:
This file defines the functions to create a specific item, the "friendly orphan".

******************************************************************************/
#include "stdafx.h" /* UNREFERENCED_PARAMETER, NULL*/
#include "FriendlyOrphanFunctions.h" /* Function declarations */
#include "GameState.h" /* struct GameState, GameState_ChangeScore */
#include "GameFlags.h" /* GameFlags_IsInList */
#include "WorldData.h" /* WorldData_GetRoom */
#include "Room.h" /* Room_GetItemList, Room_SetDescription */
#include "ItemList.h" /* ItemList_FindItem, ItemList_Remove, ItemList_Add */
#include "Item.h" /* Item_Create */

void FOrphan_Talk(CommandContext context, GameState* gameState, WorldData* worldData)
{
	/*TODO: Orphan talk*/
	UNREFERENCED_PARAMETER(context);
	UNREFERENCED_PARAMETER(gameState);
	UNREFERENCED_PARAMETER(worldData);
	Room *room;				 /* The current room */
	ItemList **roomItemsPtr; /* The list of items in the current room */
	Item *teddy;			 /* The teddy in the player's inventory */

	/* safety check on the parameters */
	if ((gameState == NULL) || (worldData == NULL))
	{
		return; /* take no action if the parameters are invalid */
	}

	/* check if we're in the right room to use the item */
	if (gameState->currentRoomIndex != 7)
	{
		/* we are not in the right room - inform the user of the problem and take no action */
		printf("There is no Orphan in this room to talk to.\n");
		return;
	}

	/* check if the cage has already been broken and scored */
	if (ItemList_FindItem(gameState->inventory, "teddy") == NULL)
	{
		/* the player already used the teddy - inform the user of the problem and take no action */
		printf("You can see John hugging Mr. Fluffles as the plane speedly dessends. You know that you will never feel Mr. Fluffles soft fur ever again.\n");
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

		/* Find the teddy in the player's inventory - it should be there, since we are in the Inventory context */
		teddy = ItemList_FindItem(gameState->inventory, "teddy");

		/* Remove the teddy from the user's inventory - they won't need it again */
		gameState->inventory = ItemList_Remove(gameState->inventory, teddy);

		/* Tell the user what they did */
		printf("Orphan of Storage Protrol, John: “Thank you!”\n You hand John Mr.Fluffles, your only true friend in the world. You obtain the Storage Key!\n");

		/* Add to the player's score */
		GameState_ChangeScore(gameState, 10);

		/* Update the room description to reflect the change in the room */
		//Room_SetDescription(room, "TODO\n");

		/* Add a key to the current room, since the cage has been bashed open */
		//*roomItemsPtr = ItemList_Add(*roomItemsPtr, Key_Build());

		/* the gold piece has not been scored, so mark the flag */
		gameState->inventory = ItemList_Add(gameState->inventory, Key_Build());
	}
}

/* Build a "FriendlyOrphan" object */
Item* FOrphan_Build()
{
	return Item_Create("friendly orphan", "Orphan of Storage Protrol, John: “Hi Mister Hunk! You probably haven’t heard of me… But I’m John! I am in charge of this ship's Storage room.”", false, NULL, NULL, NULL);
}