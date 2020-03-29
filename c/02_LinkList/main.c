#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkList.h"

typedef struct _tag_Student{
    LinkListNode header;
    int age;
    char name[32];
}Student;


void main(){

    LinkList* list = LinkList_Create();

    Student s1 = {NULL, 23 ,"张三"};
    Student s2 = {NULL, 24 ,"李四"};
    Student s3 = {NULL, 13 ,"王五"};
    Student s4 = {NULL, 35 ,"超六"};
    Student s5;
   // s1.age = 23;
   s5.header.next = NULL;
   s5.age = 32;
   strcpy(s5.name, "田七");


    return;
}