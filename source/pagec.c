#include"common.h"
#include"pagec.h"

int pc(int*sorts,int*subjects)
{

	/*int page,flag;
	page=1;
	flag=0;*/
	delay(100);
	clrmous(MouseX,MouseY);
	pcscreen();
		mouseinit();
	if(*sorts==1)
	{
	puthz(160,150,"何为工科",24,30,LIGHTRED);
	puthz(370,150,"何为理科",24,30,LIGHTRED);
	puthz(160,310,"何为文科",24,30,LIGHTRED);
    puthz(360,310,"何为医科",24,30,LIGHTRED);
	}
	else if(*sorts==2)
	{
	puthz(145,150,"电气自动化",24,30,LIGHTRED);
	puthz(370,150,"人工智能",24,30,LIGHTRED);
	puthz(160,310,"机械制造",24,30,LIGHTRED);
    puthz(360,310,"能源工程",24,30,LIGHTRED);
	}
	else if(*sorts==3)
	{
	puthz(190,150,"数学",24,30,LIGHTRED);
	puthz(400,150,"物理",24,30,LIGHTRED);
	puthz(145,310,"计算机科学",24,30,LIGHTRED);
    puthz(390,310,"化学",24,30,LIGHTRED);
	}
	else if(*sorts==4)
	{
	puthz(190,150,"法学",24,30,LIGHTRED);
	puthz(400,150,"哲学",24,30,LIGHTRED);
	puthz(160,310,"语言学",24,30,LIGHTRED);
    puthz(390,310,"临床医学",24,30,LIGHTRED);
	}
	

    
	

	while(1){
		
		newmouse(&MouseX,&MouseY,&press);
		if(mouse_press(140,140,290,180) == 1)//鼠标在登录框中，且点击
		{
			*subjects=1;
			return 13;
			
		}
		else if(mouse_press(350,140,500,180) == 1)//鼠标在返回框中，且点击
				{
					*subjects=2;
					return 13;
					
					
				}
		else if(mouse_press(140,300,290,340) == 1)//鼠标在返回框中，且点击
				{
					*subjects=3;
					return 13;
					
					
				}
		else if(mouse_press(350,300,500,340) == 1)//鼠标在返回框中，且点击
				{
					*subjects=4;
					return 13;
					
					
				}
		else if(mouse_press(5,5,20,20) == 1)//鼠标在返回框中，且点击
				{
					return 11;
					
					
				}
		}
}
				
		

void pcscreen(void)
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
	
	setfillstyle(1,DARKGRAY);
	rectangle(350,140,500,180);
	bar(350,140,500,180);

	arc(350,140,0,270,15);
	setfillstyle(1,BLACK);
	pieslice(350,140,0,270,15);
	
	setfillstyle(1,DARKGRAY);
	rectangle(140,300,290,340);
	bar(140,300,290,340);
	
	arc(140,300,0,270,15);
	setfillstyle(1,BLACK);
	pieslice(140,300,0,270,15);
	
	setfillstyle(1,DARKGRAY);
	rectangle(350,300,500,340);
	bar(350,300,500,340);
	
	arc(350,300,0,270,15);
	setfillstyle(1,BLACK);
	pieslice(350,300,0,270,15);
	
	setcolor(YELLOW);
	rectangle(80,80,560,400);
	rectangle(65,65,90,90);
	rectangle(575,415,550,390);
	rectangle(65,415,90,390);
	rectangle(575,65,550,90);
	
	
}
