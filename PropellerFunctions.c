/******************************************************************************
filename    PropellerFunctions.c
author      Christian Yan
edited by  Hunter Bradley
DP email    c.yan@digipen.edu

Brief Description:
This file defines the functions to create a specific item, the "Propeller".

******************************************************************************/
#include "stdafx.h" /* UNREFERENCED_PARAMETER, NULL*/
#include "PropellerFunctions.h" /* Function declarations */
#include "GameState.h" /* struct GameState, GameState_ChangeScore */
#include "GameFlags.h" /* GameFlags_IsInList */
#include "WorldData.h" /* WorldData_GetRoom */
#include "Room.h" /* Room_GetItemList, Room_SetDescription */
#include "ItemList.h" /* ItemList_FindItem, ItemList_Remove, ItemList_Add */
#include "Item.h" /* Item_Create */

void Propeller_Take(CommandContext context, GameState* gameState, WorldData* worldData)
{
	UNREFERENCED_PARAMETER(context);
	UNREFERENCED_PARAMETER(gameState);
	UNREFERENCED_PARAMETER(worldData);

	printf("You pick up the Propeller. It was no match for your Hunkiness.\n");
}

/* Build a "propeller" object */
Item* Propeller_Build()
{
	return Item_Create("propeller", "A Shiny Silver Propeller, Perfect for a Hunky guy like yourself.", true, NULL, Propeller_Take, NULL);
}
