/******************************************************************************
filename    TakeCommandHandler.h
author      Matthew Picioccio
DP email    mattpic@digipen.edu
course      GAM100 ** Do not use this code in your team project

Brief Description:
This file declares functions that handle the "take" user command, which removes 
an item from the current room and adds it to the user's inventory.

******************************************************************************/
#pragma once

typedef struct CommandData CommandData;
typedef struct GameState GameState;
typedef struct WorldData WorldData;


/* Handles the "take" command, which removes an item from the current room and adds it to the user's inventory */
void HandleTakeCommand(CommandData* command, GameState *gameState, WorldData *worldData);