/**
* @file	  Slist.h
* @brief			基础的LinkList的升级版，增加了更多控制的细节
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
          ElemType data;                  //数据域
          struct LinkNode* next;           //指针域，下一个节点
} LinkNode, *LinkList;

typedef struct SClist
{
          LinkNode* first;    //保存第一个节点
          LinkNode* last;     //保存最后一个节点
          int amount;         //总个数
}SClist;

LinkNode* CreateNode(ElemType x);		//节点创建
void DisplayLinkList(SClist *list);	//循环单链表的输出
LinkNode* LocateElemByNum(SClist* list, ElemType key); //按照值进行查找 

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void InitSCList(SClist* list);            //循环链表的初始化操作
void  SListSort(LinkNode* left, LinkNode* right);			//排序
void SCListDistroy(SClist* SL);					  //链表的摧毁
void SCListClear(SClist* SL);			//链表的清空
void SListReverse(SClist* SL);			//链表的反转

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void SCListPushBack(SClist* SL);	//循环单链表的尾插法
void SCListPushFront(SClist* SL);//循环单链表的头插法
void SCListInsertBackByPos(SClist* SL, int pos, ElemType e);		  // 循环单链表按照位序尾插
void SCListInsertFrontByPos(SClist* SL, int pos, ElemType e);		  // 循环单链表按照位序前插

//////////////////////////////////////////////////////////删除系列///////////////////////////////////////////////////
void SCListPopFront(SClist* SL);			//循环单链表的头部删除
void SCListPopBack(SClist* SL);		//循环单链表的尾部删除
BOOL SCListDeleteByPos(SClist* SL, int pos, ElemType* e);			//单链表的通过位序删除
BOOL SCListDeleteByNum(SClist* SL, ElemType key, ElemType* e);			//单链表的通过数值删除