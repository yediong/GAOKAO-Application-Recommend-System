#include"common.h"
#include"qresult.h"



int qresult(int *flag6, int *flag7, int *flag8, int *flag9, int *flag10, int *flag11) {
	int p6 = 0;
	int AI = 0; //人工智能
	int CS = 0;	//计算机科学
	int AIA = 0;	//自动化
	int ELEC = 0; //电气
	int MATH = 0; //数学
	int PHISICS = 0; //物理
	int ENERGY = 0; //能源
	int ROBOT = 0;	//机械
	int DOC = 0;

	int big1=0;//AI/CS
	int big2=0;//MATH/PHISICS
	int big3=0;	//AIA/ELEC
	
	clrmous(MouseX, MouseY);
	delay(10);
	mouseinit();

	while (1) {
		newmouse(&MouseX, &MouseY, &press);
		
		//返回键
		if (mouse_press(320 - 27, 410+20, 320 + 27, 438+20) == 1) {
			delay(5);
			p6=0;
					*flag6=0;
					*flag7=0;
					*flag8=0;
					*flag9=0;
					*flag10=0;
					*flag11=0;			
			return 2;
		}


		if (p6 == 0) {

			p6 = 1;

			if (*flag7 == 1) {
				puthz(100 + 16 * 9, 70, "救死扶伤的医科；", 16, 16, WHITE);
				DOC += 2;
			}


			else if (*flag7 == 2) {

				puthz(100 + 16 * 9, 70, "科技强国的理工科；", 16, 16, WHITE);
				AI += 1;
				CS += 1;
				AIA += 1;
				ELEC += 1;
				ENERGY += 1;
				ROBOT += 1;
				MATH += 1;
				PHISICS += 1;
			}



			if (*flag6 == 1) {
				puthz(100, 70 + 18, "您更擅长解决实际问题；", 16, 16, WHITE);
				AI += 1;
				CS += 1;
				AIA += 1;
				ELEC += 1;
				ENERGY += 1;
				ROBOT += 1;
			}

			else if (*flag6 == 2) {
				puthz(100, 70 + 18, "您更擅长研究理论；", 16, 16, WHITE);
				MATH += 1;
				PHISICS += 1;
			}



			if (*flag8 == 1) {
				puthz(100, 70 + 18 * 2, "您更倾向于选择软件；", 16, 16, WHITE);
				CS += 1;
				AI += 1;

			} else if (*flag8 == 2) {
				puthz(100, 70 + 18 * 2, "您更倾向于选择硬件；", 16, 16, WHITE);
				AIA += 1;
				ELEC += 1;
				ROBOT += 1;
			}



			if (*flag9 == 1) {
				puthz(100, 70 + 18 * 3, "您认为您的抽象思维能力最强；", 16, 16, WHITE);
				ELEC += 1;

			} else if (*flag9 == 2) {
				puthz(100, 70 + 18 * 3, "您认为您的空间想象能力最强；", 16, 16, WHITE);
				ROBOT += 1;
			} else if (*flag9 == 3) {
				puthz(100, 70 + 18 * 3, "您认为您的逻辑推导能力最强；", 16, 16, WHITE);
				AI += 1;
				CS += 1;
				AIA += 1;
			}



			if (*flag10 == 1) {
				puthz(100, 70 + 18 * 4, "在高中时，您最喜欢或擅长的科目是数学；", 16, 16, WHITE);
				MATH += 2;
				AI += 1;
			} else if (*flag10 == 2) {
				puthz(100, 70 + 18 * 4, "在高中时，您最喜欢或擅长的科目是物理；", 16, 16, WHITE);
				ELEC += 1;
				PHISICS += 2;
				DOC += 2;
			} else if (*flag10 == 3) {
				puthz(100, 70 + 18 * 4, "在高中时，您最喜欢或擅长的科目是化学；", 16, 16, WHITE);
				ENERGY += 1;
				ELEC += 1;
				DOC += 2;
			} else if (*flag10 == 4) {
				puthz(100, 70 + 18 * 4, "在高中时，您最喜欢或擅长的科目是生物；", 16, 16, WHITE);
				ENERGY += 1;
				DOC += 2;
			}
		


		if (*flag11 == 1) {
			puthz(100, 70 + 18 * 5, "您更偏向于创新型人才；", 16, 16, WHITE);
			ROBOT += 1;
			ENERGY += 1;
		} else if (*flag11 == 2) {
			puthz(100, 70 + 18 * 5, "您更偏向于保守型人才；", 16, 16, WHITE);
			AIA += 1;
			ELEC += 1;
			DOC+=1;
		}







/*排序说明：按照了school.txt里设定的专业好坏降序排列，因此针对于学科积分相同的情况可以优先输出综合评估较优者*/

		setfillstyle(1, BLUE);

		if ((MATH >= AI) && (MATH >= CS) && (MATH >= AIA) && (MATH >= ELEC) && (MATH >= DOC) && (MATH >= PHISICS) && (MATH >= ENERGY) && (MATH >= ROBOT)) {
			bar(100, 70 + 18 * 6, 100 + 224 - 16, 70 + 18 * 7);
			puthz(100, 70 + 18 * 6, "因此，推荐专业为数学。", 16, 16, WHITE);
		}

		if ((PHISICS >= AI) && (PHISICS >= CS) && (PHISICS >= AIA) && (PHISICS >= ELEC) && (PHISICS >= DOC) && (PHISICS >= MATH) && (PHISICS >= ENERGY) && (PHISICS >= ROBOT)) {
			bar(100, 70 + 18 * 6, 100 + 224 - 16, 70 + 18 * 7);
			puthz(100, 70 + 18 * 6, "因此，推荐专业为物理。", 16, 16, WHITE);
		}

		if ((ROBOT >= AI) && (ROBOT >= CS) && (ROBOT >= AIA) && (ROBOT >= ELEC) && (ROBOT >= DOC) && (ROBOT >= MATH) && (ROBOT >= PHISICS) && (ROBOT >= ENERGY)) {
			bar(100, 70 + 18 * 6, 100 + 224 - 16, 70 + 18 * 7);
			puthz(100, 70 + 18 * 6, "因此，推荐专业为机械。", 16, 16, WHITE);
		}
		
		if ((ENERGY >= AI) && (ENERGY >= CS) && (ENERGY >= AIA) && (ENERGY >= ELEC) && (ENERGY >= DOC) && (ENERGY >= MATH) && (ENERGY >= PHISICS) && (ENERGY >= ROBOT)) {
			bar(100, 70 + 18 * 6, 100 + 224 - 16, 70 + 18 * 7);
			puthz(100, 70 + 18 * 6, "因此，推荐专业为能源动力。", 16, 16, WHITE);
		}	
			
		if ((ELEC >= AI) && (ELEC >= CS) && (ELEC >= AIA) && (ELEC >= DOC) && (ELEC >= MATH) && (ELEC >= PHISICS) && (ELEC >= ENERGY) && (ELEC >= ROBOT)) {
			bar(100, 70 + 18 * 6, 100 + 224 - 16, 70 + 18 * 7);
			puthz(100, 70 + 18 * 6, "因此，推荐专业为电气工程。", 16, 16, WHITE);
		}		
		
		if ((DOC >= AI) && (DOC >= CS) && (DOC >= AIA) && (DOC >= ELEC) && (DOC >= MATH) && (DOC >= PHISICS) && (DOC >= ENERGY) && (DOC >= ROBOT)) {
			bar(100, 70 + 18 * 6, 100 + 224 - 16, 70 + 18 * 7);
			puthz(100, 70 + 18 * 6, "因此，推荐专业为医学。", 16, 16, WHITE);
		}		
		
		if ((AIA >= AI) && (AIA >= CS) && (AIA >= ELEC) && (AIA >= DOC) && (AIA >= MATH) && (AIA >= PHISICS) && (AIA >= ENERGY) && (AIA >= ROBOT)) {
			bar(100, 70 + 18 * 6, 100 + 224 - 16, 70 + 18 * 7);
			puthz(100, 70 + 18 * 6, "因此，推荐专业为自动化。", 16, 16, WHITE);
		}		
		
		if ((AI >= CS) && (AI >= AIA) && (AI >= ELEC) && (AI >= DOC) && (AI >= MATH) && (AI >= PHISICS) && (AI >= ENERGY) && (AI >= ROBOT)) {
			bar(100, 70 + 18 * 6, 100 + 224 - 16, 70 + 18 * 7);
			puthz(100, 70 + 18 * 6, "因此，推荐专业为人工智能。", 16, 16, WHITE);
		}	
			
		if ((CS >= AI) && (CS >= AIA) && (CS >= ELEC) && (CS >= DOC) && (CS >= MATH) && (CS >= PHISICS) && (CS >= ENERGY) && (CS >= ROBOT)) {
			bar(100, 70 + 18 * 6, 100 + 224 - 16, 70 + 18 * 7);
			puthz(100, 70 + 18 * 6, "因此，推荐专业为计算机科学。", 16, 16, WHITE);
		}

		
		
		
		/*输出六边形*/	
		big1=((AI>=CS)?AI:CS);
		big2=((MATH>=PHISICS)?MATH:PHISICS);
		big3=((AIA>=ELEC)?AIA:ELEC);
		
		clrmous(MouseX, MouseY);
		setlinestyle(0,0,3);
		setcolor(LIGHTRED);
		line(320-10*DOC,305-17*DOC,320-20*big1,305);
		line(320-20*big1,305,320-10*big2,305+17*big2);
		line(320-10*big2,305+17*big2,320+10*big3,305+17*big3);
		line(320+10*big3,305+17*big3,320+20*ENERGY,305);
		line(320+20*ENERGY,305,320+10*ROBOT,305-17*ROBOT);
		line(320+10*ROBOT,305-17*ROBOT,320-10*DOC,305-17*DOC);
		


		}

	}

}



