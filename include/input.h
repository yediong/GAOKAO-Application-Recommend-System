#ifndef _input_h_
#define _input_h_

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

#endif
