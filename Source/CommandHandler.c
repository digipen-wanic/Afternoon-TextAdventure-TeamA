/******************************************************************************
filename    CommandHandler.c
author      Matthew Picioccio
DP email    mattpic@digipen.edu
course      GAM100 ** Do not use this code in your team project

Brief Description:
This file implements the command handler, parsing commands and executing functions.

******************************************************************************/
#include "stdafx.h" /* NULL */
#include "CommandHandler.h" /* Function declarations */
#include "CommandData.h" /* struct CommandData */
#include "CommandList.h" /* struct CommandList and CommandList_Find */


/* Handles the command data and executes it against the game and world state */
void HandleCommand(CommandData* command, GameState* gameState, WorldData* worldData)
{
	CommandFunc commandFunc; /* The command function to be executed for the given verb */

	/* safety check of parameters */
	if ((command == NULL) || (gameState == NULL) || (worldData == NULL)) 
	{
		return; /* take no action if the parameters are invalid */
	}

	/* check if the command's verb is valid for searching */
	if (command->verb == NULL)
	{
		printf("Your command was not recognized.\n");
		return;
	}

	/* find the command function for the given verb*/
	commandFunc = CommandList_Find(command->commandList, command->verb);

	/* check if the command function was found */
	if (commandFunc == NULL)
	{
		printf("Your command \"%s\" was not recognized.\n", command->verb);
		return; /* take no action if the command function wasn't found */
	}

	/* execute the command function */
	commandFunc(command, gameState, worldData);
}