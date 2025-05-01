#include"common.h"
#include"option.h"

int option(int *choice,int *flag12) {
	
	int state = 0, pre_state = 0;
	int v[16] = {5, 13, 15, 5, 15, 8, 20, 8, 20, 17, 15, 17, 15, 20, 5, 13};
	*choice = 0;
	delay(5);
	clrmous(MouseX, MouseY);
	optionbk();
	clrmous(MouseX, MouseY);	
	mouseinit();
	
	
	while (1) {
		newmouse(&MouseX, &MouseY, &press);
		if (mouse_press(164, 240, 216, 280) == 2) {
			//鼠标在专业框中，且未点击
			pre_state = state;
			state = 1;
			if (pre_state != 1) {
				//防止重复标亮
				clrmous(MouseX, MouseY);
				delay(5);

				setcolor(RED);
				setlinestyle(0, 0, 3);
				rectangle(164, 240, 216, 280);
			}
		}


		else if (mouse_press(164, 240, 216, 280) == 1) { //鼠标在专业框中，且点击
			*choice = 1;
			return 4;
		}


		//地域
		else if (mouse_press(268, 240, 320, 280) == 2) { //鼠标在地域框中，且未点击
			pre_state = state;
			state = 2;

			if (pre_state != 2) { //防止重复标亮
				clrmous(MouseX, MouseY);
				delay(5);

				setcolor(RED);
				setlinestyle(0, 0, 3);
				rectangle(268, 240, 320, 280);
			}
			
			
		} else if (mouse_press(268, 240, 320, 280) == 1) { //鼠标在地域框中，且点击
			delay(100);
			*choice = 2;
			return 4;
		}


		//热门学科
		else if (mouse_press(372, 240, 476, 280) == 2) { //鼠标在地域框中，且未点击
			pre_state = state;
			state = 3;

			if (pre_state != 3) { //防止重复标亮
				clrmous(MouseX, MouseY);
				delay(5);

				setcolor(RED);
				setlinestyle(0, 0, 3);
				rectangle(372, 240, 476, 280);
			}
		} else if (mouse_press(372, 240, 476, 280) == 1) { //鼠标在地域框中，且点击
			delay(100);
			*choice = 3;
			return 4;
		}


		//综合推荐
		else if (mouse_press(268, 310, 372, 350) == 2) { //鼠标在综合推荐框中，且未点击
			pre_state = state;
			state = 5;

			if (pre_state != 5) { //防止重复标亮
				clrmous(MouseX, MouseY);
				delay(5);

				setcolor(RED);
				setlinestyle(0, 0, 3);
				rectangle(268, 310, 372, 350);
			}
			
			
		} else if (mouse_press(268, 310, 372, 350) == 1) { //鼠标在综合推荐框中，且点击
			delay(100);
			return 6;
		}
		
		
	//志愿填报 修改时间4 13，万嵩玥 
		else if(mouse_press(390,310,570,440) == 2)
		{
			pre_state = state;
			state = 6;

			if (pre_state != 6) { //防止重复标亮
				clrmous(MouseX, MouseY);
				delay(5);

				setcolor(YELLOW);
				setlinestyle(0, 0, 3);
				rectangle(390,310,570,440);
			}
		}else if (mouse_press(390,310,570,440) == 1) { //鼠标在综合推荐框中，且点击
			delay(100);
			return 15;
		}


		//返回框
		else if (mouse_press(5, 5, 20, 17) == 2) { //鼠标在返回框中，且未点击
			pre_state = state;
			state = 4;

			if (pre_state != 4) { //防止重复标亮
				clrmous(MouseX, MouseY);
				delay(5);

				setcolor(RED);
				setlinestyle(0, 0, 3);
				fillpoly(8, v);
			}
		}


		else if (mouse_press(5, 5, 20, 17) == 1) { //鼠标在返回框中，且点击
			delay(100);
			return 0;
		}
		
		
		
		//无操作状态
		else {
			pre_state = state;
			state = 0;
		}
		
		
		//专业测评按键
		if(mouse_press(25,310,250,410+20)==1)
		{
			delay(100);
			return 19;
		}





		//重填一份按键
		if(mouse_press(500,20,564,38)==1)
		{
			delay(100);
			*flag12=0;
			return 5;
		}





		//鼠标
		if (mouse_press(390,310,570,440)||mouse_press(500,20,564,38)||mouse_press(164, 240, 216, 280) ||mouse_press(25,310,250,410+20)|| mouse_press(268, 240, 320, 280) || mouse_press(372, 240, 476, 280) || mouse_press(5, 5, 20, 17) || mouse_press(268, 310, 372, 350)/*||mouse_press(280,300,500,330)||mouse_press(280,350,500,380)*/)
			MouseS = 1;
		else
			MouseS = 0;


		//如果状态发生改变，且之前不是无操作状态，则可能需清除标亮
		if (pre_state != state && pre_state != 0) {
			clrmous(MouseX, MouseY);
			delay(5);

			switch (pre_state) {
				case 1:
					setcolor(GREEN);
					setlinestyle(0, 0, 3);
					rectangle(164, 240, 216, 280);
					break;
				case 2:
					setcolor(GREEN);
					setlinestyle(0, 0, 3);
					rectangle(268, 240, 320, 280);
					break;
				case 3:
					setcolor(GREEN);
					setlinestyle(0, 0, 3);
					rectangle(372, 240, 476, 280);
					break;
				case 4:
					setcolor(LIGHTBLUE);
					setlinestyle(0, 0, 3);
					fillpoly(8,v);
					break;
				case 5:
					setcolor(GREEN);
					setlinestyle(0, 0, 3);
					rectangle(268, 310, 372, 350);
					break;
				case 6:
					setcolor(RED);
					setlinestyle(0, 0, 3);
					rectangle(390,310,570,440);
					break;					
			}
		}
	}
}


