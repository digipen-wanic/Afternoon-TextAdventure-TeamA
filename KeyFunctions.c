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

	printf("You have the Key.\nn");

}
void Key_Use(CommandContext context, GameState* gameState, WorldData* worldData) {
	UNREFERENCED_PARAMETER(context);
	UNREFERENCED_PARAMETER(gameState);
	UNREFERENCED_PARAMETER(worldData);
	Item* key = ItemList_FindItem(gameState->inventory, "key");
	if (key != NULL) {
		printf("TODO: UNLOCKING DOOR");
		gameState->gameFlags = GameFlags_Add(gameState->gameFlags, "srdoorOpen");
		gameState->inventory = ItemList_Remove(gameState->inventory, key);
	}
	else {
		printf("TODO: NO KEY");
	}
}
/* Build a "brick" object */
Item* Key_Build()
{
	return Item_Create("key", "The key for the Storage room. It shimmers in the light of your Hunkiness.", true, Key_Use, Key_Take, NULL);
}
