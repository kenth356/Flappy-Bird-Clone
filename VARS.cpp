#include "VARS.h"

// CONSTANT VARIABLES FOR INGAME ESSENTIALS
const float IG_gravity = 0.5f;
const float IG_flap_strength = -10.f;
const float IG_pipe_speed = 5.f;
const float IG_pipe_width = 80.f;
const float IG_pipe_gap = 200.f;
const float IG_spawn_intv = 2.0f;

// GAME VARIABLES
GameVARS gamevars = GV_menu;

// GAME BACKGROUND VIA IMAGE/SPRITES/TEXTURE
Texture background_TEXT, menu_TEXT, skins_TEXT, paused_TEXT, victory_TEXT;
Sprite background_SPRT, menu_SPRT, skins_SPRT, paused_SPRT, victory_SPRT;

// FOR BIRDS SKINS
vector<Texture> bird_SKINS(3);
int currSKIN_INDEX = 0;

// FOR FONTS
Font font;

// FOR CURRENT SCORING/GAMEOVER FUNCTION/PIPE SPEED HANDLING
int score = 0;
bool gameOVER = false;
bool winNER = false;
bool knockedOUT = false;
float pipeSPEED = IG_pipe_speed;
float TIME;

// FOR BACKGROUND AUDIO (FADED BY ALAN WALKER)
Music backgroundAUDIO;

// FOR FLAPPING / KNOCK-OFF SOUNDS FX
SoundBuffer flapFX, pointFX, knockedFX, gameoverFX, winnerFX;
Sound flapSOUNDS, pointSOUNDS, knockedSOUNDS, gameoverSOUNDS, winnerSOUNDS;

// FOR PIPE TEXTURES (TOP AND BOTTOM)
Texture pipeTEXT_TOP, pipeTEXT_BOT;

// FOR IN GAME TEXTS (STRINGS) MANAGING
Text scoreTEXT, gameoverTEXT;
