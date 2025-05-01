#include"common.h"
#include"connect.h"
int connect(int a,int b,int *pschool,int *sorts,int *subjects,int *flag3)
{
	int state = 0, pre_state = 0;
	delay(100);
	mouseinit();
	
		
	if(a==0)
	{
		puthz(164,178,"清华大学",24,26,BROWN);
	}
	else if(a==1)
	{
		puthz(164,178,"北京大学",24,26,BROWN);
	}	
	else if(a==2)
	{
		puthz(164,178,"浙江大学",24,26,BROWN);
	}		
	else if(a==3)
	{
		puthz(164,178,"上海交通大学",24,26,BROWN);
	}	
	else if(a==4)
	{
		puthz(164,178,"复旦大学",24,26,BROWN);
	}		
	else if(a==5)
	{
		puthz(164,178,"南京大学",24,26,BROWN);
	}		
	else if(a==6)
	{
		puthz(164,178,"中国科学技术大学",24,26,BROWN);
	}		
	else if(a==7)
	{
		puthz(164,178,"华中科技大学",24,26,BROWN);
	}		
	else if(a==8)
	{
		puthz(164,178,"武汉大学",24,26,BROWN);
	}		
	else if(a==9)
	{
		puthz(164,178,"西安交通大学",24,26,BROWN);
	}		
	
	if(b==0)
	{
		puthz(164,258,"人工智能",24,26,BROWN);
	}
	else if(b==1)
	{
		puthz(164,258,"计算机科学",24,26,BROWN);
	}	
	else if(b==2)
	{
		puthz(164,258,"自动化",24,26,BROWN);
	}	
	else if(b==3)
	{
		puthz(164,258,"电气",24,26,BROWN);
	}		
	else if(b==4)
	{
		puthz(164,258,"临床医学",24,26,BROWN);
	}		
	else if(b==5)
	{
		puthz(164,258,"数学",24,26,BROWN);
	}		
	else if(b==6)
	{
		puthz(164,258,"物理",24,26,BROWN);
	}		
	else if(b==7)
	{
		puthz(164,258,"能源工程",24,26,BROWN);
	}		
	
	else if(b==8)
	{
		puthz(164,258,"机械制造",24,26,BROWN);
	}	
	else if(b==9)
	{
		puthz(164,258,"法学",24,26,BROWN);
	}		
	else if(b==10)
	{
		puthz(164,258,"语言学",24,26,BROWN);
	}		
	else if(b==11)
	{
		puthz(164,258,"哲学",24,26,BROWN);
	}			
	
	
	while(1)
	{
		newmouse(&MouseX, &MouseY, &press);
		if (mouse_press(160,170,480,210) == 2) { //鼠标在大学框中，且未点击
			pre_state = state;
			state = 1;
			
			if (pre_state != 1) { //防止重复标亮
				clrmous(MouseX, MouseY);
				delay(5);

				setcolor(RED);
				setlinestyle(0, 0, 3);
				rectangle(160,170,480,210);
			}
		}


		else if (mouse_press(160,170,480,210) == 1) { //鼠标在大学框中，且点击
			
			*pschool=a+1;
			return 9;
		}
		
		
		
		else if (mouse_press(320 - 28, 315, 320 + 28, 343) == 2) { //鼠标在返回框中，且未点击
			pre_state = state;
			state = 2;
			
			if (pre_state != 2) { //防止重复标亮
				clrmous(MouseX, MouseY);
				delay(5);

				setcolor(YELLOW);
				setlinestyle(0, 0, 3);
				rectangle(320 - 28, 315, 320 + 28, 343);
			}
		}


		else if (mouse_press(320 - 28, 315, 320 + 28, 343) == 1) { //鼠标在返回框中，且点击
			
			if(*flag3==1)
			{
				return 4;
			}
			else if(*flag3==2)
			{
				return 6;
			}
			
		}		
		
		
		
		else if (mouse_press(160,250,480,290) == 2) { //鼠标在专业框中，且未点击
			pre_state = state;
			state = 3;
			
			if (pre_state != 3) { //防止重复标亮
				clrmous(MouseX, MouseY);
				delay(5);

				setcolor(YELLOW);
				setlinestyle(0, 0, 3);
				rectangle(160,250,480,290);
			}
		}


		else if (mouse_press(160,250,480,290) == 1) { //鼠标在专业框中，且点击
			
			switch(b)
			{
				case 0:
					*sorts=2;
					*subjects=2;
					break;
				case 1:
					*sorts=3;
					*subjects=3;
					break;				
				case 2:
					*sorts=5;
					*subjects=1;
					break;			
				case 3:
					*sorts=2;
					*subjects=1;
					break;
				case 4:
					*sorts=4;
					*subjects=4;	
					break;				
				case 5:
					*sorts=3;
					*subjects=1;
					break;					
				case 6:
					*sorts=3;
					*subjects=2;
					break;					
				case 7:
					*sorts=2;
					*subjects=4;
					break;					
				case 8:
					*sorts=2;
					*subjects=3;
					break;					
				case 9:
					*sorts=4;
					*subjects=1;
					break;					
				case 10:
					*sorts=4;
					*subjects=3;
					break;
				case 11:
					*sorts=4;
					*subjects=2;
					break;												
			}
			
			return 13;
		}
			
			
		//无操作状态
		else {
			
			pre_state = state;
			state = 0;
			
		}

		//鼠标
		if (mouse_press(160,170,480,210) || mouse_press(320 - 28, 315, 320 + 28, 343)||mouse_press(160,250,480,290))		
			MouseS = 1;
		else		
			MouseS = 0;

		//如果状态发生改变，且之前不是无操作状态，则可能需清除标亮
		if (pre_state != state && pre_state != 0) {
			
			clrmous(MouseX, MouseY);
			delay(5);

			switch (pre_state) {
				
				case 1:
					setcolor(LIGHTGRAY);
					setlinestyle(0, 0, 3);
					rectangle(160,170,480,210);
					break;
					
				case 2:
					setcolor(BROWN);
					setlinestyle(0, 0, 3);
					rectangle(320 - 28, 315, 320 + 28, 343);
					break;
					
				case 3:
					setcolor(LIGHTGRAY);
					setlinestyle(0, 0, 3);
					rectangle(160,250,480,290);
					break;	
								
			}
		}										
		
	}
				
}

void connectbk(void)
{
	cleardevice();
	setbkcolor(BLACK);
	setfillstyle(1, BLUE);
	bar(10, 10, 640 - 10, 480 - 10);
	setcolor(BROWN);
	setlinestyle(0, 0, 3);
	rectangle(10, 10, 640 - 10, 480 - 10);
	
	setfillstyle(1,WHITE);
	bar(160,170,480,210);
	bar(160,250,480,290);
	
	setcolor(BROWN);
	setlinestyle(0,0,3);
	rectangle(160,170,480,210);
	rectangle(160,250,480,290);

	//返回键
	setlinestyle(0, 0, 3);
	setfillstyle(1, WHITE);
	setcolor(BROWN);
	bar(320 - 28, 315, 320 + 28, 343);
	rectangle(320 - 28, 315, 320 + 28, 343);
	puthz(320 - 28 + 3, 318, "返回", 24, 26, RED);	

		
}
