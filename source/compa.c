#include"common.h"
#include"main.h"


int compare( int choice[2])
{
	
	int count=0;
	int falg[11]={0};//防止重复点击一个学校 
	
	
	comparescreen();
	
	while(1)
	{
		 
		newmouse(&MouseX,&MouseY,&press);
		 
		 
		if(count==0)
		{
			if(mouse_press(50+20,100+40,300,100+40+30) == 1&&falg[0]==0 )
    	{
    		 	 
    		choice[0]=1;
    		comparelight(50+20,100+40, 230);
    		count=count+1;
    			 
    		delay(200);
    		falg[0]=1;
    			 
    	 
		}
		 if(mouse_press(50+20,100+40+30+25,300,100+40+30+30+25) == 1&&falg[1]==0  ) 
		{
			 
			 choice[0]=2;
			 comparelight(50+20,100+40+30+25 ,230);
			 count++;
			 delay(200);
			 falg[1]=1;
		 } 
		 else if(mouse_press(50+20,100+40+55+55,300,100+40+30+55+55) == 1 &&falg[2]==0  )
		 {
		 	 choice[0]=3;
		 	 comparelight(50+20,100+40+55+55 ,230);
		 	 count++;
		 	 delay(200);
		 	 falg[2]=1;
		 }
		 else if(mouse_press(50+20,100+40+55+55+55,300,100+40+30+55+55+55) == 1 &&falg[3]==0  )
		 {
		 	 choice[0]=4;
		 	comparelight(50+20,100+40+165 ,230);
		 	count++;
		 	delay(200);
		 	falg[3]=1;
		 }		 
		 else if(mouse_press(50+20,100+40+220,300,100+40+30+220) == 1 &&falg[4]==0  )//鼠标在登录框中，且点击
		{   
		     choice[0]=5;
		     comparelight(50+20,100+40+220 ,230);
		     count++;
			delay(200);
			falg[4]=1;
		} 
		else if(mouse_press(50+20+270,100+40,300+270,100+40+30) == 1 &&falg[5]==0  )//鼠标在登录框中，且点击
		{   
		     choice[0]=6;
		     	comparelight(50+20+270,100+40 ,230);
		     	count++;
		     	delay(200);
		     	falg[5]=1;
	}
			else if(mouse_press(50+20+270,100+40+55,300+270,100+40+30+55) == 1&&falg[6]==0   )//鼠标在登录框中，且点击
		{   
		     choice[0]=7;
		     comparelight(50+20+270,100+40+55 ,230);
		     count++;
		     delay(200);
		     falg[6]=1;
		} 
		else if(mouse_press(50+20+270,100+40+110,300+270,100+40+30+110) == 1&&falg[7]==0  )//鼠标在登录框中，且点击
		{   
		     
			choice[0]=8;
			comparelight(50+20+270,100+40+110 ,230);
			count++;
			falg[7]=1;
			delay(200);
		} 
			else if(mouse_press(50+20+270,100+40+165,300+270,100+40+30+165) == 1 &&falg[8]==0 )//鼠标在登录框中，且点击
		{   
		     
			choice[0]=9;
			comparelight(50+20+270,100+40+165 ,230);
			count++;
			falg[8]=1;
			delay(200);
		} 
		 else if(mouse_press(50+20+270,100+40+220,300+270,100+40+30+220) == 1&&falg[9]==0  )//鼠标在登录框中，且点击
		{   
		     choice[0]=10;
		   	comparelight(50+20+270,100+40+220 ,230);
		   	count++;
		   	falg[9]=1;
		   	delay(200);
			
		}  
		}
		else if(count==1)
		{
			if(mouse_press(50+20,100+40,300,100+40+30) == 1 &&falg[0]==0 )
    	{
    		 
			choice[1]=1;
    		comparelight(50+20,100+40 ,230);
    		count=count+1;
    		delay(200);
		}
		 if(mouse_press(50+20,100+40+30+25,300,100+40+30+30+25) == 1&&falg[1]==0  )
		{
			 choice[1]=2;
			 comparelight(50+20,100+40+30+25 ,230);
			 count++;
			 delay(200);
		 } 
		 else if(mouse_press(50+20,100+40+55+55,300,100+40+30+55+55) == 1 &&falg[2]==0  )
		 {
		 	 choice[1]=3;
		 	 comparelight(50+20,100+40+55+55 ,230);
		 	 count++;
		 	 delay(200);
		 }
		 else if(mouse_press(50+20,100+40+55+55+55,300,100+40+30+55+55+55) == 1 &&falg[3]==0  )
		 {
		 	 choice[1]=4;
		 	comparelight(50+20,100+40+165 ,230);
		 	count++;
		 	delay(200);
		 }		 
		 else if(mouse_press(50+20,100+40+220,300,100+40+30+220) == 1 &&falg[4]==0  )//鼠标在登录框中，且点击
		{   
		     choice[1]=5;
		     comparelight(50+20,100+40+220 ,230);
		     count++;
		     delay(200);
			
		} 
		else if(mouse_press(50+20+270,100+40,300+270,100+40+30) == 1 &&falg[5]==0  )//鼠标在登录框中，且点击
		{   
		     choice[1]=6;
		     	comparelight(50+20+270,100+40 ,230);
		     	count++;
		     	delay(200);
		}
			else if(mouse_press(50+20+270,100+40+55,300+270,100+40+30+55) == 1 &&falg[6]==0  )//鼠标在登录框中，且点击
		{   
		     choice[1]=7;
		     comparelight(50+20+270,100+40+55 ,230);
		     count++;
		     delay(200);
		} 
		else if(mouse_press(50+20+270,100+40+110,300+270,100+40+30+110) == 1 &&falg[7]==0 )//鼠标在登录框中，且点击
		{   
		     
			choice[1]=8;
			comparelight(50+20+270,100+40+110 ,230);
			count++;
			delay(200);
		} 
			else if(mouse_press(50+20+270,100+40+165,300+270,100+40+30+165) == 1&&falg[8]==0  )//鼠标在登录框中，且点击
		{   
		     
			choice[1]=9;
			comparelight(50+20+270,100+40+165 ,230);
			count++;
			delay(200);
		} 
		 else if(mouse_press(50+20+270,100+40+220,300+270,100+40+30+220) == 1 &&falg[9]==0 )//鼠标在登录框中，且点击
		{   
		     choice[1]=10;
		   	comparelight(50+20+270,100+40+220 ,230);
		   	count++;
		   	delay(200);
			
		}  
		}
	
	      
	
		
		if(mouse_press(240,40,340,80)==1&&count==2)
		{
			return 23;
		}
		else if(mouse_press(400,40,580,80)==1)
		{
			return 24;
		}
		else if(mouse_press(5,5,30,30)==1)
		{
			return 7;
		}
	}
	
	
	
	
}

