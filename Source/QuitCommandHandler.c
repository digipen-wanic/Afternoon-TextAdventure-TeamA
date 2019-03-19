/******************************************************************************
filename    QuitCommandHandler.c
author      Matthew Picioccio
DP email    mattpic@digipen.edu
course      GAM100 ** Do not use this code in your team project

Brief Description:
This file defines functions that handle the "quit" user command, which
immediately exits the game.

******************************************************************************/
#include "stdafx.h" /* NULL */
#include "QuitCommandHandler.h" /* Function declarations */
#include "GameState.h" /* GameState_EndGame */


/* Handles the "quit" command, which immediately exits the game */
void HandleQuitCommand(CommandData* command, GameState* gameState, WorldData* worldData)
{
	/* avoid W4 warnings on unused parameters - this function conforms to a function typedef */
	UNREFERENCED_PARAMETER(command);
	UNREFERENCED_PARAMETER(worldData);

	/* safety check on the parameters */
	if (gameState == NULL) 
	{
		return; /* the parameters are invalid - take no action */
	}

	/* end the game using a generic exit message */
	GameState_EndGame(gameState, "You have quit the game.\n");
}