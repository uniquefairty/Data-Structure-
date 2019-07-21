#ifndef  _SEQLIST_H
#define  _SEQLIST_H

#include<stdio.h>
#include<Windows.h>
#include<stdlib.h>
#include<string.h>
#include<malloc.h>

typedef int SLDataType;

typedef struct SeqList
{
	SLDataType *array;
	size_t size;
	size_t capacity;
}SeqList;

void SeqListInit(SeqList *psl, size_t capacity);//˳����ʼ��
void SeqListDestory(SeqList *psl);//�ݻ�
void CheckCapacity(SeqList *psl);//����Ƿ���Ҫ����

void SeqListPushBack(SeqList *psl,SLDataType x);//��ĩβѹһ������
void SeqListPopBack(SeqList *psl);//��ĩβ��һ������

void SeqListPushFront(SeqList *psl, SLDataType x);//���ײ���һ������
void SeqListPopFront(SeqList *psl);//ɾ���ײ�����

int SeqListFind(SeqList *psl, SLDataType x);//��ֵΪx������
void SeqListInsert(SeqList *psl, size_t pos, SLDataType x);//���±�Ϊposλ����x
void SeqListErase(SeqList *psl, size_t pos);//���posλ����

void SeqListRemove(SeqList *psl, SLDataType x);//�Ƴ���һ��ֵΪx������
void SeqListRemoveAll(SeqList *psl, SLDataType x);//�Ƴ�����ֵΪx������  ʱ�临�Ӷ�O��n��  �ռ临�Ӷ�O��n��
void SeqListRemoveAll_1(SeqList *psl, SLDataType x); //ʱ�临�Ӷ�O��n��  �ռ临�Ӷ�O��1��
//void SeqListRemoveAll_2(SeqList* psl, SLDataType x);

void SeqListModify(SeqList *psl, size_t pos, SLDataType x);//�޸�
void SeqListPrint(SeqList *psl);

void SqListBubbleSort(SeqList *psl);//ð������
int SeqListBinaryFind(SeqList *psl, SLDataType x);//���ֲ���

#endif