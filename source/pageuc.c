#include"common.h"
#include"pageuc.h"

int pschoolchoose(int* university,int*count, int* flag2,int*flag1)
{
	int cnt=*count;
	int i ;
	*flag2=0;
	clrmous(MouseX,MouseY);
	delay(100);
	

    pschoolchoosescreen();
 	mouseinit();   	
    while(1)
    {
    	newmouse(&MouseX,&MouseY,&press);
    	if(*count<4)
    	{
    		if(mouse_press(50+20,100+40,300,100+40+30)==1&&flag1[1]==0)
    	{
    		university[cnt]=1;
    		*count=cnt+1;
    		flag1[1]=1;
    		
    		*flag2=0;
    			return 15;
    		
		}
		else if(mouse_press(50+20,100+40+30+25,300,100+40+30+30+25)==1&&flag1[2]==0)
    	{
    		university[cnt]=2;
    		*count=cnt+1;
    		flag1[2]=1;
    		*flag2=0;
    			return 15;
		}
		else if(mouse_press(50+20,100+40+55+55,300,100+40+30+55+55)==1&&flag1[3]==0)
    	{
    		university[cnt]=3;
    		*count=cnt+1;
    		flag1[3]=1;
    		*flag2=0;
    			return 15;
		}
		else if(mouse_press(50+20,100+40+165,300,100+40+30+165)==1&&flag1[4]==0)
    	{
    		university[cnt]=4;
    		*count=cnt+1;
    		flag1[4]=1;
    		*flag2=0;
    			return 15;
		}
		else if(mouse_press(50+20,100+40+220,300,100+40+30+220)==1&&flag1[5]==0)
    	{
    		university[cnt]=5;
    		*count=cnt+1;
    		flag1[5]=1;
    		*flag2=0;
    			return 15;
		}
	    else if(mouse_press(50+20+270,100+40,300+270,100+40+30)==1&&flag1[6]==0)
    	{
    		university[cnt]=6;
    		*count=cnt+1;
    		flag1[6]=1;
    		*flag2=0;
    			return 15;
		}
		else if(mouse_press(50+20+270,100+40+55,300+270,100+40+30+55)==1&&flag1[7]==0)
    	{
    		university[cnt]=7;
    		*count=cnt+1;
    		flag1[7]=1;
    		*flag2=0;
    			return 15;
		}
		else if(mouse_press(50+20+270,100+40+110,300+270,100+40+30+110)==1&&flag1[8]==0)
    	{
    		university[cnt]=8;
    		*count=cnt+1;
    		flag1[8]=1;
    		*flag2=0;
    			return 15;
		}
		else if(mouse_press(50+20+270,100+40+165,300+270,100+40+30+165)==1&&flag1[9]==0)
    	{
    		university[cnt]=9;
    		*count=cnt+1;
    		flag1[9]=1;
    		*flag2=0;
    			return 15;
		}
		else if(mouse_press(50+20+270,100+40+220,300+270,100+40+30+220)==1&&flag1[10]==0)
    	{
    		university[cnt]=10;
    		*count=cnt+1;
    		flag1[10]=1;
    		*flag2=0;
    			return 15;
		}
		else if(mouse_press(5,5,20,20)==1)	
		{
			return 15;
		}
	
	
     	}
     	else if(*count>=4)
     	{
     		if(mouse_press(50+20,100+40,300,100+40+30)==1)
     		{
     			*count=*count+1;
     			flag1[1]=0;
     			return 15;
     			
			 }
			else if(mouse_press(50+20,100+40+30+25,300,100+40+30+30+25)==1)
			{
				*count=*count+1;
				flag1[2]=0;
				return 15;
			}
			else if(mouse_press(50+20,100+40+55+55,300,100+40+30+55+55)==1)
			{
				*count=*count+1;
				flag1[3]=0;
				return 15;
			}
			else if(mouse_press(50+20,100+40+165,300,100+40+30+165)==1)
			{
				*count=*count+1;
				flag1[4]=0;
				return 15;
			}
			else if(mouse_press(50+20,100+40+220,300,100+40+30+220)==1)
			{
				*count=*count+1;
				flag1[5]=0;
				return 15;
			}
			else if(mouse_press(50+20+270,100+40,300+270,100+40+30)==1)
			{
				*count=*count+1;
				flag1[6]=0;
				return 15;
			}
			else if(mouse_press(50+20+270,100+40+55,300+270,100+40+30+55)==1)
			{
				*count=*count+1;
				flag1[7]=0;
				return 15;
			}
			else if(mouse_press(50+20+270,100+40+110,300+270,100+40+30+110)==1)
			{
				*count=*count+1;
				flag1[8]=0;
				return 15;
			}
			else if(mouse_press(50+20+270,100+40+165,300+270,100+40+30+165)==1)
			{
				*count=*count+1;
				flag1[9]=0;
				return 15;
			}
			else if(mouse_press(50+20+270,100+40+220,300+270,100+40+30+220)==1)
			{
				*count=*count+1;
				flag1[10]=0;
				return 15;
			}
			else if(mouse_press(5,5,20,20)==1)	
		{
			return 15;
		}
     		
		}
	
	
   }
	
}




