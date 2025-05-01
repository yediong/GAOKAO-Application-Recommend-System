#include"common.h"
#include"proba.h"

int mininum(int *a)
{
	int i=0;
	int min=a[0];
	for(i=0;i<10;i++)
	{
		if(a[i]<min)
		{
			min=a[i];
		}
	}
	return min;
}


void probable(int probability[4][4],int subjectchoice[20][20],int university[5],PERSON person[2][10][12][10],struct U *user/*,int *sch,int *maj*/)
{
	int i=0,j=0,k=0;
	int user_range=0;
	int provin=0;
	int count=0;
	int a[10]={0};
	int uni=0;
	int sub=0;
	int m=0,n=0;
	
	user_range=atoi(user->range);
	provin=atoi(user->province);
	
	
	for(i=0;i<4;i++)
	{
		
		for(j=0;j<4;j++)
		{
			
			if(subjectchoice[university[i]][j]!=0)
			{
				
				for(k=0;k<10;k++)
				{
					
					uni=university[i]-1;
					sub=subjectchoice[university[i]][j]-1;
					
					m=uni;
					n=sub;
					
					if(user_range<=person[provin][m][n][k].range)   //此处university[i]可能要减一
					{
						count++;
						
					}
					
					a[k]=person[provin][m][n][k].range;
				}
				
/*				if(count!=0)
				{
					maj[*sch]++;
				}
*/				
				if(count>=1&&count<=8)
				{
					probability[i][j]=count*10;
					count=0;
				}
				
				
				else if(count>8)
				{
					probability[i][j]=100;
					count=0;
				}
				
				
				else if(count==0)
				{
					if(abs(user_range-mininum(a))<20)
					{
						probability[i][j]=5;
					}
					else if(abs(user_range-mininum(a))<100)
					{
						probability[i][j]=1;
					}
					else 
					{
						probability[i][j]=0;
					}
				}
				
				
			}
		}
	}
	
	
	
}
