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

LinkNode* LocateElemByNum(SClist* L, ElemType key) //按照值进行查找 
{
		  if (L == NULL)
		  {
					printf("单链表没有被创建，查找失败\n");
					return NULL;

		  }
		  LinkNode* p = L->first->next;			  //首元节点
		  for (p; p != L->first && p->data != key; p = p->next);
		  return p == L->first ? NULL : p;					//需要确定是否找到
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

void SCListInsertFrontByPos(SClist* SL, int pos, ElemType e)	  // 循环单链表按照位序前插
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
		  int counter = 1;
		  while (px != SL->first && counter++ < pos - 1)				  //循环链表
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

void SCListPopFront(SClist* SL)		//循环单链表的头部删除
{
		  if (SL->amount == 0 || SL->first->next == SL->first)
		  {
					printf("循环链表为空表，没有元素，无法进行删除\n");
					return;
		  }
		  LinkNode* px = SL->first->next;		  //访问首元节点
		  if (px->next == SL->first)			  //首元节点的就是尾结点
		  {
					free(px);
					SL->last = SL->first;					//头结点为尾部
					SL->last->next = SL->first;	  //形成自循环
		  }
		  else
		  {
					SL->first->next = px->next;
					free(px);
		  }
		  SL->amount--;					//删除后数量自减
}

void SCListPopBack(SClist* SL)		//循环单链表的尾部删除
{
		  if (SL->amount == 0 || SL->first->next == SL->first)
		  {
					printf("循环链表为空表，没有元素，无法进行删除\n");
					return;
		  }
		  LinkNode* px = SL->first->next;		  //首元节点
		  while (px->next != SL->last)			  //寻找尾部节点的前驱节点
		  {
					px = px->next;
		  }
		  free(SL->last);				//删除尾部结点
		  SL->last = px;				//尾部结点为删除结点的前驱结点
		  SL->last->next = SL->first;			  //设置尾结点的next域为头结点
		  SL->amount--;					//删除后数量自减
}

BOOL SCListDeleteByPos(SClist* SL, int pos, ElemType* e)			//单链表的通过位序删除
{
		  if (pos <1 && pos>SL->amount)
		  {
					printf("循环单链表无法进行插入，输入的位序非法");
					return FALSE;
		  }
		  if (SL->amount == 0 || SL->first->next == SL->first)
		  {
					printf("循环链表为空表，没有元素，无法进行删除\n");
					return FALSE;
		  }
		  LinkNode* px = SL->first->next;		  // 首元节点
		  int counter = 1;
		  while (px != SL->first && counter++ < pos - 1)				  //循环链表，需要找到尾部节点
		  {
					px = px->next;
		  }
		  LinkNode* ptemp = px->next;	  //删除结点
		  *e = ptemp->data;
		  if (ptemp == SL->first)			  //删除节点为尾部节点
		  {
					SL->last = px;				  // px作为尾部结点
					SL->last->next = SL->first;	  //构建循环
		  }
		  else
		  {
					px->next = ptemp->next;		  //跳过ptemp
		  }
		  free(ptemp);
		  SL->amount--;
		  return TRUE;
}

BOOL SCListDeleteByNum(SClist* SL, ElemType key, ElemType* e)	//单链表的通过数值删除
{
		  if (SL->amount == 0 || SL->first->next == SL->first)
		  {
					printf("循环链表为空表，没有元素，无法进行删除\n");
					return FALSE;
		  }
		  LinkNode* px = SL->first->next;		  // 首元节点
		  LinkNode* pre = NULL;					  //前驱节点
		  while (px != SL->first && px->data !=key)				  //循环链表，需要找到尾部节点
		  {
					pre = px;
					px = px->next;
		  }
		  if (px == SL->first)
		  {
					printf("没有找到需要进行删除的数据\n");
					return FALSE;		//没有找到
		  }
		  else
		  {
					*e = px->data;				  //提取数值
					if (px == SL->first)			  //删除节点为尾部节点
					{
							  SL->last = pre;				  // pre(px的前驱)作为尾部结点
							  SL->last->next = SL->first;	  //构建循环
					}
					else
					{
							  pre->next = px->next;		  //跳过px
					}
					free(px);
					SL->amount--;
					return TRUE;
		  }
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

void SCListReverse(SClist* SL)			//链表的反转
{

}

void Swap(ElemType* a1, ElemType* a2)
{
		  ElemType temp = *a1;
		  *a1 = *a2;
		  *a2 = temp;
}

void  SCListSort(SClist* list, LinkNode* left, LinkNode* right)			//排序
{
		  if (list == NULL || list->amount ==0)
		  {
					printf("循环链表为空表，没有元素，无法进行删除\n");
					return;
		  }
		  if (left !=  list->first && right !=NULL)					  //开始的left结点不允许是头结点
		  {
					LinkNode* pre = NULL;					//记录前驱结点
					LinkNode* islow = left;		  //慢速指针
					LinkNode* jfast = islow->next;				//快速指针
					while (jfast != list->first)			//由于是循环链表因此循环的暂停条件为头结点
					{
							  if (islow->data > jfast->data)
							  {
										pre = islow;
										islow = islow->next;
										Swap(&(islow->data), &(jfast->data));
							  }
							  jfast = jfast->next;
					}
					Swap(&(left->data), &(islow->data));
					SCListSort(list, left, pre);
					SCListSort(list, islow->next, right);
		  }
}