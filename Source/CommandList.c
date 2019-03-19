/******************************************************************************
filename    CommandList.c
author      Matthew Picioccio
DP email    mattpic@digipen.edu
course      GAM100 ** Do not use this code in your team project

Brief Description:
This file implements the CommandList, which holds all supported commands and 
their related functions.

******************************************************************************/
#include "stdafx.h" /* NULL, malloc/free, strcpy_s, printf */
#include "CommandList.h" /* Function and type declarations */
#include "CommandData.h" /* MAX_COMMAND_VERB_LENGTH */


/* A linked list of command definitions, a pair of a string and function */
typedef struct CommandList
{
	/* The command name, usually a verb */
	char commandName[MAX_COMMAND_VERB_LENGTH];

	/* The function to be called for this command */
	CommandFunc commandFunc;

	/* If true, this command will show up in the user-facing help command list */
	bool showInHelp;

	/* The next command definition in the list */
	CommandList* next;
} CommandList;


/* Adds a command definition to a given list, which might be NULL (an empty list).  Returns the new head of the list */
void CommandList_Add(CommandList** commandList, const char* commandName, CommandFunc commandFunc, bool showInHelp)
{
	CommandList* newCommandList; /* the new command list */

	/* safety check on the parameters */
	if ((commandName == NULL) || (commandFunc == NULL)) 
	{
		return; /* take no action and return the passed-in commandList if the command definition is invalid */
	}

	/* create a new CommandList object */
	newCommandList = (CommandList*)malloc(sizeof(CommandList));
	if (newCommandList == NULL)
	{
		return; /* malloc can fail! */
	}

	/* copy the command name from the parameter into the new object */
	strcpy_s(newCommandList->commandName, MAX_COMMAND_VERB_LENGTH, commandName);

	/* copy the function pointer to the new object */
	newCommandList->commandFunc = commandFunc;

	/* set the show-in-help state based on the parameter */
	newCommandList->showInHelp = showInHelp;

	/* assign the previous head of the list as the "next" pointer */
	newCommandList->next = *commandList;

	/* return the new object as the head of the new list */
	*commandList = newCommandList;
}


/* Frees the memory associated with a CommandList chain */
void CommandList_Free(CommandList** commandListPtr)
{
	/* safety check on the parameters (also terminates the recursion) */
	if ((commandListPtr == NULL) || (*commandListPtr == NULL)) 
	{
		return; /* take no action if there is no command list object to free */
	}

	/* recurse to the next object, so the subsequent objects are freed before this one */
	CommandList_Free(&(*commandListPtr)->next);

	/* free the current object */
	free(*commandListPtr);
	
	/* clear the provided pointer */
	*commandListPtr = NULL;
}


/* Find the function associated with a given command */
CommandFunc CommandList_Find(CommandList* commandList, const char* commandName)
{
	/* safety check on the parameters (also terminates the recursion) */
	if ((commandList == NULL) || (commandName == NULL)) 
	{
		return NULL; /* return a NULL function if the parameters are invalid */
	}

	/* check to see if the current object's command matches the parameter */
	if ((commandList->commandName != NULL) && (strcmp(commandName, commandList->commandName) == 0))
	{
		return commandList->commandFunc; /* it matched; return the function */
	}
	else
	{
		return CommandList_Find(commandList->next, commandName); /* it did not match; recurse to the next object */
	}
}


/* Print the commands in the command list */
void CommandList_Print(CommandList* commandList)
{
	/* the current command list that we are iterating on */
	CommandList* commandListCurrent;

	/* print the list header */
	printf("The supported commands are:\n");

	/* print each command on its own line */
	commandListCurrent = commandList;
	while (commandListCurrent != NULL)
	{
		/* print the command if show-in-help says to do so */
		if (commandListCurrent->showInHelp)
		{
			printf("%s\n", commandListCurrent->commandName);
		}

		/* go to the next command in the list */
		commandListCurrent = commandListCurrent->next;
	}
}