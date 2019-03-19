/******************************************************************************
filename    TeddyFunctions.c
author      Nico Hickman
DP email    nicholas.hickman@digipen.edu

Brief Description:
This file defines the functions to create a specific item, the "teddy".

******************************************************************************/
#include "stdafx.h" /* UNREFERENCED_PARAMETER, NULL*/
#include "TeddyFunctions.h" /* Function declarations */
#include "GameState.h" /* struct GameState, GameState_ChangeScore */
#include "GameFlags.h" /* GameFlags_IsInList */
#include "WorldData.h" /* WorldData_GetRoom */
#include "Room.h" /* Room_GetItemList, Room_SetDescription */
#include "ItemList.h" /* ItemList_FindItem, ItemList_Remove, ItemList_Add */
#include "Item.h" /* Item_Create */

void Teddy_Take(CommandContext context, GameState* gameState, WorldData* worldData)
{
	UNREFERENCED_PARAMETER(context);
	UNREFERENCED_PARAMETER(gameState);
	UNREFERENCED_PARAMETER(worldData);

	printf("TODO: Teddy Take Description\n");
}

/* Build a "brick" object */
Item* Teddy_Build()
{
	return Item_Create("teddy", "TODO: Teddy Description", true,NULL, Teddy_Take, NULL);
}