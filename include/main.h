#ifndef _MAIN_H_
#define _MAIN_H_
#include"welcome.h"
#include"loginnew.h"
#include"option.h"
#include"signup.h"
#include"result.h"
#include"input.h"
#include"school.h"
#include"function.h"
#include"display.h"
#include"person.h"
#include"funcknn.h"
#include"reknn.h"
#include "page2.h"
#include"page21.h"
#include"pagea.h"
#include"pageb.h"
#include"pagec.h"
#include"paged.h"
#include"page22.h"
#include"page23.h"
#include"wait.h"
#include"question.h"
#include"qresult.h"
#include"pageu.h"
#include"pageuc.h"
#include"pages.h"
#include"pagesc.h"
#include "inputhz.h"
#include"chat.h"
#include"compa.h"
#include"cpsult.h"
#include"intro.h"

void welcomebk();//背景函数
int welcome(int *flag4,struct U *user,int *flag12);//程序初始界面，选择游客模式或个性化推荐模式或登录模式
void wait();//分析中等待过渡函数
void waitbk(char*s);//背景函数
void wait1(char*s);
int input(struct U *user,int *flag12);//用于输入用户高考年份、高考省排名、高中选科以及高考省份的函数，为后一步的个性化推荐提供数据基础，并将用户输入的数据存储在user文件中
void inputyear(struct U *user, int x1, int y1);//用于读取用户输入的高考年份，并存入user结构体
void inputprov(struct U *user, int x1, int y1);//用于读取用户输入的高考省份，并存入user结构体
void inputrange(struct U *user, int x1, int y1);//用于读取用户输入的高考省排名，并存入user结构体
int check_register2(struct U *user/*, char *cp*/);//用于检查各项数据是否已经全部输入，并检查用户输入的各项数据是否符合规定的范围
void intofile2(struct U *user);//用于将用户输入的user结构体信息写入文件存储起来
void bright(int x1,int y1,int x2,int y2,int bkcolor);//用于点亮/恢复输入框
void page3light(int x1, int y1, char *s);//按键亮框
void page3recover(int x1, int y1, char *s);//按键恢复
void buttonlight(int x1,int y1);//选科组合按键亮框
void buttonrecover(int x1,int y1);//选科组合按键恢复
void inputbk();//背景函数
int hz_input(int x1,int y1,int x2,int y2,char *s,int len,int color);
int input_method(int x,int y,char *str,int value,char *py) ;
char *itostr(int a,char *s);
void pyFrm(int x1,int y1,int x2,int y2);
int xouttextxy(int x,int y,char *s,int color);
void hz_int(int x1,int y1,int x2,int y2,char *s,int color);
int introduce(void);
int login(struct U *user,int *flag4);//登录功能函数
int check_log(struct U *user);//检查输入项是否符合规定
void loginbk(void);//背景函数
void loginrecover(int x1,int y1,char*s,int length);//按键恢复
void loginlight(int x1,int y1,char*s,int length);//输入用户名和密码按键亮框
void logpassword(struct U *user,int x1,int y1);//输入密码并保存
void logname(struct U *user,int x1,int y1);//输入用户名并保存
int mouse_press(int x1, int y1, int x2, int y2);//如果在框中点击，则返回1；在框中未点击，则返回2；不在框中则返回0
void mouse(int,int);//设计鼠标
void mouseinit(void);//初始化
void mou_pos(int*,int*,int*);//更改鼠标位置
void mread(int *,int *,int*);//改坐标不画
void save_bk_mou(int x,int y);//存鼠标背景
void clrmous(int x,int y);//清除鼠标
void drawmous(int x,int y);//画鼠标
void newmouse(int *nx,int *ny,int *nbuttons);   //更新鼠标

extern int MouseX;
extern int MouseY;
extern int MouseS;
extern int IMflag;
extern int press;
extern union REGS regs;
int option(int *choice,int *flag12);//个性化推荐初始页面，用于选择各选项卡（按专业等级/地域/专业前景推荐、综合推荐、适合专业问卷测试、模拟志愿填报及查看概率）
void optionbk(void);//背景函数
int p2(int*flag3);
void p2screen(void);
int p21(int*school);
void p21screen(void);
int p22(int* sorts);
void p22screen(void);
void searchbk(void);
 int p23(void);
 void searchlight(int x1, int y1, char*s, int length);
 void searchrecover(int x1, int y1, char*s, int length);
 void searchinput( char *string,int x1,int y1);
 int searchout(int choice ,char*string,int*school,int*subject,int*flag);
 int searchresults1(int *school,int*flag);
 int searchresults2(int*subject,int*flag);
