#include"common.h"
#include"pages.h"
#include"proba.h"

int psubject(int(* subjectchoice)[20],int *college,int* click,int* sign, int(*sign1)[20], int* sign2,int*flag2,int probability[4][4],int* university,struct U *user,PERSON person[2][10][12][10])
{
	int i=0,j=0;
	int flag=0;
	char *prochar[4][4];
	int schnum=0;
	psubjectscreen();	
	clrmous(MouseX,MouseY);
	delay(100);
	*flag2=0;
//	memset(prochar,"0",sizeof(char));
	
	for(i=0;i<4;i++)
	{
		if(*college==university[i])
		{
			schnum=i;
			break;
		}
	}
	

		mouseinit();
		
		
	while(1)
	{
	    if(flag==0)
		{  
		  if(click[*college]>=0&&*sign2==0&&click[*college]<=4){
    	 	if(*sign>=0)
    	 	{
    	 		setfillstyle(1,WHITE);
    	 		bar(50,100,590,430);
			 }
		
        	
		        for(i=0;i<click[*college];i++)
	          {
	          	setlinestyle(0,0,3);
            	setcolor(BLACK);
	            line(50+230,100,50+230,430);
	            line(500,100,500,430);
	            rectangle(270,100,290,110);
	            rectangle(270,420,290,430);
	            rectangle(490,100,510,110);
	            rectangle(490,420,510,430);
	            rectangle(50,100,590,430);
	          	setfillstyle(1,LIGHTGRAY);
		        bar(50+250,100+40+55*i,300+180,100+40+30+55*i);
		        setcolor(RED);
		        rectangle(50+250,100+40+55*i,300+180,100+40+30+55*i);
		        setcolor(RED);
				setlinestyle(0,0,3);
		        pieslice(50+120,100+40+15+55*i,0,360,20);
		        line(50+105,100+40+15+55*i,50+135,+100+40+15+55*i);
						
	          }
	            setfillstyle(1,LIGHTGRAY);
	            bar(50+250,100+40+55*(click[*college]),300+180,100+40+30+55*(click[*college]));
	            setcolor(YELLOW);
	            rectangle(50+250,100+40+55*(click[*college]),300+180,100+40+30+55*(click[*college]));
	            puthz(50+280,100+45+55*(click[*college]),"选择专业",24,30,BLUE);
	            *sign2=1;
         	}
	    
	    
	    if(click[*college]>4&&*sign2==0)
		
		{
			clrmous(MouseX,MouseY);
			click[*college]=click[*college]-1;
			setfillstyle(1,BLUE);
        	bar(80,120,220,150);
			puthz(90,125,"学科已满",24,30,RED);
        	delay(1500);
        	setfillstyle(1,WHITE);
        	bar(80,120,220,150);
        	*sign2=0;
        	return 17;
		}
	    if(click[*college]<=4)
	{
		for(i=0;i<click[*college];i++)
	     {
		     if(subjectchoice[*college][i]==1)
		    {
			puthz(50+280,100+45+55*i,"人工智能",24,30,YELLOW);
		    }
		     else if(subjectchoice[*college][i]==2)
		    {
		    puthz(50+280,100+45+55*i,"计算机",24,35,YELLOW);
		    }
		    else if(subjectchoice[*college][i]==3)
		    {
		    puthz(50+280,100+45+55*i,"自动化",24,35,YELLOW);
		    }
		    else if(subjectchoice[*college][i]==4)
		    {
		    puthz(50+280,100+45+55*i,"电气工程",24,30,YELLOW);
		    }
		    else if(subjectchoice[*college][i]==5)
		    {
		    puthz(50+280,100+45+55*i,"临床医学",24,30,YELLOW);
		    }
		    else if(subjectchoice[*college][i]==6)
		    {
		    puthz(50+280,100+45+55*i,"数学学科",24,30,YELLOW);
	     	}
		    else if(subjectchoice[*college][i]==7)
	    	{
		    puthz(50+280,100+45+55*i,"物理学科",24,30,YELLOW);
		    }
	    	else if(subjectchoice[*college][i]==8)
		    {
		    puthz(50+280,100+45+55*i,"能源工程",24,30,YELLOW);
	    	}
		    else if(subjectchoice[*college][i]==9)
		    {
		    puthz(50+280,100+45+55*i,"机械制造",24,30,YELLOW);
	    	}
		    else if(subjectchoice[*college][i]==10)
		    {
		    puthz(50+280,100+45+55*i,"法学学科",24,30,YELLOW);
	    	}
	    	else if(subjectchoice[*college][i]==11)
	    	{
	    	puthz(50+280,100+45+55*i,"语言学科",24,30,YELLOW);
			}
			else if(subjectchoice[*college][i]==12)
			{
			puthz(50+280,100+45+55*i,"哲学学科",24,30,YELLOW);
			}
		
	     }
	    
	}	/****************************************************************/
		   
		}
	
	
	
	newmouse(&MouseX,&MouseY,&press);
    	if(flag==0)
    	{
    		if(mouse_press(50+100,100+35 ,50+140,100+40+35)==1&&click[*college]>=1)
				{
					
					*sign=0;
					
					click[*college]=click[*college]-1;       
					*sign2=0;
					refreshsubject(sign1,subjectchoice,sign,college);
					cancelsubject(sign,subjectchoice,click, college);
					clrmous(MouseX,MouseY);
					delay(100);
					
					
				}
			else if(mouse_press(50+100,100+35+55 ,50+140,100+40+35+55)==1&&click[*college]>=2)    
			
				{
					
					*sign=1;
					
					click[*college]=click[*college]-1;      
					*sign2=0;
					refreshsubject(sign1,subjectchoice,sign,college);
					cancelsubject(sign,subjectchoice,click, college);
					clrmous(MouseX,MouseY);
					delay(100);
					
				}
			else if(mouse_press(50+100,100+35+55*2 ,50+140,100+40+35+55*2)==1&&click[*college]>=3)
				{
					
					*sign=2;
					
					click[*college]=click[*college]-1;    
					*sign2=0;
					refreshsubject(sign1,subjectchoice,sign,college);
					cancelsubject(sign,subjectchoice,click, college);
					clrmous(MouseX,MouseY);
					delay(100);
					
				
				}
			else if(mouse_press(50+100,100+35+55*3 ,50+140,100+40+35+55*3)==1&&click[*college]>=4)
				{
					
					*sign=3;
					
					click[*college]=click[*college]-1;       
					*sign2=0;
				    refreshsubject(sign1,subjectchoice,sign,college);
					cancelsubject(sign,subjectchoice,click, college);
					clrmous(MouseX,MouseY);
					delay(100);
					
				}
			
			
			
    		if(mouse_press(50+200,100+40+55*(click[*college]),300+180,100+40+30+55*(click[*college]))==1)
    		{
    			clrmous(MouseX,MouseY);
    			return 21;
			}
    		else if(mouse_press(5,5,20,20) == 1)//鼠标在返回框中，且点击
			{
				clrmous(MouseX,MouseY);
				*sign2=0;
				return 15;
				
					
			}
			
		}
		
		
		
		if(mouse_press(430,40,550,80)==1&&flag==0)	
		{
			delay(100);
			clrmous(MouseX,MouseY);
			probable(probability,subjectchoice,university,person, user);
			setlinestyle(0,0,1);
			setfillstyle(1,DARKGRAY);
			bar(100,40,220,80);
			puthz(110,50,"继续选择",24,25,GREEN);
			setcolor(CYAN);
			rectangle(100,40,220,80);	
			
			setfillstyle(1,LIGHTBLUE);
			bar(429,39,551,81);
			
			flag=1;	
			
		
		
		
//		for(i=0;i<4;i++)
//		{
			for(j=0;j<4;j++)
			{
//				prochar[*college][j]=itoa(probability[*college][j]);
//				itoa(probability[*college][j],prochar[*college][j],10);
				if(subjectchoice[*college][j]!=0)
				{
					prochar[schnum][j]=int_to_string(probability[schnum][j]);
				}
			}
			
//		}
		
		
		
//		for(i=0;i<4;i++)
//		{
			for(j=0;j<4;j++)
			{
				if(subjectchoice[*college][j]!=0)
				{
//					itoa(13,prochar[*college][j],10);			itoa有大问题
					outtextxy(505,100+45+55*j,prochar[schnum][j]);
					outtextxy(505+40+2,100+45+55*j,"%");
				}
			}
//		}
			
			
			
		}	
		
		if(mouse_press(100,40,220,80)==1&&flag==1)	
		{
			delay(100);
			clrmous(MouseX,MouseY);			
			setlinestyle(0,0,1);
			setfillstyle(1,DARKGRAY);
			bar(430,40,550,80);
			puthz(440,50,"查看概率",24,25,RED);
			setcolor(CYAN);
			rectangle(430,40,550,80);	
			
			setfillstyle(1,LIGHTBLUE);
			bar(99,39,221,81);			
			
			
			setfillstyle(1,WHITE);
			bar(505,115,570,415);
			flag=0;	
		}			
			
   }   
	
}



