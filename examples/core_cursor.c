#include <raygpu.h>
#include <stdio.h>

int main(void) {
    InitWindow(800, 600, "Cursor Test - Press keys to test functions");
    SetTargetFPS(60);

    bool cursorEnabled = true;
    bool cursorVisible = true;
    
    while (!WindowShouldClose()) {
        // Toggle cursor capture on SPACE
        if (IsKeyPressed(KEY_SPACE)) {
            cursorEnabled = !cursorEnabled;
            if (cursorEnabled) {
                EnableCursor();
                printf("Cursor ENABLED (normal)\n");
            } else {
                DisableCursor();
                printf("Cursor DISABLED (captured/locked)\n");
            }
        }

        // Toggle cursor visibility on H
        if (IsKeyPressed(KEY_H)) {
            cursorVisible = !cursorVisible;
            if (cursorVisible) {
                ShowCursor();
                printf("Cursor VISIBLE\n");
            } else {
                HideCursor();
                printf("Cursor HIDDEN\n");
            }
        }

        BeginDrawing();
        ClearBackground(RAYWHITE);
        
        // Title
        DrawText("Cursor Function Tests", 10, 10, 24, DARKBLUE);
        DrawLine(10, 40, 790, 40, LIGHTGRAY);
        
        // Instructions
        DrawText("SPACE - Toggle Enable/Disable (capture)", 10, 50, 18, DARKGRAY);
        DrawText("H     - Toggle Show/Hide (visibility)", 10, 75, 18, DARKGRAY);
        DrawText("ESC   - Exit", 10, 100, 18, DARKGRAY);
        DrawLine(10, 125, 790, 125, LIGHTGRAY);
        
        // Status display
        int yOffset = 145;
        char statusText[128];
        
        snprintf(statusText, sizeof(statusText), "Cursor Capture: %s", 
                 cursorEnabled ? "ENABLED" : "DISABLED");
        DrawText(statusText, 10, yOffset, 20, cursorEnabled ? GREEN : RED);
        yOffset += 30;
        
        snprintf(statusText, sizeof(statusText), "Cursor Visibility: %s", 
                 cursorVisible ? "VISIBLE" : "HIDDEN");
        DrawText(statusText, 10, yOffset, 20, cursorVisible ? GREEN : RED);
        yOffset += 30;
        
        bool isHidden = IsCursorHidden();
        snprintf(statusText, sizeof(statusText), "IsCursorHidden(): %s", 
                 isHidden ? "true" : "false");
        DrawText(statusText, 10, yOffset, 20, isHidden ? ORANGE : BLUE);
        yOffset += 25;
        
        // Explanation of IsCursorHidden behavior
        DrawText("  (returns true when hidden OR disabled)", 10, yOffset, 16, GRAY);
        yOffset += 35;
        
        // Mouse position and delta
        Vector2 mousePos = GetMousePosition();
        snprintf(statusText, sizeof(statusText), "Mouse Position: (%.1f, %.1f)", 
                 mousePos.x, mousePos.y);
        DrawText(statusText, 10, yOffset, 20, BLUE);
        yOffset += 30;
        
        Vector2 mouseDelta = GetMouseDelta();
        snprintf(statusText, sizeof(statusText), "Mouse Delta: (%.2f, %.2f)", 
                 mouseDelta.x, mouseDelta.y);
        DrawText(statusText, 10, yOffset, 20, 
                 (mouseDelta.x != 0 || mouseDelta.y != 0) ? ORANGE : BLUE);
        yOffset += 30;
        
        snprintf(statusText, sizeof(statusText), "IsCursorOnScreen(): %s", 
                 IsCursorOnScreen() ? "true" : "false");
        DrawText(statusText, 10, yOffset, 20, BLUE);
        yOffset += 50;
        
        // Visual feedback
        DrawLine(10, yOffset - 20, 790, yOffset - 20, LIGHTGRAY);
        DrawText("Move mouse to test GetMouseDelta()", 10, yOffset, 18, DARKGRAY);
        DrawText("Mouse delta should show non-zero values when moving", 10, yOffset + 25, 18, DARKGRAY);
        
        // Draw crosshair at mouse position if cursor is on screen
        if (IsCursorOnScreen()) {
            DrawLine(mousePos.x - 10, mousePos.y, mousePos.x + 10, mousePos.y, RED);
            DrawLine(mousePos.x, mousePos.y - 10, mousePos.x, mousePos.y + 10, RED);
            DrawCircle(mousePos.x, mousePos.y, 3, RED);
        }
        
        EndDrawing();
    }

    return 0;
}
