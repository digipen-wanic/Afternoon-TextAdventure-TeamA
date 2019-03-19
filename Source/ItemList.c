/******************************************************************************
filename    ItemList.c
author      Matthew Picioccio
DP email    mattpic@digipen.edu
course      GAM100 ** Do not use this code in your team project

Brief Description:
This file defines the ItemList interface, which is used to manage lists of
items in the game.

******************************************************************************/
#include "stdafx.h" /* NULL, malloc/free, printf, strcmp, */
#include "ItemList.h" /* Function declarations */
#include "Item.h" /* Item_Free, Item_GetName */


/* A linked list of items */
typedef struct ItemList
{
	Item* item; /* The item referred to by this linked-list node */
	ItemList* next; /* The next node in the list */
} ItemList;


/* Helper: Retrieve the number of items in the list */
unsigned int ItemList_GetCount(ItemList* itemList);

/* Helper: Determine if the item is in the given list */
bool ItemList_IsInList(ItemList* itemList, Item* item);


/* Adds an item to a given list, which might be NULL (an empty list).  Returns the new head of the list */
ItemList* ItemList_Add(ItemList* itemList, Item* item)
{
	ItemList* newItemList; /* the new node in the list */

	/* safety check on the parameters */
	if ((item == NULL) || ItemList_IsInList(itemList, item)) 
	{
		/* return the current list if the parameters are invalid or if the item is already in the list */
		return itemList;
	}

	/* create the new list node */
	newItemList = (ItemList*)malloc(sizeof(ItemList));
	if (newItemList == NULL)
	{
		return NULL; /* malloc can fail! */
	}

	/* copy the item parameter to the new node */
	newItemList->item = item;

	/* assign the old "head" as the next node */
	newItemList->next = itemList;

	/* return the new node as the new head */
	return newItemList;
}

/* Adds an item in place to a given list, which might be NULL (an empty list).  Returns the new head of the list */
void ItemList_AddItem(ItemList** itemList, Item* item)
{
	ItemList* newItemList; /* the new node in the list */

						   /* safety check on the parameters */
	if ((item == NULL) || ItemList_IsInList(*itemList, item))
	{
		/* return the current list if the parameters are invalid or if the item is already in the list */
		return;
	}

	/* create the new list node */
	newItemList = (ItemList*)malloc(sizeof(ItemList));
	if (newItemList == NULL)
	{
		return; /* malloc can fail! */
	}

	/* copy the item parameter to the new node */
	newItemList->item = item;

	/* assign the old "head" as the next node */
	newItemList->next = *itemList;

	/* return the new node as the new head */
	*itemList = newItemList;
}

/* Removes an item from a given list.  Returns the new head of the list */
ItemList* ItemList_Remove(ItemList* itemList, Item* item)
{
	ItemList* result; /* The resulting head of the REMAINING list*/

	/* safety check on the parameters (also terminates recursion) */
	if ((itemList == NULL) || (item == NULL)) 
	{
		return itemList;  /* if the parameters are invalid, return the existing list (terminates recursion) */
	}

	/* if the desired item is the current item, remove it */
	if (itemList->item == item)
	{
		/* return the "next" item as the new head of the REMAINING list */
		result = itemList->next;
		/* free the node, but not the item! */
		free(itemList);
	}
	else
	{
		/* return the current item as the head of the REMAINING list */
		result = itemList;
		/* recurse to the next item in the list, and assign the result back as the new "next" object */
		itemList->next = ItemList_Remove(itemList->next, item);
	}

	/* return the resulting head of the REMAINING list */
	return result;
}


/* Frees the memory associated with an ItemList chain and its included items */
void ItemList_Free(ItemList** itemListPtr)
{
	/* safety check on the parameters (terminates recursion) */
	if ((itemListPtr == NULL) || (*itemListPtr == NULL)) 
	{
		return; /* take no action if the parameters are invalid (terminates recursion) */
	}

	/* Free the remaining items in the list */
	ItemList_Free(&(*itemListPtr)->next);

	/* Free the item associated with this node */
	Item_Free(&(*itemListPtr)->item);

	/* Free the node memory */
	free(*itemListPtr);

	/* Clear the pointer to the current node */
	*itemListPtr = NULL;
}


/* Find the item associated with a given name */
Item* ItemList_FindItem(ItemList* itemList, const char* itemName)
{
	const char* checkName; /* the item name we're comparing to the parameter*/

	/* safety check on the parameters (also terminates recursion) */
	if ((itemList == NULL) || (itemName == NULL)) 
	{
		return NULL;  /* return a NULL result if the parameters are invalid (terminates recursion) */
	}

	/* get the name of the current node's item for comparison */
	checkName = Item_GetName(itemList->item);

	/* if the name matches the parameter, then return it */
	if ((checkName != NULL) && (strcmp(checkName, itemName) == 0))
	{
		return itemList->item; 
	}

	/* search the remainder of the list */
	return ItemList_FindItem(itemList->next, itemName);
}


/* Print the items in the list to standard output */
void ItemList_Print(ItemList* itemList)
{
	unsigned int count; /* the number of items in the list */
	unsigned int itemIndex; /* the index of the printed item list */
	ItemList* printingList; /* the remainder of the list to print */
	const char* itemName; /* the name of the item to print */

	/* get the number of items in the provided list */
	count = ItemList_GetCount(itemList);
	if (count == 0) 
	{
		return; /* there are no items in the list - take no action */
	}

	/* start at the beginning of the list */
	itemIndex = 0;
	printingList = itemList;

	/* iterate through the list until we run out of nodes */
	while (printingList != NULL)
	{
		/* get the name of the current item */
		itemName = Item_GetName(printingList->item);
		if (itemName != NULL)
		{
			/* if the item is not the first one, print some list material before the name */
			if (itemIndex > 0)
			{
				/* print a comma, unless there are only two items in the list - "a, b, and c" vs. "a and b" */
				printf((count > 2) ? ", " : " ");
				/* print "and" if we're at the end of the list */
				if (itemIndex == count - 1)
				{
					printf("and ");
				}
			}
			/* print the item name */
			printf(itemName);
			/* update the number of printed items */
			++itemIndex;
		}
		/* go to the next item in the list */
		printingList = printingList->next;
	}
}


/* Helper: Retrieve the number of items in the list */
unsigned int ItemList_GetCount(ItemList* itemList)
{
	/* if the provided list is NULL, then there are zero items in (terminates recursion) */
	if (itemList == NULL)
	{
		return 0;
	}

	/* add one to the total provided by the value of this function called on the remainder of the list */
	return 1 + ItemList_GetCount(itemList->next);
}


/* Helper: Determine if the item is in the given list */
bool ItemList_IsInList(ItemList* itemList, Item* item)
{
	/* safety check on the parameters (also terminates recursion) */
	if ((itemList == NULL) || (item == NULL)) 
	{
		return false; /* the item couldn't be found with invalid parameters , so return false (terminates recursion) */
	}

	/* if the current item is the desired one, we're done */
	if (itemList->item == item) 
	{
		return true; 
	}

	/* search the remainder of the list */
	return ItemList_IsInList(itemList->next, item);
}