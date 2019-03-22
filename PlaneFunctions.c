/******************************************************************************
filename    PlaneFunctions.c
author      Nico Hickman
edited by  Hunter Bradley
DP email    nicholas.hickman@digipen.edu

Brief Description:
This file defines the functions to create a specific item, the "Plane". This also has the descriptions for when building the plane.

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
					if (ItemList_FindItem(i, "propeller") != NULL && ItemList_FindItem(i, "wheel") != NULL &&ItemList_FindItem(i, "engine")) 
					{
						printf("With all the parts, you fix up the broken Escape plane, and are ready to take your leave.\n");
					}
					else {
						printf("You are still missing something to assemble the plane.\n");
					}
				}
				else {
					printf("Toby Blocks the way to the Escape plane. He will not let you pass.\n");
				}
			}
			else {
				printf("You cannot assemble the plane at this moment. The plane will melt in the presents of your Hunkiness.\n");
			}
		}
		else {

			printf("Saddly, the Airship is beyond Repair, even with your Hunkiness. You will have to use this on something else.\n");
		}
}
/* Build a "Plane" object */
Item* Plane_Build()
{
	Item* plane = 
	 Item_Create("plane", "An Escape Plane, Perfect for you and your Hunkiness to escape on.", false,NULL,NULL,NULL);
	Item_SetAssembleFunc(plane, Plane_Assemble);
	return plane;
}