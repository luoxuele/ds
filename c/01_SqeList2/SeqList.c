#include <stdio.h>
#include <malloc.h>
#include "SeqList.h"

// typedef unsigned int TSeqListNode; //32位系统
typedef unsigned long TSeqListNode;

typedef struct _tag_SeqList{
    int capacity;
    int length;
    TSeqListNode* node;
}TSeqList;


SeqList* SeqList_Create(int capacity){
    TSeqList* ret = NULL;

    if(capacity >=0){
        ret = (TSeqList*)malloc(sizeof(TSeqList) + sizeof(TSeqListNode) * capacity);
    }
    if(ret != NULL){
        ret->capacity = capacity;
        ret->length = 0;
        ret->node = (TSeqListNode*)(ret+1);
    }

    return ret;
}

void SeqList_Destroy(SeqList* list){

    free(list);
    //return ;
}
void SeqList_Clear(SeqList* list){
    TSeqList* tList = (TSeqList*)list;
    if(tList != NULL){
        tList->length = 0;
    }
    //return ;
}

int SeqList_Length(SeqList* list){
    TSeqList* tList = (TSeqList*)list;
    int ret = -1;
    if(tList != NULL){
        ret = tList->length;
    }
    return ret;
}
int SeqList_Capacity(SeqList* list){
    TSeqList* tList = (TSeqList*)list;
    int ret = -1;
    if(tList != NULL){
        ret = tList->capacity;
    }
    return ret;
}
int SeqList_Insert(SeqList* list, SeqListNode* node, int pos){
    TSeqList* tList = (TSeqList*)list;
    int ret = (tList != NULL);
    int i = 0;

    ret = ret && (tList->length < tList->capacity);
    ret = ret && ( 0 <= pos);

    if(ret){
        if(pos >= tList->length){
            pos = tList->length;
        }
        for(i = tList->length; i > pos; i--){
            tList->node[i] = tList->node[i-1];
        }

        tList->node[i] = (TSeqListNode)node;
        tList->length++;
    }

    return ret;
}

SeqListNode* SeqList_Get(SeqList* list, int pos){
    TSeqList* tList = (TSeqList*)list;
    SeqListNode* ret = NULL;

    if( (tList != NULL) && (pos >=0) && (pos < tList->length)){
        ret = (SeqListNode*)(tList->node[pos]);
    }

    return ret;
}
SeqListNode* SeqList_Delete(SeqList* list, int pos){
    TSeqList* tList = (TSeqList*)list;
    SeqListNode* ret = SeqList_Get(list,pos);
    int i=0;
    if(ret != NULL){
        for(i=pos+1; i<tList->length; i++){
            tList->node[i-1] = tList->node[i];
        }
        tList->length--;
    }

    return ret;
}