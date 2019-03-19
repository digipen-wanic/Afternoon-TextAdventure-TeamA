/******************************************************************************
filename    CommandContext.h
author      Matthew Picioccio
DP email    mattpic@digipen.edu
course      GAM100 ** Do not use this code in your team project

Brief Description:
This file contains the definition for the Command Context enumeration, which is 
used to specify the source of commands.

******************************************************************************/
#pragma once

/* Command Contexts specify the source of commands */
typedef enum CommandContext
{
	/* The _User context is for commands that were typed directly by the user */
	CommandContext_User,

	/* The _Item_Inventory context is for commands that were initiated by using an item in the inventory */
	CommandContext_Item_Inventory,

	/* The _Item_Room context is for commands that were initiated by using an item in a room (not in inventory) */
	CommandContext_Item_Room
} CommandContext;