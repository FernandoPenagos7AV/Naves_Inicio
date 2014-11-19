
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
	frames = 0;
	tiempoFrameInicio = 0;

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
	nave = new Nave(screen, "../Data/eddie.bmp", (WIDTH_SCREEN / 2)/*-(w/2)*/, (HEIGHT_SCREEN - 80)/*-(h)*/, MODULO_MINAVE_NAVE);
	menu = new Nave(screen, "../Data/menu.bmp", 0, 0, MODULO_MENU_FONDO);
	texto = new Nave(screen, "../Data/texto.bmp", 150, 0, -1);
	fondo = new Nave(screen, "../Data/fondo.bmp", 0, 0, 1);
	enemigoArreglo = new Nave*[10];
	for (int i = 0; i<10; i++)
		enemigoArreglo[i] = new Nave(screen, "../Data/enemigo1.bmp", i*65 ,0, MODULO_ENEMIGO_NAVE);
	for (int i = 0; i<10; i++)
		enemigoArreglo[i]->SetStep(4);
	menuSeleccion = MODULO_TEXTO_OPCION1;

	//nave -> CargarImagen("../Data/Eddie.bmp");
}


void CGame::Finalize()
{
	SDL_Quit();
}

bool CGame::Start()
{
	// Esta variable nos ayudara a controlar la salida del juego...
	//bool bandera = false;
	int salirJuego = false;
	while (salirJuego == false)
	{

		//Maquina de estados
		switch (estado)
		{
		case Estado::ESTADO_INICIANDO:
			
			Iniciando();
			estado = ESTADO_MENU;
			//printf("\nEstado Iniciando");
			
			
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
			menu->Pintar();
			texto->Pintar(MODULO_TEXTO_TITULO, 250, 30);
			
			texto->Pintar(MODULO_TEXTO_NOMBRE, 300, 400);
			Menu();


			//titulos->Pintar();
			//SDL_FillRect(screen, NULL, 0000000);

			SDL_Flip(screen);
			keys = SDL_GetKeyState(NULL);
			//botonInicio->Pintar();
			if (keys[SDLK_UP])
			{
			estado = ESTADO_JUGANDO;
			}
			//botonInicio->Pintar();
			if (keys[SDLK_DOWN]){
				//btnSalir= new Nave(screen,"../Data/btnSalir.bmp",0,0,1);
				//botonSalir->Pintar();
				estado = ESTADO_FINALIZADO;
				//salirJuego = true;
				
			}
			break;

			
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
			/*if (bandera==false)
			{
				estado = ESTADO_JUGANDO;
				printf("\nEstado Menu");

			}
				else
			{
				estado = ESTADO_TERMINANDO;
				printf("\nEstado Menu");
			}*/
						
		case Estado::ESTADO_JUGANDO:
			//SDL_FillRect(screen, NULL, 0x000000);
			SDL_FillRect(screen, NULL, 0x000000);
			keys = SDL_GetKeyState(NULL);
			for (int i = 0; i<10; i++)
			enemigoArreglo[i]->Actualizar();

			MoverEnemigo();			
			
			if (keys[SDLK_RIGHT] && !esLimitePantalla(nave, BORDE_DERECHO))
			{
				//nave->PintarModulo(0, 0, 0, 64, 64);
				nave->Mover(7);
				if (esLimitePantalla(nave, BORDE_DERECHO))
				{
					nave->MoverIzquierda(7);
				}
				/*Iniciando();
				estado = ESTADO_MENU;*/
			}

			if (keys[SDLK_LEFT] && !esLimitePantalla(nave, BORDE_IZQUIERDO))
			{
				//nave->PintarModulo(0, 0, 0, 64, 64);
				nave->MoverIzquierda(7);
				if (esLimitePantalla(nave, BORDE_IZQUIERDO))
				{
					nave->Mover(7);
				}
				/*Iniciando();
				estado = ESTADO_MENU;*/
			}
			if (keys[SDLK_UP] && !esLimitePantalla(nave, BORDE_SUPERIOR))
			{

				nave->MoverArriba(7);
				if (esLimitePantalla(nave, BORDE_SUPERIOR))
				{
					nave->MoverAbajo(7);
				}

			}
			if (keys[SDLK_DOWN] && !esLimitePantalla(nave, BORDE_INFERIOR))
			{

				nave->MoverAbajo(7);
				if (esLimitePantalla(nave, BORDE_INFERIOR))
				{
					nave->MoverArriba(7);
				}

			}
			fondo->Pintar();
			nave->Pintar();
			//MoverEnemigo();
			for (int i = 0; i<10; i++)
			enemigoArreglo[i]->Pintar();
			MoverEnemigo();

			
			nave->Pintar();
			break;
		case Estado::ESTADO_FINALIZADO:
			/*estado = ESTADO_MENU;
			printf("\nEstado Finalizado");
			bandera = true;*/
			break;
		case Estado::ESTADO_TERMINANDO:
			
			/*printf("\nEstado Terminando");
			getchar();*/
			salirJuego = true;
			break;
		};
		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT) { salirJuego = true; }
			if (event.type == SDL_KEYDOWN) {}
		}
		SDL_Flip(screen);// imprimir en pantalla la variable screen

		frames++;
		tiempoFrameFinal = SDL_GetTicks();
		while (tiempoFrameFinal<(tiempoFrameInicio + FPS_DELAY)){
			tiempoFrameFinal = SDL_GetTicks();
			SDL_Delay(1);
		}
		//printf("Frame:%d Tiempo:%d TiempoPorFrame:%d FPS:%f\n", frames, tiempoFrameInicio, tiempoFrameFinal - tiempoFrameInicio, 1000.0f / (float)(tiempoFrameFinal - tiempoFrameInicio));
		tiempoFrameInicio = tiempoFrameFinal;

	}
	return true;
}


