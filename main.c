#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ball.h"
#include "player.h"

int main()
{
    InitWindow(640, 480, "pong");
    SetTargetFPS(30);

    struct player players[] = {
        player_create(0.0f, ((float)GetScreenHeight() - PLAYER_HEIGHT) / 2.0f, KEY_W, KEY_S),
        player_create((float)GetScreenWidth() - (float)PLAYER_WIDTH, ((float)GetScreenHeight() - (float)PLAYER_HEIGHT) / 2.0f, KEY_UP, KEY_DOWN),
    };

    struct ball ball = ball_create((float)GetScreenWidth() / 2.0f, (float)GetScreenHeight() / 2.0f, 5.0f);

    while (!WindowShouldClose())
    {
        if (ball.y + ball.radius > (float)GetScreenHeight() || ball.y - ball.radius < 0.0f)
        {
            ball.speed.y *= -1;
        }

        if (ball.x + ball.radius > (float)GetScreenWidth())
        {
            printf("Left won.\n");
            break;
        }
        if (ball.x - ball.radius < 0.0f)
        {
            printf("Right won.\n");
            break;
        }

        ball.x += ball.speed.x * GetFrameTime();
        ball.y += ball.speed.y * GetFrameTime();

        for (size_t i = 0; i < sizeof players / sizeof(struct player); i++)
        {
            players[i].accel = 0.0f;
        }

        for (size_t i = 0; i < sizeof players / sizeof(struct player); i++)
        {
            if ((int)players[i].rect.y >= 0 && player_is_up(&players[i]))
            {
                players[i].rect.y -= players[i].speed * GetFrameTime();
                players[i].accel -= 50.0f;
            }

            if ((int)players[i].rect.y + (int)players[i].rect.height <= GetScreenHeight() && player_is_down(&players[i]))
            {
                players[i].rect.y += players[i].speed * GetFrameTime();
                players[i].accel += 50.0f;
            }
        }

        for (size_t i = 0; i < sizeof players / sizeof(struct player); i++)
        {
            if (CheckCollisionCircleRec((Vector2){.x = ball.x, .y = ball.y}, ball.radius, players[i].rect))
            {
                ball.speed.x *= -1.0f;
                ball.speed.y = BALL_SPEED * -sin((double)((((players[i].rect.y + (players[i].rect.height / 2)) - ball.y) / (players[i].rect.height / 2)) * 75));
            }
        }

        BeginDrawing();
        {
            ClearBackground(BLACK);

            for (size_t i = 0; i < sizeof players / sizeof(struct player); i++)
            {
                DrawRectangleRec(players[i].rect, WHITE);
            }

            DrawCircleV((Vector2){.x = ball.x, .y = ball.y}, ball.radius, WHITE);

            DrawFPS(0, 0);
        }
        EndDrawing();
    }

    CloseWindow();

    return 0;
}
