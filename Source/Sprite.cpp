#include "Sprite.h"
#include "SDL.h"//Cambio1



void Sprite::CargarImagen(char * ruta){
	image = SDL_LoadBMP(ruta);

}
Sprite::Sprite(SDL_Surface * screen)
{
	this-> screen = screen;
};//Cambio2

Sprite::~Sprite()
{
	SDL_FreeSurface(image);
};//Cambio3
//void Sprite::PintarModulo(int id, int x, int y, int w,  int h)
//{
//	SDL_Rect src;
//	src.x = x;
//	src.y = y;
//	src.w = w;
//	src.h = h;
//
//	SDL_BlitSurface(image, &src, screen, NULL);
//};//Cambio4

void Sprite::PintarModulo(int id, int x, int y)
{
		SDL_Rect src;
		src.x = spriteDef.modulo[id].x;
		src.y = spriteDef.modulo[id].y;
		src.w = spriteDef.modulo[id].w;
		src.h = spriteDef.modulo[id].h;
		SDL_Rect dest;
		dest.x = x;
		dest.y = y;
		SDL_BlitSurface(image, &src, screen, &dest);

}
int Sprite::WidthModule(int id)
{
	return spriteDef.modulo[id].w;
}
int Sprite::HeightModule(int id)
{
	return spriteDef.modulo[id].h;
}

