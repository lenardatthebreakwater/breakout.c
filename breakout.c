#include <string.h>
#include "raylib.h"

typedef struct Player {
	int x; 
	int y;
	int speed;
	int width;
	int height;
	Color color;
} Player;

typedef struct Ball {
	int x;
	int y;
	float radius;
	int speedX;
	int speedY;
	Color color;
} Ball;

int main(void)
{
	int screenWidth = 800;
	int screenHeight = 600;

	InitWindow(screenWidth, screenHeight, "Breakout");
	SetTargetFPS(60);

	Player player = {((screenWidth / 2) - ( 150 / 2)), (screenHeight - (14 + 10)), 6, 150, 14, RAYWHITE};
	Rectangle playerRec = {player.x, player.y, player.width, player.height};

	Ball ball = {screenWidth / 2, screenHeight / 2, 10, 5, 5, WHITE};

	char winnerText[30] = { 0 };

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

		ball.x += ball.speedX;
		ball.y += ball.speedY;
		if (ball.x < 0) {
			ball.x = 0;
			ball.speedX *= -1;
		}
		if (ball.x > (screenWidth - ball.radius)) {
			ball.x = (screenWidth - ball.radius);
			ball.speedX *= 1;
		}
		if (ball.y < 0) {
			ball.y = 0;
			ball.speedY *= -1;
		}
		if (ball.y > (screenHeight - ball.radius)) {
			memcpy(winnerText, "You lose", 9);
		}
		if (CheckCollisionCircleRec((Vector2){ball.x, ball.y}, ball.radius, playerRec)) {
			if (ball.speedY > 0) {
				ball.speedY *= -1;
				ball.speedX *= -1;
			}
		}

		BeginDrawing();
		ClearBackground(BLACK);
		DrawRectangleRec(playerRec, player.color);
		DrawCircle(ball.x, ball.y, ball.radius, ball.color);
		EndDrawing();

	}

	CloseWindow();
	return 0;
}