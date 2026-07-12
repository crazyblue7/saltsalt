#include <cstdio>
#include <raylib.h>
#include <string>
#include "helper.hpp"

int width  = 1280;
int height = 800;

void openingThingo(void) {
	int frame = 0;
	int thingoshowlength = 300;
	int startshowthing = 72;

	std::string noai = "this was made without ai i guess";
	int fadinglength = 100;
	int startshownoai= startshowthing;

	std::string mewocorp = "Copyleft (c) 2026 Mewo Corporation. All Rights Reserved.\nthis is not afiliated with the flash game sugar sugar!!!";
	int startshowmewocorp= startshowthing;

	// no ai
	while ( true ) {
		frame++;
		BeginDrawing();
			ClearBackground({0,0,0});
			if ( frame > startshownoai ) {
				// show the noai thing
				if ( frame > startshownoai+fadinglength && frame < startshownoai+fadinglength+thingoshowlength ) {
					DrawText(noai.c_str(), (float)width/2-width/5.12, height/2, height/26.66, {255,255,255,255});
				} else {
					int what = ((float) (frame-startshownoai)/fadinglength)*255;
					unsigned char opacity;
					if ( what > 255 ) {
						opacity = (unsigned char) 255-(what-255);
					} else {
						opacity = (unsigned char) what;
					}
					printf("%i\n",what);
					DrawText(noai.c_str(), (float)width/2-width/5.12, height/2, height/26.66, {255,255,255,opacity});
				}
				if ( frame > startshownoai+fadinglength*2 + thingoshowlength) {
					break;
				}
			}
		EndDrawing();
	}
	frame = 0;
	// mewocorp
	while ( true ) {
		frame++;
		BeginDrawing();
			ClearBackground({0,0,0});
			if ( frame > startshowmewocorp ) {
				// show the noai thing
				if ( frame > startshowmewocorp+fadinglength && frame < startshowmewocorp+fadinglength+thingoshowlength ) {
					DrawText(mewocorp.c_str(), (float)width/2-(width/3.2 + (float)height/2)/2, height/2, (width/42.66 + height/26.66)/2, {255,255,255,255});
				} else {
					int what = ((float) (frame-startshowmewocorp)/fadinglength)*255;
					unsigned char opacity;
					if ( what > 255 ) {
						opacity = 255-(what%255);
					} else {
						opacity = what;
					}
					//printf("%i\n",what);
					DrawText(mewocorp.c_str(), (float)width/2-(width/3.2 + (float)height/2)/2, height/2, (width/42.66 + height/26.66)/2, {255,255,255,opacity});
				}
				if ( frame > startshowmewocorp+fadinglength*2 + thingoshowlength) {
					break;
				}
			}
		EndDrawing();
	}
	// recommended aspect ratio
	frame = 0;
	while ( true ) {
		frame++;
		BeginDrawing();
			ClearBackground({0,0,0});
			if ( frame > startshowthing ) {
				// show the noai thing
				if ( frame > startshowthing+fadinglength && frame < startshowmewocorp+fadinglength+thingoshowlength ) {
					DrawText("recommended aspect ratio is 16:10", (float)width/2-(width/3.2 + (float)height/2)/2, height/2, (width/42.66 + height/26.66)/2, {255,255,255,255});
				} else {
					int what = ((float) (frame-startshowthing)/fadinglength)*255;
					unsigned char opacity;
					if ( what > 255 ) {
						opacity = 255-(what%255);
					} else {
						opacity = what;
					}
					//printf("%i\n",what);
					DrawText("recommended aspect ratio is 16:10", (float)width/2-(width/3.2 + (float)height/2)/2, height/2, (width/42.66 + height/26.66)/2, {255,255,255,opacity});
				}
				if ( frame > startshowthing+fadinglength*2 + thingoshowlength) {
					break;
				}
			}
		EndDrawing();
	}
}

Color buttonColor = {255,56,56, 255};
Vector2 mousePos = {0,0};
void levelSelect() {
	width = GetScreenWidth();
	height = GetScreenHeight();
	Vector2 *backBtnPoints = GetBackBtnPoints({(float)width/42.66f,(float)height/26.66f}, {(float)width/18.28f,(float)height/11.42f}, width, height);
	while ( true ) {
		width = GetScreenWidth();
		height = GetScreenHeight();
		mousePos = GetMousePosition();
		if ( IsKeyPressed(KEY_ESCAPE) ) {
			return;
		}
		if ( false && CheckCollisionPointPoly(mousePos, backBtnPoints, 3) ) {
			return;
		}
		BeginDrawing();
			DrawBackBtn({(float)width/42.66f,(float)height/26.66f}, {(float)width/18.28f,(float)height/11.42f}, width, height, buttonColor);
			DrawLineV(backBtnPoints[0], backBtnPoints[1], BLACK);
			DrawLineV(backBtnPoints[1], backBtnPoints[2], BLACK);
			DrawLineV(backBtnPoints[2], backBtnPoints[0], BLACK);
			ClearBackground({255,108,108});
		EndDrawing();
	}
}

void mainMenu(void) {
	float buttonHeight;
	float buttonWidth;

	Rectangle mouseRect    = {mousePos.x, mousePos.y, 1, 1};
	Rectangle playRect     = {(float)width/2,(float)height/2,buttonWidth,buttonHeight};
	Rectangle toggleFSrect = {(float)width/2,(float)height/2+buttonHeight+(float)height/160,buttonWidth,buttonHeight}; // toggle fullscreen
	
	CentralizeRect(&playRect);
	CentralizeRect(&toggleFSrect);
	while ( true ) {
		width = GetScreenWidth();
		height = GetScreenHeight();
		mousePos = GetMousePosition();

		buttonHeight = (float)height/16;
		buttonWidth  = width/2.0;

		playRect     = {(float)width/2,(float)height/2,buttonWidth,buttonHeight};
		toggleFSrect = {(float)width/2,(float)height/2+buttonHeight+(float)height/160,buttonWidth,buttonHeight}; // toggle fullscreen
		CentralizeRect(&playRect);
		CentralizeRect(&toggleFSrect);
		if ( IsKeyPressed(KEY_ESCAPE) ) {
			return;
		}
		if ( IsMouseButtonPressed(0) && CheckCollisionPointRec(mousePos, playRect) ) {
			levelSelect();
		}

		if ( IsMouseButtonPressed(0) && PointRectColision(mousePos, toggleFSrect) ) {
			ToggleFullscreen();
		}

		BeginDrawing();
			ClearBackground({255,108,108});
			DrawText("press esc to leave!", width/42.66, height/26.66, height/26.66/*was 20px before*/, WHITE);
			DrawText("salt, salt", (float)width/2 - (height/11.11 * 2.3), height/7, height/11.11, WHITE);
			DrawRect(playRect, buttonColor);
			DrawTextFromRect("play", playRect, WHITE);
			DrawRect(toggleFSrect, buttonColor);
			DrawTextFromRect("toggle fullscreen", toggleFSrect, WHITE);
		EndDrawing();
	}
}

int main(void) {
	//SetConfigFlags(FLAG_WINDOW_RESIZABLE);

	InitWindow(width,height,"swalt");
	SetTargetFPS(144);
	//openingThingo();
	mainMenu();
	CloseWindow();
	return 0;
}
