#include"common.h"
#include"signup.h"
#include"input.h"
int signup(){
	int page = 2;
		int mouse = 0;
		int flag = 0;
		int flag1 = 0;
		int flag2 = 0;
		char checkpw[10];
		int state=0, pre_state=0;
		struct U *user = (struct U *)malloc(sizeof(struct U));
		memset(user,0,sizeof(struct U));
		strcpy(user->name,"\0");
		strcpy(user->password,"\0");
		strcpy(checkpw,"\0");
		clrmous(MouseX,MouseY);
		delay(100);
	
	
	signupbk();	
	mouseinit();
	while(page==2){
		newmouse(&MouseX,&MouseY,&press);
		
		//确定框
/*		if(mouse_press(251,366,305,394) == 2)//鼠标在确定框中，且未点击
		{
			pre_state=state;
			state=1;
			if(pre_state!=1)//防止重复标亮
			{
				clrmous(MouseX,MouseY);
				delay(5);
				
				setcolor(YELLOW);
				setlinestyle(0,0,3);
				rectangle(251,366,305,394);
			}
		}
		
		if(mouse_press(251,366,305,394) == 1)//鼠标在确定框中，且点击
		{
			return 1;
		}
*/	
		//返回框
		if(mouse_press(335,366,389,394) == 2)//鼠标在返回框中，且未点击
		{
			pre_state=state;
			state=2;
		
			if(pre_state!=2)//防止重复标亮
			{
				clrmous(MouseX,MouseY);
				delay(5);
				
				setcolor(YELLOW);
				setlinestyle(0,0,3);
				rectangle(335,366,389,394);
			}
		}
		else if(mouse_press(335,366,389,394) == 1)//鼠标在返回框中，且点击
		{
			delay(100);
			return 1;
		}	
		
		
		
		
		else if (mouse_press(240,132+30,400,132+30+26) == 1)
		{
			inputname(user, 240,132+30);
		}

		else if (mouse_press(240,184+30,400,184+30+26) == 1)
		{
			inputpassword(user, 240,184+30);
		}

		else if (mouse_press(240,236+30,400,236+30+26) == 1)
		{
			inputpassword1(checkpw, 240,236+30);
		}




		else if (mouse_press(251,366,305,394) == 1)		//确认框
		{
/*			pre_state=state;
			state=1;
			if(pre_state!=1)//防止重复标亮
			{
				clrmous(MouseX,MouseY);
				delay(5);
				
				setcolor(YELLOW);
				setlinestyle(0,0,3);
				rectangle(251,366,305,394);
			}
*/			
			flag1 = check_register(user, checkpw);			
			if(flag1==3)
			{
				flag2 = existence(user);
				
							if (flag2 == 1)
							{
								setfillstyle(1,BLUE);
								bar(270,400,400,450);
								puthz(270, 400, "注册成功", 24, 25, WHITE);
								intofile(user);
								free(user);
								delay(500);
								page = 1;
							}
			}
			else{				
				setfillstyle(1,LIGHTBLUE);
				bar(270,400,400,450);				
				puthz(270, 400, "注册失败", 24, 25, WHITE);
			}
		}

		
		//无操作状态
		else
		{
			pre_state=state;
			state=0;
		}	
		
		//鼠标
		if(mouse_press(240,132+30,400,132+26+30)||mouse_press(240,184+30,400,184+26+30)||mouse_press(335,366,389,394)||mouse_press(240,236+30,400,236+26+30)||mouse_press(251,366,305,394)/*||mouse_press(280,250,500,280)||mouse_press(280,300,500,330)||mouse_press(280,350,500,380)*/)
			MouseS=1;
		else
			MouseS=0;
		
		//如果状态发生改变，且之前不是无操作状态，则可能需清除标亮
		if(pre_state!=state && pre_state!=0)
		{
			clrmous(MouseX,MouseY);
			delay(5);
			
				switch(pre_state)
				{
					case 1:
						setcolor(BROWN);
						setlinestyle(0,0,3);
						rectangle(251,366,305,394);	
						break;
					case 2:
						setcolor(BROWN);
						setlinestyle(0,0,3);
						rectangle(335,366,389,394);
						break;	
/*					case 3:
						setcolor(LIGHTGRAY);
						setlinestyle(0,0,1);
						rectangle(280,150,500,180);	
						break;
					case 5:
						setcolor(LIGHTGRAY);
						setlinestyle(0,0,1);
						rectangle(280,200,500,230);	
						break;
					case 6:
						setcolor(LIGHTGRAY);
						setlinestyle(0,0,1);
						rectangle(280,300,500,330);	
						break;
					case 7:
						setcolor(LIGHTGRAY);
						setlinestyle(0,0,1);
						rectangle(280,250,500,280);	
						break;
					case 8:
						setcolor(LIGHTGRAY);
						setlinestyle(0,0,1);
						rectangle(280,350,500,380);	
						break;*/
				}
		}
			
	}
	return page;
}


