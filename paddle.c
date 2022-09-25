#include "paddle.h"

struct paddle paddle_create(float x, float y, KeyboardKey up, KeyboardKey down)
{
    return (struct paddle){
        .rect = {
            .x = x,
            .y = y,
            .width = PLAYER_WIDTH,
            .height = PLAYER_HEIGHT,
        },
        .speed = PLAYER_SPEED,
        .accel = 0.0f,
        .up = up,
        .down = down,
    };
}

int paddle_is_up(struct paddle *paddle)
{
    return IsKeyDown(paddle->up);
}

int paddle_is_down(struct paddle *paddle)
{
    return IsKeyDown(paddle->down);
}
