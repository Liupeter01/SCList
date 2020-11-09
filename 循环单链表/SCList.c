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