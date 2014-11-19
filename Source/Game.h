#include <SDL.h>
#include <SDL_image.h>
#include "Nave.h"

class CGame
{
public:


	bool Start();
	static CGame instanceGame;

	CGame();
	void Finalize();

	enum Estado
	{
		ESTADO_INICIANDO,
		ESTADO_MENU,
		ESTADO_JUGANDO,
		ESTADO_TERMINANDO,
		ESTADO_FINALIZADO,
	};

private:
	void Iniciando();
	void MoverEnemigo();
	bool esLimitePantalla(Nave *objeto, int bandera);//1er CAMBIO int bandera

	void Menu();
	int menuSeleccion;

	Uint8 *keys;//esta variable nos servira para ver las teclas
	SDL_Event event;//La variable event de tipo evento de SDL nos sirve para
	SDL_Surface *screen;
	Nave * nave;
	Nave ** enemigoArreglo;
	Nave * menu;
	Nave * titulos;
	Nave * fondo;
	Nave * texto;
	
	Nave *botonInicio;
	Nave *botonSalir;

	Estado estado;

	float enemigoParabola;
	unsigned int frames;
	unsigned int tiempoFrameInicio;
	unsigned int tiempoFrameFinal;


};

