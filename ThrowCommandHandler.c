/******************************************************************************
filename    TalkCommandHandler.c
author      Matthew Picioccio
DP email    mattpic@digipen.edu
course      GAM100 ** Do not use this code in your team project

Brief Description:
This file defines functions that handle the "use" user command, which calls
an item-specific function on a given item

******************************************************************************/
#include "stdafx.h" /* NULL, printf */
#include "ThrowCommandHandler.h" /* Function declarations */
#include "CommandData.h" /* struct CommandData, CommandContext */
#include "GameState.h" /* struct GameState */
#include "WorldData.h" /* WorldData_GetRoom */
#include "Room.h" /* Room_GetItemList */
#include "ItemList.h" /* ItemList_FindItem */
#include "Item.h" /* ItemFunc, Item_GetUseFunc */

/* Handles the "use" command, which calls an item-specific function on a given item */
void HandleThrowCommand(CommandData* command, GameState* gameState, WorldData* worldData)
{
	Item* throwing; /* the item to be used */
	throwing = ItemList_FindItem(gameState->inventory, command->noun);
	if (throwing != NULL) {
		ItemFunc throwFunc = Item_GetThrowFunc(throwing);
		if (throwFunc != NULL) {
			throwFunc(CommandContext_Item_Inventory, gameState, worldData);
		}
		
		else {
			printf("You can't throw a %s!", command->noun);
		}
	}
	else {
		printf("You don't have a %s to throw!", command->noun);
	}
	

}