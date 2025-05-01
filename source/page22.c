/*******此为专业介绍界面分为基本常识，工科，理科，以及 文科&医科*****/ 




#include"common.h"
#include"page22.h"

int p22(int* sorts)
{
	clrmous(MouseX,MouseY);
	delay(100);
	
	
    p22screen();
    	mouseinit();
    while(1)
    {
    	newmouse(&MouseX,&MouseY,&press);
    	
    	 if(mouse_press(140,140,290,180) == 1)//鼠标在登录框中，且点击
		{   *sorts=1;
			return 12;
			
		}
		else if(mouse_press(350,140,500,180) == 1)//鼠标在返回框中，且点击
				{
					*sorts=2;
					return 12;
					
					
				}
		else if(mouse_press(140,300,290,340) == 1)//鼠标在登录框中，且点击
		{   
		    *sorts=3;
			return 12;
			
		}
		else if(mouse_press(350,300,500,340) == 1)//鼠标在登录框中，且点击
		{   
		    *sorts=4;
			return 12;
			
		}
		else if(mouse_press(5,5,20,20) == 1)//鼠标在返回框中，且点击
				{
					return 7;
					
			}
}
}
			
	

void p22screen(void)
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
	
	
	setfillstyle(1,DARKGRAY);
	rectangle(140,140,290,180);
	bar(140,140,290,180);
	
	
	arc(140,140,0,270,15);
	setfillstyle(1,BLACK);
	pieslice(140,140,0,270,15);
	puthz(160,150,"基本常识",24,30,LIGHTRED);
	
	setfillstyle(1,DARKGRAY);
	rectangle(350,140,500,180);
	bar(350,140,500,180);

	arc(350,140,0,270,15);
	setfillstyle(1,BLACK);
	pieslice(350,140,0,270,15);
	puthz(400,150,"工科",24,30,LIGHTRED);
	
	setfillstyle(1,DARKGRAY);
	rectangle(140,300,290,340);
	bar(140,300,290,340);
	
	arc(140,300,0,270,15);
	setfillstyle(1,BLACK);
	pieslice(140,300,0,270,15);
	puthz(190,310,"理科",24,30,LIGHTRED);
	
	setfillstyle(1,DARKGRAY);
	rectangle(350,300,500,340);
	bar(350,300,500,340);
	
	arc(350,300,0,270,15);
	setfillstyle(1,BLACK);
	pieslice(350,300,0,270,15);
	puthz(360,310,"文科医科",24,30,LIGHTRED);
	
	setcolor(YELLOW);
	rectangle(80,80,560,400);
	rectangle(65,65,90,90);
	rectangle(575,415,550,390);
	rectangle(65,415,90,390);
	rectangle(575,65,550,90);
	
	



}
