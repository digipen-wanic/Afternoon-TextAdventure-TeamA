/******************************************************************************
filename    GameFlags.c
author      Matthew Picioccio
DP email    mattpic@digipen.edu
course      GAM100 ** Do not use this code in your team project

Brief Description:
This file defines the GameFlags interface, which is used to set and read
arbitrary game state.

******************************************************************************/
#include "stdafx.h" /* NULL, malloc/free, strcpy_s, strcmp */
#include "GameFlags.h" /* Function declarations */

/* The maximum length of a game flag */
#define MAX_GAME_FLAG_LENGTH 32


/* A linked list of game flags */
typedef struct GameFlags
{
	/* The name of the flag */
	char flag[MAX_GAME_FLAG_LENGTH];

	/* A pointer to the next flag in the list */
	GameFlags* next;
} GameFlags;


/* Adds a flag to the set (or, ensure that it is in the list) */
GameFlags* GameFlags_Add(GameFlags* gameFlags, const char* flag)
{
	GameFlags *newGameFlags; /* The new flags object returned */

	/* safety check of parameters */
	if (flag == NULL)
	{
		return gameFlags; /* take no action and return the existing list */
	}
	
	/* if the flag is already in the list, return the existing list */
	if (GameFlags_IsInList(gameFlags, flag))
	{
		return gameFlags; 
	}

	/* create a new GameFlags object */
	newGameFlags = (GameFlags*)malloc(sizeof(GameFlags));
	if (newGameFlags == NULL)
	{
		return NULL; /* malloc can fail! */
	}

	/* copy the flag string into the new object */
	strcpy_s(newGameFlags->flag, MAX_GAME_FLAG_LENGTH, flag);

	/* set the existing list as the "next" parameter */
	newGameFlags->next = gameFlags;

#ifdef _DEBUG
	/* In debug mode, print output that the user has set a flag */
	printf("\nDEBUG: adding game flag: %s\n", flag);
#endif

	/* return the new object as the new head of the list */
	return newGameFlags;
}

/* Removes a flag from the set (or, ensures it is not in the list */
GameFlags* GameFlags_Remove(GameFlags* gameFlags, const char* flag)
{
	GameFlags* result; /* the resulting GameFlags object from this call*/

	/* safety check the parameters (also terminates recursion) */
	if ((gameFlags == NULL) || (flag == NULL))
	{
		return gameFlags; /* if the parameters are not provided, return the specified list (could be NULL) */
	}

	/* check if this flag is the one we're looking for */
	if (strcmp(gameFlags->flag, flag) == 0)
	{
		/* this is the flag we're looking for - return the "next" pointer so it will be reassigned */
		result = gameFlags->next;
		/* free this object */
		free(gameFlags);
#ifdef _DEBUG
		/* In debug mode, print output that the user has removed a flag */
		printf("\nDEBUG: removing game flag: %s\n\n", flag);
#endif
	}
	else
	{
		/* this isn't the flag we're looking for - return this object, so it'll be assigned again */
		result = gameFlags;
		/* recurse to the next flag in the list (may be NULL) */
		gameFlags->next = GameFlags_Remove(gameFlags->next, flag);
	}

	/* return the list without the flag */
	return result;
}

/* Frees the memory associated with the game flags */
void GameFlags_Free(GameFlags** gameFlagsPtr)
{
	/* safety check the parameters (also terminates recursion) */
	if ((gameFlagsPtr == NULL) || (*gameFlagsPtr == NULL)) 
	{
		return; /* take no action if the parameters are invalid */
	}

	/* free the next flag in the list */
	GameFlags_Free(&(*gameFlagsPtr)->next);

	/* free this flag object */
	free(*gameFlagsPtr);

	/* assign the incoming pointer to NULL */
	*gameFlagsPtr = NULL;
}

/* Returns true if the flag is in the list */
bool GameFlags_IsInList(GameFlags* gameFlags, const char* flag)
{
	/* safety check the parameters (also terminates recursion) */
	if ((gameFlags == NULL) || (flag == NULL)) 
	{
		return false; /* if the parameters are invalid, it's the same as not finding the flag */
	}

	/* check if this is the flag we're looking for */
	if (strcmp(gameFlags->flag, flag) == 0) 
	{
		return true; /* it is!  we're done */
	}

	/* check the next flag in the list */
	return GameFlags_IsInList(gameFlags->next, flag);
}