# pragma once

#include "Bitmap.h"

typedef struct {

	int x,y
	int imgW,imgH;
}Pipe;

Bitmap* getBotPipeBitmap();
Bitmap** get BotPipeBitmapPointer();

Pipe* newPipe(int x, int groundY);
void updatePipe(Pipe* pipe);
void drawPipe(Pipe* pipe);
void deletePipe(Pipe* pipe);

