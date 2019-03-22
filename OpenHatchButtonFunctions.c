/******************************************************************************
filename    OpenHatchButtonFunctions.c
author      Christian Yan
DP email    c.yan@digipen.edu

Brief Description:
This file defines the functions to create a specific item, the "OpenHatch".

******************************************************************************/
#include "stdafx.h" /* UNREFERENCED_PARAMETER, NULL*/
#include "OpenHatchButtonFunctions.h" /* Function declarations */
#include "GameState.h" /* struct GameState, GameState_ChangeScore */
#include "GameFlags.h" /* GameFlags_IsInList */
#include "WorldData.h" /* WorldData_GetRoom */
#include "Room.h" /* Room_GetItemList, Room_SetDescription */
#include "ItemList.h" /* ItemList_FindItem, ItemList_Remove, ItemList_Add */
#include "Item.h" /* Item_Create */

void OpenHatchButton_Use(CommandContext context, GameState* gameState, WorldData* worldData)
{
	UNREFERENCED_PARAMETER(context);
	UNREFERENCED_PARAMETER(gameState);
	UNREFERENCED_PARAMETER(worldData);

	printf("You Pressed the Button. You can hear the Hatch Doors Opening in the Distance.\n");
	Room_SetDescription(room, "The Escape Plane Hatch. You can see the open sea from here, as well as metal parts from the ship that are falling into the sea.");
}

/* Build a "brick" object */
Item* OpenHatchButton_Build()
{
	return Item_Create("openhatch", "The Button to open the Hatch doors. This is the Button you need to press to escape with your Hunkiness.", false, OpenHatchButton_Use, NULL, NULL);
}
