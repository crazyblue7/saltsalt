#include <cstdio>
#include <raylib.h>
#include <string>
bool PointRectColision(Vector2 point, Rectangle rect) {
	return point.x >= rect.x && point.y >= rect.y && point.x <= rect.x+rect.width && point.y <= rect.y+rect.height;
}
void DrawRect(Rectangle rect, Color color) { DrawRectangle(rect.x, rect.y, rect.width, rect.height, color); }
void DrawTextFromRect(std::string str, Rectangle rect, Color color) {
	DrawText(str.c_str(), (rect.x+rect.width/2)-rect.height*str.length()/3.95, (rect.y+rect.height/2)-rect.height/2, rect.height, color);
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
	std::printf("%.0f, %.0f, %.0f, %.0f\n",drawpos.x,drawpos.y,size.x,size.y);
	points[0] = {drawpos.x + size.x,drawpos.y};
	points[1] = {drawpos.x, (float)drawpos.y + size.y/2};
	points[0] = {drawpos.x + size.x, (float)drawpos.y + size.y};

	return points;
}