/*********************************************
FUNCTION:inputname
DESCRIPTION:输入用户名
PARAMETERS:struct U *user, int x1, int y1
RETURN:void
***********************************************/
void inputname(struct U *user, int x1, int y1)
{
	int i = 0;
	char t;
	char a[2];
	strcpy(user->name,"\0");
	clrmous(MouseX, MouseY);
	setfillstyle(SOLID_FILL, LIGHTGRAY);
	setlinestyle(SOLID_LINE, 0, NORM_WIDTH);
	bright(x1, y1, x1 + 160, y1 + 26, LIGHTGRAY);
	setcolor(BLUE);
	settextstyle(TRIPLEX_FONT, HORIZ_DIR, 2);
	settextjustify(LEFT_TEXT, TOP_TEXT);
	
	while (1)
	{
		t = bioskey(0);
		if (i < 10)
		{
			if (t != '\n'
				&& t != '\r'
				&& t != ' ')
			{
				if (t != '\b')
				{
					user->name[i] = t;
					a[0] = t;
					a[1] = '\0';
					user->name[i + 1] = '\0';
					outtextxy(2 + x1 + i * 10, y1 - 2, a);
					i++;
				}
				else if (t == '\b' && i > 0)
				{
					bar(x1 + i * 10 - 8, y1 , x1 + i * 10 + 4, y1 + 22);
					i--;
					user->name[i] = '\0';
				}
			}
			else
			{
				setfillstyle(SOLID_FILL, LIGHTGRAY);
				break;
			}
		}
		else if (i >= 10)
		{
			if (t != '\n'
				&& t != '\r'
				&& t != ' '
				&& t != 033)//Esc
			{
				if (t == '\b' && i > 0)
				{
					bar(x1 + i * 10 - 8, y1 , x1 + i * 10 + 4, y1 + 22);
					i--;
					user->name[i] = '\0';
				}
			}
			else
			{
				setfillstyle(SOLID_FILL, LIGHTGRAY);
				break;
			}
		}
	}
	bright(x1, y1, x1 + 160, y1 + 26, WHITE);
	outtextxy(x1 + 2, y1 - 2, user->name);
}

/*********************************************
FUNCTION:inputpassword
DESCRIPTION:输入密码
PARAMETERS:struct U *user, int x1, int y1
RETURN:void
***********************************************/
void inputpassword(struct U *user, int x1, int y1)
{
	int i = 0;
	char t;
	char a[2];
	strcpy(user->password,"\0");
	clrmous(MouseX, MouseY);
	setfillstyle(SOLID_FILL, LIGHTGRAY);
	setlinestyle(SOLID_LINE, 0, NORM_WIDTH);
	bright(x1, y1, x1 + 160, y1 + 26, LIGHTGRAY);
	setcolor(BLUE);
	settextstyle(TRIPLEX_FONT, HORIZ_DIR, 2); 
	settextjustify(LEFT_TEXT, TOP_TEXT);
	
	while (1)
	{
		t = bioskey(0);
		if (i < 10)
		{
			if (t != '\n'
				&& t != '\r'
				&& t != ' ')
			{
				if (t != '\b')
				{
					user->password[i] = t;
					a[0] = t;
					a[1] = '\0';
					user->password[i + 1] = '\0';
					outtextxy(2 + x1 + i * 10, y1 - 2, a);
					i++;
				}
				else if (t == '\b' && i > 0)
				{
					bar(x1 + i * 10 - 8, y1 , x1 + i * 10 + 4, y1 + 22);
					i--;
					user->password[i] = '\0';
				}
			}
			else
			{
				setfillstyle(SOLID_FILL, LIGHTGRAY);
				break;
			}
		}
		else if (i >= 10)
		{
			if (t != '\n'
				&& t != '\r'
				&& t != ' ')
			{
				
				if (t == '\b' && i > 0)
				{
					bar(x1 + i * 10 - 8, y1 , x1 + i * 10 + 4, y1 + 22);
					i--;
					user->password[i] = '\0';
				}
			}
			else
			{
				setfillstyle(SOLID_FILL, LIGHTGRAY);
				break;
			}
		}
	}
	bright(x1, y1, x1 + 160, y1 + 26, WHITE);
	outtextxy(x1 + 2, y1 - 2, user->password);
}

