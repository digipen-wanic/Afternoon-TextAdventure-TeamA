/******************************************************************************
filename    InputParser.c
author      Matthew Picioccio
DP email    mattpic@digipen.edu
course      GAM100 ** Do not use this code in your team project

Brief Description:
This file implements the InputParser, turning user input into verbs and nouns.

******************************************************************************/
#include "stdafx.h" /* NULL, strtok_s */
#include "InputProvider.h" /* Function declarations */
#include "CommandData.h" /* MAX_INPUT_LENGTH */


/* Gets command line input.  Matches GetInputFunc */
void GetCommandLineInput(char* dest, int destLength)
{
	/* safety-check on parameters */
	if ((dest == NULL) || (destLength <= 0))
	{
		return; /* take no action if the parameters are invalid */
	}

	/* get the user input from the command line */
	fgets(dest, destLength, stdin);
}


/* Return the default input function */
GetInputFunc GetDefaultInputFunc()
{
	/* NOTE: this function could be used to substitute file input, etc. without modifying external code */

	/* return the command-line input function */
	return GetCommandLineInput;
}


/* Parse input provided via the given function into a verb and noun */
void ParseCommand(GetInputFunc inputFunc, CommandData* command)
{
	char input[MAX_INPUT_LENGTH]; /* the array used to hold command input*/
	char* nextToken = NULL; /* "next" pointer used by the tokenizer */
	char* verb, *noun; /* The verb and noun parsed from the user's input */

	/* safety-check on the parameters.  Note that noun is optional */
	if ((inputFunc == NULL) || (command == NULL))
	{
		return; /* take no action if the parameters are invalid */
	}

	/* Read input from the input function */
	inputFunc(input, MAX_INPUT_LENGTH);

	/* convert to lowercase to provide additional robustness with input */
	_strlwr_s(input, MAX_INPUT_LENGTH);

	/* tokenize the string to grab a verb, ignoring spaces, tabs, and newlines */
	verb = strtok_s(input, " \t\n", &nextToken);

	/* tokenize the remaining string to grab a noun, ignoring tabs, and newlines */
	noun = strtok_s(NULL, "\t\n", &nextToken);

	/* copy the verb into the CommandData structure, if any */
	if (verb != NULL)
	{
		strcpy_s(command->verb, MAX_COMMAND_VERB_LENGTH, verb);
	}
	else
	{
		command->verb[0] = '\0'; /* no verb was parsed - set the CommandData value to an empty string */
	}

	/* copy the noun into the CommandData structure, if any */
	if (noun != NULL)
	{
		strcpy_s(command->noun, MAX_COMMAND_NOUN_LENGTH, noun);
	}
	else
	{
		command->noun[0] = '\0'; /* no noun was parsed - set the CommandData value to an empty string */
	}
}