#include"common.h"
#include"chat.h"
#include"inputhz.h"

int chat(struct C *chater)
{
	int lenhz=0;
	int flag=0;
	char*shit;
	FILE *fp = NULL;
    int len=0; //用户个数
    int i=0;
    struct C *su= (struct C *)malloc(sizeof(struct C));    //暂存从文件中读到的数据
	int click=0;
	
	strcpy(chater->s, "\0");		
	clrmous(MouseX,MouseY);
	delay(100);	
	mouseinit();
	memset(su,'0',sizeof(struct C));



			if ((fp = fopen("C:\\test\\Database\\chater.dat", "rb+")) == NULL)
			{
				printf("file cannot be opened222\n");
				exit(1);
			}	
	
		    fseek(fp, 0, SEEK_END);
		    len = ftell(fp) / sizeof(struct C); //得到结构体的数目
				if (fclose(fp) != 0) {
					printf("\n cannot close datatabase.");
					delay(3000);
					exit(1);
				}						    
		    
		    

	
	while(1)
	{
		newmouse(&MouseX,&MouseY,&press);
		
		
		if(flag==0)
		{
			flag=1;
			
			if ((fp = fopen("C:\\test\\Database\\chater.dat", "rb+")) == NULL)
			{
				printf("file cannot be opened222\n");
				exit(1);
			}	
	
		    fseek(fp, 0, SEEK_END);
		    len = ftell(fp) / sizeof(struct C); //得到结构体的数目
		
				
			delay(10);
			
			
			if(len==0)
			{
				setfillstyle(1,BLUE);
				bar(10,125,590,415);
		
				if (fclose(fp) != 0) {
					printf("\n cannot close datatabase.");
					delay(3000);
					exit(1);
				}				
			}
			
			
			
			else if(len==1)
			{
				setfillstyle(1,BLUE);
				bar(10,125,590,415);				
				
				setfillstyle(1,WHITE);
				bar(30,130,100,200);
				setcolor(GREEN);
				setlinestyle(0,0,3);
				rectangle(30,130,100,200);
				setcolor(BLUE);
				circle(65,155,15);
				line(65,170,65,200);
				setcolor(YELLOW);
				line(100,180,148,180);
				bar(148,170,520,190);
				rectangle(148,170,520,190);
				
				fseek(fp, 0, SEEK_SET);
				fread(su, sizeof(struct C), 1, fp);	
						
				outtextxy(105,135,su->name);
				puthz(150,172,su->s,16,16,BLACK);
				
//				itoa(lenhz,shit,10);
//				outtextxy(300,135,shit);
				
				if (fclose(fp) != 0) {
					printf("\n cannot close datatabase.");
					delay(3000);
					exit(1);
				}				
				
//				free(su);
			}
			
			
			
			else if(len==2)
			{
				setfillstyle(1,BLUE);
				bar(10,125,590,415);				
				
				for(i=0;i<2;i++)
				{
					setfillstyle(1,WHITE);
					bar(30,130+100*i,100,200+100*i);
					setcolor(GREEN);
					setlinestyle(0,0,3);
					rectangle(30,130+100*i,100,200+100*i);
					setcolor(BLUE);
					circle(65,155+100*i,15);
					line(65,170+100*i,65,200+100*i);
					setcolor(YELLOW);
					line(100,180+100*i,148,180+100*i);
					bar(148,170+100*i,520,190+100*i);
					rectangle(148,170+100*i,520,190+100*i);				
				}
				
				fseek(fp, 0, SEEK_SET);
				fread(su, sizeof(struct C), 1, fp);	
						
				outtextxy(105,135,su->name);
				puthz(150,172,su->s,16,16,BLACK);				
				
				fseek(fp, sizeof(struct C), SEEK_SET);
				fread(su, sizeof(struct C), 1, fp);	
						
				outtextxy(105,135+100,su->name);
				puthz(150,172+100,su->s,16,16,BLACK);					
				
				
				
				if (fclose(fp) != 0) {
					printf("\n cannot close datatabase.");
					delay(3000);
					exit(1);
				}		
								
			}
			
			
			else if(len>=3)
			{
				setfillstyle(1,BLUE);
				bar(10,125,590,415);	
							
				for(i=0;i<3;i++)
				{
					setfillstyle(1,WHITE);
					bar(30,130+100*i,100,200+100*i);
					setcolor(GREEN);
					setlinestyle(0,0,3);
					rectangle(30,130+100*i,100,200+100*i);
					setcolor(BLUE);
					circle(65,155+100*i,15);
					line(65,170+100*i,65,200+100*i);
					setcolor(YELLOW);
					line(100,180+100*i,148,180+100*i);
					bar(148,170+100*i,520,190+100*i);
					rectangle(148,170+100*i,520,190+100*i);				
				}					
				
				fseek(fp, (len-1-click)*sizeof(struct C), SEEK_SET);
				fread(su, sizeof(struct C), 1, fp);	
						
				outtextxy(105,135+200,su->name);
				puthz(150,172+200,su->s,16,16,BLACK);					
				
				fseek(fp, (len-2-click)*sizeof(struct C), SEEK_SET);
				fread(su, sizeof(struct C), 1, fp);	
						
				outtextxy(105,135+100,su->name);
				puthz(150,172+100,su->s,16,16,BLACK);						
				
				fseek(fp, (len-3-click)*sizeof(struct C), SEEK_SET);
				fread(su, sizeof(struct C), 1, fp);	
						
				outtextxy(105,135,su->name);
				puthz(150,172,su->s,16,16,BLACK);	
				
				if (fclose(fp) != 0) {
					printf("\n cannot close datatabase.");
					delay(3000);
					exit(1);
				}						
									
			}
			
			
			
		}
		
		
	
		//返回
		if(mouse_press(20,436,72,464)==1)
		{
			free(su);
			return 0;
		}
		
		
		
		
		 else if(mouse_press(320-186,436,320+186,464)==1)
		{
			lenhz=hz_input(320-186,436,320+186/*-240*/,436+35,chater->s,lenhz,WHITE);
//			strcpy(chater->s,temp);
		}
		
		
		
		
		
		else if(mouse_press(578-62,436,630-62,464)==1&&strcmp(chater->s,"\0")!=1)
		{ 
			
			if ((fp = fopen("C:\\test\\Database\\chater.dat", "rb+")) == NULL)
			{
				printf("file cannot be opened222\n");
				exit(1);
			}		
			
		    fseek(fp, 0, SEEK_END);
		    len = ftell(fp) / sizeof(struct C); //得到结构体的数目
//			strcpy(chater->s,"叶庭宏");					
//	    	fseek(fp, len * sizeof(struct C), SEEK_SET);//光标移到最后一个结构体开头
	        fwrite(chater, sizeof(struct C), 1, fp);		
	        flag=0;    
	         
				if (fclose(fp) != 0) {
					printf("\n cannot close datatabase.");
					delay(3000);
					exit(1);
				}					    
			delay(100);
		}		
		
		
	
	
		
		else if(mouse_press(600,30,630,60)==1&&(len-click>3))
		{
			flag=0;
			click++;
			delay(100);
		}
		
		else if(mouse_press(600,380,630,410)==1&&(click>0))
		{
			flag=0;
			click--;
			delay(100);			
		}		

}

}

