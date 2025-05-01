#include"common.h"
#include"function.h"
#include"display.h"
#include"school.h"


/*********************************************
FUNCTION:distance
DESCRIPTION:计算两个数据点之间的欧氏距离
PARAMETERS:int a,int b
RETURN:sum
*********************************************/
int distance(int a, int b) {
	int sum = abs(a - b);
	return sum;
}


/*********************************************
FUNCTION:swap
DESCRIPTION:交换
PARAMETERS:int *a,int *b
RETURN：void
*********************************************/
void swap(int *a, int *b) {
	int t;
	t = *a;
	*a = *b;
	*b = t;
}



/*********************************************
FUNCTION:str_to_int
DESCRIPTION:将字符串转换为整数
PARAMETERS:char *s
RETURN:result
***********************************************/
int str_to_int(char *s) {
	int result = 0;
	while (*s) {
		result = result * 10 + (*s - '0');
		s++;
	}
	return result;
}



/*********************************************
FUNCTION:function
DESCRIPTION:个性化推荐核心算法
PARAMETERS:struct S school[10],int user_range,int choice,后续要加入struct U *user
RETURN：void

2022.3.25说明:目前无法实现功能，因为struct U *user尚未导入，不知道user.province和真正的user_range。user_range在后续合代码
	过程中需替换为user.range,而且user.range等结构体U中的数为char形式，后续使用时需重新定义int型变量存储user中的数据。

	注意choose和choice的区别，choose是选科组合，包含在struct U *user内，choice是在option页面内选择的选项卡
*********************************************/
void function(struct U *user, struct S school[10], int choice, int *schs, int *majs, int *nb,int *cb,int *cb2) {
	int a[5] = {100 + 30, 152 + 30, 204 + 30, 256 + 30, 308 + 30};
	int k = 90; //理科选择的样本个数
	int l = 30; //文科选择的样本个数

	int indices[90];  //伪指针
	int indices2[30];
	int i = 0, j = 0, t = 0;
	int min_idx;      //最小距离的标号，用于排序
	int distances[90];  //用于存放所有点到用户数据点的距离（先只考虑理科）
	int distances2[30];
	int sch = 0, f_sch = 0;
	int maj = 0, f_maj = 0;
	int flag1 = 0, flag2 = 0;
	int s = 3; //三个结果两两之间的距离单位数

	int tmp_quality = 15;
	int tmp_region = 10;
	int tmp_salary = 20;

	int provin = 0;
	int user_range = 0;
	int temp = 0;
	provin = str_to_int(user->province);
	temp = str_to_int(user->range);
	user_range = temp;
	*nb = 0;



//理科，江苏
	if ((user->choose == 1 || user->choose == 2 || user->choose == 3) && provin == 1) {
		t = 0;
		distances[30] = 0;
		indices[30] = 0;
		/*******************排序******************/
		for (i = 0; i < 10; i++) {
			for (j = 0; j < 9; j++) {
				distances[t] = distance(school[i].rangej[j], user_range);
				t++;
			}
		}

		for (i = 0; i < 90; i++) {
			indices[i] = i;
		}

		for (i = 0; i < 89; i++) {
			min_idx = i;

			for (j = i + 1; j < 90; j++) {
				if (distances[j] < distances[min_idx]) {
					min_idx = j;
				}
			}

			swap(&distances[i], &distances[min_idx]);
			swap(&indices[i], &indices[min_idx]);   //如此一来，indices的最前面k项就是对距离从小到大排列
		}




		/*专业=1*/
		if (choice == 1) {
			/*第一轮筛选，选出较稳妥*/
			for (i = 0; i < k; i++) {
				sch = indices[i] / 9;
				maj = indices[i] % 9;

				if (user_range <= school[sch].rangej[maj] && flag1 < s) { //读取小于user_range的s个数，并比较专业的好坏，选出其中学科评估等级最优者
					flag1++;
					if (tmp_quality >= school[sch].major_quality[maj]) {
						tmp_quality = school[sch].major_quality[maj];
						f_sch = sch;
						f_maj = maj;
					}
				}

				else if (flag1 == s) {
					display(f_sch, f_maj, 123 + 52, a[1] + 3); //打印出推荐结果(较稳妥，第二行)

					schs[1] = f_sch;
					majs[1] = f_maj;

					flag2 = i;
					flag1 = 0;
					f_maj = 0;
					f_sch = 0;
					tmp_quality = 20;

					break;
				}
				
				else if(i==k-1&&*nb!=1)
				{   
					if(flag1==0)
					{
					puthz(123 + 52, a[1] + 3, "暂无", 24, 26, YELLOW);

					schs[1] = f_sch;
					majs[1] = f_maj;

					flag2 = 0;
					flag1 = 0;
					f_maj = 0;
					f_sch = 0;
					tmp_quality = 20;
					*cb = 2;
					}
					
					else if(flag1==1)
					{
					display(f_sch, f_maj, 123 + 52, a[1] + 3); //打印出推荐结果(较稳妥，第二行)

					schs[1] = f_sch;
					majs[1] = f_maj;

					flag2 = i;
					flag1 = 0;
					f_maj = 0;
					f_sch = 0;
					tmp_quality = 20;

					break;						
					}					
				}

				else {
					continue;
				}
			}



			/*第二轮筛选，选出可保底*/
			for (i = flag2 + 1; i < k; i++) {
				sch = indices[i] / 9;
				maj = indices[i] % 9;

				if (user_range <= school[sch].rangej[maj] && flag1 < s) {
					flag1++;
					if (tmp_quality >= school[sch].major_quality[maj]) {
						tmp_quality = school[sch].major_quality[maj];
						f_sch = sch;
						f_maj = maj;
					}
				}

				else if (flag1 == s) {
					display(f_sch, f_maj, 123 + 52, a[2] + 3); //打印出推荐结果(可保底，第三行)

					schs[2] = f_sch;
					majs[2] = f_maj;

					flag2 = i;
					flag1 = 0;
					f_maj = 0;
					f_sch = 0;
					tmp_quality = 20;

					break;
				}	
				else if(i==k-1&&*nb!=1)
				{
					puthz(123 + 52, a[2] + 3, "暂无", 24, 26, YELLOW);

					schs[0] = f_sch;
					majs[0] = f_maj;

					flag2 = 0;
					flag1 = 0;
					f_maj = 0;
					f_sch = 0;
					tmp_quality = 20;
					*cb2 = 2;					
									
					
				} else {
					continue;
				}
			}


			/*第三轮筛选，选出可冲刺*/
			for (i = 0; i < k; i++) {
				sch = indices[i] / 9;
				maj = indices[i] % 9;

				if (user_range > school[sch].rangej[maj] && flag1 < s) {
					flag1++;
					if (tmp_quality >= school[sch].major_quality[maj]) {
						tmp_quality = school[sch].major_quality[maj];
						f_sch = sch;
						f_maj = maj;
					}
				}

				else if (flag1 == s) {

					display(f_sch, f_maj, 123 + 52, a[0] + 3); //打印出推荐结果(可冲刺，第一行)

					schs[0] = f_sch;
					majs[0] = f_maj;

					flag2 = 0;
					flag1 = 0;
					f_maj = 0;
					f_sch = 0;
					tmp_quality = 20;

					break;
				}

				/*4.15改*/
				else if (i == k - 1) {
					puthz(123 + 52, a[0] + 3, "您已无敌，无需冲刺", 24, 26, YELLOW);

					schs[0] = f_sch;
					majs[0] = f_maj;

					flag2 = 0;
					flag1 = 0;
					f_maj = 0;
					f_sch = 0;
					tmp_quality = 20;
					*nb = 1;
				}

				else {
					continue;
				}
			}
		}



		/*地区=2*/
		if (choice == 2) {
			/*第一轮筛选，选出较稳妥*/
			for (i = 0; i < k; i++) {
				sch = indices[i] / 9;
				maj = indices[i] % 9;

				if (user_range <= school[sch].rangej[maj] && flag1 < s) { //读取小于user_range的s*2个数，并比较地区的好坏，选出其中地区人均工资最高者
					flag1++;
					if (tmp_region >= school[sch].region) {
						tmp_region = school[sch].region;
						f_sch = sch;
						f_maj = maj;
					}
				}

				else if (flag1 == s) {
					display(f_sch, f_maj, 123 + 52, a[1] + 3); //打印出推荐结果(较稳妥，第二行)

					schs[1] = f_sch;
					majs[1] = f_maj;

					flag2 = i;
					flag1 = 0;
					f_maj = 0;
					f_sch = 0;
					tmp_region = 20;

					break;
				}
				else if(i==k-1&&*nb!=1)
				{
					puthz(123 + 52, a[1] + 3, "暂无", 24, 26, YELLOW);

					schs[0] = f_sch;
					majs[0] = f_maj;

					flag2 = 0;
					flag1 = 0;
					f_maj = 0;
					f_sch = 0;
					tmp_quality = 20;
					*cb = 2;					
				}
				else {
					continue;
				}
			}



			/*第二轮筛选，选出可保底*/
			for (i = flag2 + 1; i < k; i++) {
				sch = indices[i] / 9;
				maj = indices[i] % 9;

				if (user_range <= school[sch].rangej[maj] && flag1 < s) {
					flag1++;
					if (tmp_region >= school[sch].region) {
						tmp_region = school[sch].region;
						f_sch = sch;
						f_maj = maj;
					}
				}

				else if (flag1 == s) {
					display(f_sch, f_maj, 123 + 52, a[2] + 3); //打印出推荐结果(可保底，第三行)
					schs[2] = f_sch;
					majs[2] = f_maj;
					flag2 = i;
					flag1 = 0;
					f_maj = 0;
					f_sch = 0;
					tmp_region = 20;

					break;
				} 
				else if(i==k-1&&*nb!=1)
				{
					puthz(123 + 52, a[2] + 3, "暂无", 24, 26, YELLOW);

					schs[0] = f_sch;
					majs[0] = f_maj;

					flag2 = 0;
					flag1 = 0;
					f_maj = 0;
					f_sch = 0;
					tmp_quality = 20;
					*cb2 = 2;					
				}								
				else {
					continue;
				}
			}


			/*第三轮筛选，选出可冲刺*/
			for (i = 0; i < k; i++) {
				sch = indices[i] / 9;
				maj = indices[i] % 9;

				if (user_range > school[sch].rangej[maj] && flag1 < s) {
					flag1++;
					if (tmp_region >= school[sch].region) {
						tmp_region = school[sch].region;
						f_sch = sch;
						f_maj = maj;
					}
				}

				else if (flag1 == s) {
					display(f_sch, f_maj, 123 + 52, a[0] + 3); //打印出推荐结果(可冲刺，第一行)
					schs[0] = f_sch;
					majs[0] = f_maj;
					flag2 = 0;
					flag1 = 0;
					f_maj = 0;
					f_sch = 0;
					tmp_region = 20;

					break;
				}

				/*4.15改*/
				else if (i == k - 1) {
					puthz(123 + 52, a[0] + 3, "您已无敌，无需冲刺", 24, 26, YELLOW);

					schs[0] = f_sch;
					majs[0] = f_maj;

					flag2 = 0;
					flag1 = 0;
					f_maj = 0;
					f_sch = 0;
					tmp_quality = 20;
					*nb = 1;
				}

				else {
					continue;
				}
			}
		}


		/*专业前景=3*/
		if (choice == 3) {
			/*第一轮筛选，选出较稳妥*/
			for (i = 0; i < k; i++) {
				sch = indices[i] / 9;
				maj = indices[i] % 9;

				if (user_range <= school[sch].rangej[maj] && flag1 < s) { //读取小于user_range的s个数，并比较专业的好坏，选出其中学科评估等级最优者
					flag1++;
					if (tmp_salary >= school[sch].salary[maj]) {
						tmp_salary = school[sch].salary[maj];
						f_sch = sch;
						f_maj = maj;
					}
				}

				else if (flag1 == s) {
					display(f_sch, f_maj, 123 + 52, a[1] + 3); //打印出推荐结果(较稳妥，第二行)
					schs[1] = f_sch;
					majs[1] = f_maj;
					flag2 = i;
					flag1 = 0;
					f_maj = 0;
					f_sch = 0;
					tmp_salary = 20;

					break;
				}
				else if(i==k-1&&*nb!=1)
				{
					puthz(123 + 52, a[1] + 3, "暂无", 24, 26, YELLOW);

					schs[0] = f_sch;
					majs[0] = f_maj;

					flag2 = 0;
					flag1 = 0;
					f_maj = 0;
					f_sch = 0;
					tmp_quality = 20;
					*cb = 2;					
				}
				else {
					continue;
				}
			}



			/*第二轮筛选，选出可保底*/
			for (i = flag2 + 1; i < k; i++) {
				sch = indices[i] / 9;
				maj = indices[i] % 9;

				if (user_range <= school[sch].rangej[maj] && flag1 < s) {
					flag1++;
					if (tmp_salary >= school[sch].salary[maj]) {
						tmp_salary = school[sch].salary[maj];
						f_sch = sch;
						f_maj = maj;
					}
				}

				else if (flag1 == s) {
					display(f_sch, f_maj, 123 + 52, a[2] + 3); //打印出推荐结果(可保底，第三行)
					schs[2] = f_sch;
					majs[2] = f_maj;
					flag2 = i;
					flag1 = 0;
					f_maj = 0;
					f_sch = 0;
					tmp_salary = 20;

					break;
				} 
					else if(i==k-1&&*nb!=1)
					{
						puthz(123 + 52, a[2] + 3, "暂无", 24, 26, YELLOW);
	
						schs[0] = f_sch;
						majs[0] = f_maj;
	
						flag2 = 0;
						flag1 = 0;
						f_maj = 0;
						f_sch = 0;
						tmp_quality = 20;
						*cb2 = 2;					
					}							
				else {
					continue;
				}
			}


			/*第三轮筛选，选出可冲刺*/
			for (i = 0; i < k; i++) {
				sch = indices[i] / 9;
				maj = indices[i] % 9;

				if (user_range > school[sch].rangej[maj] && flag1 < s) {
					flag1++;
					if (tmp_salary >= school[sch].salary[maj]) {
						tmp_salary = school[sch].salary[maj];
						f_sch = sch;
						f_maj = maj;
					}
				}

				else if (flag1 == s) {
					display(f_sch, f_maj, 123 + 52, a[0] + 3); //打印出推荐结果(可冲刺，第一行)
					schs[0] = f_sch;
					majs[0] = f_maj;
					flag2 = 0;
					flag1 = 0;
					f_maj = 0;
					f_sch = 0;
					tmp_salary = 20;

					break;
				}

				/*4.15改*/
				else if (i == k - 1) {
					puthz(123 + 52, a[0] + 3, "您已无敌，无需冲刺", 24, 26, YELLOW);

					schs[0] = f_sch;
					majs[0] = f_maj;

					flag2 = 0;
					flag1 = 0;
					f_maj = 0;
					f_sch = 0;
					tmp_quality = 20;
					*nb = 1;
				}

				else {
					continue;
				}
			}
		}
	}




//理科，湖南
	if ((user->choose == 1 || user->choose == 2 || user->choose == 3) && provin == 2) {
		t = 0;
		distances[30] = 0;
		indices[30] = 0;
		/*******************排序******************/
		for (i = 0; i < 10; i++) {
			for (j = 0; j < 9; j++) {
				distances[t] = distance(school[i].rangeh[j], user_range);
				t++;
			}
		}

		for (i = 0; i < 90; i++) {
			indices[i] = i;
		}

		for (i = 0; i < 89; i++) {
			min_idx = i;

			for (j = i + 1; j < 90; j++) {
				if (distances[j] < distances[min_idx]) {
					min_idx = j;
				}
			}

			swap(&distances[i], &distances[min_idx]);
			swap(&indices[i], &indices[min_idx]);   //如此一来，indices的最前面k项就是对距离从小到大排列
		}




		/*专业=1*/
		if (choice == 1) {
			/*第一轮筛选，选出较稳妥*/
			for (i = 0; i < k; i++) {
				sch = indices[i] / 9;
				maj = indices[i] % 9;

				if (user_range <= school[sch].rangeh[maj] && flag1 < s) { //读取小于user_range的s个数，并比较专业的好坏，选出其中学科评估等级最优者
					flag1++;
					if (tmp_quality >= school[sch].major_quality[maj]) {
						tmp_quality = school[sch].major_quality[maj];
						f_sch = sch;
						f_maj = maj;
					}
				}

				else if (flag1 == s) {
					display(f_sch, f_maj, 123 + 52, a[1] + 3); //打印出推荐结果(较稳妥，第二行)
					schs[1] = f_sch;
					majs[1] = f_maj;
					flag2 = i;
					flag1 = 0;
					f_maj = 0;
					f_sch = 0;
					tmp_quality = 20;

					break;
				}
				else if(i==k-1&&*nb!=1)
				{
					puthz(123 + 52, a[1] + 3, "暂无", 24, 26, YELLOW);

					schs[0] = f_sch;
					majs[0] = f_maj;

					flag2 = 0;
					flag1 = 0;
					f_maj = 0;
					f_sch = 0;
					tmp_quality = 20;
					*cb = 2;					
				}
				else {
					continue;
				}
			}



			/*第二轮筛选，选出可保底*/
			for (i = flag2 + 1; i < k; i++) {
				sch = indices[i] / 9;
				maj = indices[i] % 9;

				if (user_range <= school[sch].rangeh[maj] && flag1 < s) {
					flag1++;
					if (tmp_quality >= school[sch].major_quality[maj]) {
						tmp_quality = school[sch].major_quality[maj];
						f_sch = sch;
						f_maj = maj;
					}
				}

				else if (flag1 == s) {
					display(f_sch, f_maj, 123 + 52, a[2] + 3); //打印出推荐结果(可保底，第三行)
					schs[2] = f_sch;
					majs[2] = f_maj;
					flag2 = i;
					flag1 = 0;
					f_maj = 0;
					f_sch = 0;
					tmp_quality = 20;

					break;
				} 
				else if(i==k-1&&*nb!=1)
				{
					puthz(123 + 52, a[2] + 3, "暂无", 24, 26, YELLOW);

					schs[0] = f_sch;
					majs[0] = f_maj;

					flag2 = 0;
					flag1 = 0;
					f_maj = 0;
					f_sch = 0;
					tmp_quality = 20;
					*cb2 = 2;					
				}								
				else {
					continue;
				}
			}


			/*第三轮筛选，选出可冲刺*/
			for (i = 0; i < k; i++) {
				sch = indices[i] / 9;
				maj = indices[i] % 9;

				if (user_range > school[sch].rangeh[maj] && flag1 < s) {
					flag1++;
					if (tmp_quality >= school[sch].major_quality[maj]) {
						tmp_quality = school[sch].major_quality[maj];
						f_sch = sch;
						f_maj = maj;
					}
				}

				else if (flag1 == s) {
					display(f_sch, f_maj, 123 + 52, a[0] + 3); //打印出推荐结果(可冲刺，第一行)
					schs[0] = f_sch;
					majs[0] = f_maj;
					flag2 = 0;
					flag1 = 0;
					f_maj = 0;
					f_sch = 0;
					tmp_quality = 20;

					break;
				}

				/*4.15改*/
				else if (i == k - 1) {
					puthz(123 + 52, a[0] + 3, "您已无敌，无需冲刺", 24, 26, YELLOW);

					schs[0] = f_sch;
					majs[0] = f_maj;

					flag2 = 0;
					flag1 = 0;
					f_maj = 0;
					f_sch = 0;
					tmp_quality = 20;
					*nb = 1;
				}

				else {
					continue;
				}
			}
		}



		/*地区=2*/
		if (choice == 2) {
			/*第一轮筛选，选出较稳妥*/
			for (i = 0; i < k; i++) {
				sch = indices[i] / 9;
				maj = indices[i] % 9;

				if (user_range <= school[sch].rangeh[maj] && flag1 < s) { //读取小于user_range的s*2个数，并比较地区的好坏，选出其中地区人均工资最高者
					flag1++;
					if (tmp_region >= school[sch].region) {
						tmp_region = school[sch].region;
						f_sch = sch;
						f_maj = maj;
					}
				}

				else if (flag1 == s) {
					display(f_sch, f_maj, 123 + 52, a[1] + 3); //打印出推荐结果(较稳妥，第二行)
					schs[1] = f_sch;
					majs[1] = f_maj;
					flag2 = i;
					flag1 = 0;
					f_maj = 0;
					f_sch = 0;
					tmp_region = 20;

					break;
				}
				else if(i==k-1&&*nb!=1)
				{
					puthz(123 + 52, a[1] + 3, "暂无", 24, 26, YELLOW);

					schs[0] = f_sch;
					majs[0] = f_maj;

					flag2 = 0;
					flag1 = 0;
					f_maj = 0;
					f_sch = 0;
					tmp_quality = 20;
					*cb = 2;					
				}
				else {
					continue;
				}
			}



			/*第二轮筛选，选出可保底*/
			for (i = flag2 + 1; i < k; i++) {
				sch = indices[i] / 9;
				maj = indices[i] % 9;

				if (user_range <= school[sch].rangeh[maj] && flag1 < s) {
					flag1++;
					if (tmp_region >= school[sch].region) {
						tmp_region = school[sch].region;
						f_sch = sch;
						f_maj = maj;
					}
				}

				else if (flag1 == s) {
					display(f_sch, f_maj, 123 + 52, a[2] + 3); //打印出推荐结果(可保底，第三行)
					schs[2] = f_sch;
					majs[2] = f_maj;
					flag2 = i;
					flag1 = 0;
					f_maj = 0;
					f_sch = 0;
					tmp_region = 20;

					break;
				} 
				
				else if(i==k-1&&*nb!=1)
				{
					puthz(123 + 52, a[2] + 3, "暂无", 24, 26, YELLOW);

					schs[0] = f_sch;
					majs[0] = f_maj;

					flag2 = 0;
					flag1 = 0;
					f_maj = 0;
					f_sch = 0;
					tmp_quality = 20;
					*cb2 = 2;					
				}								
				else {
					continue;
				}
			}


			/*第三轮筛选，选出可冲刺*/
			for (i = 0; i < k; i++) {
				sch = indices[i] / 9;
				maj = indices[i] % 9;

				if (user_range > school[sch].rangeh[maj] && flag1 < s) {
					flag1++;
					if (tmp_region >= school[sch].region) {
						tmp_region = school[sch].region;
						f_sch = sch;
						f_maj = maj;
					}
				}

				else if (flag1 == s) {
					display(f_sch, f_maj, 123 + 52, a[0] + 3); //打印出推荐结果(可冲刺，第一行)
					schs[0] = f_sch;
					majs[0] = f_maj;
					flag2 = 0;
					flag1 = 0;
					f_maj = 0;
					f_sch = 0;
					tmp_region = 20;

					break;
				}



				else {
					continue;
				}
			}
		}


		/*专业前景=3*/
		if (choice == 3) {
			/*第一轮筛选，选出较稳妥*/
			for (i = 0; i < k; i++) {
				sch = indices[i] / 9;
				maj = indices[i] % 9;

				if (user_range <= school[sch].rangeh[maj] && flag1 < s) { //读取小于user_range的s个数，并比较专业的好坏，选出其中学科评估等级最优者
					flag1++;
					if (tmp_salary >= school[sch].salary[maj]) {
						tmp_salary = school[sch].salary[maj];
						f_sch = sch;
						f_maj = maj;
					}
				}

				else if (flag1 == s) {
					display(f_sch, f_maj, 123 + 52, a[1] + 3); //打印出推荐结果(较稳妥，第二行)
					schs[1] = f_sch;
					majs[1] = f_maj;
					flag2 = i;
					flag1 = 0;
					f_maj = 0;
					f_sch = 0;
					tmp_salary = 20;

					break;
				}
				else if(i==k-1&&*nb!=1)
				{
					puthz(123 + 52, a[1] + 3, "暂无", 24, 26, YELLOW);

					schs[0] = f_sch;
					majs[0] = f_maj;

					flag2 = 0;
					flag1 = 0;
					f_maj = 0;
					f_sch = 0;
					tmp_quality = 20;
					*cb = 2;					
				}
				else {
					continue;
				}
			}



			/*第二轮筛选，选出可保底*/
			for (i = flag2 + 1; i < k; i++) {
				sch = indices[i] / 9;
				maj = indices[i] % 9;

				if (user_range <= school[sch].rangeh[maj] && flag1 < s) {
					flag1++;
					if (tmp_salary >= school[sch].salary[maj]) {
						tmp_salary = school[sch].salary[maj];
						f_sch = sch;
						f_maj = maj;
					}
				}

				else if (flag1 == s) {
					display(f_sch, f_maj, 123 + 52, a[2] + 3); //打印出推荐结果(可保底，第三行)
					schs[2] = f_sch;
					majs[2] = f_maj;
					flag2 = i;
					flag1 = 0;
					f_maj = 0;
					f_sch = 0;
					tmp_salary = 20;

					break;
				} 
				
				else if(i==k-1&&*nb!=1)
				{
					puthz(123 + 52, a[2] + 3, "暂无", 24, 26, YELLOW);

					schs[0] = f_sch;
					majs[0] = f_maj;

					flag2 = 0;
					flag1 = 0;
					f_maj = 0;
					f_sch = 0;
					tmp_quality = 20;
					*cb2 = 2;					
				}								
				
				else {
					continue;
				}
			}


			/*第三轮筛选，选出可冲刺*/
			for (i = 0; i < k; i++) {
				sch = indices[i] / 9;
				maj = indices[i] % 9;

				if (user_range > school[sch].rangeh[maj] && flag1 < s) {
					flag1++;
					if (tmp_salary >= school[sch].salary[maj]) {
						tmp_salary = school[sch].salary[maj];
						f_sch = sch;
						f_maj = maj;
					}
				}

				else if (flag1 == s) {
					display(f_sch, f_maj, 123 + 52, a[0] + 3); //打印出推荐结果(可冲刺，第一行)
					schs[0] = f_sch;
					majs[0] = f_maj;
					flag2 = 0;
					flag1 = 0;
					f_maj = 0;
					f_sch = 0;
					tmp_salary = 20;

					break;
				}

				/*4.15改*/
				else if (i == k - 1) {
					puthz(123 + 52, a[0] + 3, "您已无敌，无需冲刺", 24, 26, YELLOW);

					schs[0] = f_sch;
					majs[0] = f_maj;

					flag2 = 0;
					flag1 = 0;
					f_maj = 0;
					f_sch = 0;
					tmp_quality = 20;
					*nb = 1;
				}

				else {
					continue;
				}
			}
		}
	}




//文科，江苏
	if ((user->choose == 4 || user->choose == 5 || user->choose == 6) && provin == 1) {
		t = 0;
		distances2[30] = 0;
		indices2[30] = 0;
		/*******************排序******************/
		for (i = 0; i < 10; i++) {
			for (j = 9; j < 12; j++) {
				distances2[t] = distance(school[i].rangej[j], user_range);
				t++;
			}
		}

		for (i = 0; i < 30; i++) {
			indices2[i] = i;
		}

		for (i = 0; i < 29; i++) {
			min_idx = i;

			for (j = i + 1; j < 30; j++) {
				if (distances2[j] < distances2[min_idx]) {
					min_idx = j;
				}
			}

			swap(&distances2[i], &distances2[min_idx]);
			swap(&indices2[i], &indices2[min_idx]);   //如此一来，indices的最前面k项就是对距离从小到大排列
		}




		/*专业=1*/
		if (choice == 1) {
			/*第一轮筛选，选出较稳妥*/
			for (i = 0; i < l; i++) {
				sch = indices2[i] / 3;
				maj = indices2[i] % 3 + 9;

				if (user_range <= school[sch].rangej[maj] && flag1 < s) { //读取小于user_range的s个数，并比较专业的好坏，选出其中学科评估等级最优者
					flag1++;
					if (tmp_quality >= school[sch].major_quality[maj]) {
						tmp_quality = school[sch].major_quality[maj];
						f_sch = sch;
						f_maj = maj;
					}
				}

				else if (flag1 == s) {
					display(f_sch, f_maj, 123 + 52, a[1] + 3); //打印出推荐结果(较稳妥，第二行)
					schs[1] = f_sch;
					majs[1] = f_maj;
					flag2 = i;
					flag1 = 0;
					f_maj = 0;
					f_sch = 0;
					tmp_quality = 20;

					break;
				}
				else if(i==l-1&&*nb!=1)
				{
					puthz(123 + 52, a[1] + 3, "暂无", 24, 26, YELLOW);

					schs[0] = f_sch;
					majs[0] = f_maj;

					flag2 = 0;
					flag1 = 0;
					f_maj = 0;
					f_sch = 0;
					tmp_quality = 20;
					*cb = 2;					
				}
				else {
					continue;
				}
			}



			/*第二轮筛选，选出可保底*/
			for (i = flag2 + 1; i < l; i++) {
				sch = indices2[i] / 3;
				maj = indices2[i] % 3 + 9;

				if (user_range <= school[sch].rangej[maj] && flag1 < s) {
					flag1++;
					if (tmp_quality >= school[sch].major_quality[maj]) {
						tmp_quality = school[sch].major_quality[maj];
						f_sch = sch;
						f_maj = maj;
					}
				}

				else if (flag1 == s) {
					display(f_sch, f_maj, 123 + 52, a[2] + 3); //打印出推荐结果(可保底，第三行)
					schs[2] = f_sch;
					majs[2] = f_maj;
					flag2 = i;
					flag1 = 0;
					f_maj = 0;
					f_sch = 0;
					tmp_quality = 20;

					break;
				}
				
				else if(i==l-1&&*nb!=1)
				{
					puthz(123 + 52, a[2] + 3, "暂无", 24, 26, YELLOW);

					schs[0] = f_sch;
					majs[0] = f_maj;

					flag2 = 0;
					flag1 = 0;
					f_maj = 0;
					f_sch = 0;
					tmp_quality = 20;
					*cb2 = 2;					
				}								
				
				 else {
					continue;
				}
			}


			/*第三轮筛选，选出可冲刺*/
			for (i = 0; i < l; i++) {
				sch = indices2[i] / 3;
				maj = indices2[i] % 3 + 9;

				if (user_range > school[sch].rangej[maj] && flag1 < s) {
					flag1++;
					if (tmp_quality >= school[sch].major_quality[maj]) {
						tmp_quality = school[sch].major_quality[maj];
						f_sch = sch;
						f_maj = maj;
					}
				}

				else if (flag1 == s) {
					display(f_sch, f_maj, 123 + 52, a[0] + 3); //打印出推荐结果(可冲刺，第一行)
					schs[0] = f_sch;
					majs[0] = f_maj;
					flag2 = 0;
					flag1 = 0;
					f_maj = 0;
					f_sch = 0;
					tmp_quality = 20;

					break;
				}

				/*4.15改*/
				else if (i == l - 1) {
					puthz(123 + 52, a[0] + 3, "您已无敌，无需冲刺", 24, 26, YELLOW);

					schs[0] = f_sch;
					majs[0] = f_maj;

					flag2 = 0;
					flag1 = 0;
					f_maj = 0;
					f_sch = 0;
					tmp_quality = 20;
					*nb = 1;
				}

				else {
					continue;
				}
			}
		}



		/*地区=2*/
		if (choice == 2) {
			/*第一轮筛选，选出较稳妥*/
			for (i = 0; i < l; i++) {
				sch = indices2[i] / 3;
				maj = indices2[i] % 3 + 9;

				if (user_range <= school[sch].rangej[maj] && flag1 < s) { //读取小于user_range的s*2个数，并比较地区的好坏，选出其中地区人均工资最高者
					flag1++;
					if (tmp_region >= school[sch].region) {
						tmp_region = school[sch].region;
						f_sch = sch;
						f_maj = maj;
					}
				}

				else if (flag1 == s) {
					display(f_sch, f_maj, 123 + 52, a[1] + 3); //打印出推荐结果(较稳妥，第二行)
					schs[1] = f_sch;
					majs[1] = f_maj;
					flag2 = i;
					flag1 = 0;
					f_maj = 0;
					f_sch = 0;
					tmp_region = 20;

					break;
				}
				else if(i==l-1&&*nb!=1)
				{
					puthz(123 + 52, a[1] + 3, "暂无", 24, 26, YELLOW);

					schs[0] = f_sch;
					majs[0] = f_maj;

					flag2 = 0;
					flag1 = 0;
					f_maj = 0;
					f_sch = 0;
					tmp_quality = 20;
					*cb = 2;					
				}
				else {
					continue;
				}
			}



			/*第二轮筛选，选出可保底*/
			for (i = flag2 + 1; i < l; i++) {
				sch = indices2[i] / 3;
				maj = indices2[i] % 3 + 9;

				if (user_range <= school[sch].rangej[maj] && flag1 < s) {
					flag1++;
					if (tmp_region >= school[sch].region) {
						tmp_region = school[sch].region;
						f_sch = sch;
						f_maj = maj;
					}
				}

				else if (flag1 == s) {
					display(f_sch, f_maj, 123 + 52, a[2] + 3); //打印出推荐结果(可保底，第三行)
					schs[2] = f_sch;
					majs[2] = f_maj;
					flag2 = i;
					flag1 = 0;
					f_maj = 0;
					f_sch = 0;
					tmp_region = 20;

					break;
				} 
				else if(i==l-1&&*nb!=1)
				{
					puthz(123 + 52, a[2] + 3, "暂无", 24, 26, YELLOW);

					schs[0] = f_sch;
					majs[0] = f_maj;

					flag2 = 0;
					flag1 = 0;
					f_maj = 0;
					f_sch = 0;
					tmp_quality = 20;
					*cb2 = 2;					
				}								
								
				
				else {
					continue;
				}
			}


			/*第三轮筛选，选出可冲刺*/
			for (i = 0; i < l; i++) {
				sch = indices2[i] / 3;
				maj = indices2[i] % 3 + 9;

				if (user_range > school[sch].rangej[maj] && flag1 < s) {
					flag1++;
					if (tmp_region >= school[sch].region) {
						tmp_region = school[sch].region;
						f_sch = sch;
						f_maj = maj;
					}
				}

				else if (flag1 == s) {
					display(f_sch, f_maj, 123 + 52, a[0] + 3); //打印出推荐结果(可冲刺，第一行)
					schs[0] = f_sch;
					majs[0] = f_maj;
					flag2 = 0;
					flag1 = 0;
					f_maj = 0;
					f_sch = 0;
					tmp_region = 20;

					break;
				}

				/*4.15改*/
				else if (i == l - 1) {
					puthz(123 + 52, a[0] + 3, "您已无敌，无需冲刺", 24, 26, YELLOW);

					schs[0] = f_sch;
					majs[0] = f_maj;

					flag2 = 0;
					flag1 = 0;
					f_maj = 0;
					f_sch = 0;
					tmp_quality = 20;
					*nb = 1;
				}

				else {
					continue;
				}
			}
		}


		/*专业前景=3*/
		if (choice == 3) {
			/*第一轮筛选，选出较稳妥*/
			for (i = 0; i < l; i++) {
				sch = indices2[i] / 3;
				maj = indices2[i] % 3 + 9;

				if (user_range <= school[sch].rangej[maj] && flag1 < s) { //读取小于user_range的s个数，并比较专业的好坏，选出其中学科评估等级最优者
					flag1++;
					if (tmp_salary >= school[sch].salary[maj]) {
						tmp_salary = school[sch].salary[maj];
						f_sch = sch;
						f_maj = maj;
					}
				}

				else if (flag1 == s) {
					display(f_sch, f_maj, 123 + 52, a[1] + 3); //打印出推荐结果(较稳妥，第二行)
					schs[1] = f_sch;
					majs[1] = f_maj;
					flag2 = i;
					flag1 = 0;
					f_maj = 0;
					f_sch = 0;
					tmp_salary = 20;

					break;
				}
				else if(i==l-1&&*nb!=1)
				{
					puthz(123 + 52, a[1] + 3, "暂无", 24, 26, YELLOW);

					schs[0] = f_sch;
					majs[0] = f_maj;

					flag2 = 0;
					flag1 = 0;
					f_maj = 0;
					f_sch = 0;
					tmp_quality = 20;
					*cb = 2;					
				}
				else {
					continue;
				}
			}



			/*第二轮筛选，选出可保底*/
			for (i = flag2 + 1; i < l; i++) {
				sch = indices2[i] / 3;
				maj = indices2[i] % 3 + 9;

				if (user_range <= school[sch].rangej[maj] && flag1 < s) {
					flag1++;
					if (tmp_salary >= school[sch].salary[maj]) {
						tmp_salary = school[sch].salary[maj];
						f_sch = sch;
						f_maj = maj;
					}
				}

				else if (flag1 == s) {
					display(f_sch, f_maj, 123 + 52, a[2] + 3); //打印出推荐结果(可保底，第三行)
					schs[2] = f_sch;
					majs[2] = f_maj;
					flag2 = i;
					flag1 = 0;
					f_maj = 0;
					f_sch = 0;
					tmp_salary = 20;

					break;
				} 
				else if(i==l-1&&*nb!=1)
				{
					puthz(123 + 52, a[2] + 3, "暂无", 24, 26, YELLOW);

					schs[0] = f_sch;
					majs[0] = f_maj;

					flag2 = 0;
					flag1 = 0;
					f_maj = 0;
					f_sch = 0;
					tmp_quality = 20;
					*cb2 = 2;					
				}								
								
				
				else {
					continue;
				}
			}


			/*第三轮筛选，选出可冲刺*/
			for (i = 0; i < l; i++) {
				sch = indices2[i] / 3;
				maj = indices2[i] % 3 + 9;

				if (user_range > school[sch].rangej[maj] && flag1 < s) {
					flag1++;
					if (tmp_salary >= school[sch].salary[maj]) {
						tmp_salary = school[sch].salary[maj];
						f_sch = sch;
						f_maj = maj;
					}
				}

				else if (flag1 == s) {
					display(f_sch, f_maj, 123 + 52, a[0] + 3); //打印出推荐结果(可冲刺，第一行)
					schs[0] = f_sch;
					majs[0] = f_maj;
					flag2 = 0;
					flag1 = 0;
					f_maj = 0;
					f_sch = 0;
					tmp_salary = 20;

					break;
				}

				/*4.15改*/
				else if (i == l - 1) {
					puthz(123 + 52, a[0] + 3, "您已无敌，无需冲刺", 24, 26, YELLOW);

					schs[0] = f_sch;
					majs[0] = f_maj;

					flag2 = 0;
					flag1 = 0;
					f_maj = 0;
					f_sch = 0;
					tmp_quality = 20;
					*nb = 1;
				}

				else {
					continue;
				}
			}
		}
	}




//文科，湖南
	if ((user->choose == 4 || user->choose == 5 || user->choose == 6) && provin == 2) {
		t = 0;
		distances2[30] = 0;
		indices2[30] = 0;
		/*******************排序******************/
		for (i = 0; i < 10; i++) {
			for (j = 9; j < 12; j++) {
				distances2[t] = distance(school[i].rangeh[j], user_range);
				t++;
			}
		}

		for (i = 0; i < 30; i++) {
			indices2[i] = i;
		}

		for (i = 0; i < 29; i++) {
			min_idx = i;

			for (j = i + 1; j < 30; j++) {
				if (distances2[j] < distances2[min_idx]) {
					min_idx = j;
				}
			}

			swap(&distances2[i], &distances2[min_idx]);
			swap(&indices2[i], &indices2[min_idx]);   //如此一来，indices的最前面k项就是对距离从小到大排列
		}




		/*专业=1*/
		if (choice == 1) {
			/*第一轮筛选，选出较稳妥*/
			for (i = 0; i < l; i++) {
				sch = indices2[i] / 3;
				maj = indices2[i] % 3 + 9;

				if (user_range <= school[sch].rangeh[maj] && flag1 < s) { //读取小于user_range的s个数，并比较专业的好坏，选出其中学科评估等级最优者
					flag1++;
					if (tmp_quality >= school[sch].major_quality[maj]) {
						tmp_quality = school[sch].major_quality[maj];
						f_sch = sch;
						f_maj = maj;
					}
				}

				else if (flag1 == s) {
					display(f_sch, f_maj, 123 + 52, a[1] + 3); //打印出推荐结果(较稳妥，第二行)
					schs[1] = f_sch;
					majs[1] = f_maj;
					flag2 = i;
					flag1 = 0;
					f_maj = 0;
					f_sch = 0;
					tmp_quality = 20;

					break;
				}
				else if(i==l-1&&*nb!=1)
				{
					puthz(123 + 52, a[1] + 3, "暂无", 24, 26, YELLOW);

					schs[0] = f_sch;
					majs[0] = f_maj;

					flag2 = 0;
					flag1 = 0;
					f_maj = 0;
					f_sch = 0;
					tmp_quality = 20;
					*cb = 2;					
				}
				else {
					continue;
				}
			}



			/*第二轮筛选，选出可保底*/
			for (i = flag2 + 1; i < l; i++) {
				sch = indices2[i] / 3;
				maj = indices2[i] % 3 + 9;

				if (user_range <= school[sch].rangeh[maj] && flag1 < s) {
					flag1++;
					if (tmp_quality >= school[sch].major_quality[maj]) {
						tmp_quality = school[sch].major_quality[maj];
						f_sch = sch;
						f_maj = maj;
					}
				}

				else if (flag1 == s) {
					display(f_sch, f_maj, 123 + 52, a[2] + 3); //打印出推荐结果(可保底，第三行)
					schs[2] = f_sch;
					majs[2] = f_maj;
					flag2 = i;
					flag1 = 0;
					f_maj = 0;
					f_sch = 0;
					tmp_quality = 20;

					break;
				} 
				
				else if(i==l-1&&*nb!=1)
				{
					puthz(123 + 52, a[2] + 3, "暂无", 24, 26, YELLOW);

					schs[0] = f_sch;
					majs[0] = f_maj;

					flag2 = 0;
					flag1 = 0;
					f_maj = 0;
					f_sch = 0;
					tmp_quality = 20;
					*cb2 = 2;					
				}								
								
				else {
					continue;
				}
			}


			/*第三轮筛选，选出可冲刺*/
			for (i = 0; i < l; i++) {
				sch = indices2[i] / 3;
				maj = indices2[i] % 3 + 9;

				if (user_range > school[sch].rangeh[maj] && flag1 < s) {
					flag1++;
					if (tmp_quality >= school[sch].major_quality[maj]) {
						tmp_quality = school[sch].major_quality[maj];
						f_sch = sch;
						f_maj = maj;
					}
				}

				else if (flag1 == s) {
					display(f_sch, f_maj, 123 + 52, a[0] + 3); //打印出推荐结果(可冲刺，第一行)
					schs[0] = f_sch;
					majs[0] = f_maj;
					flag2 = 0;
					flag1 = 0;
					f_maj = 0;
					f_sch = 0;
					tmp_quality = 20;

					break;
				}

				/*4.15改*/
				else if (i == l - 1) {
					puthz(123 + 52, a[0] + 3, "您已无敌，无需冲刺", 24, 26, YELLOW);

					schs[0] = f_sch;
					majs[0] = f_maj;

					flag2 = 0;
					flag1 = 0;
					f_maj = 0;
					f_sch = 0;
					tmp_quality = 20;
					*nb = 1;
				}

				else {
					continue;
				}
			}
		}



		/*地区=2*/
		if (choice == 2) {
			/*第一轮筛选，选出较稳妥*/
			for (i = 0; i < l; i++) {
				sch = indices2[i] / 3;
				maj = indices2[i] % 3 + 9;

				if (user_range <= school[sch].rangeh[maj] && flag1 < s) { //读取小于user_range的s*2个数，并比较地区的好坏，选出其中地区人均工资最高者
					flag1++;
					if (tmp_region >= school[sch].region) {
						tmp_region = school[sch].region;
						f_sch = sch;
						f_maj = maj;
					}
				}

				else if (flag1 == s) {
					display(f_sch, f_maj, 123 + 52, a[1] + 3); //打印出推荐结果(较稳妥，第二行)
					schs[1] = f_sch;
					majs[1] = f_maj;
					flag2 = i;
					flag1 = 0;
					f_maj = 0;
					f_sch = 0;
					tmp_region = 20;

					break;
				}
				else if(i==l-1&&*nb!=1)
				{
					puthz(123 + 52, a[1] + 3, "暂无", 24, 26, YELLOW);

					schs[0] = f_sch;
					majs[0] = f_maj;

					flag2 = 0;
					flag1 = 0;
					f_maj = 0;
					f_sch = 0;
					tmp_quality = 20;
					*cb = 2;					
				}
				else {
					continue;
				}
			}



			/*第二轮筛选，选出可保底*/
			for (i = flag2 + 1; i < l; i++) {
				sch = indices2[i] / 3;
				maj = indices2[i] % 3 + 9;

				if (user_range <= school[sch].rangeh[maj] && flag1 < s) {
					flag1++;
					if (tmp_region >= school[sch].region) {
						tmp_region = school[sch].region;
						f_sch = sch;
						f_maj = maj;
					}
				}

				else if (flag1 == s) {
					display(f_sch, f_maj, 123 + 52, a[2] + 3); //打印出推荐结果(可保底，第三行)
					schs[2] = f_sch;
					majs[2] = f_maj;
					flag2 = i;
					flag1 = 0;
					f_maj = 0;
					f_sch = 0;
					tmp_region = 20;

					break;
				} 
				else if(i==l-1&&*nb!=1)
				{
					puthz(123 + 52, a[2] + 3, "暂无", 24, 26, YELLOW);

					schs[0] = f_sch;
					majs[0] = f_maj;

					flag2 = 0;
					flag1 = 0;
					f_maj = 0;
					f_sch = 0;
					tmp_quality = 20;
					*cb2 = 2;					
				}								
								
				
				else {
					continue;
				}
			}


			/*第三轮筛选，选出可冲刺*/
			for (i = 0; i < l; i++) {
				sch = indices2[i] / 3;
				maj = indices2[i] % 3 + 9;

				if (user_range > school[sch].rangeh[maj] && flag1 < s) {
					flag1++;
					if (tmp_region >= school[sch].region) {
						tmp_region = school[sch].region;
						f_sch = sch;
						f_maj = maj;
					}
				}

				else if (flag1 == s) {
					display(f_sch, f_maj, 123 + 52, a[0] + 3); //打印出推荐结果(可冲刺，第一行)
					schs[0] = f_sch;
					majs[0] = f_maj;
					flag2 = 0;
					flag1 = 0;
					f_maj = 0;
					f_sch = 0;
					tmp_region = 20;

					break;
				}

				/*4.15改*/
				else if (i == l - 1) {
					puthz(123 + 52, a[0] + 3, "您已无敌，无需冲刺", 24, 26, YELLOW);

					schs[0] = f_sch;
					majs[0] = f_maj;

					flag2 = 0;
					flag1 = 0;
					f_maj = 0;
					f_sch = 0;
					tmp_quality = 20;
					*nb = 1;
				}

				else {
					continue;
				}
			}
		}


		/*专业前景=3*/
		if (choice == 3) {
			/*第一轮筛选，选出较稳妥*/
			for (i = 0; i < l; i++) {
				sch = indices2[i] / 3;
				maj = indices2[i] % 3 + 9;

				if (user_range <= school[sch].rangeh[maj] && flag1 < s) { //读取小于user_range的s个数，并比较专业的好坏，选出其中学科评估等级最优者
					flag1++;
					if (tmp_salary >= school[sch].salary[maj]) {
						tmp_salary = school[sch].salary[maj];
						f_sch = sch;
						f_maj = maj;
					}
				}

				else if (flag1 == s) {
					display(f_sch, f_maj, 123 + 52, a[1] + 3); //打印出推荐结果(较稳妥，第二行)
					schs[1] = f_sch;
					majs[1] = f_maj;
					flag2 = i;
					flag1 = 0;
					f_maj = 0;
					f_sch = 0;
					tmp_salary = 20;

					break;
				}
				else if(i==l-1&&*nb!=1)
				{
					puthz(123 + 52, a[1] + 3, "暂无", 24, 26, YELLOW);

					schs[0] = f_sch;
					majs[0] = f_maj;

					flag2 = 0;
					flag1 = 0;
					f_maj = 0;
					f_sch = 0;
					tmp_quality = 20;
					*cb = 2;					
				}
				else {
					continue;
				}
			}



			/*第二轮筛选，选出可保底*/
			for (i = flag2 + 1; i < l; i++) {
				sch = indices2[i] / 3;
				maj = indices2[i] % 3 + 9;

				if (user_range <= school[sch].rangeh[maj] && flag1 < s) {
					flag1++;
					if (tmp_salary >= school[sch].salary[maj]) {
						tmp_salary = school[sch].salary[maj];
						f_sch = sch;
						f_maj = maj;
					}
				}

				else if (flag1 == s) {
					display(f_sch, f_maj, 123 + 52, a[2] + 3); //打印出推荐结果(可保底，第三行)
					schs[2] = f_sch;
					majs[2] = f_maj;
					flag2 = i;
					flag1 = 0;
					f_maj = 0;
					f_sch = 0;
					tmp_salary = 20;

					break;
				}
				
				else if(i==l-1&&*nb!=1)
				{
					puthz(123 + 52, a[2] + 3, "暂无", 24, 26, YELLOW);

					schs[0] = f_sch;
					majs[0] = f_maj;

					flag2 = 0;
					flag1 = 0;
					f_maj = 0;
					f_sch = 0;
					tmp_quality = 20;
					*cb2 = 2;					
				}								
								
				 else {
					continue;
				}
			}


			/*第三轮筛选，选出可冲刺*/
			for (i = 0; i < l; i++) {
				sch = indices2[i] / 3;
				maj = indices2[i] % 3 + 9;

				if (user_range > school[sch].rangeh[maj] && flag1 < s) {
					flag1++;
					if (tmp_salary >= school[sch].salary[maj]) {
						tmp_salary = school[sch].salary[maj];
						f_sch = sch;
						f_maj = maj;
					}
				}

				else if (flag1 == s) {
					display(f_sch, f_maj, 123 + 52, a[0] + 3); //打印出推荐结果(可冲刺，第一行)
					schs[0] = f_sch;
					majs[0] = f_maj;
					flag2 = 0;
					flag1 = 0;
					f_maj = 0;
					f_sch = 0;
					tmp_salary = 20;

					break;
				}

				/*4.15改*/
				else if (i == l - 1) {
					puthz(123 + 52, a[0] + 3, "您已无敌，无需冲刺", 24, 26, YELLOW);

					schs[0] = f_sch;
					majs[0] = f_maj;

					flag2 = 0;
					flag1 = 0;
					f_maj = 0;
					f_sch = 0;
					tmp_quality = 20;
					*nb = 1;
				}

				else {
					continue;
				}
			}
		}
	}


}
