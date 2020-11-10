#include"SCList.h"

LinkNode* CreateNode(ElemType x)				  //�ڵ㴴��
{
		  LinkNode* s = (LinkNode*)malloc(sizeof(LinkNode));
		  assert(s != NULL);
		  s->data = x;
		  s->next = NULL;
		  return s;
}

void InitSCList(SClist* list)            //ѭ������ĳ�ʼ������
{
		  list->first = list->last = (LinkNode*)malloc(sizeof(LinkNode));
		  assert(list->first != NULL || list->last!=NULL);	//��̬���ԣ��ж��Ƿ��Ѿ������ڵ�ɹ�
		  list->last->next = list->first;		  //��ʼ��������β��ָ��ͷ��
		  list->amount = 0;
}

LinkNode* LocateElemByNum(SClist* L, ElemType key) //����ֵ���в��� 
{
		  if (L == NULL)
		  {
					printf("������û�б�����������ʧ��\n");
					return NULL;

		  }
		  LinkNode* p = L->first->next;			  //��Ԫ�ڵ�
		  for (p; p != L->first && p->data != key; p = p->next);
		  return p == L->first ? NULL : p;					//��Ҫȷ���Ƿ��ҵ�
}

void SCListPushBack(SClist* SL)	//ѭ���������β�巨
{
		  if (SL == NULL)					//������û�б���ʼ��
		  {
					InitSCList(SL);
		  }
		  ElemType item = 0;
		  printf("��������Ҫͨ��β�巨���������(-1��������):>");
		  while (scanf("%d", &item) && item != -1)
		  {
					LinkNode* s = CreateNode(item);
					if (SL->first->next == SL->first)			  //û����Ԫ�ڵ�
					{
							  SL->first->next = s;
							  SL->last = SL->first->next;			  //�������һ���ڵ�
							  SL->last->next = SL->first;			  //���һ���ڵ����һ���ڵ�ָ��ͷ���
					}
					else
					{
							  SL->last->next = s;			  //��֮ǰ�����last��nextָ���µ�s���
							  SL->last = s;				  // ��s����Ϊ���һ��ָ��
							  SL->last->next = SL->first;	  // �����һ��Ԫ�ص�nextָ��ͷ���
					}
					SL->amount++;				  //�����������
		  }
}

void SCListPushFront(SClist* SL)//ѭ���������ͷ�巨
{
		  if (SL == NULL)					//������û�б���ʼ��
		  {
					InitSCList(SL);
		  }
		  ElemType item = 0;
		  printf("��������Ҫͨ��ͷ�巨���������(-1��������):>");
		  while (scanf("%d", &item) && item != -1)
		  {
					LinkNode* s = CreateNode(item);
					if (SL->first->next == SL->first)			  //û����Ԫ�ڵ�
					{
							  SL->first->next = s;
							  SL->last = SL->first->next;			  //�������һ���ڵ�
							  SL->last->next = SL->first;			  //���һ���ڵ����һ���ڵ�ָ��ͷ���
							  SL->amount++;					//�����������
					}
					else
					{
							  s->next = SL->first->next;				  //���������һ�����ָ��ǰ����Ԫ�ڵ�
							  SL->first->next = s;					//�����²����s���Ϊ�µ���Ԫ�ڵ�
							  SL->amount++;					//�����������
					}
		  }
}

void SCListInsertBackByPos(SClist* SL, int pos, ElemType e)		  // ѭ����������λ��β��
{
		  if (SL == NULL)
		  {
					printf("ѭ�����������ڣ��������\n");
					return;
		  }
		  if (pos <1 && pos>SL->amount)
		  {
					printf("ѭ���������޷����в��룬�����λ��Ƿ�");
					return;
		  }
		  LinkNode* px = SL->first->next;		  // ��Ԫ�ڵ�
		  int counter = 0;
		  while (px != SL->first && counter++<pos -1 )				  //ѭ������
		  {
					px = px->next;
		  }
		  LinkNode* s = CreateNode(e);			  //�½����
		  if (px->next == SL->first)			  //��ǰ���Ϊβ���ڵ�
		  {
					SL->last->next = s;				  //ԭ����β������nextΪs
					SL->last = s;							//s��Ϊ�µ�β�����
					SL->last->next = SL->first;		//����ͷ���
		  }
		  else
		  {
					s->next = px->next;			  //s����һ�����Ϊԭ�ȵĽ��
					px->next = s;
		  }
		  SL->amount++;				  // �����������
}

void SCListInsertFrontByPos(SClist* SL, int pos, ElemType e)	  // ѭ����������λ��ǰ��
{
		  if (SL == NULL)
		  {
					printf("ѭ�����������ڣ��������\n");
					return;
		  }
		  if (pos <1 && pos>SL->amount)
		  {
					printf("ѭ���������޷����в��룬�����λ��Ƿ�");
					return;
		  }
		  LinkNode* px = SL->first->next;		  // ��Ԫ�ڵ�
		  int counter = 1;
		  while (px != SL->first && counter++ < pos - 1)				  //ѭ������
		  {
					px = px->next;
		  }
		  LinkNode* s = CreateNode(e);			  //�½����
		  if (px->next == SL->first)			  //��ǰ���Ϊβ���ڵ�
		  {
					SL->last->next = s;				  //ԭ����β������nextΪs
					SL->last = s;							//s��Ϊ�µ�β�����
					SL->last->next = SL->first;		//����ͷ���
		  }
		  else
		  {
					s->next = px->next;			  //s����һ�����Ϊԭ�ȵĽ��
					px->next = s;
		  }
		  SL->amount++;				  // �����������
}