/*********************************************
FUNCTION:inputpassword1
DESCRIPTION:输入确认密码
PARAMETERS:struct U *user, int x1, int y1
RETURN:void
***********************************************/
void inputpassword1(char *p, int x1, int y1)
{
	int i = 0;
	char t;
	char a[2];
	strcpy(p,"\0");
	clrmous(MouseX, MouseY);
	setfillstyle(SOLID_FILL, LIGHTGRAY);
	setlinestyle(SOLID_LINE, 0, NORM_WIDTH);
	bright(x1, y1, x1 + 160, y1 + 26, LIGHTGRAY);
	setcolor(BLUE);
	settextstyle(TRIPLEX_FONT, HORIZ_DIR, 2);
	settextjustify(LEFT_TEXT, TOP_TEXT);
	
	while (1)
	{
		t = bioskey(0);
		if (i < 10)
		{
			if (t != '\n'
				&& t != '\r'
				&& t != ' ')
			{
				if (t != '\b')
				{
					p[i] = t;
					a[0] = t;
					a[1] = '\0';
					p[i + 1] = '\0';
					outtextxy(2 + x1 + i * 10, y1 - 2, a);
					i++;
				}
				else if (t == '\b' && i > 0)
				{
					bar(x1 + i * 10 - 8, y1 , x1 + i * 10 + 4, y1 + 22);
					i--;
					p[i] = '\0';
				}
			}
			else
			{
				setfillstyle(SOLID_FILL, LIGHTGRAY);
				break;
			}
		}
		else if (i >= 10)
		{
			if (t != '\n'
				&& t != '\r'
				&& t != ' '
				&& t != 033)
			{
				if (t == '\b' && i > 0)
				{
					bar(x1 + i * 10 - 8, y1 , x1 + i * 10 + 4, y1 + 22);
					i--;
					p[i] = '\0';
				}
			}
			else
			{
				setfillstyle(SOLID_FILL, LIGHTGRAY);
				break;
			}
		}
	}
	bright(x1, y1, x1 + 160, y1 + 26, WHITE);
	outtextxy(x1 + 2, y1 - 2, p);
}


