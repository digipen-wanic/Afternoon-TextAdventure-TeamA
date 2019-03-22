/******************************************************************************
filename    WorldDataFactory.c
author      Justin Chambers
Edited by Nico Hickman
DP email    justin.chambers@digipen.edu
course      GAM100 ** Do not use this code in your team project

Last Edited by: Hunter Bradley.

Brief Description:
This file defines the WorldData factory, which creates the WorldData objects used
in this game.

This could be used to create default states as well as loaded state.

******************************************************************************/
#include "WorldDataFactory.h" /* Function declarations */
#include "WorldData.h" /* WorldData_Create, WorldData_SetRoom */
#include "Room.h" /* Room_Create, Room_AddRoomExit, Room_GetItemList */
#include "ItemList.h" /* ItemList_Add */
#include "TeddyFunctions.h"/* Teddy Function declration*/
#include "EngineFunctions.h"/* Engine Function declration*/
#include "HostileOrphanFunctions.h"/* HostileOrphan Function declration*/
#include "FriendlyOrphanFunctions.h"/* FriendlyOrphan Function declration*/
#include "OpenHatchButtonFunctions.h"/* OpenHatch Button Function declration*/
#include "EscapePodButtonFunctions.h"/* Escape Pod Button Function declration*/
#include "SelfDestructButton.h"/* Self Destruct Button Function declration*/
#include "PropellerFunctions.h"/* Propeller Function declration*/
#include "WheelFunctions.h"/* Wheel Function declration*/
#include "CandyFunctions.h"/* Candy Function declration*/
#include "PlaneFunctions.h"/* Plane Function declration*/
/******************************************************************************
	Build room TEMPLATE
    Use this example function to build additional rooms
******************************************************************************/
Room* RoomN_Build()
{
	/* Pre-declare a room pointer which we will use to build the new room */
	Room* room;

	/* Create the room
	   include an initial room description */
	room = Room_Create("TODO\n");

	/* Exits
	   add one or more exits to allow navigation between rooms */
	Room_AddRoomExit(room, "north", 1);  /* 1 = the room index this exit connects to */

	/* Return the new room */
	return room;
}


Room* Room0_Build()
{
	/* Pre-declare a room pointer which we will use to build the new room */
	Room* room = NULL;

	/* Create the room
	include an initial room description */
	room = Room_Create("This is your Cabin. It can only barely contain your Hunkiness. You can hear Orphans running in the distance.\n");

	/* Exits
	add one or more exits to allow navigation between rooms */
	Room_AddRoomExit(room, "south", 8);  /* 1 = the room index this exit connects to */
	ItemList_AddItem(Room_GetItemList(room), Teddy_Build());
	/* return the new room */
	return room;
}


Room* Room1_Build()
{
	/* Pre-declare a room pointer which we will use to build the new room */
	Room* room = NULL;

	/* Create the room
	include an initial room description */
	room = Room_Create("This is the Control Room. There are Three Buttons on the wall, Open Hanger Door, Launch Escape Pod, and Self-Destruct Buttons. There is an exit to a small side hallway to the South.\n");

	/* Exits
	add one or more exits to allow navigation between rooms */
	Room_AddRoomExit(room, "south", 2);  /* 1 = the room index this exit connects to */

	/* Items
	add items to the room */
	ItemList_AddItem(Room_GetItemList(room), EscapePodButton_Build());
	ItemList_AddItem(Room_GetItemList(room),SelfDestructButton_Build());
	ItemList_AddItem(Room_GetItemList(room),OpenHatchButton_Build());

	/* return the new room */
	return room;
}


