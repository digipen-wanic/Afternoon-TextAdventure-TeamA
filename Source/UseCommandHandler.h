/******************************************************************************
filename    UseCommandHandler.h
author      Matthew Picioccio
DP email    mattpic@digipen.edu
course      GAM100 ** Do not use this code in your team project

Brief Description:
This file declares functions that handle the "use" user command, which calls 
an item-specific function on a given item

******************************************************************************/
#pragma once

typedef struct CommandData CommandData;
typedef struct GameState GameState;
typedef struct WorldData WorldData;


/* Handles the "use" command, which calls an item-specific function on a given item */
void HandleUseCommand(CommandData* command, GameState *gameState, WorldData *worldData);