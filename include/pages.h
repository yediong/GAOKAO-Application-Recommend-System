#ifndef _PAGES_H_
#define _PAGES_H_

int psubject(int(*subjectchoice)[20],int *college,int* click,int* sign, int(*sign1)[20], int* sign2,int*flag2,int probability[4][4],int* university,struct U *user,PERSON person[2][10][12][10]);
void refreshsubject(int(*sign1)[20],int(*subjectchoice)[20],int*sign,int*college);
void cancelsubject(int*sign,int(*subjectchoice)[20],int*click,int*college);
void psubjectscreen(void);
char* int_to_string(int num);

#endif