void pschoolchoosescreen(void)
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
	setlinestyle(0,0,1);
	setfillstyle(1,DARKGRAY);
	bar(50,40,200,80);
	puthz(70,50,"高校排名榜",24,25,RED);
	bar(240,40,590,80);
	circle(260,55,10);
	setfillstyle(1,WHITE);
	floodfill(260,55,WHITE);
	bar(257,55,263,70);
	setcolor(BLACK);
	circle(260,55,8);
	setcolor(RED);
	rectangle(50,100,590,430);
	setfillstyle(1,WHITE);
	bar(52,102,588,428);
	setcolor(RED);
	setlinestyle(0,0,3);
	line(320,100,320,430);
	setfillstyle(1,LIGHTBLUE);
	
	setcolor(RED);
	bar(50+20,100+40,300,100+40+30);
	puthz(50+80+20+10,100+40+5,"清华大学",24,30,YELLOW);
	settextstyle(0,0,2);
	outtextxy(50+20+10,100+40+8,"No.1");
	setcolor(LIGHTBLUE);
	rectangle(50+20,100+40,300,100+40+30);
	
	setcolor(RED);
	bar(50+20,100+40+30+25,300,100+40+30+30+25);
	puthz(50+80+20+10,100+40+5+55,"北京大学",24,30,YELLOW);
	settextstyle(0,0,2);
	outtextxy(50+20+10,100+40+8+55,"No.2");
	
	setcolor(RED);
	bar(50+20,100+40+55+55,300,100+40+30+55+55);
	puthz(50+80+20+10,100+40+5+110,"浙江大学",24,30,YELLOW);
	settextstyle(0,0,2);
	outtextxy(50+20+10,100+40+8+110,"No.3");
	 
	setcolor(RED);
	bar(50+20,100+40+165,300,100+40+30+165);
	puthz(50+80+20+10,100+40+5+165,"上海交通大学",16,21,YELLOW);
	settextstyle(0,0,2);
	outtextxy(50+20+10,100+40+8+165,"No.4");
	
	setcolor(RED);
	bar(50+20,100+40+220,300,100+40+30+220);
	puthz(50+80+20+10,100+40+5+220,"复旦大学",24,30,YELLOW);
	settextstyle(0,0,2);
	outtextxy(50+20+10,100+40+8+220,"No.5");
	
	/**********************/
	
	setcolor(RED);
	bar(50+20+270,100+40,300+270,100+40+30);
	puthz(50+80+20+10+270,100+40+5,"南京大学",24,30,YELLOW);
	settextstyle(0,0,2);
	outtextxy(50+20+10+270,100+40+8,"No.6");
	
	
	setcolor(RED);
	bar(50+20+270,100+40+55,300+270,100+40+30+55);
	puthz(40+80+20+10+270,100+40+5+55,"中国科学技术大学",16,18,YELLOW);
	settextstyle(0,0,2);
	outtextxy(50+20+10+270,100+40+8+55,"No.7");
	
	
	setcolor(RED);
	bar(50+20+270,100+40+110,300+270,100+40+30+110);
	puthz(50+80+20+10+270,100+40+5+110,"华中科技大学",16,21,YELLOW);
	settextstyle(0,0,2);
	outtextxy(50+20+10+270,100+40+8+110,"No.8");
	
	setcolor(RED);
	bar(50+20+270,100+40+165,300+270,100+40+30+165);
	puthz(50+80+20+10+270,100+40+5+165,"武汉大学",24,30,YELLOW);
	settextstyle(0,0,2);
	outtextxy(50+20+10+270,100+40+8+165,"No.9");
	
	setcolor(RED);
	bar(50+20+270,100+40+220,300+270,100+40+30+220);
	puthz(50+80+20+10+270,100+40+5+220,"西安交通大学",16,21,YELLOW);
	settextstyle(0,0,2);
	outtextxy(50+20+10+270,100+40+8+220,"No.10");
}
