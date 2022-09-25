#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ball.h"
#include "paddle.h"

int main()
{
    InitWindow(640, 480, "pong");
    SetTargetFPS(30);

    struct paddle paddles[] = {
        paddle_create(0.0f, ((float)GetScreenHeight() - PLAYER_HEIGHT) / 2.0f, KEY_W, KEY_S),
        paddle_create((float)GetScreenWidth() - (float)PLAYER_WIDTH, ((float)GetScreenHeight() - (float)PLAYER_HEIGHT) / 2.0f, KEY_UP, KEY_DOWN),
    };

    struct ball ball = ball_create((float)GetScreenWidth() / 2.0f, (float)GetScreenHeight() / 2.0f, 5.0f);

    while (!WindowShouldClose())
    {
        if (ball.y + ball.radius > (float)GetScreenHeight() || ball.y - ball.radius < 0.0f)
        {
            ball.velocity.y *= -1;
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

        ball.x += ball.velocity.x * GetFrameTime();
        ball.y += ball.velocity.y * GetFrameTime();

        for (size_t i = 0; i < sizeof paddles / sizeof(struct paddle); i++)
        {
            paddles[i].accel = 0.0f;

            if ((int)paddles[i].rect.y >= 0 && paddle_is_up(&paddles[i]))
            {
                paddles[i].rect.y -= paddles[i].speed * GetFrameTime();
                paddles[i].accel -= 50.0f;
            }

            if ((int)paddles[i].rect.y + (int)paddles[i].rect.height <= GetScreenHeight() && paddle_is_down(&paddles[i]))
            {
                paddles[i].rect.y += paddles[i].speed * GetFrameTime();
                paddles[i].accel += 50.0f;
            }

            if (CheckCollisionCircleRec((Vector2){.x = ball.x, .y = ball.y}, ball.radius, paddles[i].rect))
            {
                ball.velocity.x *= -1.0f;
                ball.velocity.y = BALL_SPEED * -sin((double)((((paddles[i].rect.y + (paddles[i].rect.height / 2)) - ball.y) / (paddles[i].rect.height / 2)) * 75));
            }
        }

        BeginDrawing();
        {
            ClearBackground(BLACK);

            for (size_t i = 0; i < sizeof paddles / sizeof(struct paddle); i++)
            {
                DrawRectangleRec(paddles[i].rect, WHITE);
            }

            DrawCircleV((Vector2){.x = ball.x, .y = ball.y}, ball.radius, WHITE);

            DrawFPS(0, 0);
        }
        EndDrawing();
    }

    CloseWindow();

    return 0;
}
