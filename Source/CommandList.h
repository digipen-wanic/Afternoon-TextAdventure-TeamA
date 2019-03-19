/******************************************************************************
filename    CommandList.h
author      Matthew Picioccio
DP email    mattpic@digipen.edu
course      GAM100 ** Do not use this code in your team project

Brief Description:
This file declares the CommandList interface, which manages supported commands.

The mutator functions return the new effective pointer, which combines the
existing-list and new-list scenarios.  The trade-off is that the caller 
must usually reassign the existing variable to the return value.

******************************************************************************/
#pragma once
#include "stdafx.h" /* bool */
#include "CommandTypes.h" /* CommandFunc */


/* Forward declaration of the CommandList type */
typedef struct CommandList CommandList;


/* Adds a command definition to a given list, which might be NULL (an empty list).  Returns the new head of the list */
void CommandList_Add(CommandList** commandList, const char* commandName, CommandFunc commandFunc, bool showInHelp);

/* Frees the memory associated with a CommandList chain */
void CommandList_Free(CommandList** commandListPtr);

/* Find the function associated with a given command */
CommandFunc CommandList_Find(CommandList* commandList, const char* commandName);

/* Print the commands in the command list */
void CommandList_Print(CommandList* commandList);