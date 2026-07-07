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
void DrawBackBtn(Vector2 drawpos, Vector2 size, float _WIDTH, float _HEIGHT) {
	DrawLineEx(
		drawpos,
		{
			drawpos.x + size.x,
			drawpos.y + size.y/2
		},
		_HEIGHT / 200,
		BLACK
	);
	DrawLineEx(
		{
			drawpos.x + size.x,
			drawpos.y + size.y/2
		},
		{
			drawpos.x,
			drawpos.y + size.y
		},
		_HEIGHT / 200,
		BLACK
	);
	DrawLineEx(
		{
			drawpos.x,
			drawpos.y + size.y
		},
		drawpos,
		_HEIGHT / 200,
		BLACK
	);

	return;
}
