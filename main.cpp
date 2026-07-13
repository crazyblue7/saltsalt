#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <vector>
#include <cmath>
#include <raylib.h>

// helper functions
bool PointRectColision(Vector2 point, Rectangle rect) {
	return point.x >= rect.x && point.y >= rect.y && point.x <= rect.x+rect.width && point.y <= rect.y+rect.height;
}
void DrawRect(Rectangle rect, Color color) { DrawRectangle(rect.x, rect.y, rect.width, rect.height, color); }
void DrawTextFromRect(std::string str, Rectangle rect, Color color, int fontSize) {
	DrawText(str.c_str(), (rect.x+rect.width/2)-fontSize*str.length()/3.95, (rect.y+rect.height/2)-fontSize/2, fontSize, color);
}
void CentralizeRect(Rectangle *rect) {
	rect->x -= rect->width /2;
	rect->y -= rect->height/2;
	return;
}
void DrawRectCentered(Rectangle rect, Color color) { DrawRectangle(rect.x-rect.width/2, rect.y-rect.height/2, rect.width, rect.height, color); }
void DrawBackBtn(Vector2 drawpos, Vector2 size, float _WIDTH, float _HEIGHT, Color color) {
	for ( int i = drawpos.y; i < drawpos.y + size.y; i += 1 ) {
		DrawLineEx(
			{drawpos.x + size.x, (float)i},
			{
				drawpos.x,
				drawpos.y + size.y/2
			},
			_HEIGHT / 200,
			color
		);
	}
	DrawLineEx(
		{drawpos.x + size.x,drawpos.y},
		{
			drawpos.x,
			drawpos.y + size.y/2
		},
		_HEIGHT / 200,
		BLACK
	);
	DrawLineEx(
		{
			drawpos.x,
			drawpos.y + size.y/2
		},
		{
			drawpos.x + size.x,
			drawpos.y + size.y
		},
		_HEIGHT / 200,
		BLACK
	);
	DrawLineEx(
		{
			drawpos.x + size.x,
			drawpos.y + size.y
		},
		{drawpos.x + size.x,drawpos.y},
		_HEIGHT / 200,
		BLACK
	);

	return;
}
Vector2 *GetBackBtnPoints(Vector2 drawpos, Vector2 size, float _WIDTH, float _HEIGHT) {
	Vector2 *points = new Vector2 [3];
	points[0] = {drawpos.x + size.x,drawpos.y};
	points[1] = {drawpos.x, (float)drawpos.y + size.y/2};
	points[2] = {drawpos.x + size.x, (float)drawpos.y + size.y};

	return points;
}

