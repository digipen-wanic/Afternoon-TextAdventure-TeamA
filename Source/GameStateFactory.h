/******************************************************************************
filename    GameStateFactory.h
author      Matthew Picioccio
DP email    mattpic@digipen.edu
course      GAM100 ** Do not use this code in your team project

Brief Description:
This file declares the GameState factory, which creates the game state objects used
in this game.

This could be used to create default states as well as loaded state.

******************************************************************************/
#pragma once

typedef struct GameState GameState;

/* Create the game state for a new game */
GameState* CreateInitialGameState();