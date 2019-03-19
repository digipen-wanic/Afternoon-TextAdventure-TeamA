/******************************************************************************
filename    InventoryCommandHandler.c
author      Matthew Picioccio
DP email    mattpic@digipen.edu
course      GAM100 ** Do not use this code in your team project

Brief Description:
This file defines functions that handle the "inventory" user command, which outputs
a list of the items in the player's inventory.

******************************************************************************/
#include "stdafx.h"
#include "InventoryCommandHandler.h"
#include "GameState.h"
#include "ItemList.h"


/* Handles the "inventory" command, which outputs a list of the items in the player's inventory */
void HandleInventoryCommand(CommandData *command, GameState* gameState, WorldData* worldData)
{
	/* avoid W4 warnings on unused parameters - this function conforms to a function typedef */
	UNREFERENCED_PARAMETER(command);
	UNREFERENCED_PARAMETER(worldData);

	/* safety check on parameters */
	if ((gameState == NULL) || (gameState->inventory == NULL))
	{
		/* The user has no effective inventory - output this result */
		printf("Your inventory is empty.\n");
		return;
	}

	/* print the inventory ItemList */
	printf("Your inventory contains: ");
	ItemList_Print(gameState->inventory);
	printf(".\n");
}