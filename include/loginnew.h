#ifndef _loginnew_h_
#define _loginnew_h_

int login(struct U *user,int *flag4);//登录功能函数
int check_log(struct U *user);//检查输入项是否符合规定
void loginbk(void);//背景函数
void loginrecover(int x1,int y1,char*s,int length);//按键恢复
void loginlight(int x1,int y1,char*s,int length);//输入用户名和密码按键亮框
void logpassword(struct U *user,int x1,int y1);//输入密码并保存
void logname(struct U *user,int x1,int y1);//输入用户名并保存
//void bright(int x1,int y1,int x2,int y2,int bkcolor);


#endif
