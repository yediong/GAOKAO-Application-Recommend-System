#include"common.h"
#include"welcome.h"

int welcome(int *flag4,struct U *user,int *flag12) {
	int state = 0, pre_state = 0;
	int flag = 0;
	clrmous(MouseX, MouseY);
	delay(100);
	welcomebk();
	mouseinit();

	while (1) {
		newmouse(&MouseX, &MouseY, &press);
		if (mouse_press(60, 410, 130, 460) == 2) { //鼠标在登录框中，且未点击
			pre_state = state;
			state = 1;
			if (pre_state != 1) { //防止重复标亮
				clrmous(MouseX, MouseY);
				delay(5);

				setcolor(YELLOW);
				setlinestyle(0, 0, 3);
				rectangle(60, 410, 130, 460);
			}
		}

		else if (mouse_press(60, 410, 130, 460) == 1) { //鼠标在登录框中，且点击
			return 1;
		}



		//在个性化选择框中
		else if (mouse_press(213 - 110 - 65, 320 - 20 - 30, 426 - 110 - 65, 470 - 50 - 30) == 2) { //鼠标在个性化选择框中，且未点击
			pre_state = state;
			state = 2;

			if (pre_state != 2) { //防止重复标亮
				clrmous(MouseX, MouseY);
				delay(5);

				setcolor(YELLOW);
				setlinestyle(0, 0, 3);
				rectangle(213 - 110 - 65, 320 - 20 - 30, 426 - 110 - 65, 470 - 50 - 30);
			}
			if (flag == 0) {

				puthz(426 - 110 - 55, 320 - 20 - 30, "该功能需输入省排名、选科等信息，系统将根据这些信息推荐最合适的大学。用户可选择以学科评估等级（专业）、地域就业优势（地域）或专业热门程度（热门学科）为参考指标，分别得到三个档次的智能评估结果。综合推荐功能以大量样本为基础，通过算法提供最恰当的学校专业。", 16, 16, WHITE);
				flag = 1;
			}

		}

		else if (mouse_press(213 - 110 - 65, 320 - 20 - 30, 426 - 110 - 65, 470 - 50 - 30) == 1) { //鼠标在个性化选择框中，且点击
			if (*flag4 == 0) {
				puthz(130 + 13, 420, "请先登录！", 24, 26, YELLOW);
			} else {
				delay(100);
				if(strcmp(user->range,"0")==0)
				{
					*flag12=0;
				}
				else
				{
					*flag12=1;
				}
				
				return 5;
					
			}
		}



		else if (mouse_press(640 - 10 - 26, 480 - 10 - 26, 640 - 10, 480 - 10) == 2) { //鼠标在退出框中，且未点击
			pre_state = state;
			state = 3;

			if (pre_state != 3) { //防止重复标亮
				clrmous(MouseX, MouseY);
				delay(5);

				setcolor(YELLOW);
				setlinestyle(0, 0, 3);
				rectangle(640 - 10 - 26, 480 - 10 - 26, 640 - 10, 480 - 10);
			}
		} else if (mouse_press(640 - 10 - 26, 480 - 10 - 26, 640 - 10, 480 - 10) == 1) { //鼠标在退出框中，且点击
			delay(100);
			return 100;
		}


		else if (mouse_press(15+2, 80, 115+2, 120) == 2) {
			pre_state = state;
			state = 5;

			if (pre_state != 5) { //防止重复标亮
				clrmous(MouseX, MouseY);
				delay(5);

				setcolor(YELLOW);
				setlinestyle(0, 0, 3);
				rectangle(15+2, 80, 115+2, 120);
			}			
		}
		
		
			else if (mouse_press(15+2, 80, 115+2, 120) == 1) { //鼠标在交流区框中，且点击
				if (*flag4 == 0) {
					puthz(130 + 13, 420, "请先登录！", 24, 26, YELLOW);
				} else {
					delay(100);
					return 25;
				}	
			
			
				}



		else if (mouse_press(213 - 110 - 65, 240 - 20 - 30, 426 - 110 - 65, 310 - 20 - 30) == 2) { //鼠标在游客框中，且未点击
			pre_state = state;
			state = 4;

			if (pre_state != 4) { //防止重复标亮
				clrmous(MouseX, MouseY);
				delay(5);

				setcolor(YELLOW);
				setlinestyle(0, 0, 3);
				rectangle(213 - 110 - 65, 240 - 20 - 30, 426 - 110 - 65, 310 - 20 - 30);
			}

			if (flag == 0) {
				puthz(426 - 110 - 57, 240 - 20 - 30, "包含大学排行榜、专业分类以及大学、专业、学科大类等详细信息介绍。附带搜索引擎。", 16, 16, WHITE);
				flag = 2;
			}

		} else if (mouse_press(213 - 110 - 65, 240 - 20 - 30, 426 - 110 - 65, 310 - 20 - 30) == 1) { //鼠标在游客框中，且点击
			delay(100);
			return 7;
		}


		//无操作状态
		else {
			pre_state = state;
			state = 0;

			if (flag == 1) {
				setfillstyle(1, BLUE);
				bar(426 - 110 - 57, 320 - 20 - 30, 570, 460);
				flag = 0;
			}
			//			MouseS=0;
			if (flag == 2) {
				setfillstyle(1, BLUE);
				bar(426 - 110 - 57, 240 - 20 - 30, 570, 270);
				flag = 0;

			}

		}

		//鼠标
		if (mouse_press(213 - 110 - 65, 320 - 20 - 30, 426 - 110 - 65, 470 - 50 - 30) || mouse_press(640 - 10 - 26, 480 - 10 - 26, 640 - 10, 480 - 10) || mouse_press(213 - 110 - 65, 240 - 20 - 30, 426 - 110 - 65, 310 - 20 - 30)||mouse_press(15+2, 80, 115+2, 120)||mouse_press(60, 410, 130, 460))
			MouseS = 1;
		else
			MouseS = 0;

		//如果状态发生改变，且之前不是无操作状态，则可能需清除标亮
		if (pre_state != state && pre_state != 0) {
			clrmous(MouseX, MouseY);
			delay(5);
//				MouseS=0;

			switch (pre_state) {
				case 1:
					setcolor(BROWN);
					setlinestyle(0, 0, 3);
					rectangle(60, 410, 130, 460);
					break;
				case 2:
					setcolor(BROWN);
					setlinestyle(0, 0, 3);
					rectangle(213 - 110 - 65, 320 - 20 - 30, 426 - 110 - 65, 470 - 50 - 30);
					break;
				case 3:
					setcolor(BROWN);
					setlinestyle(0, 0, 3);
					rectangle(640 - 10 - 26, 480 - 10 - 26, 640 - 10, 480 - 10);
					break;
				case 4:
					setcolor(BROWN);
					setlinestyle(0, 0, 3);
					rectangle(213 - 110 - 65, 240 - 20 - 30, 426 - 110 - 65, 310 - 30 - 20);
					break;
				case 5:
					setcolor(BROWN);
					setlinestyle(0, 0, 3);
					rectangle(15+2, 80, 115+2, 120);
					break;	
				case 6:
					setcolor(BROWN);
					setlinestyle(0, 0, 3);
					rectangle(60, 410, 130, 460);
					break;									
			}
		}
	}
}

