


Bitmap* bottomPipe=NULL;

Bitmap* getBotPipeBitmap(){

	if(!bottomPipe)
		bottomPipe= loadBitmap("xxxxx");

	return bottomPipe;
}
Bitmap** get BotPipeBitmapPointer(){

	return &bottomPipe;
}

Pipe* newPipe(int x, int groundY){

	Pipe* pipe = (Pipe* )malloc(sizeof(Pipe));

	pipe->x =x;

	pipe->y = rand()%(groundY - GAP);

	pipe->imgW=getBotPipeBitmap()->bitmapInfoHeader.width;
	pipe->imgH = getBotPipeBitmap()->bitmapInfoHeader.height;

	return pipe;

}
void updatePipe(Pipe* pipe){

	pipe->x -=20; // ground speed
}
void drawPipe(Pipe* pipe){
	drawBitmap(getBotPipeBitmap(),pipe->x,p->y +GAP,ALIGN_LEFT);

}
void deletePipe(Pipe* pipe){
	free(pipe);

}
