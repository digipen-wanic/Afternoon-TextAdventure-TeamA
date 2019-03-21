/******************************************************************************
filename    WheelFunctions.c
author      Christian Yan
DP email    c.yan@digipen.edu

Brief Description:
This file defines the functions to create a specific item, the "Wheel".

******************************************************************************/
#include "stdafx.h" /* UNREFERENCED_PARAMETER, NULL*/
#include "WheelFunctions.h" /* Function declarations */
#include "GameState.h" /* struct GameState, GameState_ChangeScore */
#include "GameFlags.h" /* GameFlags_IsInList */
#include "WorldData.h" /* WorldData_GetRoom */
#include "Room.h" /* Room_GetItemList, Room_SetDescription */
#include "ItemList.h" /* ItemList_FindItem, ItemList_Remove, ItemList_Add */
#include "Item.h" /* Item_Create */

void Wheel_Take(CommandContext context, GameState* gameState, WorldData* worldData)
{
	UNREFERENCED_PARAMETER(context);
	UNREFERENCED_PARAMETER(gameState);
	UNREFERENCED_PARAMETER(worldData);

	printf("You take the Wheel from the Ship. The Orphans wont be needing it.\n");
}

/* Build a "brick" object */
Item* Wheel_Build()
{
	return Item_Create("wheel", "The Steering wheel for the ship. You figure that the crashing Orphans won’t be needing this to steer the ship to safety…", true, NULL, Wheel_Take, NULL);
}
