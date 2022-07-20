#include "seqlist.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//创建顺序表
seqList* listCreate()
{
	//在堆区申请一个顺序表的空间，将申请的地址给S
	seqList* S = (seqList*)malloc(sizeof(seqList));
	if(NULL == S)
	{
		printf("申请空间失败！\n");
		return NULL;
	}

	memset(S->data, 0, sizeof(S->data)); 		//将数组清零
	S->len = 0;

	printf("创建成功\n");
	return S;
}

//判空
int listEmpty(seqList *S)
{
	if(NULL==S)
	{
		printf("所给顺序表不合法\n");
		exit(0);
	}
	return S->len==0?1:0; 		//0表示非空 1表示空
}
//判满
int listFull(seqList* S)
{
	return S->len==MAX?1:0; 	//0表示不满 1表示满
}
//添加数据
int listAdd(seqList* S,datatype e)
{
	//判断逻辑
	if(listFull(S)){
		printf("表满，添加失败\n");
		return -1;
	}
	//添加逻辑
	S->data[S->len] = e;
	//表的变化
	S->len++;
	printf("添加成功\n");
	return 0;
}

//遍历函数
void listShow(seqList *S)
{
	//判断逻辑
	if(listEmpty(S))
	{
		printf("空空如也,遍历失败\n");
		return;
	}
	//遍历逻辑
	printf("目前顺序表中的元素分别是:");
	for(int i=0;i<S->len;i++)
	{
		printf("%d\t",S->data[i]);
	}
		printf("\n");
}

//任意位置插入
int listInsertPos(seqList* S,int pos,datatype e)
{
	//判断逻辑
	if(listFull(S))
	{
		printf("表满,插入失败\n");
		return -1;
	}
	if(pos>S->len||pos<0)
	{
		printf("位置不合法!\n");
		return -2;
	}
	//腾空
	for(int i=S->len-1;i>=pos;i--)
	{
		S->data[i+1] = S->data[i];
	}
	//插入数据
	S->data[pos] = e;
	//表的变化
	S->len++;
	printf("插入成功！\n");
	return 0;
}

//任意位置删除
int listDeletePos(seqList* S,int pos)
{
	//判断逻辑
	if(listEmpty(S) || pos>=S->len || pos<0)
	{
		printf("删除失败！\n");
		return -1;
	}
	//删除逻辑
	for(int i=pos;i<S->len-1;i++)
	{
		S->data[i] = S->data[i+1];
	}
	//表的变化
	S->len--;
	printf("删除成功！\n");
	return 0;
}
//按值查找,返回对应的位置
int listSearchValue(seqList* S,datatype e)
{
	//判断逻辑
	/*if(listEmpty(S))
	{
		return -1;
	}*/

	//查找逻辑
	for(int i=0;i<S->len;i++)
	{
		if(S->data[i] == e) 		//跟任意一个元素比较
		{
			//printf("下标为:%d\n",i);
			return i;
		}
	}
	return -2; 		//表中没找到
}

//按位置查找
void listSearchPos(seqList* S,int pos)
{
	//判断逻辑
	if(listEmpty(S)||pos<0||pos>=S->len)
	{
		printf("按位置查找失败!\n");
		//return -1;
	}
	printf("按位置查找成功!值为:%d\n",S->data[pos]);
	//return S->data[pos];
}

//按值修改
int listUpdateValue(seqList* S,datatype old_e,datatype new_e)
{
	int pos = listSearchValue(S,old_e);
	if(pos == -2)
	{
		printf("顺序表中没有要修改的元素!\n");
		return -1;
	}else
	{
		for(int i=0;i<S->len;i++)
		{
			if(S->data[i] == old_e)
			{
				S->data[i] = new_e;
			}
		}
		printf("按值修改成功!\n");
		return 0;
	}
}

//按位置修改
int listUpdatePos(seqList* S,int pos,datatype new_e)
{
	//判断逻辑
	if(listEmpty(S)||pos<0||pos>=S->len)
	{
		printf("按位置修改失败\n");
		return -1;
	}
	//修改逻辑
	S->data[pos] = new_e;
	printf("按位置修改成功\n");
	return 0;
}

//冒泡排序
void listSort(seqList* S)
{
	int i,j; 			//循环变量
	datatype temp; 		//交换变量
	for(i=0;i<S->len-1;i++)
	{
		for(j=0;j<S->len-1-i;j++)
		{
			if(S->data[j]>S->data[j+1])
			{
				temp = S->data[j];
				S->data[j] = S->data[j+1];
				S->data[j+1] = temp;
			}
		}
	}
	printf("冒泡排序升序成功!\n");
}

//选择排序
void listSelectSort(seqList* S)
{
	int i,j,maxindex;
	datatype temp;
	for(i=0;i<S->len-1;i++)
	{
		maxindex=i;
		for(j=i+1;j<S->len;j++)
		{
			if(S->data[j]>S->data[i])
			{
				maxindex = j;
			}
		}
		temp = S->data[maxindex];S->data[maxindex]=S->data[i];S->data[i]=temp;
	}
	printf("选择排序降序成功!\n");
}


//去重
void listDeleteRepeat(seqList* S)
{
	/*if(S->len<=1)
	{
		printf("去重失败！\n");
		return;
	}*/

	//去重
	for(int i=0;i<S->len;i++)
	{
		for(int j=i+1;j<S->len;j++)
		{
			if(S->data[j]==S->data[i])
			{
				listDeletePos(S,j);
				j--; 			//防止漏删
			}
		}
	}
	printf("去重成功!\n");
}

//释放表
void listFree(seqList *S)
{
	if(NULL!=S)
	{
		free(S);
	}
	S = NULL; 		//防止悬空指针、野指针
	printf("释放成功\n");
}
