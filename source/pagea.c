#include"common.h"
#include"pagea.h"

int pa(int*choice,int*flag3)
{
	
	/*int page,flag;
	page=1;
	flag=0;*/
	delay(100);
	clrmous(MouseX,MouseY);
	pascreen();
		mouseinit();
	puthz(160,150,"基本介绍",24,30,LIGHTRED);
	puthz(370,150,"录取分数",24,30,LIGHTRED);
	puthz(160,310,"学校档次",24,30,LIGHTRED);
    puthz(360,310,"优势学科",24,30,LIGHTRED);
    
    
    /*叶庭宏4.10*/  
/*	if(*flag3==1)
	{
	setfillstyle(1,LIGHTGRAY);
	bar(280,365,360,365+26);
	
	setlinestyle(0,0,1);
	rectangle(280,365,360,365+26);
	puthz(320-25,366,"返回",24,26,YELLOW);
	}
*/    
    
	while(1){
		newmouse(&MouseX,&MouseY,&press);
		if(mouse_press(140,140,290,180) == 1)//鼠标在登录框中，且点击
		{
			*choice=1;
			return 10;
			
		}
		else if(mouse_press(350,140,500,180) == 1)//鼠标在返回框中，且点击
				{
					*choice=2;
					return 10;
					
					
				}
			else if(mouse_press(140,300,290,340) == 1)//鼠标在返回框中，且点击
				{
					*choice=3;
					return 10;
					
					
				}
			else if(mouse_press(350,300,500,340) == 1)//鼠标在返回框中，且点击
				{
					*choice=4;
					return 10;
					
					
				}
				
			else if(mouse_press(5,5,20,20) == 1)//鼠标在返回框中，且点击
				{
					if(*flag3==0)
					{
						return 8;
					}
					else
					{
						return 18;
					}
					
					
				}

				
/*		if(*flag3==1)
		{	
			if(mouse_press(280,365,360,365+26)==1)
			{
				return 18; 
			}
		}							
*/				
			
	}
}

	

void pascreen(void)
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
