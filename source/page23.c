
#include"common.h"
#include"main.h"



/********************************************
Function: searchbk
Description:主菜单界面下的搜索界面的画图函数
Attention:
Return:
********************************************/

void searchbk(void)
{
	int v[16] ={5,13,15,5,15,8,20,8,20,17,15,17,15,20,5,13};
	cleardevice(); //清屏函数 
	clrmous(MouseX,MouseY);
	
	
	setbkcolor(LIGHTBLUE);//设置背景颜色
	
	setlinestyle(0, 0, 3);
	
	setlinestyle(0, 0, 3);
	setcolor(RED);
	line(0, 80, 639, 80);//长横线
	 setcolor(WHITE);
	setlinestyle(0,0,3);

	setfillstyle(1,LIGHTBLUE);
	
	rectangle(0,0,25,25); 
	fillpoly(8,v);
	
	puthz(100, 24, "学校及学科搜索界面", 32, 54, RED);

	setfillstyle(1, LIGHTRED);	
	bar(0, 82, 640, 125);
	puthz(40, 86, "请在搜索框内输入要搜索的内容的首字母", 24, 24, WHITE);
	
	setcolor(RED);
	setlinestyle(0, 0, 1);
	rectangle(3, 380, 133, 460);
	rectangle(9, 386, 127, 454);
	setlinestyle(1, 0, 1);
	rectangle(6, 383, 130, 457);
	setfillstyle(1, LIGHTRED);	
	bar(10, 387, 126, 453);
	puthz(20, 396, "推荐", 48, 48, WHITE);
	
	setfillstyle(1, DARKGRAY);	
	bar(50, 200, 90, 220);
	bar(50, 250, 90, 270);
	puthz(54, 202, "学校", 16, 16, WHITE);
	puthz(54, 252, "专业", 16, 16, WHITE);
	puthz(10, 150, "选", 16, 16, GREEN);
	puthz(10, 168, "择", 16, 16, GREEN);
	puthz(10, 186, "要", 16, 16, GREEN);
	puthz(10, 204, "搜", 16, 16, GREEN);
	puthz(10, 222, "索", 16, 16, GREEN);
	puthz(10, 240, "的", 16, 16, GREEN);
	puthz(10, 258, "类", 16, 16, GREEN);
	puthz(10, 276, "型", 16, 16, GREEN);
	
	setlinestyle(0, 0, 1);
	setcolor(BLUE);
	rectangle(140, 165, 500, 200);
	rectangle(540,165,600,200);
	puthz(545,170,"刷新",16,16,WHITE);
	setfillstyle(1, DARKGRAY);
	bar(500, 165, 535, 200);
	setcolor(WHITE);
	circle(520, 180, 8);

}
/********************************************
Function: search
Description:主菜单界面下的搜索界面的后台函数
Attention:
Return:
********************************************/