void welcomebk() {
	cleardevice();
	setbkcolor(BLACK);
	setfillstyle(1, BLUE);
	bar(10, 10, 640 - 10, 480 - 10);
	setcolor(BROWN);
	setlinestyle(0, 0, 3);
	rectangle(10, 10, 640 - 10, 480 - 10);
	
	//外边框
	setcolor(BROWN);
	setlinestyle(0, 0, 3);
	rectangle(1, 1, 639, 479);


	//目标院校个性化评估推荐系统
	setfillstyle(1, WHITE);
	bar(213 - 110 - 65, 320 - 20 - 30, 426 - 110 - 65, 470 - 50 - 30);
	setcolor(BROWN);
	rectangle(213 - 110 - 65, 320 - 20 - 30, 426 - 110 - 65, 470 - 50 - 30);
	puthz(279 - 20 - 110 - 65, 320 - 30, "目标院校个", 24, 26, RED);
	puthz(279 - 20 - 110 - 65, 350 - 30, "性化评估推", 24, 26, RED);
	puthz(279 - 20 - 110 - 65, 380 - 30, "荐系统", 24, 26, RED);

	//登录
	setfillstyle(1, LIGHTGRAY);
	bar(60, 410, 130, 460);
	puthz(69, 422, "登录", 24, 26, RED);
	setlinestyle(0, 0, 3);
	setcolor(BROWN);
	rectangle(60, 410, 130, 460);

	//游客登录模式
	setfillstyle(1, LIGHTGRAY);
	bar(213 - 110 - 65, 240 - 20 - 30, 426 - 110 - 65, 310 - 20 - 30);
	puthz(241 - 110 - 65, 240 + 25 - 20 - 30, "游客登录模式", 24, 26, RED);
	setlinestyle(0, 0, 3);
	setcolor(BROWN);
	rectangle(213 - 110 - 65, 240 - 20 - 30, 426 - 110 - 65, 310 - 20 - 30);


	//标题:万叶高考志愿填报辅助支持系统
	setfillstyle(1, YELLOW);
	bar(320 - 190, 230 - 80 - 20 - 60, 320 + 190, 230 - 20 - 60);
	puthz(320 - 182, 230 - 80 + 27 - 20 - 60, "万叶高考志愿填报辅助支持系统", 24, 26, RED);
	setcolor(BROWN);
	setlinestyle(0, 0, 3);
	rectangle(320 - 190, 230 - 80 - 20 - 60, 320 + 190, 230 - 20 - 60);
	rectangle(320 - 190 - 7, 230 - 80 + 7 - 20 - 60, 320 - 190 + 7, 230 - 80 - 7 - 20 - 60);
	rectangle(320 + 190 - 7, 230 - 80 + 7 - 20 - 60, 320 + 190 + 7, 230 - 80 - 7 - 20 - 60);
	rectangle(320 - 190 - 7, 230 + 7 - 20 - 60, 320 - 190 + 7, 230 - 7 - 20 - 60);
	rectangle(320 + 190 - 7, 230 + 7 - 20 - 60, 320 + 190 + 7, 230 - 7 - 20 - 60);

	//退出
	setfillstyle(1, LIGHTGRAY);
	bar(640 - 10 - 26, 480 - 10 - 26, 640 - 10, 480 - 10);
//	puthz(632-54,480-10+1-26,"退出",24,26,BROWN);
	setcolor(BROWN);
	setlinestyle(0, 0, 3);
	rectangle(640 - 10 - 26, 480 - 10 - 26, 640 - 10, 480 - 10);

	line(640 - 10 - 26, 480 - 10 - 26, 640 - 10, 480 - 10);
	line(640 - 10 - 26, 480 - 10, 640 - 10, 480 - 10 - 26);

	setfillstyle(1, WHITE);
	bar(15+2, 80, 115+2, 120);
	rectangle(15+2, 80, 115+2, 120);
	puthz(65 - 36+2, 88, "交流室", 24, 26, BLACK);
}