void qresultbk() {
	int i=0;
	cleardevice();
	setbkcolor(BLACK);
	setfillstyle(1, BLUE);
	bar(10, 9, 640 - 10, 480 - 10);
	setcolor(BROWN);
	setlinestyle(0, 0, 3);
	rectangle(1, 1, 639, 479);
	rectangle(10, 10, 640 - 10, 480 - 10);
	setfillstyle(1, LIGHTCYAN);
	bar(320 - 34 * 3+20,10,320 - 34 * 3+20+4+34*4,10+46);	
	rectangle(320 - 34 * 3+20,10,320 - 34 * 3+20+4+34*4,10+46);

	puthz(320 - 34 * 3+20+3, 12+7, "推荐结果", 32, 34, BLACK);

	setcolor(BROWN);
	setfillstyle(1,WHITE);
	bar(320 - 27, 410+20, 320 + 27, 438+20);
	rectangle(320 - 27, 410+20, 320 + 27, 438+20);

	puthz(320 - 25, 410+1+20, "返回", 24, 26, RED);

	puthz(100, 70, "根据测评，您更喜欢", 16, 16, WHITE);
//	puthz(150,130+26,"您")

	setlinestyle(0,0,3);
	setcolor(YELLOW);
	for(i=1;i<6;i++)
	{
		line(320-10*i,305-17*i,320-20*i,305);
		line(320-20*i,305,320-10*i,305+17*i);
		line(320-10*i,305+17*i,320+10*i,305+17*i);
		line(320+10*i,305+17*i,320+20*i,305);
		line(320+20*i,305,320+10*i,305-17*i);
		line(320+10*i,305-17*i,320-10*i,305-17*i);
	}
	
	i--;
	line(320-10*i,305-17*i,320+10*i,305+17*i);
	line(320-20*i,305,320+20*i,305);
	line(320-10*i,305+17*i,320+10*i,305-17*i);
	
	puthz(270-32-2,220-16,"医学",16,16,YELLOW);
	puthz(220-16*8-3,305-8,"人工智能或计算机",16,16,YELLOW);
	puthz(270-16*5-3,390+8,"数学或物理",16,16,YELLOW);
	puthz(370+3,390+8,"自动化或电气",16,16,YELLOW);
	puthz(420+2,305-8,"能源",16,16,YELLOW);
	puthz(370+2,220-16,"机械",16,16,YELLOW);

	
}
