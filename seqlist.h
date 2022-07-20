#ifndef ___SEQLIST_H___
#define ___SEQLIST_H___

#define MAX 20

typedef int datatype;

typedef struct
{
	datatype data[MAX]; 	//存储数据表的数组
	int len; 				//表示顺序表的长度
}seqList;

//创建顺序表
seqList* listCreate();

//判空
int listEmpty(seqList *S);

//判满
int listFull(seqList* S);

//添加元素
int listAdd(seqList* S,datatype e);

//遍历
void listShow(seqList* S);

//任意位置插入
int listInsertPos(seqList* S,int pos,datatype e);

//任意位置删除
int listDeletePos(seqList* S,int pos);

//按值查找,返回对应的位置
int listSearchValue(seqList* S,datatype e);

//按位置查找
void listSearchPos(seqList* S,int pos);

//按值修改
int listUpdateValue(seqList* S,datatype old_e,datatype new_e);

//按位置修改
int listUpdatePos(seqList* S,int pos,datatype new_e);

//排序
void listSort(seqList* S);

//去重
void listDeleteRepeat(seqList* S);

//释放表
void listFree(seqList* S);

//选择排序完成顺序表降序
void listSelectSort(seqList* S);
#endif
