#include"common.h"
#include"function.h"
#include"display.h"
#include"funcknn.h"
#include"person.h"


void funcknn(struct U *user,PERSON person[2][10][12][10],int *schs,int *majs)
{
	int indices1[900]={0};  //伪指针
	int indices2[300]={0};  //伪指针
	int i=0,j=0,k=0,l=0,t=0;
	int num=40;
	int min_idx=0;      //最小距离的标号，用于排序
	int distances1[900]={0};  //用于存放所有点到用户数据点的距离
	int distances2[300]={0};
	int label1[10][9]={0};    //用于计数距离最近的num个样本各自的学校专业出现的次数，如清华大学人工智能代表label[0][0]，若出现一次则label[0][0]加一
	int label2[10][3]={0};
	int sch=0;
	int maj=0;
	int xmax1=0,ymax1=0;   //记录最大label的坐标
	int xmax2=0,ymax2=0;
	int xmax3=0,ymax3=0;
					
	int provin=0;
	int user_range=0;
	provin=str_to_int(user->province);
	user_range=str_to_int(user->range);
//	user->choose=4;
//	schs=(int*)malloc(sizeof(int*));
//	majs=(int*)malloc(sizeof(int*));	
	
	input_person(person);
	
	
//理科	
if(user->choose==1||user->choose==2||user->choose==3){		
	t=0;
	xmax1=0,ymax1=0;   //记录最大label的坐标
	xmax2=0,ymax2=0;
	xmax3=0,ymax3=0;
/***********************排序*************************/	

	for(j=0;j<10;j++)
	{
		for(k=0;k<9;k++)
		{
			for(l=0;l<10;l++)
			{
				distances1[t]=distance(person[provin-1][j][k][l].range,user_range);
				t++;					
			}	
		}
	}


	for(i=0;i<900;i++)
	{
		indices1[i]=i;
	}	
	
	for(i=0;i<899;i++)
	{
		min_idx=i;
		
		for(j=i+1;j<900;j++)
		{
			if(distances1[j]<distances1[min_idx])
			{
				min_idx=j;
			}
		}	
		
		swap(&distances1[i], &distances1[min_idx]);
	    swap(&indices1[i], &indices1[min_idx]);   //如此一来，indices的最前面num项就是对距离从小到大排列
	}	
	
	

	for(i=0;i<num;i++)
	{
		sch=indices1[i]/90;
		maj=(indices1[i]%90)/10;
		label1[sch][maj]++;
	}	
	
	
	
	for(i=0;i<10;i++)
	{
		for(j=0;j<9;j++)
		{
			if(label1[xmax1][ymax1]<=label1[i][j])
			{
				xmax1=i;
				ymax1=j;
			}
		}
	}	
	
	
	for(i=0;i<10;i++)
	{
		for(j=0;j<9;j++)
		{
			if(!(i==xmax1&&j==ymax1)&&label1[xmax2][ymax2]<=label1[i][j])
			{
				xmax2=i;
				ymax2=j;
			}
		}
	}	
	
	
	for(i=0;i<10;i++)
	{
		for(j=0;j<9;j++)
		{
			if(!(i==xmax1&&j==ymax1) && !(i==xmax2&&j==ymax2) && label1[xmax3][ymax3]<=label1[i][j])
			{
				xmax3=i;
				ymax3=j;
			}
		}
	}	
	
	
	display(xmax1,ymax1,123+52,100+30+3);
	display(xmax2,ymax2,123+52,182+3);	
	display(xmax3,ymax3,123+52,204+30+3);	
	
	schs[0]=xmax1;
	majs[0]=ymax1;
	schs[1]=xmax2;
	majs[1]=ymax2;
	schs[2]=xmax3;
	majs[2]=ymax3;
//	memset(label1,0,sizeof(int)*90);
}




//文科	

if(user->choose==4||user->choose==5||user->choose==6){		
	xmax1=0,ymax1=9;   //记录最大label的坐标
	xmax2=0,ymax2=9;
	xmax3=0,ymax3=9;
/***********************排序*************************/	
	t=0;
	
	for(j=0;j<10;j++)
	{
		for(k=9;k<12;k++)
		{
			for(l=0;l<10;l++)
			{
				distances2[t]=distance(person[provin-1][j][k][l].range,user_range);
				t++;					
			}	
		}
	}


	for(i=0;i<300;i++)
	{
		indices2[i]=i;
	}	
	
	for(i=0;i<299;i++)
	{
		min_idx=i;
		
		for(j=i+1;j<300;j++)
		{
			if(distances2[j]<distances2[min_idx])
			{
				min_idx=j;
			}
		}	
		
		swap(&distances2[i], &distances2[min_idx]);
	    swap(&indices2[i], &indices2[min_idx]);   //如此一来，indices的最前面num项就是对距离从小到大排列
	}	
	

	for(i=0;i<num;i++)
	{
		sch=indices2[i]/30;
		maj=(indices2[i]%30)/10;
		label2[sch][maj]++;
	}	
	
	
	for(i=0;i<10;i++)
	{
		for(j=9;j<12;j++)
		{
			if(label2[xmax1][ymax1-9]<=label2[i][j-9])
			{
				xmax1=i;
				ymax1=j;
			}
		}
	}


	for(i=0;i<10;i++)
	{
		for(j=9;j<12;j++)
		{
			if(!(i==xmax1&&j==ymax1)&&label2[xmax2][ymax2-9]<=label2[i][j-9])
			{
				xmax2=i;
				ymax2=j;
			}
		}
	}	
	
	
	for(i=0;i<10;i++)
	{
		for(j=9;j<12;j++)
		{
			if(!(i==xmax1&&j==ymax1) && !(i==xmax2&&j==ymax2) && label2[xmax3][ymax3-9]<=label2[i][j-9])
			{
				xmax3=i;
				ymax3=j;
			}
		}
	}	
	
	
	display(xmax1,ymax1,123+52,100+30+3);
	display(xmax2,ymax2,123+52,182+3);	
	display(xmax3,ymax3,123+52,204+30+3);	
	
	schs[0]=xmax1;
	majs[0]=ymax1;
	schs[1]=xmax2;
	majs[1]=ymax2;
	schs[2]=xmax3;
	majs[2]=ymax3;	
//	memset(label1,0,sizeof(int)*30);
}
}
