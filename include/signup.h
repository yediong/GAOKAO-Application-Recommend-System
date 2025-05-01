#ifndef _signup_h_
#define _signup_h_
int signup();//注册功能函数
void signupbk(void);//背景函数
void inputname(struct U *user, int x1, int y1);//输入用户名
void inputpassword(struct U *user, int x1, int y1);//输入密码
void inputpassword1(char *p, int x1, int y1);//二次输入密码
int check_register(struct U *user, char *cp);//检查各项数据
int existence(struct U *user);//检查该用户是否已经存在
void intofile(struct U *user);//将信息写入文件



#endif