int __itos_digit_place_j(int i,int j) {
	return std::fmod(i/pow(10,j-1), 10);
}
std::string itos(int i) {
	std::string tmp;

	// 1000000s place
	if ( i > 999999 ) {
		if ( __itos_digit_place_j(i,7) == 0 ) tmp.append("0");
		if ( __itos_digit_place_j(i,7) == 1 ) tmp.append("1");
		if ( __itos_digit_place_j(i,7) == 2 ) tmp.append("2");
		if ( __itos_digit_place_j(i,7) == 3 ) tmp.append("3");
		if ( __itos_digit_place_j(i,7) == 4 ) tmp.append("4");
		if ( __itos_digit_place_j(i,7) == 5 ) tmp.append("5");
		if ( __itos_digit_place_j(i,7) == 6 ) tmp.append("6");
		if ( __itos_digit_place_j(i,7) == 7 ) tmp.append("7");
		if ( __itos_digit_place_j(i,7) == 8 ) tmp.append("8");
		if ( __itos_digit_place_j(i,7) == 9 ) tmp.append("9");
	}

	// 100000
	if ( i > 99999 ) {
		if ( __itos_digit_place_j(i,6) == 0 ) tmp.append("0");
		if ( __itos_digit_place_j(i,6) == 1 ) tmp.append("1");
		if ( __itos_digit_place_j(i,6) == 2 ) tmp.append("2");
		if ( __itos_digit_place_j(i,6) == 3 ) tmp.append("3");
		if ( __itos_digit_place_j(i,6) == 4 ) tmp.append("4");
		if ( __itos_digit_place_j(i,6) == 5 ) tmp.append("5");
		if ( __itos_digit_place_j(i,6) == 6 ) tmp.append("6");
		if ( __itos_digit_place_j(i,6) == 7 ) tmp.append("7");
		if ( __itos_digit_place_j(i,6) == 8 ) tmp.append("8");
		if ( __itos_digit_place_j(i,6) == 9 ) tmp.append("9");
	}

	// 10000
	if ( i > 9999 ) {
		if ( __itos_digit_place_j(i,5) == 0 ) tmp.append("0");
		if ( __itos_digit_place_j(i,5) == 1 ) tmp.append("1");
		if ( __itos_digit_place_j(i,5) == 2 ) tmp.append("2");
		if ( __itos_digit_place_j(i,5) == 3 ) tmp.append("3");
		if ( __itos_digit_place_j(i,5) == 4 ) tmp.append("4");
		if ( __itos_digit_place_j(i,5) == 5 ) tmp.append("5");
		if ( __itos_digit_place_j(i,5) == 6 ) tmp.append("6");
		if ( __itos_digit_place_j(i,5) == 7 ) tmp.append("7");
		if ( __itos_digit_place_j(i,5) == 8 ) tmp.append("8");
		if ( __itos_digit_place_j(i,5) == 9 ) tmp.append("9");
	}

	// 1000
	if ( i > 999 ) {
		if ( __itos_digit_place_j(i,4) == 0 ) tmp.append("0");
		if ( __itos_digit_place_j(i,4) == 1 ) tmp.append("1");
		if ( __itos_digit_place_j(i,4) == 2 ) tmp.append("2");
		if ( __itos_digit_place_j(i,4) == 3 ) tmp.append("3");
		if ( __itos_digit_place_j(i,4) == 4 ) tmp.append("4");
		if ( __itos_digit_place_j(i,4) == 5 ) tmp.append("5");
		if ( __itos_digit_place_j(i,4) == 6 ) tmp.append("6");
		if ( __itos_digit_place_j(i,4) == 7 ) tmp.append("7");
		if ( __itos_digit_place_j(i,4) == 8 ) tmp.append("8");
		if ( __itos_digit_place_j(i,4) == 9 ) tmp.append("9");
	}

	// 100
	if ( i > 99 ) {
		if ( __itos_digit_place_j(i,3) == 0 ) tmp.append("0");
		if ( __itos_digit_place_j(i,3) == 1 ) tmp.append("1");
		if ( __itos_digit_place_j(i,3) == 2 ) tmp.append("2");
		if ( __itos_digit_place_j(i,3) == 3 ) tmp.append("3");
		if ( __itos_digit_place_j(i,3) == 4 ) tmp.append("4");
		if ( __itos_digit_place_j(i,3) == 5 ) tmp.append("5");
		if ( __itos_digit_place_j(i,3) == 6 ) tmp.append("6");
		if ( __itos_digit_place_j(i,3) == 7 ) tmp.append("7");
		if ( __itos_digit_place_j(i,3) == 8 ) tmp.append("8");
		if ( __itos_digit_place_j(i,3) == 9 ) tmp.append("9");
	}

	// 10
	if ( i > 9 ) {
		if ( __itos_digit_place_j(i,2) == 0 ) tmp.append("0");
		if ( __itos_digit_place_j(i,2) == 1 ) tmp.append("1");
		if ( __itos_digit_place_j(i,2) == 2 ) tmp.append("2");
		if ( __itos_digit_place_j(i,2) == 3 ) tmp.append("3");
		if ( __itos_digit_place_j(i,2) == 4 ) tmp.append("4");
		if ( __itos_digit_place_j(i,2) == 5 ) tmp.append("5");
		if ( __itos_digit_place_j(i,2) == 6 ) tmp.append("6");
		if ( __itos_digit_place_j(i,2) == 7 ) tmp.append("7");
		if ( __itos_digit_place_j(i,2) == 8 ) tmp.append("8");
		if ( __itos_digit_place_j(i,2) == 9 ) tmp.append("9");
	}

	// 1
	if ( i < 10 ) {
		if ( __itos_digit_place_j(i,1) == 0 ) tmp.append("0");
		if ( __itos_digit_place_j(i,1) == 1 ) tmp.append("1");
		if ( __itos_digit_place_j(i,1) == 2 ) tmp.append("2");
		if ( __itos_digit_place_j(i,1) == 3 ) tmp.append("3");
		if ( __itos_digit_place_j(i,1) == 4 ) tmp.append("4");
		if ( __itos_digit_place_j(i,1) == 5 ) tmp.append("5");
		if ( __itos_digit_place_j(i,1) == 6 ) tmp.append("6");
		if ( __itos_digit_place_j(i,1) == 7 ) tmp.append("7");
		if ( __itos_digit_place_j(i,1) == 8 ) tmp.append("8");
		if ( __itos_digit_place_j(i,1) == 9 ) tmp.append("9");
	}
	return tmp;
}
// helper functions are over