void comparescreen(void)
{
	int v[16] ={5,13,15,5,15,8,20,8,20,17,15,17,15,20,5,13};
	cleardevice();
	clrmous(MouseX,MouseY);
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
	puthz(60,50,"选择比较学校",24,22,YELLOW);
	
	bar(240,40,340,80);
	puthz(275,45,"确定",24,24,RED);
	bar(400,40,580,80);
	puthz(415,48,"查看使用说明",24,25,YELLOW);
	
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
/*********************************************
FUNCTION:comparelight
DESCRIPTION:按键亮框
PARAMETERS:int x1,int y1,char*s
RETURN:void
***********************************************/
void comparelight(int x1, int y1   , int length)
{

    setlinestyle(0,0,3);
	clrmous(MouseX, MouseY);
	setcolor(RED);
	rectangle(x1, y1, x1 + length, y1 + 30);
	 
}

/*********************************************
FUNCTION:comparerecover
DESCRIPTION:按键恢复
PARAMETERS:int x1,int y1,char*s
RETURN:void
***********************************************/
void comparecover(int x1, int y1  , int length) 
{
	setlinestyle(0,0,3);
	clrmous(MouseX, MouseY);
	setcolor(DARKGRAY);
	rectangle(x1, y1, x1 + length, y1 + 30);
	 
}