int p23(void)
{
	int school=0;
	int subject=0;
	int sign1=0;
	int sign2=0;
	char string[]="0";
	
	int flag=0,flag1=0;//控制字幕的打出
	int t=0;
	int choice=0;
	int sign=0;//防止未输入汉字就使输出框能够被点击 
	searchbk(); 
	while(1)
	{
         newmouse(&MouseX,&MouseY,&press);
	
	if(mouse_press(10, 387, 126, 453)==1)
	{
		flag=1;
		flag1=0;
	 } 
	  if(mouse_press(540,165,585,200)==1)
	 {
		flag1=1;
		searchbk();
	 }
	  if(flag==1&&flag1==0)
	 {
	 	    setcolor(LIGHTRED);
			setlinestyle(0, 0, 1);
			rectangle(134, 350, 637, 477);
			rectangle(140, 356, 631, 471);
			setlinestyle(1, 0, 1);
			rectangle(137, 353, 634, 474);
			puthz(150, 366, "热", 16, 16, LIGHTGRAY);
			puthz(150, 392, "门", 16, 16, LIGHTGRAY);
			puthz(150, 418, "专", 16, 16, LIGHTGRAY);
			puthz(150, 444, "业", 16, 16, LIGHTGRAY);
			
			puthz(390, 366, "热", 16, 16, LIGHTGRAY);
			puthz(390, 392, "门", 16, 16, LIGHTGRAY);
			puthz(390, 418, "学", 16, 16, LIGHTGRAY);
			puthz(390, 444, "校", 16, 16, LIGHTGRAY);
				
			puthz(200, 365, "自动化专业", 16, 16, WHITE);
			puthz(200, 385, "软件工程", 16, 16, WHITE);
			puthz(200, 405, "城市规划相关专业", 16, 16, WHITE);
			puthz(200, 425, "园林景观设计专业", 16, 16, WHITE);
			puthz(200, 445, "电子竞技运营相关专业", 16, 16, WHITE);

			puthz(450, 365, "华中科技大学", 16, 16, WHITE);
			puthz(450, 385, "北京大学", 16, 16, WHITE);
			puthz(450, 405, "武汉大学", 16, 16, WHITE);
			puthz(450, 425, "国防科技大学", 16, 16, WHITE);
			puthz(450, 445, "南京信息工程大学", 16, 16,WHITE);
	 	flag=0;
	 }
	 else if(mouse_press(50, 200, 90, 220)==1)
	 {
	 	choice=1;
	 	searchlight(50,200,"学校",40);
	 	searchrecover(50,250,"专业",40);
	 }
	 else if(mouse_press(50, 250, 90, 270)==1)
	 {
	 	choice=2;
	 	searchlight(50,250,"专业",40);
	 	searchrecover(50,200,"学校",40);
	 }
	 if(mouse_press(140,165,500,200)==1)//点击输入框 
	 {
	 	if(choice==0)
	 	{
			setfillstyle(0,LIGHTGRAY);
	 		bar(250,210,390,245);
	 		puthz(255,215,"请选择学校或专业",16,16,WHITE);
	 		delay(150);
	 		setfillstyle(0,BLUE);
	 		bar(250,210,390,245);
		 }
		 
		 else if(choice==1||choice==2)
		 {
			searchinput(string,140,165);
		 }
	 }
	 
	 if(mouse_press(500,165,535,200)==1)//点击搜索框 
	 {
	 	if(string=="0")
	 	{
	 		setfillstyle(0,DARKGRAY);
	 		bar(250,210,390,245);
	 		puthz(255,215,"请输入搜索内容",16,16,WHITE);
	 		delay(150);
			setfillstyle(0,BLUE);
	 		bar(250,210,390,245);
		 }
		 
		 else if(string!="0")
		 {
		 	t=searchout(choice,string,&school,&subject,&sign);
		 }
	 }
	 if(mouse_press(0,0,25,25)==1)
	 {
	 	
	 	return 7;
	 }
	  if(mouse_press(140,201,500,235)==1&&choice==1&&t==1&&sign==1)
	 {
	    clrmous(MouseX,MouseY);
		searchresults1(&school,&sign1);
		delay(100);
		searchbk();
		sign=0;
		sign1=0;
	 	
     }
     else if(mouse_press(140,201,500,235)==1&&choice==2&&t==1&&sign==1)
     {
     	clrmous(MouseX,MouseY);
		searchresults2(&subject,&sign2);
		delay(100);
		searchbk();
		sign=0;
		sign2=0;
	 }
     
	 
}
	 
}

/*********************************************
FUNCTION:page1light
DESCRIPTION:按键亮框
PARAMETERS:int x1,int y1,char*s
RETURN:void
***********************************************/
void searchlight(int x1, int y1, char*s, int length) 
{


	clrmous(MouseX, MouseY);
	setcolor(RED);
	rectangle(x1, y1, x1 + length, y1 + 20);
	puthz(x1+4, y1 + 2, s, 16, 16, WHITE);
}

/*********************************************
FUNCTION:page1recover
DESCRIPTION:按键恢复
PARAMETERS:int x1,int y1,char*s
RETURN:void
***********************************************/
void searchrecover(int x1, int y1, char*s, int length) 
{
	clrmous(MouseX, MouseY);
	setcolor(DARKGRAY);
	rectangle(x1, y1, x1 + length, y1 + 20);
	puthz(x1+4, y1 + 2, s, 16, 16, BLUE);
}
	
	
/********************************************
Function: searchinput
Description:主菜单界面下的搜索界面搜索输入函数 
Attention:
Return:
********************************************/
			
