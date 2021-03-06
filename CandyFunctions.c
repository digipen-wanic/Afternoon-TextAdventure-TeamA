/******************************************************************************
filename    CandyFunctions.c
author      Nico Hickman
edited by  Hunter Bradley
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
			printf("You Throw the candy. Toby Lunges after the candy out of the Hanger door. You are free to fix the escape plane now.");
			Room* current = WorldData_GetRoom(worldData, 10);
			ItemList_Remove(*Room_GetItemList(current), ItemList_FindItem(*Room_GetItemList(current), "hostileOrphan"));
		}
		else {
			printf("Toby lunges at you. The rest is a blur as the small orphan tackles you out of the Open hanger. You and your Hunkiness don�t survive. ");
		}
		
	}
	else {
		printf("Your Hunkiness is above eating this Candy.");
	}
}

/* Build a "Candy" object */
Item* Candy_Build()
{
	Item* candy = Item_Create("candy", "A handful of candy with a note attached to it saying: 'This is the Property of Orphan General Toby, DO NOT TOUCH!'.", true, Candy_Use, Candy_Take, NULL);
	Item_SetThrowFunc(candy, Candy_Use);
	return candy;
}