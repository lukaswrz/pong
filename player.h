#pragma once

#include <raylib.h>

#define PLAYER_HEIGHT 50.0f
#define PLAYER_WIDTH  8.0f
#define PLAYER_SPEED  250.0f
#define PLAYER_ACCEL  2.0f

struct player
{
    Rectangle rect;
    float speed;
    float accel;
    KeyboardKey up;
    KeyboardKey down;
};

struct player player_create(float x, float y, KeyboardKey up, KeyboardKey down);
int player_is_up(struct player *player);
int player_is_down(struct player *player);
