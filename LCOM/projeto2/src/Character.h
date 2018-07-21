#pragma once

#include "Bitmap.h"


typedef struct {
	int x,y,w,h,v;
	Bitmap* sprite;
}Character;

Character* createCharacter();
void updateCharacter(Character* personagem);
void updateCharacterKbd(Character* personagem);
void drawCharacter(Character* personagem);
void deleteCharacter(Character* personagem);


#endif
