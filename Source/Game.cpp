
#include <stdio.h>
#include <stdlib.h>
#include "Game.h"
#include <SDL_image.h>
#include <SDL.h>
#include "Config.h"
#include "Sprite.h"
#include "Nave.h"

CGame::CGame()
{
	estado = Estado::ESTADO_INICIANDO;
	atexit(SDL_Quit);
}
void CGame::Iniciando(){




	if (SDL_Init(SDL_INIT_AUDIO)){
		printf("Error %s ", SDL_GetError());
		exit(EXIT_FAILURE);

	}

	screen = SDL_SetVideoMode(WIDTH_SCREEN, HEIGHT_SCREEN, 24, SDL_HWSURFACE);

	if (screen == NULL){
		printf("Error %s ", SDL_GetError());
		exit(EXIT_FAILURE);
	}
	SDL_Flip(screen);
	SDL_WM_SetCaption("Mi primer Juego", NULL);
	nave = new Nave(screen, "../Data/minave.bmp");
	//nave -> CargarImagen("../Data/Eddie.bmp");
}


void CGame::Finalize()
{
	SDL_Quit();
}

bool CGame::Start()
{
	// Esta variable nos ayudara a controlar la salida del juego...
	int salirJuego = false;
	while (salirJuego == false)
	{

		//Maquina de estados
		switch (estado)
		{
		case Estado::ESTADO_INICIANDO:
			
			Iniciando();
			estado = ESTADO_MENU;
			printf("\nEstado Iniciando");
			
			
			break;
			
			//{		
		//

		//								/* nave = SDL_LoadBMP("../Data/Eddie.bmp");

		//								 SDL_Rect Fuente;
		//								 Fuente.x = 90;
		//								 Fuente.y = 152;
		//								 Fuente.w = 242;
		//								 Fuente.h = 76;
		//								 SDL_Rect destino;
		//								 destino.x = 100;
		//								 destino.y = 100;
		//								 destino.w = 100;
		//								 destino.h = 100;

		//								 SDL_BlitSurface(nave, &Fuente, screen, &destino);

		//								 SDL_BlitSurface(nave, NULL, screen, NULL);

		//								 SDL_FreeSurface(nave);*/
		//}

		case Estado::ESTADO_MENU:
			SDL_FillRect(screen, NULL, 0xFF0000);
			keys = SDL_GetKeyState(NULL);
			if (keys[SDLK_RIGHT])
			{
				//nave->PintarModulo(0, 0, 0, 64, 64);
				nave->MoverDerecha(4);
				/*Iniciando();
				estado = ESTADO_MENU;*/
			}
			if (keys[SDLK_LEFT])
			{
				//nave->PintarModulo(0, 0, 0, 64, 64);
				nave->MoverIzquierda(4);
				/*Iniciando();
				estado = ESTADO_MENU;*/
			}
			if (keys[SDLK_UP])
			{
			
				nave->MoverArriba(4);
			
			}
			if (keys[SDLK_DOWN])
			{

				nave->MoverAbajo(4);

			}
			nave->Pintar();

			/*if (keys[SDLK_UP])
			{
				nave->PintarModulo(0, 200, 100);
			}
			if (keys[SDLK_RIGHT])
			{
				nave->PintarModulo(0, 400, 200);
			}
			if (keys[SDLK_LEFT])
			{
				nave->PintarModulo(0, 0, 200);
			}*/
			estado = ESTADO_JUGANDO;
			printf("\nEstado Menu");
			break;
			
		case Estado::ESTADO_JUGANDO:
			estado = ESTADO_FINALIZADO;
			printf("\nEstado Jugando");
			break;
		case Estado::ESTADO_FINALIZADO:
			estado = ESTADO_TERMINANDO;
			printf("\nEstado Finalizando");
			break;
		case Estado::ESTADO_TERMINANDO:
			
			printf("\nEstado Terminando");
			getchar();
			salirJuego = true;
			break;
		};
		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT) { salirJuego = true; }
			if (event.type == SDL_KEYDOWN) {}
		}
		SDL_Flip(screen);// imprimir en pantalla la variable screen
	}
	return true;
}

