#include"common.h"
#include"wait.h"

void wait1(char *s)
{
	int i=0;
	setfillstyle(1,WHITE);
	bar(150,160,490,320);
	setcolor(YELLOW);
	setlinestyle(0,0,3);
	rectangle(150,160,490,320);
	puthz(235-45,200,s,32,34,BLACK);
	setcolor(BLACK);
	rectangle(240,260,400,290);
	setfillstyle(1,GREEN);
	for(i=1;i<160;i++)
	{
		bar(241,261,239+i,289);
		delay(8);
	}
	bar(241,261,399,289);
	delay(300);
	
}

void wait(void)
{
	circle(250-20,300,20);
	floodfill(250-20,300,BROWN);
	delay(700);
	circle(310-20,300,20);
	floodfill(310-20,300,BROWN);
	delay(700);
	circle(370-20,300,20);	
	floodfill(370-20,300,BROWN);
	delay(700);
		
}

void waitbk(char *s)
{
	cleardevice();
	setbkcolor(MAGENTA);
	setfillstyle(1, WHITE);
	bar(10, 10, 640 - 10, 480 - 10);
	setcolor(BROWN);
	setlinestyle(0, 0, 3);
	rectangle(10, 10, 640 - 10, 480 - 10);
	
	puthz(180-5,170,s,48,52,BROWN);
}
