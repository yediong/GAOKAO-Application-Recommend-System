#include"common.h"
#include"pageu.h"
int puniversity(int* university,int *flag,int* count,int* flag2,int*flag1,int*college)
{
	
	int cnt=*count;//s是记录删除次数；
	int i;
	pschoolscreen();	
	clrmous(MouseX,MouseY);
	delay(100);
	

    	mouseinit();
    
    while(1)
    {
        
		
		
    	 if(*count>=0&&*flag2==0&&*count<=4){
    	 	if(*flag>=0)
    	 	{
    	 		setfillstyle(1,WHITE);
    	 		bar(50,100,590,430);
			 }
		
        	
		        for(i=0;i<*count;i++)
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
	            bar(50+250,100+40+55*(*count),300+180,100+40+30+55*(*count));
	            setcolor(YELLOW);
	            setfillstyle(1,LIGHTGRAY);
	            bar(50+250,100+40+55*(*count),300+180,100+40+30+55*(*count));
	            setcolor(YELLOW);
	            rectangle(50+250,100+40+55*(*count),300+180,100+40+30+55*(*count));
	            puthz(50+280,100+45+55*(*count),"选择学校",24,30,BLUE);
	            *flag2=1;
         	}
	    
		
		if(*count>4&&*flag2==0)
		
		{
			clrmous(MouseX,MouseY);
			cnt=cnt-1;
			*count=cnt;
			setfillstyle(1,BLUE);
        	bar(80,120,220,150);
			puthz(90,125,"学校已满",24,30,RED);
        	delay(1500);
        	setfillstyle(1,WHITE);
        	bar(80,120,220,150);
        	*flag2=0;
        	return 15;
		}
        
	    
	      
	if(*count<=4)
	{
		for(i=0;i<*count;i++)
	     {
		     if(university[i]==1)
		    {
			puthz(50+280,100+45+55*i,"清华大学",24,30,YELLOW);
		    }
		     else if(university[i]==2)
		    {
		    puthz(50+280,100+45+55*i,"北京大学",24,30,YELLOW);
		    }
		    else if(university[i]==3)
		    {
		    puthz(50+280,100+45+55*i,"浙江大学",24,30,YELLOW);
		    }
		    else if(university[i]==4)
		    {
		    puthz(50+280,100+45+55*i,"上海交通大学",16,21,YELLOW);
		    }
		    else if(university[i]==5)
		    {
		    puthz(50+280,100+45+55*i,"复旦大学",24,30,YELLOW);
		    }
		    else if(university[i]==6)
		    {
		    puthz(50+280,100+45+55*i,"南京大学",24,30,YELLOW);
	     	}
		    else if(university[i]==7)
	    	{
		    puthz(50+280,100+45+55*i,"中国科学技术大学",16,18,YELLOW);
		    }
	    	else if(university[i]==8)
		    {
		    puthz(50+280,100+45+55*i,"华中科技大学",16,21,YELLOW);
	    	}
		    else if(university[i]==9)
		    {
		    puthz(50+280,100+45+55*i,"武汉大学",24,30,YELLOW);
	    	}
		    else if(university[i]==10)
		    {
		    puthz(50+280,100+45+55*i,"西安交通大学",16,21,YELLOW);
	    	}
		
	     }
	    
	
		   
	}
	    
    	newmouse(&MouseX,&MouseY,&press);
    	
    		if(mouse_press(50+100,100+35 ,50+140,100+40+35)==1&&*count>=1)
				{
					
					*flag=0;
					
					*count=*count-1;       
					*flag2=0;
					refresh(flag1,university,flag);
					cancel(flag,university,count);
					clrmous(MouseX,MouseY);
					delay(100);
					
					
				}
			else if(mouse_press(50+100,100+35+55 ,50+140,100+40+35+55)==1&&*count>=2)    
			
				{
					
					*flag=1;
					
					*count=*count-1;       
					*flag2=0;
					refresh(flag1,university,flag);
					cancel(flag,university,count);
					clrmous(MouseX,MouseY);
					delay(100);
					
				}
			else if(mouse_press(50+100,100+35+55*2 ,50+140,100+40+35+55*2)==1&&*count>=3)
				{
					
					*flag=2;
					
					*count=*count-1;       
					*flag2=0;
					refresh(flag1,university,flag);
					cancel(flag,university,count);
					clrmous(MouseX,MouseY);
					delay(100);
					
				
				}
			else if(mouse_press(50+100,100+35+55*3 ,50+140,100+40+35+55*3)==1&&*count>=4)
				{
					
					*flag=3;
					
					*count=*count-1;       
					*flag2=0;
					refresh(flag1,university,flag);
					cancel(flag,university,count);
					clrmous(MouseX,MouseY);
					delay(100);
					
					
				}
				
			if(mouse_press(50+200,100+40,300+180,100+40+30)==1&&*count>=1)
			{
				i=university[0];
				*college=i;
				return 17;
			}
			else if(mouse_press(50+200,100+40+55,300+180,100+40+30+55)==1&&*count>=2)
			{
				i=university[1];
				*college=i;
				return 17;
				
			}
			else if(mouse_press(50+200,100+40+55+55,300+180,100+40+30+55+55)==1&&*count>=3)
			{
				i=university[2];
				*college=i;
				return 17;
				
			}
			else if(mouse_press(50+200,100+40+55+110,300+180,100+40+30+55+110)==1&&*count>=4)
			{
				i=university[3];
				*college=i;
				return 17;
				
			}
			
			
			
			
    		if(mouse_press(50+200,100+40+55*(*count),300+180,100+40+30+55*(*count))==1)
    		{
    			clrmous(MouseX,MouseY);
    			return 16;
			}
    		else if(mouse_press(5,5,20,20) == 1)//鼠标在返回框中，且点击
			{
				clrmous(MouseX,MouseY);
				*flag2=0;
				return 2;
				
					
			}
			
			
		
	}
}

/*****function:使被删除的学校能够重新被选*****/
void refresh(int*flag1,int*university,int*flag)
{
	int i,j;
	i=*flag;
	j=university[i];
	*(flag1+j)=0;

	
}
/*****function:删减flag指定的大学*****/
void cancel(int*flag,int*university,int*count)
{
	int i;
	for(i=*flag;i<*count;i++)
	{
		university[i]=university[i+1];
	}
}

void pschoolscreen(void)
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
	puthz(245,50,"模拟志愿填报",24,25,RED);
	setcolor(CYAN);
	rectangle(235,40,405,80);
	
	setcolor(RED);
	rectangle(50,100,590,430);
	setfillstyle(1,WHITE);
	bar(52,102,588,428);
	setcolor(RED);
	setlinestyle(0,0,3);
	setfillstyle(1,LIGHTBLUE);
	
	
	
	
	
	
}