/*********************************************
FUNCTION:inputyear
DESCRIPTION:输入高考年份
PARAMETERS:struct U *user, int x1, int y1
RETURN:void
***********************************************/
/*void inputyear(struct U *user, int x1, int y1){
	int i = 0;
	char t;
	char a[2];
	strcpy(user->year,"\0");
	clrmous(MouseX, MouseY);
	setfillstyle(SOLID_FILL, LIGHTGRAY);
	setlinestyle(SOLID_LINE, 0, NORM_WIDTH);
	bright(x1, y1, x1 + 163, y1 + 26, LIGHTGRAY);
	setcolor(BLUE);
	settextstyle(TRIPLEX_FONT, HORIZ_DIR, 2); 
	settextjustify(LEFT_TEXT, TOP_TEXT);
	
	while (1)
	{
		t = bioskey(0);
		if (i < 5)
		{
			if (t != '\n'
				&& t != '\r'
				&& t != ' ')
			{
				if (t != '\b')
				{
					user->year[i] = t;
					a[0] = t;
					a[1] = '\0';
					user->year[i + 1] = '\0';
					outtextxy(2 + x1 + i * 10, y1 - 2, a);
					i++;
				}
				else if (t == '\b' && i > 0)
				{
					bar(x1 + i * 10 - 8, y1 , x1 + i * 10 + 4, y1 + 22);
					i--;
					user->year[i] = '\0';
				}
			}
			else
			{
				setfillstyle(SOLID_FILL, LIGHTGRAY);
				break;
			}
		}
		else if (i >= 5)
		{
			if (t != '\n'
				&& t != '\r'
				&& t != ' ')
			{
				if (t == '\b' && i > 0)
				{
					bar(x1 + i * 10 - 8, y1 , x1 + i * 10 + 4, y1 + 22);
					i--;
					user->year[i] = '\0';
				}
			}
			else
			{
				setfillstyle(SOLID_FILL, LIGHTGRAY);
				break;
			}
		}
	}
	bright(x1, y1, x1 + 163, y1 + 26, WHITE);
	outtextxy(x1 + 2, y1 - 2, user->year);	
}


/*********************************************
FUNCTION:inputprov
DESCRIPTION:输入高考省份
PARAMETERS:struct U *user, int x1, int y1
RETURN:void
***********************************************/
/*void inputprov(struct U *user, int x1, int y1){
	int i = 0;
	char t;
	char a[2];
	strcpy(user->province,"\0");
	clrmous(MouseX, MouseY);
	setfillstyle(SOLID_FILL, LIGHTGRAY);
	setlinestyle(SOLID_LINE, 0, NORM_WIDTH);
	bright(x1, y1, x1 + 163, y1 + 26, LIGHTGRAY);
	setcolor(BLUE);
	settextstyle(TRIPLEX_FONT, HORIZ_DIR, 2); 
	settextjustify(LEFT_TEXT, TOP_TEXT);
	
	while (1)
	{
		t = bioskey(0);
		if (i < 10)
		{
			if (t != '\n'
				&& t != '\r'
				&& t != ' ')
			{
				if (t != '\b')
				{
					user->province[i] = t;
					a[0] = t;
					a[1] = '\0';
					user->province[i + 1] = '\0';
					outtextxy(2 + x1 + i * 10, y1 - 2, a);
					i++;
				}
				else if (t == '\b' && i > 0)
				{
					bar(x1 + i * 10 - 8, y1 , x1 + i * 10 + 4, y1 + 22);
					i--;
					user->province[i] = '\0';
				}
			}
			else
			{
				setfillstyle(SOLID_FILL, LIGHTGRAY);
				break;
			}
		}
		else if (i >= 10)
		{
			if (t != '\n'
				&& t != '\r'
				&& t != ' ')
			{
				if (t == '\b' && i > 0)
				{
					bar(x1 + i * 10 - 8, y1 , x1 + i * 10 + 4, y1 + 22);
					i--;
					user->province[i] = '\0';
				}
			}
			else
			{
				setfillstyle(SOLID_FILL, LIGHTGRAY);
				break;
			}
		}
	}
	bright(x1, y1, x1 + 163, y1 + 26, WHITE);
	outtextxy(x1 + 2, y1 - 2, user->province);	
}


/*********************************************
FUNCTION:inputrange
DESCRIPTION:输入高考省排名
PARAMETERS:struct U *user, int x1, int y1
RETURN:void
***********************************************/
/*void inputrange(struct U *user, int x1, int y1){
	int i = 0;
	char t;
	char a[2];
	strcpy(user->range,"\0");
	clrmous(MouseX, MouseY);
	setfillstyle(SOLID_FILL, LIGHTGRAY);
	setlinestyle(SOLID_LINE, 0, NORM_WIDTH);
	bright(x1, y1, x1 + 163, y1 + 26, LIGHTGRAY);
	setcolor(BLUE);
	settextstyle(TRIPLEX_FONT, HORIZ_DIR, 2); 
	settextjustify(LEFT_TEXT, TOP_TEXT);
	
	while (1)
	{
		t = bioskey(0);
		if (i < 5)
		{
			if (t != '\n'
				&& t != '\r'
				&& t != ' ')
			{
				if (t != '\b')
				{
					user->range[i] = t;
					a[0] = t;
					a[1] = '\0';
					user->range[i + 1] = '\0';
					outtextxy(2 + x1 + i * 10, y1 - 2, a);
					i++;
				}
				else if (t == '\b' && i > 0)
				{
					bar(x1 + i * 10 - 8, y1 , x1 + i * 10 + 4, y1 + 22);
					i--;
					user->range[i] = '\0';
				}
			}
			else
			{
				setfillstyle(SOLID_FILL, LIGHTGRAY);
				break;
			}
		}
		else if (i >= 4)
		{
			if (t != '\n'
				&& t != '\r'
				&& t != ' ')
			{
				if (t == '\b' && i > 0)
				{
					bar(x1 + i * 10 - 8, y1 , x1 + i * 10 + 4, y1 + 22);
					i--;
					user->range[i] = '\0';
				}
			}
			else
			{
				setfillstyle(SOLID_FILL, LIGHTGRAY);
				break;
			}
		}
	}
	bright(x1, y1, x1 + 163, y1 + 26, WHITE);
	outtextxy(x1 + 2, y1 - 2, user->range);	
}

/*********************************************
FUNCTION:check_register
DESCRIPTION:检验各项数据是否输入正确
PARAMETERS:struct U *user, char *cp
RETURN:t
***********************************************/
int check_register(struct U *user, char *cp)
{
	int t = 0;
	int length, i;
	struct U *a1;         //有鸟用？

	if (strcmp(user->name, "\0") == 0)
	{
		puthz(240, 132+30+26+2, "用户名未输入", 16, 16, WHITE);
		delay(1000);

		return 0;
	}

	else
	{
        t++;
	}
	
	if (strcmp(user->password, "\0") == 0)
	{
		puthz(240, 184+30+26+2, "密码未输入", 16, 16, WHITE);
		delay(1000);

		return 0;
	}

	else
	{
        t++;
	}

	if (strcmp(cp, user->password) != 0)
	{
		puthz(240, 236+30+26+2, "密码不一致", 16, 16, WHITE);
		delay(1000);

		return 0;
	}
	
	else
	{
		t++;
	}
	

	return t;
}

