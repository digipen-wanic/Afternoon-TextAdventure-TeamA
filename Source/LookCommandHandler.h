/******************************************************************************
filename    LookCommandHandler.h
author      Matthew Picioccio
DP email    mattpic@digipen.edu
course      GAM100 ** Do not use this code in your team project

Brief Description:
This file declares functions that handle the "look" user command, which outputs
a description of an item or the current room.

******************************************************************************/
#pragma once

typedef struct CommandData CommandData;
typedef struct GameState GameState;
typedef struct WorldData WorldData;


/* Handles the "look" command, which outputs a description of an item or the current room */
void HandleLookCommand(CommandData* command, GameState *gameState, WorldData *worldData);