Room* Room2_Build()
{
	/* Pre-declare a room pointer which we will use to build the new room */
	Room* room = NULL;

	/* Create the room
	include an initial room description */
	room = Room_Create("A Smaller Side Hallway form the main hallway. To the North, there is the Control Room. To the South, there is the Engine room, where you can hear a clatter of noise from what you assume is a broken engine. To the East, there is the Main Hallway.\n");

	/* Exits
	add one or more exits to allow navigation between rooms */
	Room_AddRoomExit(room, "north", 1);  /* 1 = the room index this exit connects to */
	Room_AddRoomExit(room, "east", 8);  /* 1 = the room index this exit connects to */
	Room_AddRoomExit(room, "south", 3);  /* 1 = the room index this exit connects to */

	/* Items
	add items to the room */
	/* return the new room */
	return room;
}

Room* Room3_Build()
{
	/* Pre-declare a room pointer which we will use to build the new room */
	Room* room = NULL;

	/* Create the room
	include an initial room description */
	room = Room_Create("This is the Engine Room.The Main Engine of the ship seems to have stopped working, But your no Mechanic, and there is no Mechanic on board the ship as well. To the North is a Small Side Hallway.\n");

	/* Exits
	add one or more exits to allow navigation between rooms */
	Room_AddRoomExit(room, "north", 2);  /* 1 = the room index this exit connects to */

	/* Items
	add items to the room */
	ItemList_AddItem(Room_GetItemList(room), Engine_Build());
	/* return the new room */
	return room;
}

Room* Room4_Build()
{
	/* Pre-declare a room pointer which we will use to build the new room */
	Room* room = NULL;

	/* Create the room
	include an initial room description */
	room = Room_Create("This is the Storage Room. You had to make a huge Sacrifice to get here. There is a lot of Shelves around here, full of Boxes. There is an Exit to the Main Hallway to the North.\n");

	/* Exits
	add one or more exits to allow navigation between rooms */
	Room_AddRoomExit(room, "north", 8);  /* 1 = the room index this exit connects to */

	/* Items
	add items to the room */
	ItemList_AddItem(Room_GetItemList(room), Propeller_Build());
	/* return the new room */
	return room;
}

Room* Room5_Build()
{
	/* Pre-declare a room pointer which we will use to build the new room */
	Room* room = NULL;

	/* Create the room
	include an initial room description */
	room = Room_Create("This Staircase leads Down to the Hanger. To the North is the Kitchen.\n");

	/* Exits
	add one or more exits to allow navigation between rooms */
	Room_AddRoomExit(room, "north", 6);  /* 1 = the room index this exit connects to */
	Room_AddRoomExit(room, "south", 9);  /* 1 = the room index this exit connects to */

	/* Items
	add items to the room */
	/* return the new room */
	return room;
}

Room* Room6_Build()
{
	/* Pre-declare a room pointer which we will use to build the new room */
	Room* room = NULL;

	/* Create the room
	include an initial room description */
	room = Room_Create("The Kitchen of the Ship. You can see some of the Orphans taking as much food as they can hold or carry in bag, but they seem to busy to talk to you. There is an Exit into the hallway to the West and an Exit to the Bridge to the North. There is a Stairway (STAIRS DOWN) to the South that leads down to the Hanger.\n");

	/* Exits
	add one or more exits to allow navigation between rooms */
	Room_AddRoomExit(room, "north", 7);  /* 1 = the room index this exit connects to */
	Room_AddRoomExit(room, "west", 8);  /* 1 = the room index this exit connects to */
	Room_AddRoomExit(room, "south", 5);  /* 1 = the room index this exit connects to */

	/* Items
	add items to the room */
	ItemList_AddItem(Room_GetItemList(room), Candy_Build());
	/* return the new room */
	return room;
}

Room* Room7_Build()
{
	/* Pre-declare a room pointer which we will use to build the new room */
	Room* room = NULL;

	/* Create the room
	include an initial room description */
	room = Room_Create("This is the Bridge of the ship. Orphans are running all over the place. There is a huge Window you could look out of. There is a Orphan that is standing in the corner. There is an Exit to the Kitchen to the South.\n");

	/* Exits
	add one or more exits to allow navigation between rooms */
	Room_AddRoomExit(room, "south", 6);  /* 1 = the room index this exit connects to */

	/* Items
	add items to the room */
	ItemList_AddItem(Room_GetItemList(room), Wheel_Build());
	ItemList_AddItem(Room_GetItemList(room),FOrphan_Build());
		/* return the new room */
	return room;
}

