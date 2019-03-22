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
#include "TalkCommandHandler.h" /* Function declarations */
#include "CommandData.h" /* struct CommandData, CommandContext */
#include "GameState.h" /* struct GameState */
#include "WorldData.h" /* WorldData_GetRoom */
#include "Room.h" /* Room_GetItemList */
#include "ItemList.h" /* ItemList_FindItem */
#include "Item.h" /* ItemFunc, Item_GetUseFunc */

/* Handles the "use" command, which calls an item-specific function on a given item */
void HandleTalkCommand(CommandData* command, GameState* gameState, WorldData* worldData)
{
	Item* talkingTo; /* the item to be used */
	Room* room; /* the current room */
	ItemFunc talkFunc; /* The function to be called for the given item when it is used */
	room = WorldData_GetRoom(worldData, gameState->currentRoomIndex);

													 /* safety check on the parameters */
	if ((command == NULL) || (command->noun == NULL) || (gameState == NULL) || (worldData == NULL))
	{
		return;  /* take no action if the parameters are invalid */
	}
	talkingTo = ItemList_FindItem(*Room_GetItemList(room), command->noun);

	if (talkingTo != NULL)
	{
		talkFunc = Item_GetTalkFunc(talkingTo);
		if (talkFunc == NULL) {
			printf("You cannot talk to a %s", command->noun);
			return;
		}
		else {
			talkFunc(CommandContext_User, gameState, worldData);
		}
	}
	else {
		printf("You don't see a %s here.", command->noun);
		return;
	}

}