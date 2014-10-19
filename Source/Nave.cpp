#include "Nave.h"
#include "Config.h"
#include "Sprite.h"
Nave::Nave(SDL_Surface * screen, char * rutaImagen)
{
	sprite = new Sprite(screen);
	sprite->CargarImagen(rutaImagen);
	x = (WIDTH_SCREEN / 2) - (sprite->WidthModule(0)/ 2);
	y = (HEIGHT_SCREEN-80)-(sprite->HeightModule(0));
}
Nave::~Nave()
	{
		delete sprite;
	}
void Nave::Pintar()
	{
		sprite->PintarModulo(0, x, y);
	}
void Nave::MoverDerecha(int posicion)
{
	x += posicion;
}
void Nave::MoverIzquierda(int posicion)
{
	x -= posicion;
}
void Nave::MoverArriba(int posicion)
{
	y -= posicion;
}
void Nave::MoverAbajo(int posicion)
{
	y += posicion;
}