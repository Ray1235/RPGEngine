// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#pragma once
#pragma warning( disable : 4018)

#define _CRT_SECURE_NO_WARNINGS
#define __FILENAME__ (strrchr(__FILE__, '\\') ? strrchr(__FILE__, '\\') + 1 : __FILE__)
#define maxMenuIndex 128
#define MAX_LINES_SHOWN 20

#include "targetver.h"
#include "Branding.h"

#include <stdio.h>
#include <tchar.h>
#include <iostream>
#include <fstream>
#include <unordered_map>

#include <physfs.h>
#include "tmx\NLTmxMap.h"

#include <allegro5\allegro.h>
#include <allegro5\allegro_image.h>
#include <allegro5\allegro_font.h>
#include <allegro5\allegro_ttf.h>
#include <allegro5\allegro_physfs.h>
#include <allegro5\keyboard.h>

#include <allegro5\allegro_native_dialog.h>
//#include "json.hpp"
//using json = nlohmann::json;

extern ALLEGRO_EVENT_QUEUE* aEventQueue;
extern ALLEGRO_TIMER* aTimer;
extern ALLEGRO_DISPLAY* aDisplay;
extern ALLEGRO_FONT *font;
//extern ALLEGRO_TEXTLOG *txtLog;

extern std::ifstream gameConfig;

extern std::string consoleLog;
extern std::string consoleInput;

extern bool bInitialized;
extern int menuIndex;
extern float menuIndexSelectFrac[maxMenuIndex];

extern int __width;
extern int __height;

extern bool showCon;

typedef enum {
	GAME_STATE_ENGINE_INTRO,
	GAME_STATE_INTRO,
	GAME_STATE_MENU,
	GAME_STATE_INGAME
} gameState_e;

extern gameState_e gameState;

typedef struct gameInfo_s {
	char *name;
} gameInfo_t;

extern gameInfo_t gameInfo;

#include "Common.h"
#include "rUI.h"
#include "rEntity.h"
#include "rTile.h"
#include "rMap.h"
#include "rMenu.h"
#include "rWorld.h"
#include "rPlayer.h"
#include "rScript.h"
#include "rBitmap.h"

extern rUI gUI;
extern rScript gScript;
extern rBitmap gBitmap;
extern rWorld gWorld;
extern rPlayer player;

void initialize_assets();



// TODO: reference additional headers your program requires here
