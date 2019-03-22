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

void Candy_Use(CommandContext context, GameState* gameState, WorldData* worldData) {
	UNREFERENCED_PARAMETER(context);
	UNREFERENCED_PARAMETER(gameState);
	UNREFERENCED_PARAMETER(worldData);
	if (gameState->currentRoomIndex == 10) {
		if (GameFlags_IsInList(gameState->gameFlags, "hatchOpen")) {
			printf("TODO: Candy Use");
			Room* current = WorldData_GetRoom(worldData, 10);
			ItemList_Remove(*Room_GetItemList(current), ItemList_FindItem(*Room_GetItemList(current), "hostileOrphan"));
		}
		else {
			printf("TODO: Hatch not Open");
		}
		
	}
	else {
		printf("TODO: Not in right room");
	}
}

/* Build a "brick" object */
Item* Candy_Build()
{
	Item* candy = Item_Create("candy", "A handful of candy with a note attached to it saying: 'This is the Property of Orphan General Toby, DO NOT TOUCH!'.", true, Candy_Use, Candy_Take, NULL);
	Item_SetThrowFunc(candy, Candy_Use);
	return candy;
}