#include <graphics.h>	//EasyX
#include <conio.h>		//_getch
#include"Command.h"
#include"shape.h"
int main()
{
	initgraph(1280, 720);	//initialize graphics

	IMAGE	img_bg;		//background image
	IMAGE	img_menu;	//menu image

	// load images
	loadimage(&img_bg, "E:\\desktop\\CourseDesigh\\OOPCPPCD\\data\\image.jpg");
	loadimage(&img_menu, "E:\\desktop\\CourseDesigh\\OOPCPPCD\\data\\MapDraw_UI.png");
	// display images
	putimage(200, 0, &img_bg);
	putimage(0, 0, &img_menu);

	//消息处理
	Command cmd;
	cmd.run();

	closegraph();	//close graphics
	return 0;
}