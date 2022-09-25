#include <raylib.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <limits.h>

int main()
{
    InitWindow(640, 480, "pong");

    size_t fpslen = (int)((ceil(log10(INT_MAX))+1)*sizeof(char));
    char fpsstr[fpslen];

    while (!WindowShouldClose())
    {
        BeginDrawing();
        {
            ClearBackground(BLACK);

            // Draw FPS counter.
            int fps = GetFPS();
            sprintf(fpsstr, "%d", fps);
            DrawText(fpsstr, 0, 0, 10, RED);
        }
        EndDrawing();
    }

    CloseWindow();

    return 0;
}
