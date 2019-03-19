/******************************************************************************
filename    GoldPieceFunctions.c
author      Matthew Picioccio
DP email    mattpic@digipen.edu
course      GAM100 ** Do not use this code in your team project

Brief Description:
This file defines the functions to create a specific item, the "gold piece".

******************************************************************************/
#include "stdafx.h"
#include "GoldPieceFunctions.h"
#include "GameState.h"
#include "GameFlags.h"
#include "Item.h"

typedef struct WorldData WorldData;


/* Helper: The action performed when the gold piece is taken. */
void GoldPiece_Take(CommandContext context, GameState* gameState, WorldData* worldData)
{
	/* avoid W4 warnings on unused parameters - this function conforms to a function typedef */
	UNREFERENCED_PARAMETER(context);
	UNREFERENCED_PARAMETER(worldData);

	/* safety check on the parameters */
	if (gameState == NULL)
	{
		return; /* take no action if the parameters are invalid */
	}

	/* check if the gold piece has already been scored */
	if (!GameFlags_IsInList(gameState->gameFlags, "goldPieceScored"))
	{
		/* tell the user that something cool happens when they pick up the gold piece */
		printf("The gold piece burns in your hand.  You're rich!\n");
		/* add to the user's score */
		GameState_ChangeScore(gameState, 5);
		/* the gold piece has not been scored, so mark the flag */
		gameState->gameFlags = GameFlags_Add(gameState->gameFlags, "goldPieceScored");
	}
}


/* Build a "gold piece" object */
Item* GoldPiece_Build()
{
	/* Create a "gold piece" item, using the functions defined in this file */
	return Item_Create("gold piece", "A small piece of gold\n", true, NULL, GoldPiece_Take, NULL);
}