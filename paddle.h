#pragma once

#include <raylib.h>

#define PLAYER_HEIGHT 50.0f
#define PLAYER_WIDTH  8.0f
#define PLAYER_SPEED  250.0f
#define PLAYER_ACCEL  2.0f

struct paddle
{
    Rectangle rect;
    float speed;
    float accel;
    KeyboardKey up;
    KeyboardKey down;
};

struct paddle paddle_create(float x, float y, KeyboardKey up, KeyboardKey down);
int paddle_is_up(struct paddle *paddle);
int paddle_is_down(struct paddle *paddle);