void pascreen(void);
int pa(int*choice,int *flag3);
void pbscreen(void);
int pb(int school,int choice);
void pcscreen(void);
int pc(int*sorts,int*subjects);
void pdscreen(void);
int pd(int sorts,int subjects,int*flag3);
int psubject(int(*subjectchoice)[20],int *college,int* click,int* sign, int(*sign1)[20], int* sign2,int*flag2,int probability[4][4],int* university,struct U *user,PERSON person[2][10][12][10]);
void refreshsubject(int(*sign1)[20],int(*subjectchoice)[20],int*sign,int*college);
void cancelsubject(int*sign,int(*subjectchoice)[20],int*click,int*college);
void psubjectscreen(void);
char* int_to_string(int num);
int psubjectchoose(int(*subjectchoice)[20],int*college,int* click,int(*sign1)[20],int*sign2);
void pscscreen(void);
int puniversity(int* university,int *flag,int* count,int* flag2,int*flag1,int*college);
void pschoolscreen(void);
void cancel(int*flag,int*university,int*count);
void refresh(int*flag1,int*university,int*flag);
int pschoolchoose(int* university,int* count,int* flag2,int* flag1);
void pschoolchoosescreen(void);
void input_person(PERSON person[2][10][12][10]);//将文件中的2400个样本信息读入person结构体
int mininum(int *a);
void probable(int probability[4][4],int subjectchoice[20][20],int university[5],PERSON person[2][10][12][10],struct U *user/*,int *sch,int *maj*/);
int qresult(int *flag6,int *flag7,int *flag8,int *flag9,int *flag10,int *flag11);//根据适合专业问卷调查给出测评结果（包括文字分析和拓扑图数据显示）
void qresultbk();//背景函数
int question(int *flag6,int *flag7,int *flag8,int *flag9,int *flag10,int *flag11);//适合专业问卷调查函数
void questionbk(void);//背景函数
int result(int *p,int *flag3,int *nb,int *cb,int *cb2);//个性化推荐结果展示界面，点击给出的结果可跳转到对应的大学专业详细介绍页面
void resultbk();//背景函数
int resultknn(int *p,int *flag3);//个性化推荐中的综合推荐结果显示界面，点击对应结果可跳转至对应大学专业详细信息介绍页面
void resultknnbk();//背景函数
void input_school(struct S school[10]);//从文件中读取学校各专业信息，包括录取分数线，所在城市就业薪资排名等
int signup();//注册功能函数
void signupbk(void);//背景函数
void inputname(struct U *user, int x1, int y1);//输入用户名
void inputpassword(struct U *user, int x1, int y1);//输入密码
void inputpassword1(char *p, int x1, int y1);//二次输入密码
int check_register(struct U *user, char *cp);//检查各项数据
int existence(struct U *user);//检查该用户是否已经存在
void intofile(struct U *user);//将信息写入文件
int chat(struct C *chater);
void chatbk();
void comparescreen(void);
int compare( int choice[2]);
void comparelight(int x1, int y1,int length) ;
void comparecover(int x1, int y1,int length) ;
int compasult(int choice[2]);
void compasultbk(void);
int connect(int a,int b,int *pschool,int *sorts,int *subjects,int *flag3);//个性化推荐结果与大学或专业详细信息之间的过渡页面，用于选择查看大学还是专业
void connectbk(void);//过渡页面背景函数
void display(int a,int b,int x,int y);//用于在指定位置输出个性化推荐的大学和专业的名字
void funcknn(struct U *user,PERSON person[2][10][12][10],int *schs,int *majs);//个性化推荐中综合推荐分支的核心算法，使用了机器学习中的k近邻算法，通过计算用户省排名与大量样本省排名之间的欧氏距离大小，经过排序筛选出距离最近的k个样本，并依次推荐出其中出现次数最多的三个样本对应的学校及专业。 
void function(struct U *user,struct S school[10],int choice,int *schs,int *majs,int *nb,int *cb,int *cb2);//个性化推荐算法中的分类算法，在省排名符合条件的基础上，分别以专业评估等级、地区就业薪资水平、专业发展前景为优先考虑项（具体排名从文件中读取），分别给出了可冲刺、较稳妥、可保底这三个推荐结果。
int distance(int a,int b);//用于计算欧氏距离的函数
void swap(int *a,int *b);//用于交换两变量的值的函数
int str_to_int(char *s);//用于将字符串转化为整型的函数
void puthz(int x, int y,char *s,int flag,int part,int color);














#endif
