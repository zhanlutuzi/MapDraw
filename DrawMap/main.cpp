
#include "Commander.h"
#include <graphics.h>
using namespace MapDraw;

	void loadImageUI();	//前向声明，加载UI

	int main()
	{
		initgraph(1280, 720);	//initialize graphics

		IMAGE	img_bg;		//background image
		IMAGE	img_menu;	//menu image

		loadImageUI();

		//消息处理
		Commander cmd;
		cmd.Run();

		closegraph();	//close graphics
		return 0;
	}

	void loadImageUI()
	{
		IMAGE	img_bg;
		IMAGE	img_menu;

		loadimage(&img_bg, "E:\\desktop\\CourseDesigh\\OOPCPPCD\\data\\image.jpg");
		loadimage(&img_menu, "E:\\desktop\\CourseDesigh\\OOPCPPCD\\data\\MapDraw_UI.png");

		putimage(200, 0, &img_bg);
		putimage(0, 0, &img_menu);
	}

