#include "ball.h"

struct ball ball_create(float x, float y, float radius)
{
    return (struct ball){
        .x = x,
        .y = y,
        .radius = radius,
        .speed = {
            .x = BALL_SPEED,
            .y = BALL_SPEED,
        },
    };
}
