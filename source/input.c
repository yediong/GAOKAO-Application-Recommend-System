#include"common.h"
#include"input.h"
#include"signup.h"


			
/*********************************************
FUNCTION:inputyear
DESCRIPTION:输入高考年份
PARAMETERS:struct U *user, int x1, int y1
RETURN:void
***********************************************/
void inputyear(struct U *user, int x1, int y1){
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
FUNCTION:inputrange
DESCRIPTION:输入高考省排名
PARAMETERS:struct U *user, int x1, int y1
RETURN:void
***********************************************/
void inputrange(struct U *user, int x1, int y1){
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
FUNCTION:check_register2
DESCRIPTION:检验各项数据是否输入正确
PARAMETERS:struct U *user, char *cp
RETURN:t
***********************************************/
int check_register2(struct U *user/*, char *cp*/)
{
	int t = 0;
	int length, i;
	struct U *a1;

	if (strcmp(user->year, "0") == 0)
	{
		setfillstyle(1,BLUE);
		bar(147,132+30+26+2,147+16*8,184+30-3);
		puthz(147, 132+30+26+2, "高考年份未输入", 16, 16, WHITE);
		delay(500);
		return 0;
	}
	
	else if(atoi(user->year)<2021||atoi(user->year)>2023)
	{
		setfillstyle(1,BLUE);
		bar(147,132+30+26+2,147+16*8,184+30-3);		
		puthz(147, 132+30+26+2, "高考年份超出范围", 16, 16, WHITE);
		return 0;
	}	

	else
	{
		setfillstyle(1,BLUE);
		bar(147,132+30+26+2,147+16*8,184+30-3);				
		
        t++;
	}	

	if (strcmp(user->province, "0") == 0)
	{
		puthz(147,236+30+26+2, "高考省份未输入", 16, 16, WHITE);
		delay(500);

		return 0;
	}
	
	else
	{
        t++;
	}	
	
	
	
	
	if(strcmp(user->range,"0")==0)
	{
		setfillstyle(1,BLUE);
		bar(147,184+30+26+2,147+16*9,236+30-3);			
		
		puthz(147, 184+30+26+2, "高考省排名未输入", 16, 16, WHITE);
		delay(500);

		return 0;				
	}
	

	else if((atoi(user->range)>3000||atoi(user->range)<1)&&(user->choose==1||user->choose==2||user->choose==3))
	{
		setfillstyle(1,BLUE);
		bar(147,184+30+26+2,147+16*9,236+30-3);			
		
		puthz(147, 184+30+26+2, "高考省排名超出范围", 16, 16, WHITE);
		delay(500);

		return 0;		
	}


	else if((atoi(user->range)>900||atoi(user->range)<1)&&(user->choose==4||user->choose==5||user->choose==6))
	{
		setfillstyle(1,BLUE);
		bar(147,184+30+26+2,147+16*9,236+30-3);			
		
		puthz(147, 184+30+26+2, "高考省排名超出范围", 16, 16, WHITE);
		delay(500);

		return 0;		
	}	


	else
	{
		setfillstyle(1,BLUE);
		bar(147,184+30+26+2,147+16*9,236+30-3);			
        t++;
	}		
	
	
	
	if (user->choose== 0)
	{
		puthz(147, 254+30+26+2, "高考选科未输入", 16, 16, WHITE);
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
FUNCTION:intofile2
DESCRIPTION:注册信息写入文件
PARAMETERS:struct U *user
RETURN:void
***********************************************/
void intofile2(struct U *user)
{
	FILE *fp = NULL;
    int len=0; //用户个数
    int i=0;
    struct U *su; //暂存从文件中读到的数据
    
	if ((fp = fopen("C:\\test\\Database\\user.dat", "rb+")) == NULL)
	{
		printf("file cannot be opened222\n");
		exit(1);
	}

    fseek(fp, 0, SEEK_END);
    len = ftell(fp) / sizeof(struct U); //得到结构体的数目


       for (i = 0; i < len; i++)
        {
            if ((su = (struct U *)malloc(sizeof(struct U))) == NULL)
            {
                printf("memory allocation runs wrong in input.c");
                delay(3000);
                exit(1);
            }
            
            fseek(fp, i * sizeof(struct U), SEEK_SET);//光标移到第i个结构体开头
            fread(su, sizeof(struct U), 1, fp);
            
			if (strcmp(su->name, user->name) == 0) //用户名匹配
            {
                if (strcmp(su->password, user->password) == 0) //密码匹配
                {
                    fseek(fp, i * sizeof(struct U), SEEK_SET);//指针回退一个（fread会向前移指针）
                    fwrite(user, sizeof(struct U), 1, fp);
                    if (su != NULL)
                    {
                        free(su);
                        su = NULL;
                    }
                    delay(1000);
                    if (fclose(fp) != 0)
                    {
                        printf("\n cannot close Database");
                        delay(3000);
                        exit(1);
                    }
                    break;
                }
            }
            if (su != NULL)//若已经走到最后一个,要清除su
            {
                free(su);
                su = NULL;
            }
        }

        if (su != NULL)
        {
            free(su);
            su = NULL;
        }



}

/*********************************************
FUNCTION:bright
DESCRIPTION:点亮/恢复输入框
PARAMETERS:int x1,int y1,int x2,int y2,int bkcolor
RETURN:void
***********************************************/
void bright(int x1,int y1,int x2,int y2,int bkcolor)
{
	clrmous(MouseX, MouseY);
	setfillstyle(1, bkcolor);
	bar(x1, y1, x2, y2);
}


/*********************************************
FUNCTION:page3light
DESCRIPTION:按键亮框
PARAMETERS:int x1, int y1, char *s
RETURN:void
***********************************************/
void page3light(int x1, int y1, char *s)
{
	clrmous(MouseX, MouseY);
	setfillstyle(SOLID_FILL, BLUE);
	bar(x1, y1, x1 + 68, y1 + 34);
	puthz(x1 + 10, y1 + 5, s, 24, 26, WHITE);
}


/*********************************************
FUNCTION:page3recover
DESCRIPTION:按键恢复
PARAMETERS:int x1, int y1, char *s
RETURN:void
***********************************************/
void page3recover(int x1, int y1,char*s)
{
	clrmous(MouseX, MouseY);
	setfillstyle(SOLID_FILL, WHITE);
	bar(x1, y1, x1 + 68, y1 + 34);
	puthz(x1 + 10, y1 + 5, s, 24, 26, BLUE);
}



/*********************************************
FUNCTION:buttonlight
DESCRIPTION:选科组合按键亮框
PARAMETERS:int x1, int y1, char *s
RETURN:void
***********************************************/
void buttonlight(int x1, int y1)
{
	clrmous(MouseX, MouseY);
	setlinestyle(0,0,3);
	setcolor(GREEN);
	rectangle(x1, y1, x1 + 80, y1 + 26);
}


/*********************************************
FUNCTION:buttonlight
DESCRIPTION:选科组合按键恢复
PARAMETERS:int x1, int y1, char *s
RETURN:void
***********************************************/
void buttonrecover(int x1, int y1)
{
	clrmous(MouseX, MouseY);
	setlinestyle(0,0,3);
	setcolor(YELLOW);
	rectangle(x1, y1, x1 + 80, y1 + 26);
}


void inputbk()
{
	int i=0;
	int a[5]={80+30,132+30,184+30,236+30,288+30};
	cleardevice();
	setbkcolor(BLACK);
	setfillstyle(1,BLUE);
	bar(10,10,640-10,480-10);
	setcolor(BROWN);
	setlinestyle(0,0,3);
	rectangle(10,10,640-10,480-10);
	rectangle(1, 1, 639, 479);	
	
	puthz(320-34*3,20+20,"个人信息输入",32,34,WHITE);
	
	//输入信息
	puthz(92,132+30,"年份",24,26,WHITE);
	puthz(40,184+30,"全省排名",24,26,WHITE);
	puthz(92,236+30,"省份",24,26,WHITE);
	
	//左边的框们
	setcolor(YELLOW);
	setlinestyle(0,0,3);
	setfillstyle(1,WHITE);
	for(i=1;i<4;i++){
		bar(144+3,a[i],310,a[i]+26);
		rectangle(147,a[i],310,a[i]+26);
	}
	

	//选科组合
	//被选项鼠标点击后变为绿框
	setlinestyle(0,0,1);
	puthz(410,110,"选科组合",24,26,WHITE);
	for(i=1;i<4;i++){
		bar(370,a[i],450,a[i]+26);
		rectangle(370,a[i],450,a[i]+26);
	}
	for(i=1;i<4;i++){
		bar(470,a[i],550,a[i]+26);
		rectangle(470,a[i],550,a[i]+26);
	}
	
	puthz(371,a[1]+1,"物化生",24,26,BROWN);
	puthz(371,a[2]+1,"物化地",24,26,BROWN);
	puthz(371,a[3]+1,"物生地",24,26,BROWN);
	puthz(471,a[1]+1,"史政地",24,26,BROWN);
	puthz(471,a[2]+1,"史生地",24,26,BROWN);
	puthz(471,a[3]+1,"史政生",24,26,BROWN);
	
	//确定，退出
	setcolor(BROWN);
	bar(251,366,305,394);
	rectangle(251,366,305,394);
	bar(335,366,389,394);
	rectangle(335,366,389,394);
	puthz(253,368,"确定",24,26,RED);
	puthz(337,368,"退出",24,26,RED);
	
	puthz(15,465-16-17*2,"注：省份仅限于江苏和湖南",16,17,YELLOW);
	puthz(15,465-16-17,"且高考省排名理科最高为一，最低为三千；文科最低为九百",16,17,YELLOW);	
	puthz(15,465-16,"高考年份仅限于二零二一到二零二三年之间",16,17,YELLOW);		
	
}	





int input(struct U *user,int *flag12)
{
	int page = 5;
	int mouse = 0;
	int flag = 0;
	int flag1 = 0;
	int flag2 = 0;	
	int flag3 =0;
//	struct U *user = (struct U *)malloc(sizeof(struct U));
//	memset(user,0,sizeof(struct U));
		
		strcpy(user->province, "0");
		strcpy(user->year, "0");	
		strcpy(user->range, "0");
		user->choose=0;		
		*flag12=0;
		
		clrmous(MouseX,MouseY);
		delay(100);
	
		inputbk();
		mouseinit();
		while(page==5){
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
				
				setcolor(RED);
				setlinestyle(0,0,1);
				rectangle(251,366,305,394);
			}
		}
		
		else if(mouse_press(251,366,305,394) == 1)//鼠标在确定框中，且点击
		{
			return 1;
		}
	
		//返回框
/*		else if(mouse_press(335,366,389,394) == 2)//鼠标在返回框中，且未点击
		{
			pre_state=state;
			state=2;
		
			if(pre_state!=2)//防止重复标亮
			{
				clrmous(MouseX,MouseY);
				delay(5);
				
				setcolor(RED);
				setlinestyle(0,0,1);
				rectangle(335,366,389,394);
			}
		}
		else */if(mouse_press(335,366,389,394) == 1)//鼠标在返回框中，且点击
		{
			delay(100);
			return 0;
		}			
		
	
		if (mouse_press(144+3,132+30,310,132+30+26) == 1)
		{
			inputyear(user, 144+3,132+30);
		}
		else if(mouse_press(144+3,184+30,310,184+30+26)==1)
		{
			inputrange(user, 144+3,184+30);
		}
		
		else if (mouse_press(144+3,236+30,310,236+30+26) == 1&&flag3==0)
		{
	//		inputprov(user,144+3,236+30);
	
			flag3=1;
			delay(10);
			clrmous(MouseX,MouseY);
			setfillstyle(1,WHITE);
			setlinestyle(0,0,1);
			setcolor(BROWN);
			bar(147,292,310,360);
			rectangle(147,292,310,360);
			puthz(148,293,"江苏",16,16,BLACK);
			puthz(148+40,293,"湖南",16,16,BLACK);
			puthz(148+40*2,293,"湖北",16,16,BLACK);
			puthz(148+40*3,293,"北京",16,16,BLACK);
			
			puthz(148,293+17,"上海",16,16,BLACK);
			puthz(148+40,293+17,"河北",16,16,BLACK);
			puthz(148+40*2,293+17,"河南",16,16,BLACK);
			puthz(148+40*3,293+17,"山东",16,16,BLACK);			
			
			puthz(148,293+17*2,"广东",16,16,BLACK);
			puthz(148+40,293+17*2,"山西",16,16,BLACK);
			puthz(148+40*2,293+17*2,"广西",16,16,BLACK);
			puthz(148+40*3,293+17*2,"陕西",16,16,BLACK);						
			
			puthz(148,293+17*3,"安徽",16,16,BLACK);
			puthz(148+40,293+17*3,"四川",16,16,BLACK);
			puthz(148+40*2,293+17*3,"吉林",16,16,BLACK);
			puthz(148+40*3,293+17*3,"浙江",16,16,BLACK);					
				
		}		
		
		if(flag3==1)
		{
			if(mouse_press(148,293,148+32,293+16)==1)
			{
				delay(10);
				clrmous(MouseX,MouseY);
				strcpy(user->province,"1");
				
				setfillstyle(1,WHITE);
				bar(147,236+30,310,266+26);
				setcolor(YELLOW);
				setlinestyle(0,0,1);
				rectangle(147,236+30,310,266+26);				
				
				puthz(150,267,"江苏",24,25,BLACK);
				setfillstyle(1,BLUE);
				bar(147,292,310,360);
				setlinestyle(0,0,3);
				setcolor(YELLOW);
				line(147,292,310,292);
				flag3=0;
			}
			
			
			if(mouse_press(148+40,293,148+32+40,293+16)==1)
			{
				delay(10);
				clrmous(MouseX,MouseY);
				strcpy(user->province,"2");
				
				setfillstyle(1,WHITE);
				bar(147,236+30,310,266+26);
				setcolor(YELLOW);
				setlinestyle(0,0,1);
				rectangle(147,236+30,310,266+26);
				
				puthz(150,267,"湖南",24,25,BLACK);
				setfillstyle(1,BLUE);
				bar(147,292,310,360);
				setlinestyle(0,0,3);
				setcolor(YELLOW);
				line(147,292,310,292);
				flag3=0;
			}			
			
		}
		
		
		else if(mouse_press(370,132+30,450,132+30+26)==1)
		{
			user->choose=1;		//物化生
			buttonlight(370,132+30);
			buttonrecover(370,184+30);
			buttonrecover(370,236+30);
			buttonrecover(470,132+30);
			buttonrecover(470,184+30);
			buttonrecover(470,236+30);			
		}
		else if(mouse_press(370,184+30,450,184+30+26)==1)
		{
			user->choose=2;		//物化地
			buttonlight(370,184+30);
			buttonrecover(370,132+30);
			buttonrecover(370,236+30);
			buttonrecover(470,132+30);
			buttonrecover(470,184+30);
			buttonrecover(470,236+30);				
		}		
		else if(mouse_press(370,236+30,450,236+30+26)==1)
		{
			user->choose=3;		//物生地
			buttonlight(370,236+30);
			buttonrecover(370,184+30);
			buttonrecover(370,132+30);
			buttonrecover(470,132+30);
			buttonrecover(470,184+30);
			buttonrecover(470,236+30);				
		}
		else if(mouse_press(470,132+30,550,132+30+26)==1)
		{
			user->choose=4;		//史政地
			buttonlight(470,132+30);
			buttonrecover(370,184+30);
			buttonrecover(370,236+30);
			buttonrecover(370,132+30);
			buttonrecover(470,184+30);
			buttonrecover(470,236+30);						
			
		}
		else if(mouse_press(470,184+30,550,184+30+26)==1)
		{
			user->choose=5;		//史生地
			buttonlight(470,184+30);
			buttonrecover(370,184+30);
			buttonrecover(370,236+30);
			buttonrecover(370,132+30);
			buttonrecover(470,132+30);
			buttonrecover(470,236+30);					
		}
		
		else if(mouse_press(470,236+30,550,236+30+26)==1)
		{
			user->choose=6;		//史政生
			buttonlight(470,236+30);
			buttonrecover(370,184+30);
			buttonrecover(370,236+30);
			buttonrecover(470,132+30);
			buttonrecover(470,184+30);
			buttonrecover(370,132+30);					
		}
		
/*		if(user->choose!=0)
		{
			t++;
		}
*/		
		
		else if (mouse_press(251,366,305,394) == 1)		//确认框(此处可能有问题)
		{
			flag1 = check_register2(user/*, checkpw*/);

			if(flag1==4)
			{
//				flag2 = existence(user);          //可能有问题
				
//							if (flag2 == 1)
//							{
												setfillstyle(1,BLUE);
												bar(270,400,370,426);
								puthz(270, 400, "输入成功", 24, 25, WHITE);
								intofile2(user);
								delay(1000);
								page = 2;
								*flag12=1;
//							}
			}
			else{
				setfillstyle(1,BLUE);
				bar(270,400,370,426);
				puthz(270, 400, "输入失败", 24, 25, WHITE);
			}
		}

/*		else if (mouse_press(251,366,305,394) == 2)
		{
			if (flag == 0)
			{
				page3light(251, 366, "确定");
				flag = 1;
			}
			continue;
		}
		

		if (mouse == 0)
		{
			if (flag == 1)
			{
				page3recover(251,366, "确定");
				flag = 0;
			}
		}
*/
    
		
		
		
		//还要处理一个点击选科组合卡变高亮的效果
		
		
		
		//无操作状态
/*		else
		{
			pre_state=state;
			state=0;
		}	
*/		
		//鼠标
		if(mouse_press(251,366,305,394)||mouse_press(335,366,389,394)||mouse_press(251,366,305,394)/*||mouse_press(280,250,500,280)||mouse_press(280,300,500,330)||mouse_press(280,350,500,380)*/)
			MouseS=1;
		else
			MouseS=0;
		
		//如果状态发生改变，且之前不是无操作状态，则可能需清除标亮
/*		if(pre_state!=state && pre_state!=0)
		{
			clrmous(MouseX,MouseY);
			delay(5);
			
				switch(pre_state)
				{
					case 1:
						setcolor(BROWN);
						setlinestyle(0,0,1);
						rectangle(608,0,640,32);	
						break;
					case 2:
						setcolor(BROWN);
						setlinestyle(0,0,1);
						rectangle(0,0,32,32);
						break;	
/*					case 3:
						setcolor(LIGHTGRAY);
						setlinestyle(0,0,1);
						rectangle(280,150,500,180);	
						break;
*/
//				}
//		}
			
	}
	
	
	return page;
}				
