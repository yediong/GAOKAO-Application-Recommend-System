#include"common.h"
#include"school.h"

void input_school(struct S school[10])
{
	int i=0,j=0;
	char tmp;
	FILE *fp = NULL;

	for(i=0;i<10;i++)
	{
		school[i].name=0;
		school[i].region=0;
	}


	if ((fp = fopen("C:\\test\\Database\\school.txt", "rb+")) == NULL)        //用相对路径就读不了
		{
			printf("file cannot be opened222\n");
		}	
		
	for(i=0;i<10;i++){
		school[i].name=i+1;      //设置大学名字编号:1.清华大学 2.北京大学 3.浙江大学 4.上海交通大学 5.复旦大学 6.南京大学 7.中国科学技术大学 8.华中科技大学 9.武汉大学 10.西安交通大学
		
		for(j=0;j<12;j++)
		{		
			fscanf(fp,"%c",&tmp);
			fscanf(fp,"%d",&school[i].major[j]);							
		}
		
		for(j=0;j<12;j++)
		{
			fscanf(fp,"%c",&tmp);
			fscanf(fp,"%d",&school[i].major_quality[j]);			
		}

			fscanf(fp,"%c",&tmp);
			fscanf(fp,"%d",&school[i].region);	
			
		for(j=0;j<12;j++)
		{
			fscanf(fp,"%c",&tmp);
			fscanf(fp,"%d",&school[i].salary[j]);						
		}					
		
		for(j=0;j<12;j++)
		{
			fscanf(fp,"%c",&tmp);
			fscanf(fp,"%d",&school[i].rangej[j]);						
		}
		
		for(j=0;j<12;j++)
		{
			fscanf(fp,"%c",&tmp);
			fscanf(fp,"%d",&school[i].rangeh[j]);						
		}		
	}
	
	if (fclose(fp) != 0)
	{
		printf("\n cannot close datatabase.");
	}


}
