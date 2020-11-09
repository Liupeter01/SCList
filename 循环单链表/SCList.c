#include"SCList.h"

LinkNode* CreateNode(ElemType x)				  //节点创建
{
		  LinkNode* s = (LinkNode*)malloc(sizeof(LinkNode));
		  assert(s != NULL);
		  s->data = x;
		  s->next = NULL;
		  return s;
}

void InitSCList(SClist* list)            //循环链表的初始化操作
{
		  list->first = list->last = (LinkNode*)malloc(sizeof(LinkNode));
		  assert(list->first != NULL || list->last!=NULL);	//静态断言，判断是否已经创建节点成功
		  list->last->next = list->first;		  //初始化将链表尾部指向头部
		  list->amount = 0;
}

void SCListPushBack(SClist* SL)	//循环单链表的尾插法
{
		  if (SL == NULL)					//该链表没有被初始化
		  {
					InitSCList(SL);
		  }
		  ElemType item = 0;
		  printf("请输入需要通过尾插法插入的数据(-1结束输入):>");
		  while (scanf("%d", &item) && item != -1)
		  {
					LinkNode* s = CreateNode(item);
					if (SL->first->next == SL->first)			  //没有首元节点
					{
							  SL->first->next = s;
							  SL->last = SL->first->next;			  //更新最后一个节点
							  SL->last->next = SL->first;			  //最后一个节点的下一个节点指向头结点
					}
					else
					{
							  SL->last->next = s;			  //将之前保存的last的next指向新的s结点
							  SL->last = s;				  // 将s更新为最后一个指针
							  SL->last->next = SL->first;	  // 将最后一个元素的next指向头结点
					}
					SL->amount++;				  //结点数增加了
		  }
}

void SCListPushFront(SClist* SL)//循环单链表的头插法
{
		  if (SL == NULL)					//该链表没有被初始化
		  {
					InitSCList(SL);
		  }
		  ElemType item = 0;
		  printf("请输入需要通过头插法插入的数据(-1结束输入):>");
		  while (scanf("%d", &item) && item != -1)
		  {
					LinkNode* s = CreateNode(item);
					if (SL->first->next == SL->first)			  //没有首元节点
					{
							  SL->first->next = s;
							  SL->last = SL->first->next;			  //更新最后一个节点
							  SL->last->next = SL->first;			  //最后一个节点的下一个节点指向头结点
							  SL->amount++;					//结点数增加了
					}
					else
					{
							  s->next = SL->first->next;				  //插入结点的下一个结点指向当前的首元节点
							  SL->first->next = s;					//更新新插入的s结点为新的首元节点
							  SL->amount++;					//结点数增加了
					}
		  }
}

void SCListInsertBackByPos(SClist* SL, int pos, ElemType e)		  // 循环单链表按照位序尾插
{
		  if (SL == NULL)
		  {
					printf("循环单链表不存在，插入错误\n");
					return;
		  }
		  if (pos <1 && pos>SL->amount)
		  {
					printf("循环单链表无法进行插入，输入的位序非法");
					return;
		  }
		  LinkNode* px = SL->first->next;		  // 首元节点
		  int counter = 0;
		  while (px != SL->first && counter++<pos -1 )				  //循环链表
		  {
					px = px->next;
		  }
		  LinkNode* s = CreateNode(e);			  //新建结点
		  if (px->next == SL->first)			  //当前结点为尾部节点
		  {
					SL->last->next = s;				  //原来的尾部结点的next为s
					SL->last = s;							//s作为新的尾部结点
					SL->last->next = SL->first;		//链接头结点
		  }
		  else
		  {
					s->next = px->next;			  //s的下一个结点为原先的结点
					px->next = s;
		  }
		  SL->amount++;				  // 结点数量自增
}

void DisplayLinkList(SClist* list)//循环单链表的输出
{
		  LinkNode* p = list->first->next;		  //跳过首元节点
		  if (p->next != NULL)
		  {
					while (p != list->first)				//不是头结点
					{
							  printf("%d--->", p->data);
							  p = p->next;
					}
					printf("END\n");
		  }
}

void SCListDistroy(SClist* SL)				  //链表的摧毁
{
		  LinkNode* px = SL->first->next;
		  while (px->next != SL->first)
		  {
					LinkNode* p = px;
					px = px->next;
					free(p);
		  }
		  free(SL->first);
		  SL->amount = 0;
}

void SCListClear(SClist* SL)			//链表的清空
{

}