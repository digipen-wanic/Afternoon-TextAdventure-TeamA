/******************************************************************************
filename    CoverFunctions.c
author      Christian Yan
DP email    c.yan@digipen.edu

Brief Description:
This file defines the functions to create a specific item, the "Cover".

******************************************************************************/
#include "stdafx.h" /* UNREFERENCED_PARAMETER, NULL*/
#include "CoverFunctions.h" /* Function declarations */
#include "GameState.h" /* struct GameState, GameState_ChangeScore */
#include "GameFlags.h" /* GameFlags_IsInList */
#include "WorldData.h" /* WorldData_GetRoom */
#include "Room.h" /* Room_GetItemList, Room_SetDescription */
#include "ItemList.h" /* ItemList_FindItem, ItemList_Remove, ItemList_Add */
#include "Item.h" /* Item_Create */

void Cover_Take(CommandContext context, GameState* gameState, WorldData* worldData)
{
	UNREFERENCED_PARAMETER(context);
	UNREFERENCED_PARAMETER(gameState);
	UNREFERENCED_PARAMETER(worldData);

	printf("TODO: Cover Take Description\n");
}

/* Build a "brick" object */
Item* Cover_Build()
{
	return Item_Create("cover", "TODO: Cover Description", true, NULL, Cover_Take, NULL);
}