#ifndef __SPRITEDEF_H__
#define  __SPRITEDEF_H__

class SpriteDef
{
	struct Modulo
	{
		int id;
		int x;
		int y;
		int w;
		int h;	
	};
public :
	Modulo modulo[1]; //Tipo nombre y numero de arreglo para la estructura
	SpriteDef(); //Constructor

};

#endif

	