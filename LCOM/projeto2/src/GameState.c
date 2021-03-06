#include "GameState.h"


#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <minix/drivers.h>

#include <stdint.h>
#include <machine/int86.h>

#include "video_gr.h"
#include "kbd.h"

GameState* newGameState(){


	GameState* state = (GameState*) malloc(sizeof(GameState));

	state->done=0;
	state->backgroundX=0;
	state->background = loadBitmap("/home/lcom/projeto/src/images/flappy_floor.bmp");
	state->back = loadBitmap("/home/lcom/projeto/src/images/flappy_fundo.bmp");

	state->mario =(Mario*) createMario();


	return state;



}

void moveBackground(GameState* state){

	state->backgroundX-=40;
	int backgroundWidth = state->background-> bitmapInfoHeader.width;
	if(state->backgroundX + backgroundWidth >= getXResolution())
		state->backgroundX=0;

}
void updateGameState(GameState* state,unsigned long scancode){
	if(scancode == 0x4D || scancode == 0x4B)
		moveBackground(state);


}

void drawGameState(GameState* state){
	//drawBitmap(state->back, state->backgroundX, 0, ALIGN_LEFT);
	drawBitmap(state->back, 0, 160, ALIGN_LEFT);
	drawBitmap(state->background, state->backgroundX, 550, ALIGN_LEFT);


}
void deleteGameState(GameState* state){
	deleteBitmap(state->background);
	free(state);



}
