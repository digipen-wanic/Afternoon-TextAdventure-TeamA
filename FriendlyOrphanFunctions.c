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
}

/* Build a "brick" object */
Item* FOrphan_Build()
{
	return Item_Create("friendly orphan", "TODO: Friendly Orphan Description", false, NULL, NULL, NULL);
}