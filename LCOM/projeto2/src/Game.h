#ifndef _MARIO_H
#define _MARIO_H

#include "Bitmap.h"
#include "timer.h"
#include "kbd.h"
#include "i8254.h"

typedef enum {
	MAIN_MENU_STATE,GAME_STATE

}State;

#include "GameState.h"


typedef struct {
	int kbd_irq;
	int timer_irq;
	int done;
	int draw;
	unsigned long scancode;
	Bitmap* background;

	int x;
	int y;
	int size;

	Timer* timer;

	State currentState;
	void* state;


}Mario;

Mario* createMario();
void updateMario(Mario* game);
void drawMario(Mario* game);
void deleteMario(Mario* game);
void updateMarioKbd(Mario* mario);

#endif
