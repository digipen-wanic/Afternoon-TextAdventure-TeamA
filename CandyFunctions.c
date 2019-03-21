/******************************************************************************
filename    CandyFunctions.c
author      Nico Hickman
DP email    nicholas.hickman@digipen.edu

Brief Description:
This file defines the functions to create a specific item, the "candy".

******************************************************************************/
#include "stdafx.h" /* UNREFERENCED_PARAMETER, NULL*/
#include "CandyFunctions.h" /* Function declarations */
#include "GameState.h" /* struct GameState, GameState_ChangeScore */
#include "GameFlags.h" /* GameFlags_IsInList */
#include "WorldData.h" /* WorldData_GetRoom */
#include "Room.h" /* Room_GetItemList, Room_SetDescription */
#include "ItemList.h" /* ItemList_FindItem, ItemList_Remove, ItemList_Add */
#include "Item.h" /* Item_Create */

void Candy_Take(CommandContext context, GameState* gameState, WorldData* worldData)
{
	UNREFERENCED_PARAMETER(context);
	UNREFERENCED_PARAMETER(gameState);
	UNREFERENCED_PARAMETER(worldData);

	printf("You pick up the Candy.\n");
}

/* Build a "brick" object */
Item* Candy_Build()
{
	return Item_Create("candy", "A handful of candy with a note attached to it saying: “This is the Property of Orphan General Toby, DO NOT TOUCH!”.", true, NULL, Candy_Take, NULL);
}