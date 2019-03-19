/******************************************************************************
filename    GameState.h
author      Matthew Picioccio
DP email    mattpic@digipen.edu
course      GAM100 ** Do not use this code in your team project

Brief Description:
This file declares the GameState interface, which is used to reflect the user state
in the game.

The mutation functions are recommended because they  provide a consistent 
user experience for operations, though those operations could also be performed 
directly on the object.

******************************************************************************/
#pragma once
#include "stdafx.h" /* bool */

typedef struct ItemList ItemList;
typedef struct GameFlags GameFlags;

/* The user state in the game */
typedef struct GameState
{
	/* the user's score */
	int score;

	/* the user's flags */
	GameFlags* gameFlags;

	/* the user's inventory */
	ItemList* inventory;

	/* The index of the room the user is currently in */
	int currentRoomIndex;

	/* If false, the game is over and should exit */
	bool isRunning;
} GameState;

/* Create an empty game state object */
GameState* GameState_Create();

/* Free the memory associated with a game-state object */
void GameState_Free(GameState** gameStatePtr);

/* Modify the score, with appropriate user information */
void GameState_ChangeScore(GameState* gameState, int modifier);

/* End the game, with appropriate user information */
void GameState_EndGame(GameState* gameState, const char* message);