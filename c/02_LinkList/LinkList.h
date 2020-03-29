#ifndef _LINKLIST_H_
#define _LINK_LIST_H_

typedef void LinkList;
//LinkListNode是一个结构体，结构体里面只有一个指向自己的指针，叫next
typedef struct _tag_LinkListNode LinkListNode;
struct _tag_LinkListNode{
    LinkListNode* next;
};

LinkList* LinkList_Create();
void LinkList_Destroy(LinkList* list);
void LinkList_Clear(LinkList* list);

int LinkList_Length(LinkList* list);
int LinkList_Insert(LinkList* list, LinkListNode* node, int pos);

LinkListNode* LinkList_Get(LinkList* list, int pos);
LinkListNode* LinkList_Delete(LinkList* list, int pos);

#endif //_LINKLIST_H_
