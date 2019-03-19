/******************************************************************************
filename    DropCommandHandler.h
author      Matthew Picioccio
DP email    mattpic@digipen.edu
course      GAM100 ** Do not use this code in your team project

Brief Description:
This file declares functions that handle the "drop" user command, which removes
the specified item from the user's inventory and adds it to the current room.

******************************************************************************/
#pragma once

typedef struct CommandData CommandData;
typedef struct GameState GameState;
typedef struct WorldData WorldData;


/* Handles the "drop" user command, which drops an item in inventory to the current room.*/
void HandleDropCommand(CommandData* command, GameState *gameState, WorldData *worldData);