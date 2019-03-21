/******************************************************************************
filename    WorldDataFactory.c
author      Justin Chambers
DP email    justin.chambers@digipen.edu
course      GAM100 ** Do not use this code in your team project

Brief Description:
This file defines the WorldData factory, which creates the WorldData objects used
in this game.

This could be used to create default states as well as loaded state.

******************************************************************************/
#include "WorldDataFactory.h" /* Function declarations */
#include "WorldData.h" /* WorldData_Create, WorldData_SetRoom */
#include "Room.h" /* Room_Create, Room_AddRoomExit, Room_GetItemList */
#include "ItemList.h" /* ItemList_Add */
#include "BrickFunctions.h" /* Brick_Build */
#include "GoldPieceFunctions.h" /* GoldPiece_Build */
#include "ExitDoorFunctions.h" /* ExitDoor_Build */



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

	/* Items
	   add items to the room */
	ItemList_AddItem(Room_GetItemList(room), ExitDoor_Build());

	/* Return the new room */
	return room;
}


/* TODO REQUIRED: Build room 0 */
Room* Room0_Build()
{
	/* Pre-declare a room pointer which we will use to build the new room */
	Room* room = NULL;

	/* Create the room
	include an initial room description */
	room = Room_Create("This is your Cabin. It can only barely contain your Hunkiness. You can hear Orphans running in the distance.\n");

	/* Exits
	add one or more exits to allow navigation between rooms */
	Room_AddRoomExit(room, "east", 8);  /* 1 = the room index this exit connects to */

	/* Items
	add items to the room */
	/* ItemList_AddItem(Room_GetItemList(room), ExitDoor_Build()); */

	/* TODO REQUIRED: Call Room_Create with the Room 1 description:
	"This is room 0. It is a display room with a cage in the middle. You can see a jeweled egg inside the cage.  There is a crack in the west wall, but you can't fit through it from this side.\n" */
	
	/* TODO REQUIRED: Add an Exit "north" to Room 1 */
	/* TODO BASIC: Add room exit shortcut for "n" */

	/* TODO REQUIRED: add an exit door to the list of items in the room, ExitDoor_Build() */
	/* TODO ADVANCED: (not required) update the description and add a room exit to the "east" */

	/* return the new room */
	return room;
}


/* TODO REQUIRED: Build room 1 */
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
	ItemList_AddItem(Room_GetItemList(room), ExitDoor_Build());
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
	ItemList_AddItem(Room_GetItemList(room), ExitDoor_Build());
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
	ItemList_AddItem(Room_GetItemList(room), ExitDoor_Build());
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
	ItemList_AddItem(Room_GetItemList(room), ExitDoor_Build());
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

	/* Items
	add items to the room */
	ItemList_AddItem(Room_GetItemList(room), ExitDoor_Build());
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
	ItemList_AddItem(Room_GetItemList(room), ExitDoor_Build());
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
	ItemList_AddItem(Room_GetItemList(room), ExitDoor_Build());
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
	Room_AddRoomExit(room, "east", 8);  /* 1 = the room index this exit connects to */

	/* Items
	add items to the room */
	ItemList_AddItem(Room_GetItemList(room), ExitDoor_Build());
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
	Room_AddRoomExit(room, "east", 8);  /* 1 = the room index this exit connects to */

	/* Items
	dd items to the room */
	ItemList_AddItem(Room_GetItemList(room), ExitDoor_Build());
	/* return the new room */
	return room;
}

Room* Room10_Build()
{
	/* Pre-declare a room pointer which we will use to build the new room */
	Room* room = NULL;

	/* Create the room
	include an initial room description */
	room = Room_Create("This is the Hanger. A large Escape Plane sits in the center of the room. To the South, is a Staircase (STAIRS UP) up to the Kitchen.\n");

	/* Exits
	add one or more exits to allow navigation between rooms */
	Room_AddRoomExit(room, "east", 8);  /* 1 = the room index this exit connects to */

	/* Items
	add items to the room */
	ItemList_AddItem(Room_GetItemList(room), ExitDoor_Build());
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

	/* TODO REQUIRED: update room count to match the number of rooms you have created and added to the world
	   if this number doesn't match then your game will either crash or you will end up stuck in a broken room with no exits */
	int roomCount = 1;

	/* create the new WorldData object with 3 rooms */
	worldData = WorldData_Create("Welcome to my GAM100 Game!\n\n", roomCount);

	/* build each room and assign them to the world data */
	WorldData_SetRoom(worldData, 0, Room0_Build());
	/* TODO REQUIRED: add rooms 1 and 2 to the world data */

	/* TODO ADVANCED: add additional advanced rooms */

	/* return the new object */
	return worldData;
}