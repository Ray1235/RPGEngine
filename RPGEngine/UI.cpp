#include "stdafx.h"
#include "UI.h"


rUI::rUI()
{
}


rUI::~rUI()
{
}

void rUI::DrawWindow(int x, int y, int width, int height)
{
	al_draw_bitmap_region(windowBG, 0, 0, 4, 4, x-4, y-4, NULL);
	al_draw_bitmap_region(windowBG, 12, 12, 4, 4, x + width, y + height, NULL);
	al_draw_scaled_bitmap(windowBG, 4, 4, 4, 4, x, y, width, height, NULL);
}

void rUI::DrawColoredWindow(int x, int y, int width, int height, ALLEGRO_COLOR color)
{
	al_draw_tinted_bitmap_region(windowBG, color, 0, 0, 4, 4, x - 4, y - 4, NULL);
	al_draw_tinted_bitmap_region(windowBG, color, 12, 12, 4, 4, x + width, y + height, NULL);
	al_draw_tinted_scaled_bitmap(windowBG, color, 4, 4, 4, 4, x, y, width, height, NULL);
}

void rUI::DrawMenuOption(int index, int x, int y, int width, int height, const char * text)
{
	DrawColoredMenuOption(index, x, y, width, height, text, al_map_rgb(0, 128, 255));
}

void rUI::DrawColoredMenuOption(int index, int x, int y, int width, int height, const char * text, ALLEGRO_COLOR color)
{
	int rx = x;
	int ry = y;
	int rw = width;
	int rh = height;
	ALLEGRO_COLOR rc = color;
	rx += (int)(8.0f * menuIndexSelectFrac[index]);
	//rw -= 8 * menuIndexSelectFrac[index];
	rc.r += 60.0f * menuIndexSelectFrac[index] / 255.0f;
	rc.g += 60.0f * menuIndexSelectFrac[index] / 255.0f;
	rc.b += 60.0f * menuIndexSelectFrac[index] / 255.0f;
	rc.r = __min(rc.r, 1);
	rc.g = __min(rc.g, 1);
	rc.b = __min(rc.b, 1);
	DrawColoredWindowWithText(text, rx, ry, rw, rh, rc, ALLEGRO_ALIGN_CENTER);
}

void rUI::DrawWindowWithText(const char * txt, int x, int y, int width, int height, int align)
{
	DrawColoredWindowWithText(txt, x, y, width, height, al_map_rgb(255, 255, 255), align);
}

void rUI::DrawColoredWindowWithText(const char * txt, int x, int y, int width, int height, ALLEGRO_COLOR color, int align)
{
	DrawColoredWindow(x, y, width, height, color);
	if(align == ALLEGRO_ALIGN_LEFT)
		al_draw_multiline_text(font, al_map_rgb(255, 255, 255), x + 2, y + 2, width - 4, 13, align, txt);
	else if(align == ALLEGRO_ALIGN_CENTER)
		al_draw_multiline_text(font, al_map_rgb(255, 255, 255), x + ((width - 4)/2) + 2, y + 2, width - 4, 13, align, txt);
	else
		al_draw_multiline_text(font, al_map_rgb(255, 255, 255), x + width - 2, y + 2, width - 4, 13, align, txt);
}

int fpsval[60];

void updatefps(int t)
{
	for (int i = 1; i < 60; i++)
	{
		fpsval[i - 1] = fpsval[i];
	}
	fpsval[59] = t;
}

int getavgfps()
{
	double a = 0;
	for (int i = 0; i < 60; i++)
	{
		a += fpsval[i];
	}
	a = a / 60.0f;
	return (int)a;
}

void rUI::DrawFPS(double dt)
{
	updatefps((int)(1 / dt));
	char * f = va("%d FPS", getavgfps());
	if (dt < (1.0f / 30.0f))
	{
		DrawColoredWindowWithText(f, 640 - (12+al_get_text_width(font, f)), 6, al_get_text_width(font, f)+6, 14, al_map_rgb(0, 255, 0), ALLEGRO_ALIGN_RIGHT);
	}
	else
	{
		DrawColoredWindowWithText(f, 640 - (12 + al_get_text_width(font, f)), 6, al_get_text_width(font, f) + 6, 14, al_map_rgb(255, 0, 0), ALLEGRO_ALIGN_RIGHT);
	}
	delete f;
}