void chatbk()
{
	cleardevice();
	setbkcolor(BLACK);
	setfillstyle(1,BLUE);
	bar(0,0,640,480);
	setcolor(BROWN);
	setlinestyle(0,0,3);
	rectangle(0,0,640,480);

	//输入框和发送
	setfillstyle(1,WHITE);
	bar(320-186,436,320+186,464);
	setfillstyle(1,YELLOW);
	bar(578-62,436,630-62,464);
	setcolor(YELLOW);
	setlinestyle(0,0,1);
	rectangle(320-186,436,320+186,464);
	rectangle(578-62,436,630-62,464);
	puthz(580-62,438,"发送",24,25,BROWN);
	
	/*滚条和分界线*/
	setfillstyle(1,WHITE);
	bar(600,30,630,60);
	bar(600,380,630,410);	
	bar(600,60,630,380);	
	setcolor(YELLOW);
	line(0,420,640,420);
	setcolor(BLACK);	
	rectangle(600,30,630,60);
	rectangle(600,380,630,410);
	setcolor(BLACK);
	line(605,55,625,55);
	line(625,55,615,35);
	line(615,35,605,55);
	line(605,385,625,385);
	line(625,385,615,405);
	line(615,405,605,385);
	

	bar(20,436,72,464);
	setcolor(BROWN);
	rectangle(20,436,72,464);
	puthz(22,438,"返回",24,26,BLACK);
	
	/*标题*/
	setfillstyle(1,CYAN);
	bar(30,40-15,520,120-15);
	setcolor(YELLOW);
	setlinestyle(0,0,3);
	rectangle(30,40-15,520,120-15);
	puthz(93,56-15,"志愿填报交流室",48,52,BLACK);
	
}
