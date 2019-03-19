/******************************************************************************
filename    RoomExit.h
author      Matthew Picioccio
DP email    mattpic@digipen.edu
course      GAM100 ** Do not use this code in your team project

Brief Description:
This file declares the RoomExit interface, which is used to manage room exits
in the game.

******************************************************************************/
#pragma once
#include "stdafx.h" /* bool */


/* Forward declaration for the RoomExit type */
typedef struct RoomExit RoomExit;


/* Adds an exit to a given list, which might be NULL (an empty list).  Returns the new head of the list */
RoomExit* RoomExit_Add(RoomExit* existingList, const char* direction, int nextRoomIndex, bool showInHelp);

/* Free the memory associated with a linked list of RoomExits */
void RoomExit_Free(RoomExit** roomExitListPtr);

/* Find the next room index associated with a given direction */
bool RoomExit_Find(RoomExit* roomExitList, const char* direction, int* outNextRoomIndex);

/* Print the list of exits to standard output */
void RoomExit_Print(RoomExit* roomExitList);