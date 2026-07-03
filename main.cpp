#include <raylib.h>
#include <string>

int width  = 1280;
int height = 800;

void openingThingo(void) {
	int frame = 0;
	int thingoshowlength = 300;

	std::string noai = "this was made without ai i guess";
	int fadinglength = 100;
	int startshownoai= 72;

	std::string mewocorp = "Copyleft (c) 2026 Mewo Corporation. All Rights Reserved.\nthis is not afiliated with the flash game sugar sugar!!!";
	int startshowmewocorp= 72;

	// no ai
	while ( true ) {
		frame++;
		BeginDrawing();
			ClearBackground({0,0,0});
			if ( frame > startshownoai ) {
				// show the noai thing
				if ( frame > startshownoai+fadinglength && frame < startshownoai+fadinglength+thingoshowlength ) {
					DrawText(noai.c_str(), width/2-250, height/2, 30, {255,255,255,255});
				} else {
					int what = ((float) (frame-startshownoai)/fadinglength)*255;
					unsigned char opacity;
					if ( what > 255 ) {
						opacity = (unsigned char) 255-(what-255);
					} else {
						opacity = (unsigned char) what;
					}
					printf("%i\n",what);
					DrawText(noai.c_str(), width/2-250, height/2, 30, {255,255,255,opacity});
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
		printf("mewo\n");
		BeginDrawing();
			ClearBackground({0,0,0});
			if ( frame > startshowmewocorp ) {
				// show the noai thing
				if ( frame > startshowmewocorp+fadinglength && frame < startshowmewocorp+fadinglength+thingoshowlength ) {
					DrawText(mewocorp.c_str(), width/2-400, height/2, 30, {255,255,255,255});
				} else {
					int what = ((float) (frame-startshowmewocorp)/fadinglength)*255;
					unsigned char opacity;
					if ( what > 255 ) {
						opacity = 255-(what%255);
					} else {
						opacity = what;
					}
					printf("%i\n",what);
					DrawText(mewocorp.c_str(), width/2-400, height/2, 30, {255,255,255,opacity});
				}
				if ( frame > startshowmewocorp+fadinglength*2 + thingoshowlength) {
					break;
				}
			}
		EndDrawing();
	}
}

void mainMenu(void) {
	while ( true ) {
		if ( IsKeyDown(KEY_ESCAPE) ) {
			return;
		}
		BeginDrawing();
			ClearBackground({255,108,108});
			DrawText("press esc to leave!", 30, 30, height/36, WHITE);
			DrawText("Salt, salt", width/2 - 140, height/7, height/10, WHITE);
		EndDrawing();
	}
}

int main(void) {
	InitWindow(width,height,"test");
	SetTargetFPS(144);
	//openingThingo();
	mainMenu();
	CloseWindow();
	return 0;
}
