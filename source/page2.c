/*****此为游客登录界面*****/
/****分别是：大学排行榜，专业介绍 以及志愿填报三个分类****/
/****注：游客登录界面不能进行个性化服务，只能对相应的信息进行查看*****/ 



#include"common.h"
#include"page2.h"

int p2(int*flag3)
{
	clrmous(MouseX,MouseY);
	delay(100);
	
	*flag3=0;
	
	p2screen();
	mouseinit();
	
	while(1)
	{
		newmouse(&MouseX,&MouseY,&press);
		
		if(mouse_press(240,140,390,180)==1)
		{
			return 8;
		}
		else if(mouse_press(240,250,390,290)==1)
		{
			return 11;
		}
		else if(mouse_press(240,360,390,400)==1)
		{
			return 14;
		}
		else if(mouse_press(42, 367, 158, 433)==1)
		{
			return 22; 
		}
		else if(mouse_press(5,5,20,20) == 1)//鼠标在返回框中，且点击
				{
					return 0;
					
			}
	}
}
	



void p2screen(void)
{
	int v[16] ={5,13,15,5,15,8,20,8,20,17,15,17,15,20,5,13};
	cleardevice();
	setbkcolor(BLUE);
	setcolor(WHITE);
	setlinestyle(0,0,3);
	rectangle(30,30,610,450);
	setfillstyle(1,LIGHTBLUE);
	
	rectangle(0,0,25,25);
	
	fillpoly(8,v);
	bar(30,30,610,450);
	setcolor(RED);
	setlinestyle(0,0,3);
	setfillstyle(1,DARKGRAY);
	
	bar(140,35,490,95);
	setcolor(WHITE);
	puthz(175,50,"游客登录界面",32,50,RED);
	
	setfillstyle(1,DARKGRAY);
	bar(240,140,390,180);
	rectangle(240,140,390,180);
	puthz(260,150,"高校排名",24,30,LIGHTRED);

	
	setcolor(YELLOW);
	rectangle(230,130,400,190);
	rectangle(225,125,235,135);
	rectangle(395,185,405,195);
	rectangle(395,125,405,135);
	rectangle(225,185,235,195);
	
	setcolor(WHITE);
	setfillstyle(1,DARKGRAY);
	bar(240,250,390,290);
	rectangle(240,250,390,290);
	puthz(260,260,"专业介绍",24,30, LIGHTRED);
	
	
	
	
	setcolor(YELLOW);
	rectangle(230,130+110,400,190+110);
	rectangle(225,125+110,235,135+110);
	rectangle(395,185+110,405,195+110);
	rectangle(395,125+110,405,135+110);
	rectangle(225,185+110,235,195+110);
	
	setcolor(WHITE);
	setfillstyle(1,DARKGRAY);
	bar(240,360,390,400);
	rectangle(240,360,390,400);
	puthz(260,370,"搜索引擎",24,30,LIGHTRED);
	
	setcolor(YELLOW);
	rectangle(230,130+110+110,400,190+110+110);
	rectangle(225,125+110+110,235,135+110+110);
	rectangle(395,185+110+110,405,195+110+110);
	rectangle(395,125+110+110,405,135+110+110);
	rectangle(225,185+110+110,235,195+110+110);
	
	setcolor(YELLOW);
	setlinestyle(0, 0, 1);
	rectangle(35, 360, 165, 440);
	rectangle(41, 366, 157, 434);
	setlinestyle(1, 0, 1);
	setcolor(WHITE);
	rectangle(38, 363, 162, 437);
	setfillstyle(1, DARKGRAY);	
	bar(42, 367, 158, 433);
	puthz(50, 372, "高校比较", 24,24, LIGHTRED);
	puthz(75,401,"模块",24,24,LIGHTRED);
	
	
	
	
	
	
}
