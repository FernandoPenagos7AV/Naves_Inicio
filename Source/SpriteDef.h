#ifndef __SPRITEDEF_H__
#define __SPRITEDEF_H__

class SpriteDef{
	struct Modulo
	{
		int id;
		int x;
		int y;
		int w;
		int h;
	};
public:
		Modulo modulos[9];// Tipo Nombre [espacio de la estructura]
	SpriteDef();//constructor
};


#endif

