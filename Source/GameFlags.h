/******************************************************************************
filename    GameFlags.h
author      Matthew Picioccio
DP email    mattpic@digipen.edu
course      GAM100 ** Do not use this code in your team project

Brief Description:
This file declares the GameFlags interface, which is used to set and read 
arbitrary game state.

The mutator functions return the new effective pointer, which combines the
existing-list and new-list scenarios.  The trade-off is that the caller
must usually reassign the existing variable to the return value.

******************************************************************************/
#pragma once

/* Forward declaration of the GameFlags type */
typedef struct GameFlags GameFlags;

/* Adds a flag to the set (or, ensure that it is in the list) */
GameFlags* GameFlags_Add(GameFlags* gameFlags, const char* flag);

/* Removes a flag from the set (or, ensures it is not in the list */
GameFlags* GameFlags_Remove(GameFlags* gameFlags, const char* flag);

/* Frees the memory associated with the game flags */
void GameFlags_Free(GameFlags** gameFlagsPtr);

/* Returns true if the flag is in the list */
bool GameFlags_IsInList(GameFlags* gameFlags, const char* flag);