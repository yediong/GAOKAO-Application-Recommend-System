#include"common.h"
#include"pageb.h"

int pb(int school,int choice)
{
	
	int v[16] ={5,13,15,5,15,8,20,8,20,17,15,17,15,20,5,13};

	FILE* fp=NULL;
	char current[5000]={'0'};
	/*int page,flag;
	page=1;
	flag=0;*/

	clrmous(MouseX,MouseY);	
	pbscreen();	
	clrmous(MouseX,MouseY);
	delay(100);
		mouseinit();
	if(school==1&&choice==1)
	{
		puthz(260,70,"基本介绍",24,30,LIGHTRED);
		if((fp=fopen("C:\\test\\Database\\jbjs1.dat","rb+"))==NULL)
			{
				printf("cnnot open the file\n");
				closegraph();
				
			}
			fread(current,sizeof(char),1000,fp);
			fclose(fp);
			puthz(75,145,current,16,16,WHITE);
	 
	}
	else if(school==1&&choice==2)
	{
		puthz(260,70,"录取分数",24,30,LIGHTRED);
		if((fp=fopen("C:\\test\\Database\\luqu1.dat","rb+"))==NULL)
			{
				printf("cnnot open the file\n");
				closegraph();
				
			}
			fread(current,sizeof(char),1000,fp);
			fclose(fp);
			puthz(75,145,current,16,16,WHITE);
	}
	else if(school==1&&choice==3)
	{
		puthz(260,70,"学校档次",24,30,LIGHTRED);
		if((fp=fopen("C:\\test\\Database\\danci1.dat","rb+"))==NULL)
			{
				printf("cnnot open the file\n");
				closegraph();
				
			}
			fread(current,sizeof(char),1000,fp);
			fclose(fp);
			puthz(75,145,current,16,16,WHITE);
	}
	else if(school==1&&choice==4)
	{
		puthz(260,70,"优势学科",24,30,LIGHTRED);
		if((fp=fopen("C:\\test\\Database\\youshi1.dat","rb+"))==NULL)
			{
				printf("cnnot open the file\n");
				closegraph();
				
			}
			fread(current,sizeof(char),1000,fp);
			fclose(fp);
			puthz(75,145,current,16,16,WHITE);
	}
	else if(school==2&&choice==1)
	{
		puthz(260,70,"基本介绍",24,30,LIGHTRED);
		if((fp=fopen("C:\\test\\Database\\jbjs2.dat","rb+"))==NULL)
			{
				printf("cnnot open the file\n");
				closegraph();
				
			}
			fread(current,sizeof(char),1000,fp);
			fclose(fp);
			puthz(75,145,current,16,16,WHITE);
	}
	else if(school==2&&choice==2)
	{
		puthz(260,70,"录取分数",24,30,LIGHTRED);
		 if((fp=fopen("C:\\test\\Database\\luqu2.dat","rb+"))==NULL)
			{
				printf("cnnot open the file\n");
				closegraph();
				
			}
			fread(current,sizeof(char),1000,fp);
			fclose(fp);
			puthz(75,145,current,16,16,WHITE);
	}
	else if(school==2&&choice==3)
	{
		puthz(260,70,"学校档次",24,30,LIGHTRED);
		 if((fp=fopen("C:\\test\\Database\\danci2.dat","rb+"))==NULL)
			{
				printf("cnnot open the file\n");
				closegraph();
				
			}
			fread(current,sizeof(char),1000,fp);
			fclose(fp);
			puthz(75,145,current,16,16,WHITE);
	}
	else if(school==2&&choice==4)
	{
		puthz(260,70,"优势学科",24,30,LIGHTRED);
		 if((fp=fopen("C:\\test\\Database\\youshi2.dat","rb+"))==NULL)
			{
				printf("cnnot open the file\n");
				closegraph();
				
			}
			fread(current,sizeof(char),1000,fp);
			fclose(fp);
			puthz(75,145,current,16,16,WHITE);
	}
	else if(school==3&&choice==1)
	{
		puthz(260,70,"基本介绍",24,30,LIGHTRED);
		if((fp=fopen("C:\\test\\Database\\jbjs3.dat","rb+"))==NULL)
			{
				printf("cnnot open the file\n");
				closegraph();
				
			}
			fread(current,sizeof(char),1000,fp);
			fclose(fp);
			puthz(75,145,current,16,16,WHITE);
	}
	else if(school==3&&choice==2)
	{
		puthz(260,70,"录取分数",24,30,LIGHTRED);
		if((fp=fopen("C:\\test\\Database\\luqu3.dat","rb+"))==NULL)
			{
				printf("cnnot open the file\n");
				closegraph();
				
			}
			fread(current,sizeof(char),1000,fp);
			fclose(fp);
			puthz(75,145,current,16,16,WHITE);
	}
	else if(school==3&&choice==3)
	{
		puthz(260,70,"学校档次",24,30,LIGHTRED);
		if((fp=fopen("C:\\test\\Database\\danci3.dat","rb+"))==NULL)
			{
				printf("cnnot open the file\n");
				closegraph();
				
			}
			fread(current,sizeof(char),1000,fp);
			fclose(fp);
			puthz(75,145,current,16,16,WHITE);
	}
	else if(school==3&&choice==4)
	{
		puthz(260,70,"优势学科",24,30,LIGHTRED);
		if((fp=fopen("C:\\test\\Database\\youshi3.dat","rb+"))==NULL)
			{
				printf("cnnot open the file\n");
				closegraph();
				
			}
			fread(current,sizeof(char),1000,fp);
			fclose(fp);
			puthz(75,145,current,16,16,WHITE);
	}
	
	
	else if(school==4&&choice==1)
	{
		puthz(260,70,"基本介绍",24,30,LIGHTRED);
		if((fp=fopen("C:\\test\\Database\\jbjs4.dat","rb+"))==NULL)
			{
				printf("cnnot open the file\n");
				closegraph();
				
			}
			fread(current,sizeof(char),1000,fp);
			fclose(fp);
			puthz(75,145,current,16,16,WHITE);
	}
	else if(school==4&&choice==2)
	{
		puthz(260,70,"录取分数",24,30,LIGHTRED);
		if((fp=fopen("C:\\test\\Database\\luqu4.dat","rb+"))==NULL)
			{
				printf("cnnot open the file\n");
				closegraph();
				
			}
			fread(current,sizeof(char),1000,fp);
			fclose(fp);
			puthz(75,145,current,16,16,WHITE);
	}
	else if(school==4&&choice==3)
	{
		puthz(260,70,"学校档次",24,30,LIGHTRED);
       if((fp=fopen("C:\\test\\Database\\danci4.dat","rb+"))==NULL)
			{
				printf("cnnot open the file\n");
				closegraph();
				
			}
			fread(current,sizeof(char),1000,fp);
			fclose(fp);
			puthz(75,145,current,16,16,WHITE);
	}
	else if(school==4&&choice==4)
	{
		puthz(260,70,"优势学科",24,30,LIGHTRED);
		if((fp=fopen("C:\\test\\Database\\youshi4.dat","rb+"))==NULL)
			{
				printf("cnnot open the file\n");
				closegraph();
				
			}
			fread(current,sizeof(char),1000,fp);
			fclose(fp);
			puthz(75,145,current,16,16,WHITE);
	}
	else if(school==5&&choice==1)
	{
		puthz(260,70,"基本介绍",24,30,LIGHTRED);
		if((fp=fopen("C:\\test\\Database\\jbjs5.dat","rb+"))==NULL)
			{
				printf("cnnot open the file\n");
				closegraph();
				
			}
			fread(current,sizeof(char),1000,fp);
			fclose(fp);
			puthz(75,145,current,16,16,WHITE);
	}
	else if(school==5&&choice==2)
	{
		puthz(260,70,"录取分数",24,30,LIGHTRED);
		if((fp=fopen("C:\\test\\Database\\luqu5.dat","rb+"))==NULL)
			{
				printf("cnnot open the file\n");
				closegraph();
				
			}
			fread(current,sizeof(char),1000,fp);
			fclose(fp);
			puthz(75,145,current,16,16,WHITE);
	}
	else if(school==5&&choice==3)
	{
		puthz(260,70,"学校档次",24,30,LIGHTRED);
		/*if((fp=fopen("C:\\test\\Database\\danci5.dat","rb+"))==NULL)
			{
				printf("cnnot open the file\n");
				closegraph();
				
			}
			fread(current,sizeof(char),1000,fp);
			fclose(fp);*/
			puthz(75,145,"复旦大学拥有世界一流的办学声誉，全球声誉位于三十位至六十位位之间，位于中国大陆第三；在全国第四轮一级学科评估中，学校率先启动建设全国首个”交叉学科“门类一级学科集成电路科学与工程；有十三个个学科入选上海市高峰学科建设。学校致力于以最佳状态持续稳定奉献文明进步，积极落实十七项联合国可体面工作和经济增长等领域中获得全球公认的突出性成就。在教育部一流本科专业建设“双万计划”中，六十一个专业获批国家级一流本科专业建设点。持续发展目标，可持续发展综合影响力位居世界高校前列，并在经济适用的清洁能源和体面工作和经济增长等领域中获得全球公认的突出性成就。在教育部一流本科专业建设“双万计划”中，六十一个专业获批国家级一流本科专业建设点。",16,16,WHITE);
	}
	else if(school==5&&choice==4)
	{
		puthz(260,70,"优势学科",24,30,LIGHTRED);
		 if((fp=fopen("C:\\test\\Database\\youshi5.dat","rb+"))==NULL)
			{
				printf("cnnot open the file\n");
				closegraph();
				
			}
			fread(current,sizeof(char),1000,fp);
			fclose(fp);
			puthz(75,145,current,16,16,WHITE);
	}
	else if(school==6&&choice==1)
	{
		puthz(260,70,"基本介绍",24,30,LIGHTRED);
		if((fp=fopen("C:\\test\\Database\\jbjs6.dat","rb+"))==NULL)
			{
				printf("cnnot open the file\n");
				closegraph();
				
			}
			fread(current,sizeof(char),1000,fp);
			fclose(fp);
			puthz(75,145,current,16,16,WHITE);
	}
	else if(school==6&&choice==2)
	{
			puthz(260,70,"录取分数",24,30,LIGHTRED);
			if((fp=fopen("C:\\test\\Database\\luqu6.dat","rb+"))==NULL)
			{
				printf("cnnot open the file\n");
				closegraph();
				
			}
			fread(current,sizeof(char),1000,fp);
			fclose(fp);
			puthz(75,145,current,16,16,WHITE);
	}
	else if(school==6&&choice==3)
	{
		puthz(260,70,"学校档次",24,30,LIGHTRED);
		if((fp=fopen("C:\\test\\Database\\danci6.dat","rb+"))==NULL)
			{
				printf("cnnot open the file\n");
				closegraph();
				
			}
			fread(current,sizeof(char),1000,fp);
			fclose(fp);
			puthz(75,145,current,16,16,WHITE);
	}
	else if(school==6&&choice==4)
	{
		puthz(260,70,"优势学科",24,30,LIGHTRED);
		if((fp=fopen("C:\\test\\Database\\youshi6.dat","rb+"))==NULL)
			{
				printf("cnnot open the file\n");
				closegraph();
				
			}
			fread(current,sizeof(char),1000,fp);
			fclose(fp);
			puthz(75,145,current,16,16,WHITE);
	}
	else if(school==7&&choice==1)
	{
		puthz(260,70,"基本介绍",24,30,LIGHTRED);
		if((fp=fopen("C:\\test\\Database\\jbjs7.dat","rb+"))==NULL)
			{
				printf("cnnot open the file\n");
				closegraph();
				
			}
			fread(current,sizeof(char),1000,fp);
			fclose(fp);
			puthz(75,145,current,16,16,WHITE);
	}
	else if(school==7&&choice==2)
	{
		puthz(260,70,"录取分数",24,30,LIGHTRED);
		if((fp=fopen("C:\\test\\Database\\luqu7.dat","rb+"))==NULL)
			{
				printf("cnnot open the file\n");
				closegraph();
				
			}
			fread(current,sizeof(char),1000,fp);
			fclose(fp);
			puthz(75,145,current,16,16,WHITE);
	}
	else if(school==7&&choice==3)
	{
		puthz(260,70,"学校档次",24,30,LIGHTRED);
		if((fp=fopen("C:\\test\\Database\\danci7.dat","rb+"))==NULL)
			{
				printf("cnnot open the file\n");
				closegraph();
				
			}
			fread(current,sizeof(char),1000,fp);
			fclose(fp);
			puthz(75,145,current,16,16,WHITE);
	}
	else if(school==7&&choice==4)
	{
		puthz(260,70,"优势学科",24,30,LIGHTRED);
		if((fp=fopen("C:\\test\\Database\\youshi7.dat","rb+"))==NULL)
			{
				printf("cnnot open the file\n");
				closegraph();
				
			}
			fread(current,sizeof(char),1000,fp);
			fclose(fp);
			puthz(75,145,current,16,16,WHITE);
	}
	else if(school==8&&choice==1)
	{
		puthz(260,70,"基本介绍",24,30,LIGHTRED);
		if((fp=fopen("C:\\test\\Database\\jbjs8.dat","rb+"))==NULL)
			{
				printf("cnnot open the file\n");
				closegraph();
				
			}
			fread(current,sizeof(char),1000,fp);
			fclose(fp);
			puthz(75,145,current,16,16,WHITE);
	}
	else if(school==8&&choice==2)
	{
		puthz(260,70,"录取分数",24,30,LIGHTRED);
		if((fp=fopen("C:\\test\\Database\\luqu8.dat","rb+"))==NULL)
			{
				printf("cnnot open the file\n");
				closegraph();
				
			}
			fread(current,sizeof(char),1000,fp);
			fclose(fp);
			puthz(75,145,current,16,16,WHITE);
	}
	else if(school==8&&choice==3)
	{
		puthz(260,70,"学校档次",24,30,LIGHTRED);
		if((fp=fopen("C:\\test\\Database\\danci8.dat","rb+"))==NULL)
			{
				printf("cnnot open the file\n");
				closegraph();
				
			}
			fread(current,sizeof(char),1000,fp);
			fclose(fp);
			puthz(75,145,current,16,16,WHITE);
	}
	else if(school==8&&choice==4)
	{
		puthz(260,70,"优势学科",24,30,LIGHTRED);
		if((fp=fopen("C:\\test\\Database\\youshi8.dat","rb+"))==NULL)
			{
				printf("cnnot open the file\n");
				closegraph();
				
			}
			fread(current,sizeof(char),1000,fp);
			fclose(fp);
			puthz(75,145,current,16,16,WHITE);
	}
	else if(school==9&&choice==1)
	{
		puthz(260,70,"基本介绍",24,30,LIGHTRED);
			if((fp=fopen("C:\\test\\Database\\jbjs9.dat","rb+"))==NULL)
			{
				printf("cnnot open the file\n");
				closegraph();
				
			}
			fread(current,sizeof(char),1000,fp);
			fclose(fp);
			puthz(75,145,current,16,16,WHITE);
	}
	else if(school==9&&choice==2)
	{
		puthz(260,70,"录取分数",24,30,LIGHTRED);
		if((fp=fopen("C:\\test\\Database\\luqu9.dat","rb+"))==NULL)
			{
				printf("cnnot open the file\n");
				closegraph();
				
			}
			fread(current,sizeof(char),1000,fp);
			fclose(fp);
			puthz(75,145,current,16,16,WHITE);
	}
	else if(school==9&&choice==3)
	{
		puthz(260,70,"学校档次",24,30,LIGHTRED);
		if((fp=fopen("C:\\test\\Database\\danci9.dat","rb+"))==NULL)
			{
				printf("cnnot open the file\n");
				closegraph();
				
			}
			fread(current,sizeof(char),1000,fp);
			fclose(fp);
			puthz(75,145,current,16,16,WHITE);
	}
	else if(school==9&&choice==4)
	{
		puthz(260,70,"优势学科",24,30,LIGHTRED);
		if((fp=fopen("C:\\test\\Database\\youshi9.dat","rb+"))==NULL)
			{
				printf("cnnot open the file\n");
				closegraph();
				
			}
			fread(current,sizeof(char),1000,fp);
			fclose(fp);
			puthz(75,145,current,16,16,WHITE);
	}
	else if(school==10&&choice==1)
	{
		puthz(260,70,"基本介绍",24,30,LIGHTRED);
		if((fp=fopen("C:\\test\\Database\\jbjs10.dat","rb+"))==NULL)
			{
				printf("cnnot open the file\n");
				closegraph();
				
			}
			fread(current,sizeof(char),1000,fp);
			fclose(fp);
			puthz(75,145,current,16,16,WHITE);
	}
	else if(school==10&&choice==2)
	{
		puthz(260,70,"录取分数",24,30,LIGHTRED);
		if((fp=fopen("C:\\test\\Database\\luqu10.dat","rb+"))==NULL)
			{
				printf("cnnot open the file\n");
				closegraph();
				
			}
			fread(current,sizeof(char),1000,fp);
			fclose(fp);
			puthz(75,145,current,16,16,WHITE);
	}
	else if(school==10&&choice==3)
	{
		puthz(260,70,"学校档次",24,30,LIGHTRED);
		if((fp=fopen("C:\\test\\Database\\danci10.dat","rb+"))==NULL)
			{
				printf("cnnot open the file\n");
				closegraph();
				
			}
			fread(current,sizeof(char),1000,fp);
			fclose(fp);
			puthz(75,145,current,16,16,WHITE);
	}
	else if(school==10&&choice==4)
	{
		puthz(260,70,"优势学科",24,30,LIGHTRED);
		if((fp=fopen("C:\\test\\Database\\youshi10.dat","rb+"))==NULL)
			{
				printf("cnnot open the file\n");
				closegraph();
				
			}
			fread(current,sizeof(char),1000,fp);
			fclose(fp);
			puthz(75,145,current,16,16,WHITE);
	}
	while(1)
	{
		newmouse(&MouseX,&MouseY,&press);
	    if(mouse_press(5,5,20,20) == 1)//鼠标在登录框中，且点击
		{
			return 9;
			
		}
	}
}
	
	
	
	
	
	
	
	
	
	

	



void pbscreen(void)
{
	int v[16] ={5,13,15,5,15,8,20,8,20,17,15,17,15,20,5,13};
	cleardevice();
	setbkcolor(BLUE);
	setcolor(WHITE);
	setlinestyle(0,0,3);
	rectangle(30,30,610,450);
	setfillstyle(1,LIGHTBLUE);
	rectangle(0,0,25,25);
	fillpoly(8,v);
	bar(30,30,610,450);
	
	setfillstyle(1,DARKGRAY);
	rectangle(240,60,390,100);
	bar(240,60,390,100);
	
	setcolor(YELLOW);
	rectangle(230,50,400,110);
	rectangle(225,45,235,55);
	rectangle(405,115,395,105);
	rectangle(225,105,235,115);
	rectangle(405,45,395,55);
	
	rectangle(60,130,580,420);
	setfillstyle(1,LIGHTGRAY);
	floodfill(65,240,YELLOW);
}
