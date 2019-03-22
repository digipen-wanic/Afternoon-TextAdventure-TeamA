/******************************************************************************
filename    CandyFunctions.c
author      Nico Hickman
DP email    nicholas.hickman@digipen.edu

Brief Description:
This file defines the functions to create a specific item, the "candy".

******************************************************************************/
#include "stdafx.h" /* UNREFERENCED_PARAMETER, NULL*/
#include "PlaneFunctions.h" /* Function declarations */
#include "GameState.h" /* struct GameState, GameState_ChangeScore */
#include "GameFlags.h" /* GameFlags_IsInList */
#include "WorldData.h" /* WorldData_GetRoom */
#include "Room.h" /* Room_GetItemList, Room_SetDescription */
#include "ItemList.h" /* ItemList_FindItem, ItemList_Remove, ItemList_Add */
#include "Item.h" /* Item_Create */

void Plane_Assemble(CommandContext context, GameState* gameState, WorldData* worldData)
{
	UNREFERENCED_PARAMETER(context);
	UNREFERENCED_PARAMETER(gameState);
	UNREFERENCED_PARAMETER(worldData);
	ItemList* i = gameState->inventory;
	Room* current = WorldData_GetRoom(worldData, gameState->currentRoomIndex);
	Item* hostileOrphan = ItemList_FindItem(*Room_GetItemList(current), "hostileOrphan");
		if (gameState->currentRoomIndex == 10) {
			if (GameFlags_IsInList(gameState->gameFlags, "hatchOpen")) {
				if (hostileOrphan == NULL) {
					if (ItemList_FindItem(i, "propeller") != NULL && ItemList_FindItem(i, "wheel") != NULL &&ItemList_FindItem(i, "engine")) {
						printf("TODO");
					}
					else {
						printf("TODO");
					}
				}
				else {
					printf("TODO");
				}
			}
			else {
				printf("TODO");
			}
		}
		else {

			printf("TODO: Candy Take Description\n");
		}
}
/* Build a "brick" object */
Item* Plane_Build()
{
	Item* plane = 
	 Item_Create("plane", "TODO: Candy Description", false,NULL,NULL,NULL);
	Item_SetAssembleFunc(plane, Plane_Assemble);
	return plane;
}