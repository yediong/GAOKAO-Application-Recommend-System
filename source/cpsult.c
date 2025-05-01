#include"common.h"
#include"main.h"

int compasult(int choice[2])
{
	char name[2][30]={'0'};//学校名称 
	char score[2][10]={'0'};//最低分数 
	char temp[100]={'0'};//存储空格 
	char precent[2][10]={'0'};//保研概率 
	char num[2][10]={'0'};//A+学科数量
	int a=choice[0]-1;//第一个学校编号
	int b=choice[1]-1;//第二个学校编号 
	 
	
	 
	int tempa=0;
	int tempb=0;
	FILE* fp=NULL;
	if(a==0||a==1||a==2||a==4||a==5||a==8||a==3||a==9)
	{
		tempa=8;
	}
	 
	else if(a==6||a==7)
	{
		tempa=6;
	}
	
	if(b==0||b==1||b==2||b==4||b==5||b==8||b==3||b==9)
	{
		tempb=8;
	}
	 
	else if(b==6||b==7)
	{
		tempb=6;
	}
	
	compasultbk();
	
	if((fp=fopen("C:\\test\\Database\\school1.dat","rb+"))==NULL)
			{
				printf("cnnot open the file\n");
				closegraph();
				exit(0);
			}
	fseek(fp,a*26,SEEK_SET);
	fread(name[0],sizeof(char),tempa,fp);
	fread(temp,sizeof(char),16-tempa,fp);
	fread(score[0],sizeof(char),3,fp);
	fread(num[0],sizeof(char),3,fp);
	fread(precent[0],sizeof(char),3,fp);
	
	fseek(fp,0,SEEK_SET);
	fseek(fp,b*26,SEEK_SET);
	fread(name[1],sizeof(char),tempb,fp);
	fread(temp,sizeof(char),16-tempb,fp);
	fread(score[1],sizeof(char),3,fp);
	fread(num[1],sizeof(char),3,fp);
	fread(precent[1],sizeof(char),3,fp);
	fclose(fp);
	
	
	puthz(200,24,name[0],32,32,YELLOW);
	puthz(400,24,name[1],32,32,YELLOW);
	setcolor(LIGHTRED);
	settextstyle(1,0,6);
	outtextxy(335,10,"VS");
	puthz(24,191,name[0],32,32,CYAN);
	puthz(24,257,name[1],32,32,CYAN);
	settextstyle(1,0,6);
	setcolor(DARKGRAY);
	outtextxy(198,171, num[0]);
	outtextxy(198,237, num[1]);
	settextstyle(1,0,6);
	setcolor(RED);
	outtextxy(357,171, score[0]);
	outtextxy(357,237, score[1]);
	settextstyle(1,0,6);
	setcolor(BLUE);
	outtextxy(516,171, precent[0]);
	outtextxy(516,237, precent[1]);
	
	if(atoi(num[0])>atoi(num[1]))
	{
		puthz(390,350,name[0],32,32,DARKGRAY);
	}
	else if(atoi(num[0])<atoi(num[1]))
	{
		puthz(390,350,name[1],32,32,DARKGRAY);
	}
	else if(atoi(num[0])==atoi(num[1]))
	{
		if(atoi(score[0])>atoi(score[1]))
		{
			puthz(390,350,name[0],32,32,DARKGRAY);
		}
		else if(atoi(score[0])<atoi(score[1]))
		{
			puthz(390,350,name[0],32,32,DARKGRAY);
		}
	}
	
	if(atoi(precent[0])>atoi(precent[1]))
	{
		puthz(390,400,name[0],32,32,DARKGRAY);
	}
	else if(atoi(precent[0])<atoi(precent[1]))
	{
		puthz(390,400,name[1],32,32,DARKGRAY);
	}
	else if(atoi(precent[0])==atoi(precent[1]))
	{
		if(atoi(score[0])>atoi(score[1]))
		{
			puthz(390,350,name[0],32,32,DARKGRAY);
		}
		else if(atoi(score[0])<atoi(score[1]))
		{
			puthz(390,350,name[1],32,32,DARKGRAY);
		}
	}
	
	
	
	while(1)
	{
		newmouse(&MouseX,&MouseY,&press);
		if(mouse_press(5,5,30,30)==1)
		{
			return 22;
		}
	}
	
	   
}

void compasultbk(void)
{
	 
	int v[16] ={5,13,15,5,15,8,20,8,20,17,15,17,15,20,5,13};	 
	cleardevice(); //清屏函数 
	setbkcolor(LIGHTBLUE);//设置背景颜色
	setlinestyle(0, 0, 3);
	setlinestyle(0, 0, 3);
	setcolor(WHITE);
	rectangle(0,0,25,25);
	setfillstyle(1,BLUE);
	fillpoly(8,v);	
//	setfillstyle(1,  LIGHTRED);
//	bar(550, 20, 630, 60); 
//	puthz(558, 24, "收藏", 32, 32, WHITE);  	  //收藏
	setcolor(RED);
	line(0, 80, 639, 80);//横线
	settextstyle(0, 0, 4);       //设置文本输出字形、方向和大小
	puthz(50, 24,"当前比较：", 32, 32, RED);
	
	
	setlinestyle(0, 0, 1);//中间部分的边框 
	setcolor(GREEN);
	rectangle(3, 85, 637, 147);  	 
	rectangle(9, 91, 631, 141);    		 
	setlinestyle(1, 0, 1); 
	rectangle(6, 88, 634, 144); 
	
	setlinestyle(0, 0, 1);//下面的大边框 
	setcolor(GREEN);
	rectangle(3, 150, 637, 477);  	 
	rectangle(9, 156, 631, 471);    		 
	setlinestyle(1, 0, 1); 
	rectangle(6, 153, 634, 474); 

	puthz(24, 100, "学校名称", 32, 32, DARKGRAY); 
	puthz(183, 100, "一流学科", 32, 32, YELLOW);
	puthz(342, 100, "最低分数", 32, 32, RED);
	puthz(501, 100, "保研概率", 32, 32, CYAN);
	
	setfillstyle(1,WHITE);
	bar(12,159,629,469);
	setcolor(RED);
	setlinestyle(0,0,2);
	line(13,314,628,314);
	setlinestyle(1,0,1);
	setcolor(DARKGRAY);
	line(13,316,628,316);
	line(13,312,628,312);
	
	setcolor(RED);
	setlinestyle(0, 0, 1);
	rectangle(35, 360, 165, 440);
	rectangle(41, 366, 157, 434);
	setlinestyle(1, 0, 1);
	setcolor(RED);
	rectangle(38, 363, 162, 437);
	setfillstyle(1, DARKGRAY);	
	bar(42, 367, 158, 433);
	puthz(50, 372, "高校对比", 24,24, BLUE);
	puthz(75,401,"结果",24,24,BLUE);
	
	puthz(180,360,"按学科实力看，选",24,24,RED);
	puthz(180,410,"按升学率看，选",24,24,RED);
	
}
