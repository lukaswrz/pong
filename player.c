#include "player.h"

struct player player_create(float x, float y, KeyboardKey up, KeyboardKey down)
{
    return (struct player){
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

int player_is_up(struct player *player)
{
    return IsKeyDown(player->up);
}

int player_is_down(struct player *player)
{
    return IsKeyDown(player->down);
}
