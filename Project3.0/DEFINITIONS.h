/*
 * COP 3003 - Game Menu
 * Sources:
 * https://www.sfml-dev.org/tutorials/2.5/ - sfml website: download code.
 * https://en.sfml-dev.org/forums/index.php?topic=8536.0 - sfml dev on how code works.
 * http://gamedevgeek.com/tutorials/managing-game-states-in-c/ - How game states work and how to implement
 * https://github.com/SonarSystems - code for game state algorithm and chest game algorithm
 * Special thanks to people on SFML dev website, game state, and sonar systems for aid in project.
 */

#pragma once

#define SCREEN_WIDTH 1920
#define SCREEN_HEIGHT 1080

#define SPLASH_STATE_SHOW_TIME 3.0f

#define SPLASH_SCENE_BACKGROUND_FILEPATH "copyright.png"
#define MAIN_MENU_BACKGROUND_FILEPATH "Background_for_Menu.png"
#define GAME_BACKGROUND_FILEPATH "Background_for_Menu.png"
#define PAUSE_BACKGROUND_FILEPATH "Background_for_Menu.png"
#define GAMEOVER_BACKGROUND_FILEPATH "god.png"
#define SHOP_BACKGROUND_FILEPATH "shopplz.png"

#define MAIN_MENU_TITLE_PATH "Games.png"

#define MAIN_MENU_PLAY_BUTTON "play.png"
#define GLOPPY_MENU_PLAY_BUTTON "meat.png"
#define RESUME_BUTTON "resume.png"
#define HOME_BUTTON "MainMenu.png"
#define RETRY_BUTTON "Retry.png"

#define MAIN_MENU_PLAY_BUTTON_OUTER "shop.png"

#define PAUSE_BUTTON "PAUSE.png"

#define X_PIECE_FILEPATH "x.png"
#define O_PIECE_FILEPATH "o.png"

#define X_WINNING_PIECE_FILEPATH "XWin.png"
#define O_WINNING_PIECE_FILEPATH "OWin.png"

#define GRID_SPRITE_FILE_PATH "grid.png"

#define X_PIECE 8
#define O_PIECE 0
#define EMPTY_PIECE -1
#define PLAYER_PIECE X_PIECE
#define AI_PIECE O_PIECE

#define STATE_PLAYING 98
#define STATE_PAUSED 97
#define STATE_WON 96
#define STATE_LOSE 95
#define STATE_PLACING_PIECE 94
#define STATE_AI_PLAYING 93
#define STATE_DRAW 92

#define TIME_BEFORE_SHOWING_GAME_OVER 2