#pragma once
#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>

using namespace std;
using namespace sf;

// CONSTANT VARIABLES FOR INGAME ESSENTIALS
extern const float IG_gravity;
extern const float IG_flap_strength;
extern const float IG_pipe_speed;
extern const float IG_pipe_width;
extern const float IG_pipe_gap;
extern const float IG_spawn_intv;

// GAME VARIABLES
enum GameVARS { GV_menu, GV_skinselect, GV_game, GV_pause, GV_finish };
extern GameVARS gamevars;

// GAME BACKGROUND VIA IMAGE/SPRITES/TEXTURE
extern Texture background_TEXT, menu_TEXT, skins_TEXT, paused_TEXT, victory_TEXT;
extern Sprite background_SPRT, menu_SPRT, skins_SPRT, paused_SPRT, victory_SPRT;

// FOR BIRDS SKINS
extern vector<Texture> bird_SKINS;
extern int currSKIN_INDEX;

// FOR FONTS
extern Font font;

// FOR CURRENT SCORING/GAMEOVER FUNCTION/PIPE SPEED HANDLING
extern int score;
extern bool gameOVER;
extern bool winNER;
extern bool knockedOUT;
extern float pipeSPEED;
extern float TIME;

// FOR BACKGROUND AUDIO (FADED BY ALAN WALKER)
extern Music backgroundAUDIO;

// FOR FLAPPING / KNOCK-OFF SOUNDS FX
extern SoundBuffer flapFX, pointFX, knockedFX, gameoverFX, winnerFX;
extern Sound flapSOUNDS, pointSOUNDS, knockedSOUNDS, gameoverSOUNDS, winnerSOUNDS;

// FOR PIPE TEXTURES (TOP AND BOTTOM)
extern Texture pipeTEXT_TOP, pipeTEXT_BOT;

// FOR IN GAME TEXTS (STRINGS) MANAGING
extern Text scoreTEXT, gameoverTEXT;