int width  = 1280;
int height = 800;

void DrawFrames(void) {
	char *tmp = (char*)(itos(GetFPS()).c_str());
	std::cout << "WHAT iS IT " << tmp << std::endl;
	DrawText(strcat(tmp, " fps"), 10,10, 20, WHITE);
}

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
				// show the mewo corp thing
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
				// show the aspect ratio
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

void level(int lvlId) {
	std::cout << "What is it " << lvlId + 1 << std::endl;
	return;
}

void levelSelect(void) {
	width = GetScreenWidth();
	height = GetScreenHeight();
	Vector2 *backBtnPoints = GetBackBtnPoints({(float)width/42.66f,(float)height/26.66f}, {(float)width/18.28f,(float)height/11.42f}, width, height);
	
	std::vector<int> levels;
	levels.push_back(1);
	levels.push_back(1);
	levels.push_back(1);
	levels.push_back(1);
	levels.push_back(1);

	int loopy = 0;
	int loopx = 0;

	while ( true ) {

		width = GetScreenWidth();
		height = GetScreenHeight();
		mousePos = GetMousePosition();
		if ( IsKeyPressed(KEY_ESCAPE) ) {
			return;
		}
		if ( IsMouseButtonPressed(0) && CheckCollisionPointPoly(mousePos, backBtnPoints, 3) ) {
			return;
		}
		loopy=-1;
		loopx=0;
		for ( int i=0; i < levels.size(); i++ ) {
			if ( width/8.53+loopx*(width/13.47) > width-(width/8.53) ) {
				loopy++;
				loopx=0;
			}
			if ( IsMouseButtonPressed(0) && PointRectColision(mousePos, {
				static_cast<float>(width/8.53+loopx*(width/13.47)),
				static_cast<float>(width/5.33+loopy*(height/8.42)),
				static_cast<float>(width/16),
				static_cast<float>(height/10)
			}) ) {
				level(i);
			}
			loopx++;
		}
		BeginDrawing();
			ClearBackground({255,108,108});

			loopy=-1;
			loopx=0;
			for ( int i=0; i < levels.size(); i++ ) {
				if ( width/8.53+loopx*(width/13.47) > width-(width/8.53) ) {
					loopy++;
					loopx=0;
				}
				DrawRect({
				static_cast<float>(width/8.53+loopx*(width/13.47)),
				static_cast<float>(width/5.33+loopy*(height/8.42)),
				static_cast<float>(width/16),
				static_cast<float>(height/10)
			}, WHITE);
				DrawRectangle(
					static_cast<float>(width/8.53+loopx*(width/13.47)),
					static_cast<float>(width/5.33+loopy*(height/8.42)),
					static_cast<float>(width/16),
					static_cast<float>(height/10), buttonColor
				);
				DrawRectangleLinesEx({
					static_cast<float>(width/8.53+loopx*(width/13.47)),
					static_cast<float>(width/5.33+loopy*(height/8.42)),
					static_cast<float>(width/16),
					static_cast<float>(height/10)
				}, height/200, BLACK);
				DrawTextFromRect(itos(i+1), {static_cast<float>(width/8.53+loopx*(width/13.47)), static_cast<float>(width/5.33+loopy*(height/8.42)), static_cast<float>(width/16),static_cast<float>(height/10)}, BLACK, height/26.66);
				loopx++;
			}

			DrawBackBtn({(float)width/42.66f,(float)height/26.66f}, {(float)width/18.28f,(float)height/11.42f}, width, height, buttonColor);
			DrawLineV(backBtnPoints[0], backBtnPoints[1], BLACK);
			DrawLineV(backBtnPoints[1], backBtnPoints[2], BLACK);
			DrawLineV(backBtnPoints[2], backBtnPoints[0], BLACK);
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
			DrawTextFromRect("play", playRect, WHITE, playRect.height);
			DrawRect(toggleFSrect, buttonColor);
			DrawTextFromRect("toggle fullscreen", toggleFSrect, WHITE, toggleFSrect.height);
		EndDrawing();
	}
}

int main(void) {
	//SetConfigFlags(FLAG_WINDOW_RESIZABLE);

	InitWindow(width,height,"swalt");
	// SetTargetFPS(144);
	//openingThingo();
	mainMenu();
	CloseWindow();
	return 0;
}
