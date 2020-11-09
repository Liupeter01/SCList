/**
* @file	  Slist.h
* @brief			������LinkList�������棬�����˸�����Ƶ�ϸ��
* @details	    This is the detail description.
* @author		LPH
* @date		    2020.11.4
* @version	    v0.1
* @par Copyright(c): 	LPH corporation
* @par History:
*	version: author, date, desc\n
*/
#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<Windows.h>

#define ElemType int
#pragma warning(disable:6011)

typedef struct LinkNode
{
          ElemType data;                  //������
          struct LinkNode* next;           //ָ������һ���ڵ�
} LinkNode, *LinkList;

typedef struct SClist
{
          LinkNode* first;    //�����һ���ڵ�
          LinkNode* last;     //�������һ���ڵ�
          int amount;         //�ܸ���
}SClist;

LinkNode* CreateNode(ElemType x);		//�ڵ㴴��
void DisplayLinkList(SClist *list);	//ѭ������������
LinkNode* LocateElemByNum(SClist* list, ElemType key); //����ֵ���в��� 

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void InitSCList(SClist* list);            //ѭ������ĳ�ʼ������
void  SListSort(LinkNode* left, LinkNode* right);			//����
void SCListDistroy(SClist* SL);					  //����Ĵݻ�
void SCListClear(SClist* SL);			//��������
void SListReverse(SClist* SL);			//����ķ�ת

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void SCListPushBack(SClist* SL);	//ѭ���������β�巨
void SCListPushFront(SClist* SL);//ѭ���������ͷ�巨
void SCListInsertBackByPos(SClist* SL, int pos, ElemType e);		  // ѭ����������λ��β��
void SCListInsertFrontByPos(SClist* SL, int pos, ElemType e);		  // ѭ����������λ��ǰ��

//////////////////////////////////////////////////////////ɾ��ϵ��///////////////////////////////////////////////////
void SCListPopFront(SClist* SL);			//ѭ���������ͷ��ɾ��
void SCListPopBack(SClist* SL);		//ѭ���������β��ɾ��
BOOL SCListDeleteByPos(SClist* SL, int pos, ElemType* e);			//�������ͨ��λ��ɾ��
BOOL SCListDeleteByNum(SClist* SL, ElemType key, ElemType* e);			//�������ͨ����ֵɾ��