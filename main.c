#include "seqlist.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char *argv[])
{
	seqList *S = listCreate();
	if(NULL==S)
	{
		return -1;
	}
	//调用添加
	listAdd(S,4);
	listAdd(S,4);
	listAdd(S,4);
	listAdd(S,7);
	listAdd(S,4);
	listAdd(S,5);
	//调用遍历
	listShow(S);
	//调用插入
	listInsertPos(S,3,8);
	listInsertPos(S,4,0);
	listShow(S);
	//调用按位置删除
	listDeletePos(S,1);
	listShow(S);
	//按值查找
	int res = listSearchValue(S,8);
	if(res>=0)
	{
		printf("按值查找成功,下标为:%d\n",res);
	}else if(res == -1)
	{
		printf("表空,按值查找失败\n");
	}else if(res == -2)
	{
		printf("没有你要查找的元素！\n");
	}

	//按位置修改函数
	listUpdatePos(S,2,100);
	listShow(S);
	//按值修改
	listUpdateValue(S,4,9);
	listShow(S);
	//调用按位置查找
	listSearchPos(S,2);
	//调用排序函数
	listSort(S);
	listShow(S);
	//调用选择排序
	listSelectSort(S);
	listShow(S);
	//调用去重函数
	listDeleteRepeat(S);
	listShow(S);
	//调用释放表函数
	listFree(S);
	S=NULL;
	listShow(S);

	return 0;
}
