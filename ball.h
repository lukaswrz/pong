#pragma once

#include <raylib.h>

#define BALL_SPEED 200.0f

struct ball
{
    float x;
    float y;
    float radius;
    struct
    {
        float x;
        float y;
    } speed;
};

struct ball ball_create(float x, float y, float radius);
