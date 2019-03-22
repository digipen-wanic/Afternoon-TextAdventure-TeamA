/******************************************************************************
filename   EscapePodButtonFunctions.c
author      Christian Yan
DP email    c.yan@digipen.edu

Brief Description:
This file defines the functions to create a specific item, the "EscapePodButton".

******************************************************************************/
#include "stdafx.h" /* UNREFERENCED_PARAMETER, NULL*/
#include "EscapePodButtonFunctions.h" /* Function declarations */
#include "GameState.h" /* struct GameState, GameState_ChangeScore */
#include "GameFlags.h" /* GameFlags_IsInList */
#include "WorldData.h" /* WorldData_GetRoom */
#include "Room.h" /* Room_GetItemList, Room_SetDescription */
#include "ItemList.h" /* ItemList_FindItem, ItemList_Remove, ItemList_Add */
#include "Item.h" /* Item_Create */

void EscapePodButton_Use(CommandContext context, GameState* gameState, WorldData* worldData)
{
	UNREFERENCED_PARAMETER(context);
	UNREFERENCED_PARAMETER(gameState);
	UNREFERENCED_PARAMETER(worldData);

	printf("You Pressed the Button. You can hear the screaming of Orphans as Escape pods drop from the sky. No Orphans have been saved with those escape pods.\n");
}

/* Build a "brick" object */
Item* EscapePodButton_Build()
{
	return Item_Create("escapepodbutton", "The Escape Pod Button. You see no use for the Escape Pods, seeing as they can not contain your Hunkiness.", false, EscapePodButton_Use, NULL, NULL);
}