Room* Room8_Build()
{
	/* Pre-declare a room pointer which we will use to build the new room */
	Room* room = NULL;

	/* Create the room
	include an initial room description */
	room = Room_Create("This is the Main Hallway to the ship. You can see flashing red lights and Orphans running up and Down the Hallway. To the North is your Cabin. To the South is the Storage room. To The East is the Kitchen. To the West is a Smaller Side Hallway.\n");

	/* Exits
	add one or more exits to allow navigation between rooms */
	Room_AddRoomExit(room, "east", 6);  /* 1 = the room index this exit connects to */
	Room_AddRoomExit(room, "north", 0);  /* 1 = the room index this exit connects to */
	Room_AddRoomExit(room, "west", 2);  /* 1 = the room index this exit connects to */

	/* Items
	add items to the room */
	/* return the new room */
	return room;
}

Room* Room9_Build()
{
	/* Pre-declare a room pointer which we will use to build the new room */
	Room* room = NULL;

	/* Create the room
	include an initial room description */
	room = Room_Create("This Staircase leads Up to the Kitchen. To the North is the Hanger.\n");

	/* Exits
	add one or more exits to allow navigation between rooms */
	Room_AddRoomExit(room, "north", 5);  /* 1 = the room index this exit connects to */
	Room_AddRoomExit(room, "west", 10);  /* 1 = the room index this exit connects to */

	/* Items
	dd items to the room */
	/* return the new room */
	return room;
}

Room* Room10_Build()
{
	/* Pre-declare a room pointer which we will use to build the new room */
	Room* room = NULL;

	/* Create the room
	include an initial room description */
	room = Room_Create("This is the Hanger. A large Escape Plane sits in the center of the room. To the South, is a Staircase up to the Kitchen. It is being guarded by an Orphan who doesn�t seem to want to go anywhere, anytime soon.\n");

	/* Exits
	add one or more exits to allow navigation between rooms */
	Room_AddRoomExit(room, "east", 9);  /* 1 = the room index this exit connects to */

	/* Items
	add items to the room */
	ItemList_AddItem(Room_GetItemList(room), HostileOrphan_Build());
	ItemList_AddItem(Room_GetItemList(room), Plane_Build());

	/* return the new room */
	return room;
}


/* ------------------------------------------------------- */
/* Create the world data for a new game */
/* ------------------------------------------------------- */
WorldData* CreateInitialWorldData()
{
	/* The new world data */
	WorldData* worldData;

	int roomCount = 11;

	/* create the new WorldData object with 3 rooms */
	worldData = WorldData_Create("Your name is Steve Hunk, Super famous hunky adventure of the entire steampunk era. You are coming back from your most recent adventure by catching a lift with a band of Orphan Pirates on there Airship. You get woken up from your slumber by a loud bang coming from the Engine room. You know that these Orphans won’t hesitate to abandon ship without you and your Hunkiness, so your best option is to find another way of escape.Right now, you are in your Cabin.\n\n", roomCount);

	/* build each room and assign them to the world data */
	WorldData_SetRoom(worldData, 0, Room0_Build());
	WorldData_SetRoom(worldData, 1, Room1_Build());
	WorldData_SetRoom(worldData, 2, Room2_Build());
	WorldData_SetRoom(worldData, 3, Room3_Build());
	WorldData_SetRoom(worldData, 4, Room4_Build());
	WorldData_SetRoom(worldData, 5, Room5_Build());
	WorldData_SetRoom(worldData, 6, Room6_Build());
	WorldData_SetRoom(worldData, 7, Room7_Build());
	WorldData_SetRoom(worldData, 8, Room8_Build());
	WorldData_SetRoom(worldData, 9, Room9_Build());
	WorldData_SetRoom(worldData, 10, Room10_Build());

	/* return the new object */
	return worldData;
}