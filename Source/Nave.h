#ifndef __NAVE_H__
#define __NAVE_H__
#include "Sprite.h"

class Nave{
	int x;
	int y;
	int w;
	int h;
	int posicionActual;
	int posicionFinal;
	int posicionBrinco;
	int stepsActual;
	int stepFinal;
	int moduleUsing;
	Sprite *sprite;
public:
	Nave(SDL_Surface * screen, char * rutaImagen, int x, int y, int module);
	~Nave();
	void Pintar();
	void Pintar(int module, int x, int y);
	//void Mover(int posicion);
	void Mover(int brinco, int puntoFinal);
	
	void Nave::Mover(int posicion);
	void Nave::MoverIzquierda(int posicion);
	void Nave::MoverArriba(int posicion);
	void Nave::MoverAbajo(int posicion);
	void SetStep(int stepFinal);
	void IncrementarStep();
	int ObtenerStepActual();
	void Actualizar();
	bool IsRunningAnacion();
	void TerminacionAnimacion();
	int obtenerX();
	int obtenerY();
	int obtenerW();
	int obtenerH();
	void ponerEn(int x,int y);
};

#endif