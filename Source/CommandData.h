/******************************************************************************
filename    CommandData.h
author      Matthew Picioccio
DP email    mattpic@digipen.edu
course      GAM100 ** Do not use this code in your team project

Brief Description:
This file contains the definition for the CommandData structure, which is used
to encapsulate the data related to a single command.

******************************************************************************/
#pragma once
#include "CommandContext.h" /* enum CommandContext */


/* The maximum length of a verb in a command */
#define MAX_COMMAND_VERB_LENGTH 256

/* The maximum length of a noun in a command.*/
#define MAX_COMMAND_NOUN_LENGTH 256

/* The maximum input length allowed by the game */
#define MAX_INPUT_LENGTH (MAX_COMMAND_VERB_LENGTH + MAX_COMMAND_NOUN_LENGTH + 2)


typedef struct CommandList CommandList;

/* Encapsulation of all data for a single command.*/
typedef struct CommandData
{
	/* The verb in the command */
	char verb[MAX_COMMAND_VERB_LENGTH];

	/* The noun in the command */
	char noun[MAX_COMMAND_NOUN_LENGTH];

	/* The context of the command */
	CommandContext context;

	/* The list of command definitions to be used to parse this command */
	CommandList* commandList;
} CommandData;