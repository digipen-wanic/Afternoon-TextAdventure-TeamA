/******************************************************************************
filename    EggFunctions.c
author      Matthew Picioccio
DP email    mattpic@digipen.edu
course      GAM100 ** Do not use this code in your team project

Brief Description:
This file defines the functions to create a specific item, the "egg".

******************************************************************************/
#include "stdafx.h" /* NULL, UNREFERENCED_PARAMETER */
#include "EggFunctions.h" /* Function declarations */
#include "GameState.h" /* struct GameState, GameState_ChangeScore, GameState_EndGame */
#include "GameFlags.h" /* GameFlags_IsInList, GameFlags_Add */
#include "Item.h" /* Item_Create */

typedef struct WorldData WorldData;


/* Helper: The action performed when the egg is taken. */
void Egg_Take(CommandContext context, GameState* gameState, WorldData* worldData)
{
	/* avoid W4 warnings on unused parameters - this function conforms to a function typedef */
	UNREFERENCED_PARAMETER(context);
	UNREFERENCED_PARAMETER(worldData);

	/* safety check on the parameters */
	if (gameState == NULL)
	{
		return; /* take no action if the parameters are invalid */
	}

	/* check if the egg has already been scored */
	if (!GameFlags_IsInList(gameState->gameFlags, "eggScored"))
	{
		/* tell the user that something cool happens when they pick up the egg */
		printf("The fragile egg shines in the dim light as you put it in your pocket.\n");
		/* add to the user's score */
		GameState_ChangeScore(gameState, 25);
		/* the egg has not been scored, so mark the flag */
		gameState->gameFlags = GameFlags_Add(gameState->gameFlags, "eggScored");
	}
}


/* Helper: The action performed when the egg is dropped. */
void Egg_Drop(CommandContext context, GameState* gameState, WorldData* worldData)
{
	/* avoid W4 warnings on unused parameters - this function conforms to a function typedef */
	UNREFERENCED_PARAMETER(context);
	UNREFERENCED_PARAMETER(worldData);

	/* don't drop the egg!  if you do, it shatters and you can't finish the game */
	GameState_EndGame(gameState, "The egg shatters, and you know that you can never leave...\n");

	/* 
	Note: if we wanted to really implement "shattering", we'd remove the egg from the room where it was dropped.
	However, that's not needed, as we quit the game and the user can't look at the room anymore.
	*/
}


/* Build a "egg" object */
Item* Egg_Build()
{
	/* Create a "egg" item, using the functions defined in this file */
	return Item_Create("egg", "The fragile egg is beautiful iridescent green, and it is obviously very valuable.\n", true, NULL, Egg_Take, Egg_Drop);
}