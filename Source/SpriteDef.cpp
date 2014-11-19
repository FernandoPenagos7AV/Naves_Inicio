#include "SpriteDef.h"
#include "config.h"

SpriteDef::SpriteDef()
{
	modulos[0].id = MODULO_MINAVE_NAVE;
	modulos[0].x = 0;
	modulos[0].y = 0;
	modulos[0].w = 54;
	modulos[0].h = 64;
	modulos[1].id = MODULO_MENU_FONDO;
	modulos[1].x = 0;
	modulos[1].y = 0;
	modulos[1].w = WIDTH_SCREEN;
	modulos[1].h = HEIGHT_SCREEN;


	modulos[2].id =  MODULO_ENEMIGO_NAVE;
	modulos[2].x = 0;
	modulos[2].y = 0;
	modulos[2].w = 54;
	modulos[2].h = 61;

	modulos[3].id = MODULO_TEXTO_TITULO;
	modulos[3].x = 194;
	modulos[3].y = 59;
	modulos[3].w = 105;
	modulos[3].h = 54;

	modulos[4].id = MODULO_TEXTO_NOMBRE;
	modulos[4].x = 34;
	modulos[4].y = 276;
	modulos[4].w = 169;
	modulos[4].h = 33;

	modulos[5].id = MODULO_TEXTO_OPCION1;
	modulos[5].x = 155;
	modulos[5].y = 155;
	modulos[5].w = 78;
	modulos[5].h = 27;

	modulos[6].id = MODULO_TEXTO_OPCION2;
	modulos[6].x = 156;
	modulos[6].y = 182;
	modulos[6].w = 58;
	modulos[6].h = 25;


	modulos[7].id = MODULO_TEXTO_OPCION1_SELECCION;
	modulos[7].x = 300;
	modulos[7].y = 155;
	modulos[7].w = 76;
	modulos[7].h = 24;


	modulos[8].id = MODULO_TEXTO_OPCION2_SELECCION;
	modulos[8].x = 300;
	modulos[8].y = 183;
	modulos[8].w = 56;
	modulos[8].h = 23;


}