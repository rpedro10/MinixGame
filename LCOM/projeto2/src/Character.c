
#include "Character.h"


#include "video_gr.h"
#include "kbd.h"


Character* createCharacter(){
	Character* personagem = (Character*)malloc(sizeof(Character));

	personagem->sprite = loadBitmap("/home/lcom/projeto/src/images/mario3.bmp");

	personagem->x=0;
	personagem->y=300;
	personagem -> w = personagem->sprite->bitmapInfoHeader.width;
	personagem -> h = personagem->sprite->bitmapInfoHeader.height;

	personagem->v =0;

	return personagem;



}
void updateCharacter(Character* mario){

		int newy = mario->y + 1;

		if (newy > 500)
			mario->y = 500;
		else
			mario->y = newy;
}
void updateCharacterKbd(Character* mario){

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
			mario->y -= 50;
		}
}



void drawCharacter(Character* mario){
	drawBitmap(mario->sprite, mario->x,mario->y, ALIGN_LEFT);


}
void deleteCharacter(Character* mario){
	deleteBitmap(mario->sprite);
	free(mario);

}
