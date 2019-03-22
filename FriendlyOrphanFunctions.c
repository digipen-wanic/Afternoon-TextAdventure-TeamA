/******************************************************************************
filename    FriendlyOrphanFunctions.c
author      Nico Hickman
edited by  Hunter Bradley
DP email    nicholas.hickman@digipen.edu

Last Edited By: Hunter Bradley

Brief Description:
This file defines the functions to create a specific item, the "friendly orphan". Also has the descriptions for when talking to the friendly orphan.

******************************************************************************/
#include "stdafx.h" /* UNREFERENCED_PARAMETER, NULL*/
#include "FriendlyOrphanFunctions.h" /* Function declarations */
#include "KeyFunctions.h" /* Key Function Declerations*/
#include "GameState.h" /* struct GameState, GameState_ChangeScore */
#include "GameFlags.h" /* GameFlags_IsInList */
#include "WorldData.h" /* WorldData_GetRoom */
#include "Room.h" /* Room_GetItemList, Room_SetDescription */
#include "ItemList.h" /* ItemList_FindItem, ItemList_Remove, ItemList_Add */
#include "Item.h" /* Item_Create */
void FOrphan_Talk(CommandContext context, GameState* gameState, WorldData* worldData)
{
	UNREFERENCED_PARAMETER(context);
	UNREFERENCED_PARAMETER(gameState);
	UNREFERENCED_PARAMETER(worldData);
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
	teddy = ItemList_FindItem(gameState->inventory, "teddy");
	/* check if the cage has already been broken and scored */
	if ( teddy== NULL)
	{
		/* the player already used the teddy - inform the user of the problem and take no action */
		printf("You can see John hugging Mr. Fluffles as the plane speedly dessends. You know that you will never feel Mr. Fluffles soft fur ever again.\n");
		return;
	}
	else
	{
		gameState->inventory = ItemList_Remove(gameState->inventory, teddy);
		printf("You hand John Mr.Fluffles, your only true friend in the world.\n");
		/* Tell the user what they did */
		printf("Orphan of Storage Protrol, John: “Thank you! Oh, here, it wouldn't be a fair trade if i didn't give you something in return.”\n You obtain the Storage Key!\n");

		/* Add to the player's score */
		GameState_ChangeScore(gameState, 10);

		/* the gold piece has not been scored, so mark the flag */
		gameState->inventory = ItemList_Add(gameState->inventory, Key_Build());
	}
}

/* Build a "FriendlyOrphan" object */
Item* FOrphan_Build()
{
	Item* orphan = 
	 Item_Create("orphan", "Orphan of Storage Protrol, John: “Hi Mister Hunk! You probably haven’t heard of me… But I’m John! I am in charge of this ship's Storage room. Im looking for something to make me feel safe while we are crashing.”", false, NULL, NULL, NULL);
	Item_SetTalkFunc(orphan, FOrphan_Talk);
	return orphan;
}