void searchinput( char *string,int x1,int y1)
{
	int i = 0;
	char t = '\0';
	char a[2] = "\0";
	strcpy(string, "\0");
	clrmous(MouseX, MouseY);
	setfillstyle(SOLID_FILL, LIGHTGRAY);
	setlinestyle(SOLID_LINE, 0, NORM_WIDTH);
	bright(x1, y1, x1 + 360, y1 + 35, LIGHTGRAY);
	setcolor(BLUE);
	settextstyle(TRIPLEX_FONT, HORIZ_DIR, 2);
	settextjustify(LEFT_TEXT, TOP_TEXT);

	while (1) {
		t = bioskey(0);
		if (i < 10) {
			if (t != '\n'
			        && t != '\r'
			        && t != ' '
			        && t != 033) { //Esc
				if (t != '\b') {
					string[i] = t;
					a[0] = t;
					a[1] = '\0';
					string[i + 1] = '\0';
					outtextxy(2 + x1 + i * 10, y1 - 2, a);
					i++;
				} else if (t == '\b' && i > 0) {
					bar(x1 + i * 10 - 8, y1, x1 + i * 10 + 4, y1 + 22);
					i--;
					string[i] = '\0';
				}
			} else {
				setfillstyle(SOLID_FILL, LIGHTGRAY);
				break;
			}
		}

		else if (i >= 10) {
			if (t != '\n'
			        && t != '\r'
			        && t != ' '
			        && t != 033) { //Esc
				if (t == '\b' && i > 0) {
					bar(x1 + i * 10 - 8, y1, x1 + i * 10 + 4, y1 + 22);
					i--;
					string[i] = '\0';
				}
			}

			else {
				setfillstyle(SOLID_FILL, LIGHTGRAY);
				break;
			}
		}
	}
	bright(x1, y1, x1 + 360, y1 + 35, LIGHTBLUE);
	setcolor(BLUE);
	rectangle(x1,y1,x1+360,y1+35);
	outtextxy(x1 + 2, y1 - 1, string);
}


/********************************************
Function: searchout 
Description:主菜单界面下的搜索界面的搜索结果显示函数 
Attention:
Return:
********************************************/