void optionbk() {
	/*	int gd=VGA,gm=VGAHI;
		initgraph(&gd,&gm,"C:\\borland c\\bgi");*/
	int v[16] = {5, 13, 15, 5, 15, 8, 20, 8, 20, 17, 15, 17, 15, 20, 5, 13};
	cleardevice();
	setbkcolor(BLACK);
	setfillstyle(1, BLUE);
	bar(10, 10, 640 - 10, 480 - 10);
	setcolor(BROWN);
	setlinestyle(0, 0, 3);
	rectangle(10, 10, 640 - 10, 480 - 10);
	rectangle(1, 1, 639, 479);
	
	//标题
	setcolor(BROWN);
	setlinestyle(0, 0, 3);
	setfillstyle(1, LIGHTGRAY);
	rectangle(180, 40 + 50, 640 - 180, 40 + 50 + 40);
	bar(180, 40 + 50, 640 - 180, 40 + 50 + 40);
	setcolor(BROWN);
	setlinestyle(0, 0, 3);
	rectangle(180 - 7, 40 + 50 - 7, 180 + 7, 40 + 50 + 7);
	rectangle(180 - 7, 80 - 7 + 50, 180 + 7, 80 + 7 + 50);
	rectangle(460 - 7, 40 - 7 + 50, 460 + 7, 40 + 7 + 50);
	rectangle(460 - 7, 80 - 7 + 50, 460 + 7, 80 + 7 + 50);
	puthz(255, 7 + 40 + 50, "个性化评估", 24, 26, RED);

	//问句
	puthz(151, 130 + 50, "您想以哪项为基准查看结果？", 24, 26, WHITE);

	//选项卡
	setfillstyle(1, WHITE);
	bar(164, 240, 216, 280);
	bar(268, 240, 320, 280);
	bar(372, 240, 476, 280);
	setcolor(GREEN);
	setlinestyle(0, 0, 3);
	rectangle(164, 240, 216, 280);
	rectangle(268, 240, 320, 280);
	rectangle(372, 240, 476, 280);
	puthz(165, 247, "专业", 24, 26, RED);
	puthz(269, 247, "地域", 24, 26, RED);
	puthz(373, 247, "热门学科", 24, 26, RED);

	//画返回键

	setfillstyle(1, LIGHTBLUE);
	setcolor(WHITE);
	fillpoly(8, v);
	
	
	//专业测评
	setfillstyle(1,WHITE);
	bar(25,310,250,410+20);
	setlinestyle(0,0,1);
	setcolor(BROWN);
	rectangle(25,310,250,410+20);
	puthz(100-24*2,320,"专业测评",24,27,BLACK);
	puthz(26,380,"这位同学，来测测你适合什么专",16,16,BLACK);
	puthz(26,398,"业吧！",16,16,BLACK);

	//画综合推荐
	setfillstyle(1, WHITE);
	bar(268, 310, 372, 350);
	setcolor(GREEN);
	setlinestyle(0, 0, 3);
	rectangle(268, 310, 372, 350);
	puthz(269, 317, "综合推荐", 24, 26, RED);


	setfillstyle(1,CYAN);
	bar(390,310,570,440);
	puthz(395,340,"志愿填报及模拟录取概率",24,24,BLACK);
	setcolor(RED);
	setlinestyle(0, 0, 3);
	rectangle(390,310,570,440);
		
	
	setfillstyle(1,YELLOW);
	bar(500,20,564,38);
	setlinestyle(0,0,1);
	setcolor(BROWN);
	rectangle(500,20,564,38);
	puthz(500,21,"重填一份",16,16,BLACK);
}
