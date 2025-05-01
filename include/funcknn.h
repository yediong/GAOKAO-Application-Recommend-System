#ifndef _funcknn_h_
#define _funcknn_h_
void funcknn(struct U *user,PERSON person[2][10][12][10],int *schs,int *majs);//个性化推荐中综合推荐分支的核心算法，使用了机器学习中的k近邻算法，通过计算用户省排名与大量样本省排名之间的欧氏距离大小，经过排序筛选出距离最近的k个样本，并依次推荐出其中出现次数最多的三个样本对应的学校及专业。 
#endif