int searchout(int choice ,char*string,int*school,int*subject, int* flag)
{
	
//	char *p = string;	
	

	
	if(choice == 0)
	{
		puthz(140, 205, "请选择要查询的类型", 16, 16, GREEN);
		
	}
	
	if(choice == 1)//学校搜索 
	{
		
			
			if(strcmp(string,"hgd")==0)
			{
				setfillstyle(1,LIGHTBLUE);
				bar(140, 201, 500, 235);
				setcolor(LIGHTRED);
	            setlinestyle(0, 0, 1);
	            rectangle(140, 201, 500, 235);
				puthz(150, 210, "哈工大",16,16,RED);
				*flag=1;
				*school=1;
				
			}
			else if(strcmp(string,"zsdx")==0)
			{
				setfillstyle(1,LIGHTBLUE);
				bar(140, 201, 500, 235);
				setcolor(LIGHTRED);
	            setlinestyle(0, 0, 1);
	            rectangle(140, 201, 500, 235);
				puthz(150, 210, "中山大学",16,16,RED);
				*flag=1;
				*school=2;
				
			}
			else if(strcmp(string,"dndx")==0)
			{
				setfillstyle(1,LIGHTBLUE);
				bar(140, 201, 500, 235);
				setcolor(LIGHTRED);
	            setlinestyle(0, 0, 1);
	            rectangle(140, 201, 500, 235);
				puthz(150, 210, "东南大学",16,16,RED);
				*flag=1;
				*school=3; 
				
			}
			else if(strcmp(string,"hndx")==0)
			{
				setfillstyle(1,LIGHTBLUE);
				bar(140, 201, 500, 235);
				setcolor(LIGHTRED);
	            setlinestyle(0, 0, 1);
	            rectangle(140, 201, 500, 235);
				puthz(150, 210, "海南大学",16,16,RED);
				*flag=1;
				*school=4;
				
			}
			else if(strcmp(string,"scdx")==0)
			{
				setfillstyle(1,LIGHTBLUE);
				bar(140, 201, 500, 235);
				setcolor(LIGHTRED);
	            setlinestyle(0, 0, 1);
	            rectangle(140, 201, 500, 235);
				puthz(150, 210, "四川大学",16,16,RED);
				*flag=1;
				*school=5;
				
			}
			
		 
				 	
	}
	
	if(choice == 2)//专业搜索 
	{
		
			
			if(strcmp(string,"ylys")==0)
			{
				setfillstyle(1,LIGHTBLUE);
				bar(140, 201, 500, 235);
				setcolor(LIGHTRED);
	            setlinestyle(0, 0, 1);
	            rectangle(140, 201, 500, 235);
				puthz(150, 210, "园林艺术",16,16,RED);
				*subject=1;
                *flag=1;
			} 
			else if(strcmp(string,"dj")==0)
			{
				setfillstyle(1,LIGHTBLUE);
				bar(140, 201, 500, 235);
				setcolor(LIGHTRED);
	            setlinestyle(0, 0, 1);
	            rectangle(140, 201, 500, 235);
				puthz(150, 210, "电竞",16,16,RED);
				*subject=2;
				*flag=1;
			} 
			
	
	
	}
	
	return 1;

}
/********************************************
Function: searchresults1
Description:主菜单界面下学校的搜索界面的搜索结果详细介绍界面 
Attention:
Return:
********************************************/
int searchresults1(int *school,int*flag)
{
	char current[5000];
	int v[16] ={5,13,15,5,15,8,20,8,20,17,15,17,15,20,5,13};	
	int i;
	FILE* fp;
	cleardevice(); //清屏函数 
	*flag=1;
	
	setbkcolor(LIGHTBLUE);//设置背景颜色
	 
	setlinestyle(0, 0, 3);
	
	setlinestyle(0, 0, 3);
	setcolor(RED);
	line(0, 80, 639, 80);//横线
	fillpoly(8,v);	
//	setfillstyle(1,  LIGHTRED);
//	bar(550, 20, 630, 60); 
//	puthz(558, 24, "收藏", 32, 32, WHITE);  	  //收藏
		
	settextstyle(0, 0, 4);       //设置文本输出字形、方向和大小
	puthz(50, 24,"当前搜索：", 32, 32, RED);
	
	
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

	puthz(34, 100, "基本概况", 32, 32, DARKGRAY); 
	puthz(193, 100, "优势学科", 32, 32, YELLOW);
	puthz(352, 100, "录取分数", 32, 32, RED);
	puthz(511, 100, "学校档次", 32, 32, CYAN);
	if(*school==1)
	{
		puthz(200, 24, "哈工大", 32, 32, RED);
	}
	else if(*school==2)
	{
		puthz(200, 24, "中山大学", 32, 32, RED);
	}
		else if(*school==3)
	{
		puthz(200, 24, "东南大学", 32, 32, RED);
	}
        else if(*school==4)
	{
		puthz(200, 24, "海南大学", 32, 32, RED);
	}
		else if(*school==5)
	{
		puthz(200, 24, "四川大学", 32, 32, RED);
	}
	     
	
	while(1)
	{
		newmouse(&MouseX,&MouseY,&press);
		if(mouse_press(0,0,35,35)==1&&*flag==1)
		{
			return 0;
		}
		else if(mouse_press(28,91,168,141)==1&&*school==1&&*flag==1)//点击基本概况 
		{
			for(i=0;i<2000;i++)
			{
				current[i]='\0';
			}
			setfillstyle(1,WHITE);
			bar(9, 156, 631, 471);
			
			if((fp=fopen("C:\\test\\Database\\jbgk1.dat","rb+"))==NULL)
			{
				printf("cnnot open the file\n");
				closegraph();
				
			}
			fread(current,sizeof(char),464,fp);
			fclose(fp);
			puthz(60,160,current,16,16,RED);
	   }
		else if(mouse_press(187,91,327,141)==1&&*school==1&&*flag==1)//点击优势学科 
		{
			setfillstyle(1,WHITE);
			bar(9, 156, 631, 471);
		for(i=0;i<2000;i++)
			{
				current[i]='\0';
			}
			if((fp=fopen("C:\\test\\Database\\ysxk1.dat","rb+"))==NULL)
			{
				printf("cnnot open the file\n");
				closegraph();
				exit(0);
			}
			fread(current,sizeof(char),388,fp);
			fclose(fp);
			puthz(60,160,current,16,16,RED);
	}
		else if(mouse_press(346,91,486,141)==1&&*school==1&&*flag==1)//点击录取分数 
		{
			setfillstyle(1,WHITE);
			bar(9, 156, 631, 471);
			for(i=0;i<2000;i++)
			{
				current[i]='\0';
			}
			if((fp=fopen("C:\\test\\Database\\lqfs1.dat","rb+"))==NULL)
			{
				printf("cnnot open the file\n");
				closegraph();
				exit(0);
			}
			fread(current,sizeof(char),1000,fp);
			fclose(fp);
			puthz(60,160,current,16,16,RED);
		}
		else if(mouse_press(505,91,581,141)==1&&*school==1&&*flag==1)//点击学校档次 
		{
			setfillstyle(1,WHITE);
			bar(9, 156, 631, 471);
			for(i=0;i<2000;i++)
			{
				current[i]='\0';
			}
			if((fp=fopen("C:\\test\\Database\\xxdc1.dat","rb+"))==NULL)
			{
				printf("cnnot open the file\n");
				closegraph();
				exit(0);
			}
			fread(current,sizeof(char),1000,fp);
			fclose(fp);
			puthz(60,160,current,16,16,RED);
		}
			else if(mouse_press(28,91,168,141)==1&&*school==2&&*flag==1)//点击基本概况
		{
			setfillstyle(1,WHITE);
			bar(9, 156, 631, 471);
			for(i=0;i<2000;i++)
			{
				current[i]='\0';
			}
			if((fp=fopen("C:\\test\\Database\\jbgk2.dat","rb+"))==NULL)
			{
				printf("cnnot open the file\n");
				closegraph();
				exit(0);
			}
			fread(current,sizeof(char),1000,fp);
			fclose(fp);
			puthz(60,160,current,16,16,RED);
		}
		    else if(mouse_press(187,91,327,141)==1&&*school==2&&*flag==1)//点击优势学科 
		
		{
			setfillstyle(1,WHITE);
			bar(9, 156, 631, 471);
			for(i=0;i<2000;i++)
			{
				current[i]='\0';
			}
			if((fp=fopen("C:\\test\\Database\\ysxk2.dat","rb+"))==NULL)
			{
				printf("cnnot open the file\n");
				closegraph();
				exit(0);
			}
			fread(current,sizeof(char),1000,fp);
			fclose(fp);
			puthz(60,160,current,16,16,RED);
		}
		
		    else if(mouse_press(346,91,486,141)==1&&*school==2&&*flag==1)//点击录取分数 
		{
			setfillstyle(1,WHITE);
			bar(9, 156, 631, 471);
			for(i=0;i<2000;i++)
			{
				current[i]='\0';
			}
			if((fp=fopen("C:\\test\\Database\\lqfs2.dat","rb+"))==NULL)
			{
				printf("cnnot open the file\n");
				closegraph();
				exit(0);
			}
			fread(current,sizeof(char),1000,fp);
			fclose(fp);
			puthz(60,160,current,16,16,RED);
		}
		
		    else if(mouse_press(505,91,581,141)==1&&*school==2&&*flag==1)//点击学校档次 
		{
			setfillstyle(1,WHITE);
			bar(9, 156, 631, 471);
			for(i=0;i<2000;i++)
			{
				current[i]='\0';
			}
			if((fp=fopen("C:\\test\\Database\\xxdc2.dat","rb+"))==NULL)
			{
				printf("cnnot open the file\n");
				closegraph();
				exit(0);
			}
			fread(current,sizeof(char),1000,fp);
			fclose(fp);
			puthz(60,160,current,16,16,RED);
		}
		
	        else if(mouse_press(28,91,168,141)==1&&*school==3&&*flag==1)//点击基本概况
	    {
	    	setfillstyle(1,WHITE);
			bar(9, 156, 631, 471);
			for(i=0;i<2000;i++)
			{
				current[i]='\0';
			}
			if((fp=fopen("C:\\test\\Database\\jbgk3.dat","rb+"))==NULL)
			{
				printf("cnnot open the file\n");
				closegraph();
				exit(0);
			}
			fread(current,sizeof(char),1000,fp);
			fclose(fp);
			puthz(60,160,current,16,16,RED);
		}
		
		    else if(mouse_press(187,91,327,141)==1&&*school==3&&*flag==1)//点击优势学科
		{
			setfillstyle(1,WHITE);
			bar(9, 156, 631, 471);
			for(i=0;i<2000;i++)
			{
				current[i]='\0';
			}
			if((fp=fopen("C:\\test\\Database\\ysxk3.dat","rb+"))==NULL)
			{
				printf("cnnot open the file\n");
				closegraph();
				exit(0);
			}
			fread(current,sizeof(char),1000,fp);
			fclose(fp);
			puthz(60,160,current,16,16,RED);
		}
		    else if(mouse_press(346,91,486,141)==1&&*school==3&&*flag==1)//点击录取分数 
		{
			setfillstyle(1,WHITE);
			bar(9, 156, 631, 471);
			for(i=0;i<2000;i++)
			{
				current[i]='\0';
			}
			if((fp=fopen("C:\\test\\Database\\lqfs3.dat","rb+"))==NULL)
			{
				printf("cnnot open the file\n");
				closegraph();
				exit(0);
			}
			fread(current,sizeof(char),1000,fp);
			fclose(fp);
			puthz(60,160,current,16,16,RED);
		}
		
		    else if(mouse_press(505,91,581,141)==1&&*school==3&&*flag==1)//点击学校档次 
		{
			setfillstyle(1,WHITE);
			bar(9, 156, 631, 471);
			for(i=0;i<2000;i++)
			{
				current[i]='\0';
			}
			if((fp=fopen("C:\\test\\Database\\xxdc3.dat","rb+"))==NULL)
			{
				printf("cnnot open the file\n");
				closegraph();
				exit(0);
			}
			fread(current,sizeof(char),1000,fp);
			fclose(fp);
			puthz(60,160,current,16,16,RED);
		}
		    else if(mouse_press(28,91,168,141)==1&&*school==4&&*flag==1)//点击基本概况
		{
			setfillstyle(1,WHITE);
			bar(9, 156, 631, 471);
			for(i=0;i<2000;i++)
			{
				current[i]='\0';
			}
			if((fp=fopen("C:\\test\\Database\\jbgk4.dat","rb+"))==NULL)
			{
				printf("cnnot open the file\n");
				closegraph();
				exit(0);
			}
			fread(current,sizeof(char),1000,fp);
			fclose(fp);
			puthz(60,160,current,16,16,RED);
		}
		
			else if(mouse_press(187,91,327,141)==1&&*school==4&&*flag==1)//点击优势学科 
		{
			setfillstyle(1,WHITE);
			bar(9, 156, 631, 471);
			for(i=0;i<2000;i++)
			{
				current[i]='\0';
			}
			if((fp=fopen("C:\\test\\Database\\ysxk4.dat","rb+"))==NULL)
			{
				printf("cnnot open the file\n");
				closegraph();
				exit(0);
			}
			fread(current,sizeof(char),1000,fp);
			fclose(fp);
			puthz(60,160,current,16,16,RED);
		}
		    else if(mouse_press(346,91,486,141)==1&&*school==4&&*flag==1)//点击录取分数 
		{
			setfillstyle(1,WHITE);
			bar(9, 156, 631, 471);
			for(i=0;i<2000;i++)
			{
				current[i]='\0';
			}
			if((fp=fopen("C:\\test\\Database\\lqfs4.dat","rb+"))==NULL)
			{
				printf("cnnot open the file\n");
				closegraph();
				exit(0);
			}
			fread(current,sizeof(char),1000,fp);
			fclose(fp);
			puthz(60,160,current,16,16,RED);
		}
		    else if(mouse_press(505,91,581,141)==1&&*school==4&&*flag==1)//点击学校档次 
		{
			setfillstyle(1,WHITE);
			bar(9, 156, 631, 471);
			for(i=0;i<2000;i++)
			{
				current[i]='\0';
			}
			if((fp=fopen("C:\\test\\Database\\xxdc4.dat","rb+"))==NULL)
			{
				printf("cnnot open the file\n");
				closegraph();
				exit(0);
			}
			fread(current,sizeof(char),1000,fp);
			fclose(fp);
			puthz(60,160,current,16,16,RED);
	    }
		    else if(mouse_press(28,91,168,141)==1&&*school==5&&*flag==1)//点击基本概况 
		{
			setfillstyle(1,WHITE);
			bar(9, 156, 631, 471);
			for(i=0;i<2000;i++)
			{
				current[i]='\0';
			}
			if((fp=fopen("C:\\test\\Database\\jbgk5.dat","rb+"))==NULL)
			{
				printf("cnnot open the file\n");
				closegraph();
				exit(0);
			}
			fread(current,sizeof(char),1000,fp);
			fclose(fp);
			puthz(60,160,current,16,16,RED);
	}
     	    else if(mouse_press(187,91,327,141)==1&&*school==5&&*flag==1)//点击优势学科 
		{
			setfillstyle(1,WHITE);
			bar(9, 156, 631, 471);
		for(i=0;i<2000;i++)
			{
				current[i]='\0';
			}
			if((fp=fopen("C:\\test\\Database\\ysxk5.dat","rb+"))==NULL)
			{
				printf("cnnot open the file\n");
				closegraph();
				exit(0);
			}
			fread(current,sizeof(char),1000,fp);
			fclose(fp);
			puthz(60,160,current,16,16,RED);
		}
     	    else if(mouse_press(346,91,486,141)==1&&*school==5&&*flag==1)//点击录取分数 
		{
			setfillstyle(1,WHITE);
			bar(9, 156, 631, 471);
			for(i=0;i<2000;i++)
			{
				current[i]='\0';
			}
			if((fp=fopen("C:\\test\\Database\\lqfs5.dat","rb+"))==NULL)
			{
				printf("cnnot open the file\n");
				closegraph();
				exit(0);
			}
			fread(current,sizeof(char),1000,fp);
			fclose(fp);
			puthz(60,160,current,16,16,RED);
		}
     	    else if(mouse_press(505,91,581,141)==1&&*school==5&&*flag==1)//点击学校档次 
		{
			setfillstyle(1,WHITE);
			bar(9, 156, 631, 471);
		for(i=0;i<2000;i++)
			{
				current[i]='\0';
			}
			if((fp=fopen("C:\\test\\Database\\xxdc5.dat","rb+"))==NULL)
			{
				printf("cnnot open the file\n");
				closegraph();
				exit(0);
			}
			fread(current,sizeof(char),1000,fp);
			fclose(fp);
			puthz(60,160,current,16,16,RED);
		}
		
	}
}
/********************************************
Function: searchresults2
Description:主菜单界面下专业的搜索界面的搜索结果详细介绍界面 
Attention:
Return:
********************************************/
int searchresults2(int*subject,int*flag)
{
	int v[16] ={5,13,15,5,15,8,20,8,20,17,15,17,15,20,5,13};
	char current[5000];
	FILE* fp=NULL;
	int i;
	cleardevice(); //清屏函数 
	*flag=1;
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
	
	if(*subject==1)
	{
		puthz(260,70,"园林艺术",24,30,LIGHTRED);
		for(i=0;i<2000;i++)
			{
				current[i]='\0';
			}
			if((fp=fopen("C:\\test\\Database\\xkzl1.dat","rb+"))==NULL)
			{
				printf("cnnot open the file\n");
				closegraph();
				exit(0);
			}
			fread(current,sizeof(char),1000,fp);
			fclose(fp);
			puthz(75,145,current,16,16,WHITE);
	}
	else if(*subject==2)
	{
		puthz(260,70,"电竞专业",24,30,LIGHTRED);
		for(i=0;i<2000;i++)
			{
				current[i]='\0';
			}
			if((fp=fopen("C:\\test\\Database\\xkzl2.dat","rb+"))==NULL)
			{
				printf("cnnot open the file\n");
				closegraph();
				exit(0);
			}
			fread(current,sizeof(char),1000,fp);
			fclose(fp);
			puthz(75,145,current,16,16,WHITE);
}
	
    while(1)
    {
		newmouse(&MouseX,&MouseY,&press);
    	if(mouse_press(5,5,20,20)==1&&*flag==1)
    	{
    		return 0;
		}
	}
}
