/******************************************************************************
filename    GoCommandHandler.h
author      Matthew Picioccio
DP email    mattpic@digipen.edu
course      GAM100 ** Do not use this code in your team project

Brief Description:
This file declares functions that handle the "go" user command, which moves
the user from one room to another using defined exits.

******************************************************************************/
#pragma once

typedef struct CommandData CommandData;
typedef struct GameState GameState;
typedef struct WorldData WorldData;


/* Handles the "go" command, which moves the user to another room */
void HandleGoCommand(CommandData* command, GameState *gameState, WorldData *worldData);