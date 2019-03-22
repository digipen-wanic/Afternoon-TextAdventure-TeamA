/******************************************************************************
filename    EngineFunctions.c
author      Nico Hickman
edited by  Hunter Bradley
DP email    nicholas.hickman@digipen.edu

Brief Description:
This file defines the functions to create a specific item, the "engine".

******************************************************************************/
#include "stdafx.h" /* UNREFERENCED_PARAMETER, NULL*/
#include "EngineFunctions.h" /* Function declarations */
#include "GameState.h" /* struct GameState, GameState_ChangeScore */
#include "GameFlags.h" /* GameFlags_IsInList */
#include "WorldData.h" /* WorldData_GetRoom */
#include "Room.h" /* Room_GetItemList, Room_SetDescription */
#include "ItemList.h" /* ItemList_FindItem, ItemList_Remove, ItemList_Add */
#include "Item.h" /* Item_Create */

void Engine_Take(CommandContext context, GameState* gameState, WorldData* worldData)
{
	UNREFERENCED_PARAMETER(context);
	UNREFERENCED_PARAMETER(gameState);
	UNREFERENCED_PARAMETER(worldData);

	printf("You pick up the Engine. It was no match for your Hunkiness.\n");
}

/* Build a "Cover" object */
Item* Engine_Build()
{
	return Item_Create("engine", "A very powerful Engine from the best inventor from this Era. It will perfectly suit you and your Hunkiness.", true, NULL, Engine_Take, NULL);
}