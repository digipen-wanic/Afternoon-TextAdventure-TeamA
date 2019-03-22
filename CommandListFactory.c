/******************************************************************************
filename    CommandFactory.c
author      Justin Chambers
DP email    justin.chambers@digipen.edu
course      GAM100 ** Do not use this code in your team project

Brief Description:
This file implements the CommandList factory, creating the commands used
in this game.

******************************************************************************/
#include "stdafx.h" /* NULL */
#include "CommandListFactory.h" /* Function declarations */
#include "CommandList.h" /* CommandList and CommandList_Add */
#include "CommandHandlerFunctions.h" /* all Handle___Command functions */
#include "ThrowCommandHandler.h"
#include "TalkCommandHandler.h"
#include "CommandData.h" /* struct CommandData, CommandContext */
#include "GameState.h" /* struct GameState */
#include "WorldData.h" /* WorldData_GetRoom */
#include "Room.h" /* Room_GetItemList */
#include "ItemList.h" /* ItemList_FindItem */
#include "Item.h" /* ItemFunc, Item_GetUseFunc */
void HandleAssembleCommand(CommandData* command, GameState* gameState, WorldData* worldData)
{
	Item* assembling; /* the item to be used */
	assembling = ItemList_FindItem(*Room_GetItemList(WorldData_GetRoom( worldData, gameState->currentRoomIndex)), command->noun);
	if (assembling != NULL) {
		ItemFunc assembleFunc = Item_GetAssembleFunc(assembling);
		if (assembleFunc != NULL) {
			assembleFunc(CommandContext_User, gameState, worldData);
		}

		else {
			printf("You can't assemble a %s!", command->noun);
		}
	}
	else {
		printf("You don't see a %s to assemble!", command->noun);
	}


}/* Create the command list with all commands used in this game.*/
CommandList* CreateCommandList()
{
	/* The command list to be returned, starting empty */
	CommandList* commandList = NULL;
	CommandList** cmdListPtr = &commandList;

	/*
	* NOTES: - Add the commands in the reverse of the order they'll be used, to reduce searching.
	*		 - Short alias commands do not show up in help.
	*/

	/* EXAMPLE: This is how you create the "help" command
	and add it to the list of commands for the game
	NOTICE:  It uses a function called HandleHelpCommand, you can find
	additional command handler functions by looking here: CommandHandlerFunctions.h */
	CommandList_Add(cmdListPtr, "help", HandleHelpCommand, true);
	CommandList_Add(cmdListPtr, "h", HandleHelpCommand, false);
	CommandList_Add(cmdListPtr, "quit", HandleQuitCommand, true);
	CommandList_Add(cmdListPtr, "q", HandleQuitCommand, false);
	CommandList_Add(cmdListPtr, "drop", HandleDropCommand, true);
	CommandList_Add(cmdListPtr, "d", HandleDropCommand, false);
	CommandList_Add(cmdListPtr, "take", HandleTakeCommand, true);
	CommandList_Add(cmdListPtr, "t", HandleTakeCommand, false);
	CommandList_Add(cmdListPtr, "use", HandleUseCommand, true);
	CommandList_Add(cmdListPtr, "u", HandleUseCommand, false);
	CommandList_Add(cmdListPtr, "look", HandleLookCommand, true);
	CommandList_Add(cmdListPtr, "l", HandleLookCommand, false);
	CommandList_Add(cmdListPtr, "inventory", HandleInventoryCommand, true);
	CommandList_Add(cmdListPtr, "i", HandleInventoryCommand, false);
	CommandList_Add(cmdListPtr, "go", HandleGoCommand, true);
	CommandList_Add(cmdListPtr, "g", HandleGoCommand, false);
	CommandList_Add(cmdListPtr, "throw", HandleThrowCommand, true);
	CommandList_Add(cmdListPtr, "assemble", HandleAssembleCommand, true);
	CommandList_Add(cmdListPtr, "talk", HandleTalkCommand, true);
	return commandList;
}