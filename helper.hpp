#ifndef HELPER_H_SALTY
	#define HELPER_H_SALTY
	#include <raylib.h>
	#include <string>
	bool      PointRectColision(Vector2 point, Rectangle rect);
	void      CentralizeRect(Rectangle *rect);
	void      DrawRect(Rectangle rect, Color color);
	void      DrawRectCentered(Rectangle rect, Color color);
	void      DrawTextFromRect(std::string str, Rectangle rect, Color color);
	void      DrawBackBtn(Vector2 drawpos, Vector2 size, float _WIDTH, float _HEIGHT, Color color);
	Vector2 *GetBackBtnPoints(Vector2 drawpos, Vector2 size, float _WIDTH, float _HEIGHT);
#endif
