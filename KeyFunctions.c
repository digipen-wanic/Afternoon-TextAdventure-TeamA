/******************************************************************************
filename    KeyFunctions.c
author      Christian Yan
DP email    c.yan@digipen.edu

Brief Description:
This file defines the functions to create a specific item, the "Key".

******************************************************************************/
#include "stdafx.h" /* UNREFERENCED_PARAMETER, NULL*/
#include "KeyFunctions.h" /* Function declarations */
#include "GameState.h" /* struct GameState, GameState_ChangeScore */
#include "GameFlags.h" /* GameFlags_IsInList */
#include "WorldData.h" /* WorldData_GetRoom */
#include "Room.h" /* Room_GetItemList, Room_SetDescription */
#include "ItemList.h" /* ItemList_FindItem, ItemList_Remove, ItemList_Add */
#include "Item.h" /* Item_Create */

void Key_Take(CommandContext context, GameState* gameState, WorldData* worldData)
{
	UNREFERENCED_PARAMETER(context);
	UNREFERENCED_PARAMETER(gameState);
	UNREFERENCED_PARAMETER(worldData);

	printf("You have the Key.\n");
}

/* Build a "brick" object */
Item* Key_Build()
{
	return Item_Create("key", "The key for the Storage room. It shimmers in the light of your Hunkiness.", true, NULL, Key_Take, NULL);
}
