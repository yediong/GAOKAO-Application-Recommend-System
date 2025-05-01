#ifdef _function_h_
#define _function_h_

void function(struct U *user,struct S school[10],int choice,int *schs,int *majs,int *nb,int *cb,int *cb2);//个性化推荐算法中的分类算法，在省排名符合条件的基础上，分别以专业评估等级、地区就业薪资水平、专业发展前景为优先考虑项（具体排名从文件中读取），分别给出了可冲刺、较稳妥、可保底这三个推荐结果。
int distance(int a,int b);//用于计算欧氏距离的函数
void swap(int *a,int *b);//用于交换两变量的值的函数
int str_to_int(char *s);//用于将字符串转化为整型的函数
#endif
