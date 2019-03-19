/******************************************************************************
filename    CommandTypes.h
author      Matthew Picioccio
DP email    mattpic@digipen.edu
course      GAM100 ** Do not use this code in your team project

Brief Description:
This file declares other types needed for the command system.

******************************************************************************/
#pragma once

typedef struct CommandData CommandData;
typedef struct GameState GameState;
typedef struct WorldData WorldData;

/* CommandFunc is the function pointer type for game command functions */
typedef void(*CommandFunc)(CommandData* command, GameState* gameState, WorldData* worldData);