/*********************************************
FUNCTION:existence
DESCRIPTION:检验用户是否存在
PARAMETERS:struct U *user
RETURN:0/1
***********************************************/
int existence(struct U *user)
{
	FILE *fp = NULL;
	int length, i;
	struct U *u= (struct U *)malloc(sizeof(struct U));

	if ((fp = fopen("C:\\test\\Database\\user.dat", "rb+")) == NULL)
	{
		outtextxy(320, 300, "file cannot be opened");
		delay(1000);
		exit(1);
	}

	fseek(fp, 0, 2);
	length = ftell(fp) / sizeof(struct U);
	
	for (i = 0; i < length; i++)
	{
		if ((u = (struct U*)malloc(sizeof(struct U))) == NULL)
		{
			printf("no enough memory");
			exit(1);
		}
		fseek(fp, i * sizeof(struct U), SEEK_SET);
		fread(u, sizeof(struct U), 1, fp);

		if (strcmp(u->name, user->name) == 0)
		{
			puthz(240, 132+30+26+2, "用户存在", 24, 24, WHITE);
			delay(1500);

			if (u != NULL)
			{
				free(u);
				u = NULL;
			}
			if (fclose(fp) != 0)
			{
				printf("\n 1 cannot close datatabase.");
				delay(3000);
				exit(1);
			}
			return 0;
		}

		free(u);
		u = NULL;
	}

	if (fclose(fp) != 0)
	{
		printf("\n 2 cannot close datatabase.");
		delay(3000);
		exit(1);
	}

	return 1;
}

/*********************************************
FUNCTION:intofile
DESCRIPTION:注册信息写入文件
PARAMETERS:struct U *user
RETURN:void
***********************************************/
void intofile(struct U *user)
{
	FILE *fp = NULL;

	if ((fp = fopen("C:\\test\\Database\\user.dat", "rb+")) == NULL)
	{
		printf("file cannot be opened222\n");
		exit(1);
	}

	fseek(fp, 0, SEEK_END); 
	fwrite(user, sizeof(struct U), 1, fp);
//	fprintf(fp,"%s %s ",user->name,user->password);
	
	if (user != NULL)
	{
		free(user);
		user = NULL;
	}

	if (fclose(fp) != 0)
	{
		printf("\n cannot close datatabase.");
		delay(3000);
		exit(1);
	}
}



/*********************************************
FUNCTION:signupbk
DESCRIPTION:注册界面
PARAMETERS:void
RETURN:void
***********************************************/
void signupbk(){
	int i=0;
	int a[5]={80+30,132+30,184+30,236+30,288+30};
//	int gd=VGA,gm=VGAHI;
//	initgraph(&gd,&gm,"C:\\borland c\\bgi");
	cleardevice();
	setbkcolor(BLACK);
	setfillstyle(1,BLUE);
	bar(10,10,640-10,480-10);
	setcolor(BROWN);
	setlinestyle(0,0,3);
	rectangle(10,10,640-10,480-10);
	
	puthz(286,80,"注册",32,34,WHITE);
	
	//输入信息
	puthz(240-88,132+30,"用户名",24,26,WHITE);
	puthz(240-62,184+30,"密码",24,26,WHITE);
	puthz(240-114,236+30,"确认密码",24,26,WHITE);

	setcolor(YELLOW);
	setlinestyle(0,0,3);
	setfillstyle(1,WHITE);
	for(i=1;i<4;i++){
		bar(240,a[i],400,a[i]+26);
		rectangle(240,a[i],400,a[i]+26);
	}
	

	//确定，退出
	setcolor(BROWN);
	bar(251,366,305,394);
	rectangle(251,366,305,394);
	bar(335,366,389,394);
	rectangle(335,366,389,394);
	puthz(253,368,"确定",24,26,RED);
	puthz(337,368,"退出",24,26,RED);
	


}
