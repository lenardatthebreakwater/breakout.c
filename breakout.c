#include "raylib.h"

typedef struct Player {
	int x; 
	int y;
	int speed;
	int width;
	int height;
	Color color;
} Player;

int main(void)
{
	int screenWidth = 800;
	int screenHeight = 600;

	InitWindow(screenWidth, screenHeight, "Breakout");
	SetTargetFPS(60);

	Player player = {((screenWidth / 2) - ( 150 / 2)), (screenHeight - (14 + 10)), 6, 150, 14, RAYWHITE};
	Rectangle playerRec = {player.x, player.y, player.width, player.height};

	while (!WindowShouldClose()) {

		if (IsKeyDown(KEY_RIGHT)) {
			playerRec.x += player.speed;
		}
		else if (IsKeyDown(KEY_LEFT)){
			playerRec.x -= player.speed;
		}
		if (playerRec.x < 0) {
			playerRec.x = 0;
		}
		if (playerRec.x > (screenWidth- playerRec.width)) {
			playerRec.x = (screenWidth - playerRec.width);
		}

		BeginDrawing();

			ClearBackground(BLACK);

			DrawRectangleRec(playerRec, player.color);

		EndDrawing();

	}

	CloseWindow();
	return 0;
}