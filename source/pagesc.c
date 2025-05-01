#include"common.h"
#include"pagesc.h"
int psubjectchoose(int(*subjectchoice)[20],int*college,int* click,int(*sign1)[20],int*sign2)
{
	
	int i ;
	int j;
	
	j=*college;
	*sign2=0;
	clrmous(MouseX,MouseY);
	delay(100);
	
	
    pscscreen();
 	mouseinit();   
    while(1)
    {
    	newmouse(&MouseX,&MouseY,&press);
    	if(click[*college]<4)
    	{
		
    	if(mouse_press(50+20,100+20,300,100+20+30)==1&&sign1[j][1]==0)
    	{
    		subjectchoice[j][click[*college]]=1;
    		click[*college]=click[*college]+1; 
    		sign1[j][1]=1;
    		
    		
    			return 17;
    		
		}
		else if(mouse_press(50+20,100+20+30+22,300,100+20+30+30+22)==1&&sign1[j][2]==0)
    	{
    		subjectchoice[j][click[*college]]=2;
    		click[*college]=click[*college]+1; 
    		sign1[j][2]=1;
    		
    	
    			return 17;
    		
		}
		else if(mouse_press(50+20,100+20+52+52,300,100+20+30+52+52)==1&&sign1[j][3]==0)
    	{
    		subjectchoice[j][click[*college]]=3;
    		click[*college]=click[*college]+1; 
    		sign1[j][3]=1;
    		
    	
    			return 17;
    		
		}
		else if(mouse_press(50+20,100+20+156,300,100+20+30+156)==1&&sign1[j][4]==0)
    	{
    		subjectchoice[j][click[*college]]=4;
    		click[*college]=click[*college]+1; 
    		sign1[j][4]=1;
    		
    	
    			return 17;
    		
		}
		else if(mouse_press(50+20,100+20+208,300,100+20+30+208)==1&&sign1[j][5]==0)
    	{
    		subjectchoice[j][click[*college]]=5;
    		click[*college]=click[*college]+1; 
    		sign1[j][5]=1;
    		
    	
    			return 17;
    		
		}
	   else if(mouse_press(50+20,100+20+260,300,100+20+30+260)==1&&sign1[j][6]==0)
    	{
    		subjectchoice[j][click[*college]]=6;
    		click[*college]=click[*college]+1; 
    		sign1[j][6]=1;
    		
    	
    			return 17;
    		
		}
		else if(mouse_press(50+20+270,100+20,300+270,100+20+30)==1&&sign1[j][7]==0)
    	{
    		subjectchoice[j][click[*college]]=7;
    	click[*college]=click[*college]+1; 
    		sign1[j][7]=1;
    		
    	
    			return 17;
    		
		}
		else if(mouse_press(50+20+270,100+20+52,300+270,100+20+30+52)==1&&sign1[j][8]==0)
    	{
    		subjectchoice[j][click[*college]]=8;
    		click[*college]=click[*college]+1; 
    		sign1[j][8]=1;
    		
    	
    			return 17;
    		
		}
		
		else if(mouse_press(50+20+270,100+20+104,300+270,100+20+30+104)==1&&sign1[j][9]==0)
    	{
    		subjectchoice[j][click[*college]]=9;
    	click[*college]=click[*college]+1; 
    		sign1[j][9]=1;
    		
    	
    			return 17;
    		
		}
		else if(mouse_press(50+20+270,100+20+156,300+270,100+20+30+156)==1&&sign1[j][10]==0)
    	{
    		subjectchoice[j][click[*college]]=10;
    	click[*college]=click[*college]+1; 
    		sign1[j][10]=1;
    		
    	
    			return 17;
    		
		}
		else if(mouse_press(50+20+270,100+20+208,300+270,100+20+30+208)==1&&sign1[j][11]==0)
    	{
    		subjectchoice[j][click[*college]]=11;
    	click[*college]=click[*college]+1; 
    		sign1[j][11]=1;
    		
    	
    			return 17;
    		
		}
		else if(mouse_press(50+20+270,100+20+260,300+270,100+20+30+260)==1&&sign1[j][12]==0)
    	{
    		subjectchoice[j][click[*college]]=12;
    		click[*college]=click[*college]+1; 
    		sign1[j][12]=1;
    		
    	
    			return 17;
    		
		}
		else if(mouse_press(5,5,20,20)==1)	
		{
			return 17;
		}
	
	     
        }
    else if(click[*college]>=4)
    {
    	if(mouse_press(50+20,100+20,300,100+20+30)==1)
    	{
    		
    		sign1[j][1]=0;
    		click[*college]=click[*college]+1; 
    		
    		
    			return 17;
    		
		}
		else if(mouse_press(50+20,100+20,300,100+20+30)==1)
    	{
    		
    		sign1[j][2]=0;
    		click[*college]=click[*college]+1; 
    		
    		
    			return 17;
    		
		}
		
		else if(mouse_press(50+20,100+20,300,100+20+30)==1)
    	{
    		
    		sign1[j][3]=0;
    		click[*college]=click[*college]+1; 
    		
    		
    			return 17;
    		
		}
		else if(mouse_press(50+20,100+20,300,100+20+30)==1)
    	{
    		
    		sign1[j][4]=0;
    		click[*college]=click[*college]+1; 
    		
    		
    			return 17;
    		
		}
		else if(mouse_press(50+20,100+20,300,100+20+30)==1)
    	{
    		
    		sign1[j][5]=0;
    		click[*college]=click[*college]+1; 
    		
    		
    			return 17;
    		
		}
	   else if(mouse_press(50+20,100+20,300,100+20+30)==1)
    	{
    		
    		sign1[j][6]=0;
    		click[*college]=click[*college]+1; 
    		
    		
    			return 17;
    		
		}
		else if(mouse_press(50+20,100+20,300,100+20+30)==1)
    	{
    		
    		sign1[j][7]=0;
    		click[*college]=click[*college]+1; 
    		
    		
    			return 17;
    		
		}
		else if(mouse_press(50+20,100+20,300,100+20+30)==1)
    	{
    		
    		sign1[j][8]=0;
    		click[*college]=click[*college]+1; 
    		
    		
    			return 17;
    		
		}
		
		else if(mouse_press(50+20,100+20,300,100+20+30)==1)
    	{
    		
    		sign1[j][9]=0;
    		click[*college]=click[*college]+1; 
    		
    		
    			return 17;
    		
		}
		else if(mouse_press(50+20,100+20,300,100+20+30)==1)
    	{
    		
    		sign1[j][10]=0;
    		click[*college]=click[*college]+1; 
    		
    		
    			return 17;
    		
		}
		else if(mouse_press(50+20,100+20,300,100+20+30)==1)
    	{
    		
    		sign1[j][11]=0;
    		click[*college]=click[*college]+1; 
    		
    		
    			return 17;
    		
		}
		else if(mouse_press(50+20,100+20,300,100+20+30)==1)
    	{
    		
    		sign1[j][12]=0;
    		click[*college]=click[*college]+1; 
    		
    		
    			return 17;
    		
		}
		else if(mouse_press(5,5,20,20)==1)	
		{
			return 17;
		}
	}
}
	
	
} 

