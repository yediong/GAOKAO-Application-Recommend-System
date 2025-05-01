#include"common.h"
#include"main.h"

int introduce(void)
{
	int v[16] ={5,13,15,5,15,8,20,8,20,17,15,17,15,20,5,13};
	char current[5000]={'0'};
	FILE* fp=NULL;
	
	cleardevice(); //清屏函数 
	
	setbkcolor(BLUE);
	setcolor(WHITE);
	setlinestyle(0,0,3);
	rectangle(30,30,610,450);
	setfillstyle(1,LIGHTBLUE);
	rectangle(0,0,25,25);
	fillpoly(8,v);
	bar(30,30,610,450);
	
	setfillstyle(1,DARKGRAY);
	rectangle(240,60,390,100);
	bar(240,60,390,100);
	
	setcolor(YELLOW);
	rectangle(230,50,400,110);
	rectangle(225,45,235,55);
	rectangle(405,115,395,105);
	rectangle(225,105,235,115);
	rectangle(405,45,395,55);
	
	rectangle(60,130,580,420);
	setfillstyle(1,LIGHTGRAY);
	floodfill(65,240,YELLOW);
	
	
	if((fp=fopen("C:\\test\\Database\\sysm.dat","rb+"))==NULL)
			{
				printf("cnnot open the file\n");
				closegraph();
				exit(0);
			}
		puthz(260,70,"使用说明",24,30,LIGHTRED);
		fread(current,sizeof(char),1000,fp);
			fclose(fp);
			puthz(90,160,current,24,24,WHITE);
			
	while(1)
	{
		newmouse(&MouseX,&MouseY,&press);
		if(mouse_press(5,5,30,30)==1)
		{
			return 22;
		}
	}
}
