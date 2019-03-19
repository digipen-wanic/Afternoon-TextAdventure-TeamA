/******************************************************************************
filename    WorldDataFactory.h
author      Matthew Picioccio
DP email    mattpic@digipen.edu
course      GAM100 ** Do not use this code in your team project

Brief Description:
This file declares the WorldData factory, which creates the WorldData objects used
in this game.

This could be used to create default states as well as loaded state.

******************************************************************************/
#pragma once

typedef struct WorldData WorldData;


/* Create the world data for a new game */
WorldData* CreateInitialWorldData();