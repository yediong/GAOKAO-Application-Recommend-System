#include"common.h"
#include"person.h"

void input_person(PERSON person[2][10][12][10])
{
	int i=0,j=0,k=0,l=0;
	char tmp;
	FILE *fp = NULL;
//	school= (struct S *)malloc(sizeof(struct S));    //用数组？

	for(i=0;i<2;i++)
	{
		for(j=0;j<10;j++)
		{
			for(k=0;k<12;k++)
			{
				for(l=0;l<10;l++)
				{
					person[i][j][k][l].name=0;
					person[i][j][k][l].major=0;
					person[i][j][k][l].range=0;
				}
			}
		}
	}


	if ((fp = fopen("C:\\test\\Database\\person.txt", "rb+")) == NULL)        //用相对路径就读不了
		{
			printf("file cannot be opened222\n");
		}	
		
				
	for(i=0;i<2;i++)
	{
		for(j=0;j<10;j++)
		{
			for(k=0;k<12;k++)
			{
				for(l=0;l<10;l++)
				{
				person[i][j][k][l].name=j;					
				person[i][j][k][l].major=k;
				fscanf(fp,"%c",&tmp);          //可能用不到
				fscanf(fp,"%d",&person[i][j][k][l].range);	
				}								
			}
		}
	}	
		
		
	if (fclose(fp) != 0)
	{
		printf("\n cannot close datatabase.");
	}


}		
