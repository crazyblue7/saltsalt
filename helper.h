#ifndef HELPER_H_SALTY
	#define HELPER_H_SALTY
	#include <raylib.h>
	#include <string>
	bool PointRectColision(Vector2 point, Rectangle rect);
	void DrawRect(Rectangle rect, Color color);
	void DrawTextFromRect(std::string str, Rectangle rect, Color color);
	void CentralizeRect(Rectangle *rect);
	void DrawRectCentered(Rectangle rect, Color color);
#endif
