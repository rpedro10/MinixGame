# include "Mario.h"

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <minix/drivers.h>
/**
 #include <minix/sysutil.h>
 #include <minix/syslib.h>
 #include <minix/drivers.h>
 #include <minix/driver.h>
 */
#include <stdint.h>
#include <machine/int86.h>

#include "video_gr.h"
#include "kbd.h"


Mario* createMario() {

	Mario* mario = (Mario*) malloc(sizeof(Mario));
	mario->kbd_irq = kbd_subscribe_int();
	printf("kbd_irq: %i \n", mario->kbd_irq);

	mario->timer_irq = timer_subscribe_int();
	printf("timer_irq: %i \n", mario->timer_irq);
	mario->done = 0;
	printf("mario_done: %i \n", mario->done);

	//mario->draw = 1;

	mario->scancode = 0;

	mario->x = 0;
	mario->y = 300;
	mario->size = 20;
	mario->timer = createTimer();
	mario->background = loadBitmap("/home/lcom/projeto/src/images/mario3.bmp");



	return mario;

}

void updateMario(Mario* mario) {

	//unsigned int maxHeight = getYResolution()/200;
	int newy = mario->y + 5
			;

	if (newy > 500)
		mario->y = 500;
	else
		mario->y = newy;


}



void updateMarioKbd(Mario* mario) {

	unsigned int h_res = getXResolution();

	if (mario->scancode == 0x4D && mario->x < 600)//(h_res - 20 - mario->size)) //right arrow key
			{
		mario->x += 20;
	}

	if (mario->scancode == 0x4B && mario->x > 20) //left arrow key
			{
		mario->x -= 20;
	}
	if (mario->scancode == KEY_SPACE && mario->y > 20) // space key
	{
		mario->y -= 100;
	}



}

void drawMario(Mario* mario) {
	//clear_screen(5);
	//draw_square(mario->x, mario->y, mario->size, 2);
	drawGameState(mario-> state);
	drawBitmap(mario->background, mario->x, mario->y, ALIGN_LEFT);

}

void deleteMario(Mario* mario) {
	kbd_unsubscribe_int();
	timer_unsubscribe_int();
	deleteTimer(mario->timer);
	free(mario);
}

