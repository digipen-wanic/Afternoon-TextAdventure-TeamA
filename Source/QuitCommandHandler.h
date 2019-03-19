/******************************************************************************
filename    QuitCommandHandler.h
author      Matthew Picioccio
DP email    mattpic@digipen.edu
course      GAM100 ** Do not use this code in your team project

Brief Description:
This file declares functions that handle the "quit" user command, which 
immediately exits the game.

******************************************************************************/
#pragma once

typedef struct CommandData CommandData;
typedef struct GameState GameState;
typedef struct WorldData WorldData;


/* Handles the "quit" command, which immediately exits the game */
void HandleQuitCommand(CommandData* command, GameState *gameState, WorldData *worldData);