void pscscreen(void)
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
	puthz(70,50,"专业选择榜",24,25,RED);
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
	bar(50+20,100+20,300,100+20+30);
	puthz(50+80+20+10,100+20+5,"人工智能",24,30,YELLOW);
	settextstyle(0,0,2);
	outtextxy(50+20+10,100+20+8,"No.1");
	
	
	setcolor(RED);
	bar(50+20,100+20+30+22,300,100+20+30+30+22);
	puthz(50+80+20+10,100+20+5+52,"计算机",24,35,YELLOW);
	settextstyle(0,0,2);
	outtextxy(50+20+10,100+20+8+52,"No.2");
	
	setcolor(RED);
	bar(50+20,100+20+52+52,300,100+20+30+52+52);
	puthz(50+80+20+10,100+20+5+104,"自动化",24,35,YELLOW);
	settextstyle(0,0,2);
	outtextxy(50+20+10,100+20+8+104,"No.3");
	 
	setcolor(RED);
	bar(50+20,100+20+156,300,100+20+30+156);
	puthz(50+80+20+10,100+20+5+156,"电气工程",24,30,YELLOW);
	settextstyle(0,0,2);
	outtextxy(50+20+10,100+20+8+156,"No.4");
	
	setcolor(RED);
	bar(50+20,100+20+208,300,100+20+30+208);
	puthz(50+80+20+10,100+20+5+208,"临床医学",24,30,YELLOW);
	settextstyle(0,0,2);
	outtextxy(50+20+10,100+20+8+208,"No.5");
	
	setcolor(RED);
	bar(50+20,100+20+260,300,100+20+30+260);
	puthz(50+80+20+10,100+20+5+260,"数学学科",24,30,YELLOW);
	settextstyle(0,0,2);
	outtextxy(50+20+10,100+20+8+260,"No.6");
	
	/**********************/
	
	setcolor(RED);
	bar(50+20+270,100+20,300+270,100+20+30);
	puthz(50+80+20+10+270,100+20+5,"物理学科",24,30,YELLOW);
	settextstyle(0,0,2);
	outtextxy(50+20+10+270,100+20+8,"No.7");
	
	
	setcolor(RED);
	bar(50+20+270,100+20+52,300+270,100+20+30+52);
	puthz(50+80+20+10+270,100+20+5+52,"能源学科",24,30,YELLOW);
	settextstyle(0,0,2);
	outtextxy(50+20+10+270,100+20+8+52,"No.8");
	
	
	setcolor(RED);
	bar(50+20+270,100+20+104,300+270,100+20+30+104);
	puthz(50+80+20+10+270,100+20+5+104,"机械工程",24,30,YELLOW);
	settextstyle(0,0,2);
	outtextxy(50+20+10+270,100+20+8+104,"No.9");
	
	setcolor(RED);
	bar(50+20+270,100+20+156,300+270,100+20+30+156);
	puthz(50+80+20+10+270,100+20+5+156,"法学学科",24,30,YELLOW);
	settextstyle(0,0,2);
	outtextxy(50+20+10+270,100+20+8+156,"No.10");
	
	setcolor(RED);
	bar(50+20+270,100+20+208,300+270,100+20+30+208);
	puthz(50+80+20+10+270,100+20+5+208,"语言学科",24,30,YELLOW);
	settextstyle(0,0,2);
	outtextxy(50+20+10+270,100+20+8+208,"No.11");
	
	setcolor(RED);
	bar(50+20+270,100+20+260,300+270,100+20+30+260);
	puthz(50+80+20+10+270,100+20+5+260,"哲学学科",24,30,YELLOW);
	settextstyle(0,0,2);
	outtextxy(50+20+10+270,100+20+8+260,"No.12");
	
	
}
