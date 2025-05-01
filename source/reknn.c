#include"common.h"
#include"reknn.h"
int resultknn(int *p,int *flag3){
	int state=0,pre_state=0;
	int v[16] ={5,13,15,5,15,8,20,8,20,17,15,17,15,20,5,13};		
	delay(100);
//	clrmous(MouseX,MouseY);
//	resultbk();
	mouseinit();
	*flag3=2;
	
	while(1){
		newmouse(&MouseX,&MouseY,&press);
		if(mouse_press(320-28,300,320+28,328) == 2)//鼠标在返回框中，且未点击
				{
					pre_state=state;
					state=1;
					if(pre_state!=1)//防止重复标亮
					{
						clrmous(MouseX,MouseY);
						delay(5);
						
						setcolor(RED);
						setlinestyle(0,0,3);
						rectangle(320-28,300,320+28,328);
					}
				}
				
		else if(mouse_press(320-28,300,320+28,328) == 1)//鼠标在返回框中，且点击
		{
			return 2;
		}
		
			//返回框
				else if(mouse_press(5,5,20,17) == 2)//鼠标在返回框中，且未点击
				{
					pre_state=state;
					state=2;
				
					if(pre_state!=2)//防止重复标亮
					{
						clrmous(MouseX,MouseY);
						delay(5);
						
						setcolor(RED);
						setlinestyle(0,0,3);
						fillpoly(8,v);
					}
				}
				
				else if(mouse_press(5,5,20,17) == 1)//鼠标在返回框中，且点击
				{
					delay(100);
					return 0;
				}
	
	
/*第一行*/		
		else if (mouse_press(120, 100 + 30, 640 - 125, 100 + 30 + 28) == 2) { //鼠标在返回框中，且未点击
			pre_state = state;
			state = 3;

			if (pre_state != 3) { //防止重复标亮
				clrmous(MouseX, MouseY);
				delay(5);

				setcolor(YELLOW);
				setlinestyle(0, 0, 3);
				rectangle(120, 100 + 30, 640 - 125, 100 + 30 + 28);
			}
		}

		else if (mouse_press(120, 100 + 30, 640 - 125, 100 + 30 + 28) == 1) { //鼠标在返回框中，且点击
		
			*p=0;
			delay(100);
			return 18;			
		}		
		
		
/*第二行*/		
		else if (mouse_press(120, 152 + 30, 640 - 125, 152 + 30 + 28) == 2) { //鼠标在返回框中，且未点击
			pre_state = state;
			state = 4;

			if (pre_state != 4) { //防止重复标亮
				clrmous(MouseX, MouseY);
				delay(5);

				setcolor(YELLOW);
				setlinestyle(0, 0, 3);
				rectangle(120, 152 + 30, 640 - 125, 152 + 30 + 28);
			}
		}

		else if (mouse_press(120, 152 + 30, 640 - 125, 152 + 30 + 28) == 1) { //鼠标在返回框中，且点击
		
			*p=1;
			delay(100);
			return 18;			
		}		

/*第三行*/
		else if (mouse_press(120, 204 + 30, 640 - 125, 204 + 30 + 28) == 2) { //鼠标在返回框中，且未点击
			pre_state = state;
			state = 5;

			if (pre_state != 5) { //防止重复标亮
				clrmous(MouseX, MouseY);
				delay(5);

				setcolor(YELLOW);
				setlinestyle(0, 0, 3);
				rectangle(120, 204 + 30, 640 - 125, 204 + 30 + 28);
			}
		}

		else if (mouse_press(120, 204 + 30, 640 - 125, 204 + 30 + 28) == 1) { //鼠标在返回框中，且点击
		
			*p=2;
			delay(100);
			return 18;			
		}				
					
						
		//无操作状态
		else
		{
			pre_state=state;
			state=0;
		}	
		
		
		//鼠标
		if(mouse_press(320-28,300,320+28,328)||mouse_press(5,5,20,17)||mouse_press(120, 100 + 30, 640 - 125, 100 + 30 + 28)||mouse_press(120, 152 + 30, 640 - 125, 152 + 30 + 28)||mouse_press(120, 204 + 30, 640 - 125, 204 + 30 + 28))
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
						setcolor(LIGHTGRAY);
						setlinestyle(0,0,3);
						rectangle(320-28,300,320+28,328);	
						break;
					case 2:
						setcolor(LIGHTBLUE);
						setlinestyle(0,0,3);
						rectangle(5,5,20,17);	
						break;		
				case 3:
					setcolor(LIGHTGRAY);
					setlinestyle(0, 0, 3);
					rectangle(120, 100 + 30, 640 - 125, 100 + 30 + 28);
					break;	
				
				case 4:
					setcolor(LIGHTGRAY);
					setlinestyle(0, 0, 3);
					rectangle(120, 152 + 30, 640 - 125, 152 + 30 + 28);
					break;	

				case 5:
					setcolor(LIGHTGRAY);
					setlinestyle(0, 0, 3);
					rectangle(120, 204 + 30, 640 - 125, 204 + 30 + 28);
					break;	
																
										
				}
		}		
	}
}			

void resultknnbk(){
	int i=0;
	int a[5]={100+30,152+30,204+30,256+30,308+30};
	int v[16] ={5,13,15,5,15,8,20,8,20,17,15,17,15,20,5,13};

	cleardevice();
	setbkcolor(BLACK);
	setfillstyle(1,BLUE);
	bar(10,10,640-10,480-10);
	setcolor(BROWN);
	setlinestyle(0,0,3);
	rectangle(10,10,640-10,480-10);
	rectangle(1, 1, 639, 479);
	
	//评估结果
	setcolor(BROWN);
	setlinestyle(0,0,1);
	setfillstyle(1,LIGHTGRAY);
	puthz(260,20+20,"评估结果",32,34,WHITE);
	
	//学校专业
	for(i=0;i<3;i++){
		bar(120,a[i],640-125,a[i]+28);
		rectangle(120,a[i],640-125,a[i]+28);
	}
	
	puthz(123,a[0]+3,"一、",24,26,YELLOW);
	puthz(123,a[1]+3,"二、",24,26,YELLOW);
	puthz(123,a[2]+3,"三、",24,26,YELLOW);
	
		
	//返回键
	setlinestyle(0,0,3);
	setfillstyle(1,WHITE);
	bar(320-28,300,320+28,328);
	rectangle(320-28,300,320+28,328);
	puthz(320-28+3,303,"返回",24,26,RED);
	
	//返回主页键

	setfillstyle(1,LIGHTBLUE);
	setcolor(WHITE);
	fillpoly(8,v);	
	
}
