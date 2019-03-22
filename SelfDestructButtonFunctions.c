/******************************************************************************
filename   SelfDestructButtonFunctions.c
author      Christian Yan
DP email    c.yan@digipen.edu

Brief Description:
This file defines the functions to create a specific item, the "SelfDestructButton".

******************************************************************************/
#include "stdafx.h" /* UNREFERENCED_PARAMETER, NULL*/
#include "EscapePodButtonFunctions.h" /* Function declarations */
#include "GameState.h" /* struct GameState, GameState_ChangeScore */
#include "GameFlags.h" /* GameFlags_IsInList */
#include "WorldData.h" /* WorldData_GetRoom */
#include "Room.h" /* Room_GetItemList, Room_SetDescription */
#include "ItemList.h" /* ItemList_FindItem, ItemList_Remove, ItemList_Add */
#include "Item.h" /* Item_Create */

void SelfDestructButton_Use(CommandContext context, GameState* gameState, WorldData* worldData)
{
	UNREFERENCED_PARAMETER(context);
	UNREFERENCED_PARAMETER(gameState);
	UNREFERENCED_PARAMETER(worldData);

	printf("You Pressed the Button. The ship Blows up. This is the end of you and your Hunkiness. Hopefully you will have a successor who has more Hunkiness then you have…\n");
}

/* Build a "brick" object */
Item* SelfDestructButton_Build()
{
	return Item_Create("escapepodbutton", "The Self-Destruct Button for the ship. Best not to press the button while your still on board the ship, or that will be the end of you and your Hunkiness.", false, SelfDestructButton_Use, NULL, NULL);
}
