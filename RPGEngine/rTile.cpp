#include "stdafx.h"
#include "rTile.h"


rTile::rTile()
{
}

rTile::rTile(int x, int y, int layer, char* name)
{
	PositionX = x * 32;
	PositionY = y * 32;
	Layer = layer;
	strcpy(pathToImage, name);
}

rTile::~rTile()
{
}

rScaledRegion_t rTile::GetScaledRegionForTile()
{
	rScaledRegion_t sc;
	sc.sourceX = (tileID * 32) % (columns * 32);
	int Yofs = 0;
	int o = tileID;
	while (o >= columns)
	{
		o -= (columns);
		Yofs++;
	}
	sc.sourceY = Yofs * 32;
	sc.sourceW = 32;
	sc.sourceH = 32;
	sc.destinationX = PositionX - player.cameraOffset.X;
	sc.destinationY = PositionY - player.cameraOffset.Y;
	sc.destinationW = 32;
	sc.destinationH = 32;
	return sc;
}

void rTile::Draw()
{
	cachedRegion = GetScaledRegionForTile();
	al_draw_tinted_scaled_bitmap(cachedBitmap, gWorld.GetColorTint(), cachedRegion.sourceX, cachedRegion.sourceY, cachedRegion.sourceW, cachedRegion.sourceH, cachedRegion.destinationX, cachedRegion.destinationY, cachedRegion.destinationW, cachedRegion.destinationH, NULL);
}

void rTile::DrawToBitmap(int ofsX, int ofsY)
{
	al_draw_tinted_scaled_bitmap(cachedBitmap, al_map_rgb(255,255,255), cachedRegion.sourceX, cachedRegion.sourceY, cachedRegion.sourceW, cachedRegion.sourceH, cachedRegion.destinationX+ofsX, cachedRegion.destinationY+ofsY, cachedRegion.destinationW, cachedRegion.destinationH, NULL);
}

void rTile::Cache()
{
	if (!cachedBitmap)
		cachedBitmap = gBitmap.GetBitmap(pathToImage, false, true);
	if (!isRegionCached)
		cachedRegion = GetScaledRegionForTile();
}