bool CGame::esLimitePantalla(Nave *objeto, int bandera){
	if (bandera & BORDE_IZQUIERDO) //CTRL + ESPACIO// & para valores binarios y 
	if (objeto->obtenerX() <= 0)//revisar bordes falso o verdadero//
		return true;
	if (bandera & BORDE_SUPERIOR)
	if (objeto->obtenerY() <= 0)
		return true;
	if (bandera & BORDE_DERECHO)
	if (objeto->obtenerX() >= (WIDTH_SCREEN - objeto->obtenerW()))
		return true;
	if (bandera & BORDE_INFERIOR)
	if (objeto->obtenerY() >= (HEIGHT_SCREEN - objeto->obtenerH()))
		return true;
	return false;// si se cumplen todas las condiciones quiere decir que estamos adentro de la pantalla//
}


//bool CGame::esLimitePantalla(Nave *objeto, int bandera)
//{
//	if (objeto->obtenerX() <= 0 || objeto->obtenerX() > (WIDTH_SCREEN - objeto->obtenerW() ))
//	
//		return true;
//
//	if (objeto->obtenerY() <= 0 || objeto->obtenerY() > (HEIGHT_SCREEN - objeto->obtenerH()))
//	
//		return true;
//	
//	return false;
//}
void CGame::MoverEnemigo(){
	//	if(!esLimitePantalla(enemigo,BORDE_DERECHO))
	//enemigo->Mover(1,50);
	/*
	switch(enemigo->ObtenerStepActual()){
	case 0:
	if(!enemigo->IsRunningAnimacion())
	//enemigo->IncrementarStep();
	enemigo->Mover(1,WIDTH_SCREEN-enemigo->obtenerW());
	break;
	case 1:
	enemigo->IncrementarStep();
	break;
	case 2:

	if (!enemigo->IsRunningAnimacion())

	enemigo->Mover(-1,WIDTH_SCREEN-enemigo->obtenerW());
	//enemigo->IncrementarSenemigo->Mover(-1,150);
	// enemigo->IncrementarStep();

	break;
	case 3:
	enemigo->IncrementarStep();
	break;
	}
	*/
	//enemigo->ponerEn(enemigoParabola*enemigoParabola,enemigoParabola);
	//enemigoParabola+=0.1f;
	//copia sw-------------
	for (int i = 0; i<10; i++)
		switch (enemigoArreglo[i]->ObtenerStepActual()){
		case 0:
			if (!enemigoArreglo[i]->IsRunningAnacion())
				//enemigoArreglo[i]->IncrementarStep();
				enemigoArreglo[i]->Mover(5, WIDTH_SCREEN );
				
			
			if (esLimitePantalla(enemigoArreglo[i], BORDE_DERECHO))
				//enemigoArreglo[i]->Mover(5, WIDTH_SCREEN - enemigoArreglo[i]->obtenerW());
				enemigoArreglo[i]->TerminacionAnimacion();
				//enemigoArreglo[i]->Mover(-5, -640);

		
			break;
		case 1:
			enemigoArreglo[i]->IncrementarStep();
			
			break;
		case 2:
			if (!enemigoArreglo[i]->IsRunningAnacion())
				
				enemigoArreglo[i]->Mover(-5, WIDTH_SCREEN);



			if (esLimitePantalla(enemigoArreglo[i], BORDE_IZQUIERDO))
				enemigoArreglo[i]->TerminacionAnimacion();

			break;
		case 3:
			enemigoArreglo[i]->IncrementarStep();
			break;
	}

}
void CGame::Menu()
{
	for (int i = MODULO_TEXTO_OPCION1, j = 0; i <= MODULO_TEXTO_OPCION2; i++, j++)
	{	
		if (i == menuSeleccion)
			texto->Pintar(i+MENU_NUMERO_ELEMENTOS, 150, 130 + (j * 50));

		else

			texto->Pintar(i, 150, 130+(j*50));

	}
}