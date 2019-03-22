/******************************************************************************
filename    StorageRoomDoor.c
author      Nico Hickman
DP email    nicholas.hickman@digipen.edu

Brief Description:
This file defines the functions to create a specific item, the "candy".

******************************************************************************/
#include "stdafx.h" /* UNREFERENCED_PARAMETER, NULL*/
#include "StorageRoomDoor.h" /* Function declarations */
#include "GameState.h" /* struct GameState, GameState_ChangeScore */
#include "GameFlags.h" /* GameFlags_IsInList */
#include "WorldData.h" /* WorldData_GetRoom */
#include "Room.h" /* Room_GetItemList, Room_SetDescription */
#include "ItemList.h" /* ItemList_FindItem, ItemList_Remove, ItemList_Add */
#include "Item.h" /* Item_Create */

void SRDoor_Use(CommandContext context, GameState* gameState, WorldData* worldData)
{
	UNREFERENCED_PARAMETER(context);
	UNREFERENCED_PARAMETER(gameState);
	UNREFERENCED_PARAMETER(worldData);

	if (GameFlags_IsInList(gameState->gameFlags, "srdoorOpen")) {
		gameState->currentRoomIndex = 4;
		printf("TODO: Move storage");
		Room* currentRoom = WorldData_GetRoom(worldData, gameState->currentRoomIndex);
		Room_Print(currentRoom);
	}
	else {
		printf("TODO: NOT OPEN\n");
	}
}

/* Build a "brick" object */
Item* SRDoor_Build()
{
	return Item_Create("srdoor", "TODO: Candy Description", false, SRDoor_Use, NULL, NULL);
}