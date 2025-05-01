#include"common.h"
#include"main.h"

void main() {
	int page = 0;
	int choice = 0;
	char temp[20];
    int *pschool;	
	int* pchoice;//school,choice分别是学校和查看选项卡的编号，由其两者共同决定pb（信息输出栏）的内容。
	int* sorts;
	int* subjects;//sorts,subjects分别是选项卡以及所选科目的编号，两者共同决定pd(信息输出栏)的内容。
	int university[5]={0};//为所选学校的代码； *******************************
	int count=0;//记录点击次数；
	int flag=0;//记录删除的大学的序号并给予删除，实现志愿的可视化编辑。
	int flag1[11]={0};//防止添加多所大学被选上
	int flag2=0;//控制屏幕刷新次数，防止多次打印屏幕使屏幕闪烁
	int flag3=0;//控制返回按键是否出现
	int flag4=0;//标记个性化推荐前是否登录过
	int flag5=0;//标记是否用knn
	int flag6=0;//标记问题1
	int flag7=0;//标记问题2
	int flag8=0;//标记问题3
	int flag9=0;//标记问题4
	int flag10=0;//标记问题5
	int flag11=0;
	int flag12=0;//控制是否进入input函数
	int subjectchoice[20][20]={0};/**************************************/
	int college=0;
	int sign=0;
	int sign1[20][20]={0};
	int sign2=0;
	int click[20]={0};
	int schs[3];
	int majs[3];
	int point=0;
	int nb=0;
	int cb=0;
	int cb2=0;
	int probability[4][4]={0};
	char s[100]={0};
	int choose[2]={0};
	
	struct C *chater=(struct C *)malloc(sizeof(struct C));
	struct U *user = (struct U *)malloc(sizeof(struct U));
	struct S school[10];
	PERSON person[2][10][12][10] = {0};
	int gd=VGA,gm=VGAHI;
	initgraph(&gd, &gm, "C:\\borland c\\bgi");
	memset(user, '0', sizeof(struct U));
	memset(person, 0, sizeof(PERSON));
	memset(chater,'0',sizeof(struct C));
	input_school(school);
	input_person(person);
//	mouseinit();

	while (1) {
		switch (page) {
			case 0:
				page = welcome(&flag4,user,&flag12);
				break;
				
			case 1:
				page = login(user,&flag4);
				strcpy(chater->name,user->name);
				break;
				
			case 2:
			
				flag3=0;
				page = option(&choice,&flag12);	
				break;
				
			case 3:
				page = signup();
				break;
				
			case 4:
				clrmous(MouseX, MouseY);
				if(flag3==0)
				{
				strcpy(s,"智能分析中。。。");	
				wait1(s);
				}			
				resultbk();
				delay(100);
				function(user, school, choice, schs, majs, &nb,&cb,&cb2);
				page = result(&point,&flag3,&nb,&cb,&cb2);
				break;
				
			case 5:
				if(flag12==0)
				{
				clrmous(MouseX, MouseY);
				page = input(user,&flag12);
				}
				else if(flag12==1)
				{
					page=2;
				}
				break;
				
			case 6:
				clrmous(MouseX, MouseY);
				if(flag3==0)
				{
				strcpy(s,"智能分析中。。。");	
				wait1(s);
				}				
				resultknnbk();
				delay(100);
				funcknn(user, person,schs,majs);
				page = resultknn(&point,&flag3);
				break;
				
			case 18:
				clrmous(MouseX,MouseY);
				connectbk();
				page=connect(schs[point],majs[point],pschool,sorts,subjects,&flag3);
				break;	
				
			case 19:
				clrmous(MouseX,MouseY);
				if(user->choose>=1&&user->choose<=3)
				{
					questionbk();
					page=question(&flag6,&flag7,&flag8,&flag9,&flag10,&flag11);
					if(page==20)
					{
					strcpy(s,"生成图像中。。。");	
					wait1(s);	
					}				
				}	
				else if(user->choose>=4&&user->choose<=6)
				{
					delay(5);
					clrmous(MouseX,MouseY);
					setbkcolor(BLACK);
					setfillstyle(1,BLUE);
					bar(10,10,640-10,480-10);
					setcolor(BROWN);
					setlinestyle(0,0,3);
					rectangle(10,10,640-10,480-10);
					puthz(320-50*2,200,"暂无题库！",48,50,WHITE);
					delay(1500);
					page=2;
				}

				break;

			case 20:
				clrmous(MouseX,MouseY);
				qresultbk();
				page=qresult(&flag6,&flag7,&flag8,&flag9,&flag10,&flag11);
				break;

			case 25:
				clrmous(MouseX,MouseY);
				chatbk();
				page=chat(chater);
				break;
									
/***************************************************************/	
							
	  	  	case 7:	
	  	    page=p2(&flag3);//初始化页面
			break;
			
			case 8:
			page=p21(pschool);//学校排行页面 
			break;
			
			case 9:
			page=pa(pchoice,&flag3);//信息选项卡页面 
			break;
			
			case 10:
			page=pb(*pschool,*pchoice);//信息输出页面 
			break;
				
			case 11:
			page=p22(sorts);//学科大类信息
			break;
			
			case 12:
			page=pc(sorts,subjects);  //学科基本信息
			break;
			
			case 13:
			page=pd(*sorts,*subjects,&flag3);//大类,学科详细介绍
			break;	
			
			case 14:
			delay(100);
			clrmous(MouseX, MouseY);
			page=p23();//学校以及志愿搜索界面 
			break;
			
			case 15:
			delay(100);
			clrmous(MouseX,MouseY);
			page=puniversity(university,&flag,&count,&flag2,flag1,&college);//填报学校展示界面 
			break;
			
			case 16:
			delay(100);
			clrmous(MouseX,MouseY);
			page=pschoolchoose(university,&count,&flag2,flag1);//填报志愿选择界面 
			break;
			
			case 17:
			delay(100);
			clrmous(MouseX,MouseY);
//			probable(probability,subjectchoice,university,person, user);
 //			outtextxy()
			page=psubject(subjectchoice,&college,click,&sign,sign1,&sign2,&flag2,probability,university,user,person);//填报专业展示界面 
			break;
			
			case 21:
			delay(100);
			clrmous(MouseX,MouseY);
			page=psubjectchoose(subjectchoice,&college,click,sign1,&sign2);//志愿填报选择界面 
			break;
			
			case 22:
			delay(100);
			clrmous(MouseX,MouseY);
			page=compare( choose);
			break;
			
			case 23:
			delay(100);
			strcpy(s,"正在进行对比");	
				waitbk(s);
				wait();
			clrmous(MouseX,MouseY);
			page=compasult(choose);
			break;
			
			case 24:
			delay(100);
			clrmous(MouseX,MouseY);
			page=introduce();
			break;
			                     				
			case 100:
				free(user);
				delay(1000);
				exit(1);
				break;
			default:
				free(user);
				delay(1000);
				exit(1);
				break;
		}
	}
//	getchar();
//    closegraph();
//	return 0;
}
