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
#include "AssembleCommandHandler.h" /* Function declarations */
#include "CommandData.h" /* struct CommandData, CommandContext */
#include "GameState.h" /* struct GameState */
#include "WorldData.h" /* WorldData_GetRoom */
#include "Room.h" /* Room_GetItemList */
#include "ItemList.h" /* ItemList_FindItem */
#include "Item.h" /* ItemFunc, Item_GetUseFunc */

/* Handles the "use" command, which calls an item-specific function on a given item */
void HandleAssembleCommand(CommandData* command, GameState* gameState, WorldData* worldData)
{
	Item* assembling; /* the item to be used */
	assembling = ItemList_FindItem(*Room_GetItemList(WorldData_GetRoom(worldData, gameState->currentRoomIndex)), command->noun);
	if (assembling != NULL) {
		ItemFunc assembleFunc = Item_GetAssembleFunc(assembling);
		if (assembleFunc != NULL) {
			assembleFunc(CommandContext_User, gameState, worldData);
		}

		else {
			printf("You can't assemble a %s!", command->noun);
		}
	}
	else {
		printf("You don't see a %s to assemble!", command->noun);
	}


}