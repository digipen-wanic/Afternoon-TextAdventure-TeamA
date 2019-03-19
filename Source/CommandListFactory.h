/******************************************************************************
filename    CommandFactory.h
author      Matthew Picioccio
DP email    mattpic@digipen.edu
course      GAM100 ** Do not use this code in your team project

Brief Description:
This file declares the CommandList factory, which creates the commands used
in this game.

******************************************************************************/
#pragma once

typedef struct CommandList CommandList;

/* Create the command list with all commands used in this game.*/
CommandList* CreateCommandList();