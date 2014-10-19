#ifndef __NAVE_H__
#define  __NAVE_H__
#include "Sprite.h"
class Nave
{
	int x;
	int y;
	Sprite * sprite;
public:
	Nave(SDL_Surface * screen, char * rutaImagen);
	~Nave();
	void Pintar();
	void MoverDerecha(int posicion);
	void MoverIzquierda(int posicion);
	void MoverArriba(int posicion);
	void MoverAbajo(int posicion);
};



#endif