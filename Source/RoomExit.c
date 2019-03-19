/******************************************************************************
filename    RoomExit.c
author      Matthew Picioccio
DP email    mattpic@digipen.edu
course      GAM100 ** Do not use this code in your team project

Brief Description:
This file defines the RoomExit interface, which is used to manage room exits
in the game.

******************************************************************************/
#include "stdafx.h" /* NULL, printf, malloc/free, strcpy_s, strcmp */
#include "RoomExit.h" /* Function declarations */


/* The maximum length of an exit string */
#define MAX_DIRECTION_LENGTH 32


/* A linked list of exits from a room to another room */
typedef struct RoomExit
{
	char direction[MAX_DIRECTION_LENGTH]; /* The name of the exit, matched to command nouns */
	bool showInHelp;
	int nextRoomIndex; /* The index of the room in the specified direction */
	struct RoomExit* next; /* The next exit in the list */
} RoomExit;


/* Helper: Retrieve the number of exits in the list */
unsigned int RoomExit_GetCountVisible(RoomExit* roomExitList);


/* Adds an exit to a given list, which might be NULL (an empty list).  Returns the new head of the list */
RoomExit* RoomExit_Add(RoomExit* existingList, const char* direction, int nextRoomIndex, bool showInHelp)
{
	RoomExit* existingListSearch; /* the current node when searching through the existing list */
	RoomExit* newRoomExit; /* The new room exit added to the list */

						   /* safety check on the parameters */
	if (direction == NULL)
	{
		return existingList; /* take no action if the parameters are invalid, so return the existing list */
	}

	/* iterate through the room-exit list to see if the specified direction is already in the list */
	existingListSearch = existingList;
	while (existingListSearch != NULL)
	{
		/* if the current exit's direction matches the parameter, then update it  */
		if (strcmp(existingListSearch->direction, direction) == 0)
		{
			existingListSearch->nextRoomIndex = nextRoomIndex;
			return existingList; /* take no further action, so return the existing list */
		}
		/* go to the next exit in the list */
		existingListSearch = existingListSearch->next;
	}

	/* the direction was not in the list - create a new RoomExit object */
	newRoomExit = (RoomExit*)malloc(sizeof(RoomExit));
	if (newRoomExit == NULL)
	{
		return existingList; /* malloc can fail! */
	}

	/* copy the parameter data to the new object */
	strcpy_s(newRoomExit->direction, MAX_DIRECTION_LENGTH, direction);
	newRoomExit->nextRoomIndex = nextRoomIndex;
	newRoomExit->showInHelp = showInHelp;

	/* assign the existing list head as the next node from the new one */
	newRoomExit->next = existingList;

	/* return the new head node */
	return newRoomExit;
}


/* Helper: Free the memory associated with a linked list of RoomExits */
void RoomExit_Free(RoomExit** roomExitPtr)
{
	/* safety check on the parameters (also terminates recursion) */
	if ((roomExitPtr == NULL) || (*roomExitPtr == NULL))
	{
		return; /* take no action if the parameters are invalid (terminates recursion) */
	}

	/* free the rest of the list */
	RoomExit_Free(&(*roomExitPtr)->next);

	/* free the current node */
	free(*roomExitPtr);

	/* clear the given pointer*/
	*roomExitPtr = NULL;
}


/* Find the next room index associated with a given direction */
bool RoomExit_Find(RoomExit* roomExitList, const char* direction, int* outNextRoomIndex)
{
	/* safety check on parameters (also terminates recursion) */
	if ((roomExitList == NULL) || (direction == NULL) || (outNextRoomIndex == NULL))
	{
		return false; /* the search cannot be performed, so the exit was not found (terminates recursion) */
	}

	/* if the current exit is the correct one, then return it */
	/* if the current exit's direction matches the parameter, then we're done */
	if (strcmp(roomExitList->direction, direction) == 0)
	{
		*outNextRoomIndex = roomExitList->nextRoomIndex;
		return true;
	}

	/* this node isn't the right one - search the remainder of the list, and return the result */
	return RoomExit_Find(roomExitList->next, direction, outNextRoomIndex);
}


/* Print the list of exits to standard output */
void RoomExit_Print(RoomExit* roomExitList)
{
	unsigned int numRoomExits; /* the number of exits in the given list*/
	unsigned int roomExitIndex; /* the index of the printed room exit */
	RoomExit* roomExitCurrent; /* the current node in the list being printed */

	/* get the number of items in the provided list */
	numRoomExits = RoomExit_GetCountVisible(roomExitList);
	if (numRoomExits == 0)
	{
		return; /* there are no exits in the list - take no action */
	}

	/* start at the beginning of the list */
	roomExitCurrent = roomExitList;
	roomExitIndex = 0;

	while (roomExitCurrent != NULL)
	{
		/* if the exit isn't supposed to be shown to the user then skip and continue */
		if (!roomExitCurrent->showInHelp)
		{
			/* move to the next item in the list */
			roomExitCurrent = roomExitCurrent->next;
			continue;
		}

		/* if the exit  is not the first one, print some list material before the name */
		if (roomExitIndex > 0)
		{
			/* print a comma, unless there are only two exits in the list - "a, b, and c" vs. "a and b" */
			printf((numRoomExits > 2) ? ", " : " ");

			/* print "and" if we're at the end of the list */
			if (roomExitIndex == numRoomExits - 1)
			{
				printf("and ");
			}
		}
		/* print the exit's direction  */
		printf(roomExitCurrent->direction);
		/* move to the next item in the list */
		++roomExitIndex;
		roomExitCurrent = roomExitCurrent->next;
	}
}


/* Helper: Retrieve the number of RoomExits in the list */
unsigned int RoomExit_GetCountVisible(RoomExit* roomExitList)
{
	/* if the provided list is NULL, then there are zero items in (terminates recursion) */
	if (roomExitList == NULL)
	{
		return 0;
	}

	/* add one to the total provided by the value of this function called on the remainder of the list */
	if (roomExitList->showInHelp)
	{
		return 1 + RoomExit_GetCountVisible(roomExitList->next);
	}
	else
	{
		return RoomExit_GetCountVisible(roomExitList->next);
	}
}