char* int_to_string(int num) {
    int digit = 0, temp = num;
    char* str;
    // 计算数字位数
    while (temp) {
        digit++;
        temp /= 10;
    }
    // 分配字符串内存并将数字转化为字符串
    str = (char*)malloc(sizeof(char) * (digit + 1));
    sprintf(str, "%d", num);
    return str;
}





/*****function:使被删除的学科在这一大学中能够重新被选*****/
void refreshsubject(int(*sign1)[20],int(*subjectchoice)[20],int*sign,int*college)
{
	int i,j,k;
	i=*sign;
	k=*college;
	j=subjectchoice[k][i];
	*(sign1[k]+j)=0;

	
}




/*****function:删减sign指定的学科*****/
void cancelsubject(int*sign,int(*subjectchoice)[20],int*click,int*college)
{
	int i,j,temp;
	j=*college;
	temp=click[*college];
	for(i=*sign;i<click[*college];i++)
	{
		subjectchoice[j][i]=subjectchoice[j][i+1];
	}
	subjectchoice[j][temp]=0;
}
	    
		
	
	




void psubjectscreen(void)
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
	setlinestyle(0,0,1);
	setfillstyle(1,DARKGRAY);
	bar(235,40,405,80);
	puthz(245,50,"模拟专业选择",24,25,RED);
	setcolor(CYAN);
	rectangle(235,40,405,80);
	
	
	
	setcolor(RED);
	rectangle(50,100,590,430);
	setlinestyle(0,0,3);
	setcolor(BLACK);
	line(50+230,100,50+230,430);
	setfillstyle(1,WHITE);
	bar(52,102,588,428);
	setlinestyle(0,0,3);
	setcolor(BLACK);
	line(50+230,100,50+230,430);
	setcolor(RED);
	setlinestyle(0,0,3);
	setfillstyle(1,LIGHTBLUE);
	
	
		setlinestyle(0,0,1);
		setfillstyle(1,DARKGRAY);
		bar(430,40,550,80);
		puthz(440,50,"录取概率",24,25,RED);
		setcolor(CYAN);
		rectangle(430,40,550,80);
	
	
	
	
}
