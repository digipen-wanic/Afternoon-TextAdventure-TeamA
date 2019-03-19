/******************************************************************************
filename    ItemList.h
author      Matthew Picioccio
DP email    mattpic@digipen.edu
course      GAM100 ** Do not use this code in your team project

Brief Description:
This file declares the ItemList interface, which is used to manage lists of
items in the game.

******************************************************************************/
#pragma once

typedef struct Item Item;


/* Forward declaration for the ItemList type */
typedef struct ItemList ItemList;


/* Adds an item to a given list, which might be NULL (an empty list).  Returns the new head of the list */
ItemList* ItemList_Add(ItemList* itemList, Item* item);

/* Adds an item and modifies the input list */
void ItemList_AddItem(ItemList** itemList, Item* item);

/* Removes an item from a given list.  Returns the new head of the list */
ItemList* ItemList_Remove(ItemList* itemList, Item* item);

/* Frees the memory associated with an ItemList chain and its included items */
void ItemList_Free(ItemList** itemListPtr);

/* Find the item associated with a given name */
Item* ItemList_FindItem(ItemList* itemList, const char* itemName);

/* Print the items in the list to standard output */
void ItemList_Print(ItemList* itemList);