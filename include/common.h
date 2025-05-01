#ifndef _common_h_
#define _common_h_

#include<graphics.h>
#include<stdio.h>
#include<stdlib.h>
#include<bios.h>
#include<string.h>
#include<dos.h>
#include<math.h>
//#include<time.h>
#include"hz.h"
#include"mouse.h"
#include <conio.h>
#define NUM0 0x5230
#define NUM1 0x4f31
#define NUM2 0x5032
#define NUM3 0x5133
#define NUM4 0x4134
#define NUM5 0x4c35
#define NUM6 0x4d36
#define NUM7 0x4737
#define NUM8 0x4838
#define NUM9 0x4939
#define F2 0x3c00
#define F3 0x3d00
#define F4 0x3e00
#define F5 0x3f00
#define F6 0x4000
#define F7 0x4100
#define F8 0x4200
#define F9 0x4300
#define F10 0x4400
#define F1 0x3b00
#define ENTER 0x1c0d
#define BACK 0x0e08
#define ESC 0x011b
#define UP 0x4800
#define DOWN 0x5000
#define RIGHT 0x4d00
#define LEFT 0x4b00
#define ONE 0x0231
#define TWO 0x0332
#define THREE 0x0433
#define FOUR 0x0534
#define FIVE 0x0635
#define SIX 0x0736
#define SEVEN 0x0837
#define EIGHT 0x0938
#define NINE 0x0a39
#define ZERO 0x0b30
#define DELETE 0x5300
#define SPACE 0x3920

#define LASTLINE 0x1a5b
#define NEXTLINE 0x1b5d

#define FIRST 0x0231
#define SECOND 0x0332
#define THIRD 0x0433
#define FOURTH 0x0534

#define MAXPY 12      //最大拼音（西文）数量 

#define FAIL 0
#define SUCCESS 1
//void puthz(int x, int y,char *s,int flag,int part,int color);

struct U
{
	char name[10];//用户名
	char password[10];//密码
	char range[6];//省排名	
	char year[6];//高考年份 
	char province[10];//省份
	int choose; //选课组合---1为物化生 2为物化地 3为物生地 4史政地 5史生地 6史政生

};

struct S
{
	int name;//学校编号：1.清华大学 2.北京大学 3.浙江大学 4.上海交通大学 5.复旦大学 6.南京大学 7.中国科学技术大学 8.华中科技大学 9.武汉大学 10.西安交通大学
	int major[12];//专业编号：1.人工智能 2.计算机科学 3.自动化 4.电气 5.临床医学 6.数学 7.物理 8.能源工程 9.机械制造 10.法学 11.语言学 12.哲学
	int major_quality[12];//学科评估等级：1.A+	2.A	 3.A-	4.B+  以此类推
	int region;//地区：1.上海 2.北京 3.杭州 4.南京 5.武汉 6.合肥 7.西安
	int salary[12];//地区工资排名：如上
	int rangej[12];//江苏用户输入省排名
	int rangeh[12];//湖南用户输入省排名
};

typedef struct p
{
	int name;
	int major;
	int range;
}PERSON;

struct C 
{
	char name[10];
	char s[50];
};

#endif
