/******************************************************************************
filename    Item.h
author      Matthew Picioccio
DP email    mattpic@digipen.edu
course      GAM100 ** Do not use this code in your team project

Brief Description:
This file declares the Item interface, which is used to manage items in the game.

******************************************************************************/
#pragma once
#include "stdafx.h" /* bool */
#include "CommandContext.h" /* enum CommandContext */

typedef struct GameState GameState;
typedef struct WorldData WorldData;


/* Forward declaration for the Item type */
typedef struct Item Item;

/* The function pointer type for item-operation functions */
typedef void(*ItemFunc)(CommandContext context, GameState* gameState, WorldData* worldData);


/* Create a new Item object with the provided data */
Item* Item_Create(const char* name, const char* description, bool isCarryable, ItemFunc useFunc, ItemFunc takeFunc, ItemFunc dropFunc);

/* Free the memory associated with a given Item object */
void Item_Free(Item** itemPtr);

/* Retrieve the name of the given item */
const char* Item_GetName(Item* item);

/* Retrieve the description of the given item */
const char* Item_GetDescription(Item* item);

/* Retrieve whether the item is carryable */
bool Item_IsCarryable(Item* item);

/* Retrieve the "use" function for this item, if any */
ItemFunc Item_GetUseFunc(Item* item);

/* Retrieve the "take" function for this item, if any */
ItemFunc Item_GetTakeFunc(Item* item);

/* Retrieve the "drop" function for this item, if any */
ItemFunc Item_GetDropFunc(Item* item);

/* Print a description of the item to standard output */
void Item_Print(Item* item);