void SCListPopFront(SClist* SL)		//ѭ���������ͷ��ɾ��
{
		  if (SL->amount == 0 || SL->first->next == SL->first)
		  {
					printf("ѭ������Ϊ�ձ�û��Ԫ�أ��޷�����ɾ��\n");
					return;
		  }
		  LinkNode* px = SL->first->next;		  //������Ԫ�ڵ�
		  if (px->next == SL->first)			  //��Ԫ�ڵ�ľ���β���
		  {
					free(px);
					SL->last = SL->first;					//ͷ���Ϊβ��
					SL->last->next = SL->first;	  //�γ���ѭ��
		  }
		  else
		  {
					SL->first->next = px->next;
					free(px);
		  }
		  SL->amount--;					//ɾ���������Լ�
}

void SCListPopBack(SClist* SL)		//ѭ���������β��ɾ��
{
		  if (SL->amount == 0 || SL->first->next == SL->first)
		  {
					printf("ѭ������Ϊ�ձ�û��Ԫ�أ��޷�����ɾ��\n");
					return;
		  }
		  LinkNode* px = SL->first->next;		  //��Ԫ�ڵ�
		  while (px->next != SL->last)			  //Ѱ��β���ڵ��ǰ���ڵ�
		  {
					px = px->next;
		  }
		  free(SL->last);				//ɾ��β�����
		  SL->last = px;				//β�����Ϊɾ������ǰ�����
		  SL->last->next = SL->first;			  //����β����next��Ϊͷ���
		  SL->amount--;					//ɾ���������Լ�
}

BOOL SCListDeleteByPos(SClist* SL, int pos, ElemType* e)			//�������ͨ��λ��ɾ��
{
		  if (pos <1 && pos>SL->amount)
		  {
					printf("ѭ���������޷����в��룬�����λ��Ƿ�");
					return FALSE;
		  }
		  if (SL->amount == 0 || SL->first->next == SL->first)
		  {
					printf("ѭ������Ϊ�ձ�û��Ԫ�أ��޷�����ɾ��\n");
					return FALSE;
		  }
		  LinkNode* px = SL->first->next;		  // ��Ԫ�ڵ�
		  int counter = 1;
		  while (px != SL->first && counter++ < pos - 1)				  //ѭ��������Ҫ�ҵ�β���ڵ�
		  {
					px = px->next;
		  }
		  LinkNode* ptemp = px->next;	  //ɾ�����
		  *e = ptemp->data;
		  if (ptemp == SL->first)			  //ɾ���ڵ�Ϊβ���ڵ�
		  {
					SL->last = px;				  // px��Ϊβ�����
					SL->last->next = SL->first;	  //����ѭ��
		  }
		  else
		  {
					px->next = ptemp->next;		  //����ptemp
		  }
		  free(ptemp);
		  SL->amount--;
		  return TRUE;
}

BOOL SCListDeleteByNum(SClist* SL, ElemType key, ElemType* e)	//�������ͨ����ֵɾ��
{
		  if (SL->amount == 0 || SL->first->next == SL->first)
		  {
					printf("ѭ������Ϊ�ձ�û��Ԫ�أ��޷�����ɾ��\n");
					return FALSE;
		  }
		  LinkNode* px = SL->first->next;		  // ��Ԫ�ڵ�
		  LinkNode* pre = NULL;					  //ǰ���ڵ�
		  while (px != SL->first && px->data !=key)				  //ѭ��������Ҫ�ҵ�β���ڵ�
		  {
					pre = px;
					px = px->next;
		  }
		  if (px == SL->first)
		  {
					printf("û���ҵ���Ҫ����ɾ��������\n");
					return FALSE;		//û���ҵ�
		  }
		  else
		  {
					*e = px->data;				  //��ȡ��ֵ
					if (px == SL->first)			  //ɾ���ڵ�Ϊβ���ڵ�
					{
							  SL->last = pre;				  // pre(px��ǰ��)��Ϊβ�����
							  SL->last->next = SL->first;	  //����ѭ��
					}
					else
					{
							  pre->next = px->next;		  //����px
					}
					free(px);
					SL->amount--;
					return TRUE;
		  }
}

void DisplayLinkList(SClist* list)//ѭ������������
{
		  LinkNode* p = list->first->next;		  //������Ԫ�ڵ�
		  if (p->next != NULL)
		  {
					while (p != list->first)				//����ͷ���
					{
							  printf("%d--->", p->data);
							  p = p->next;
					}
					printf("END\n");
		  }
}

void SCListDistroy(SClist* SL)				  //����Ĵݻ�
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

void SCListClear(SClist* SL)			//��������
{

}

void SCListReverse(SClist* SL)			//����ķ�ת
{

}

void Swap(ElemType* a1, ElemType* a2)
{
		  ElemType temp = *a1;
		  *a1 = *a2;
		  *a2 = temp;
}

void  SCListSort(SClist* list, LinkNode* left, LinkNode* right)			//����
{
		  if (list == NULL || list->amount ==0)
		  {
					printf("ѭ������Ϊ�ձ�û��Ԫ�أ��޷�����ɾ��\n");
					return;
		  }
		  if (left !=  list->first && right !=NULL)					  //��ʼ��left��㲻������ͷ���
		  {
					LinkNode* pre = NULL;					//��¼ǰ�����
					LinkNode* islow = left;		  //����ָ��
					LinkNode* jfast = islow->next;				//����ָ��
					while (jfast != list->first)			//������ѭ���������ѭ������ͣ����Ϊͷ���
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