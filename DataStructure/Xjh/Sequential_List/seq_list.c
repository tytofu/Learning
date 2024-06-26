#include "seq_list.h"
#include <stdio.h>

/*-----implement init_seq_list_pointer function start-----*/
void init_seq_list_pointer(seq_list_t **seq_list, size_t capicity){

  /*初始化描述顺序表数据类型的指针*/
  *seq_list = (seq_list_t*)malloc(sizeof(seq_list_t));
  if(NULL == *seq_list) {
    printf("申请堆内存失败,请重新再尝试!\n");
    exit(1);
  }

  /*初始化顺序表*/
  (*seq_list)->data = (elem_t*)malloc(sizeof(elem_t) * capicity);
  if(NULL == (*seq_list)->data) {
    printf("申请堆内存失败,请重新再尝试!\n");
    exit(1);
  }
  (*seq_list)->size = 0;
  (*seq_list)->capicity = capicity;
}

void init_seq_list_object(seq_list_t *seq_list, size_t capicity){

  /*初始化顺序表*/
  seq_list->data = (elem_t*)malloc(sizeof(elem_t) * capicity);
  if(NULL == seq_list->data){
    printf("申请堆内存失败,请重新再尝试!\n");
    exit(1);
  }
  seq_list->size = 0;
  seq_list->capicity = capicity;
}
/*-----implement init_seq_list_pointer function End-----*/

/*-----implement print_seq_list function start-----*/
void print_seq_list(seq_list_t *seq_list) {
  for (size_t i = 0;i < seq_list->size;i++) {
    printf("seq_list->data[%zu]: %d\n",i,seq_list->data[i]);
  }
  printf("seq_list->size: %zu\n",seq_list->size);
}
/*-----implement print_seq_list function end-----*/

/*-----implement expansion_seq_list function start*/
void expansion_seq_list(seq_list_t *seq_list) {
  if (NULL == seq_list) {
    printf("顺序表的地址为NULL\n");
    exit(-1);
  }
  //扩容倍数
  
  seq_list->capicity *= 2;
  seq_list->data = (elem_t*)realloc(seq_list->data, sizeof(elem_t) * seq_list->capicity);
  if (NULL == seq_list->data){
    printf("扩容失败\n");
    exit(-1);
  }
}
/*-----implement expansion_seq_list function end*/

/*-----implement push_back_in_seq_list function Start----- */
void push_back_in_seq_list(seq_list_t *seq_list, elem_t element){
  /*判断seq_list是否为空*/
  if(NULL == seq_list) {
    printf("seq_list为NULL!\n");
    exit(1);
  }
  /*顺序表如果满了,则进行扩容*/
  if (seq_list->size >= seq_list->capicity)
    expansion_seq_list(seq_list);
  /*对顺序表尾部元素赋值*/
  seq_list->data[seq_list->size] = element;
  seq_list->size++;
}
/*-----implement push_back_in_seq_list function Start-----*/

void push_front_in_seq_list(seq_list_t *seq_list, elem_t element){
  /*判断seq_list是否为空*/
  if (NULL == seq_list) {
    printf("seq_list为NULL!\n");
    exit(1);
  }
  /*顺序表若满了,则扩容顺序表*/
  if (seq_list->size >= seq_list->capicity)
    expansion_seq_list(seq_list);
  /*将顺序表中所有元素后移*/
  /* for (size_t i = seq_list->size;i > 0;i--) {
    seq_list->data[i] = seq_list->data[i - 1];
  }  */
  int end = seq_list->size - 1;
  while(end >= 0){
    seq_list->data[end + 1] = seq_list->data[end];
    end--;
  }
  /*将元素插入到顺序表头部*/
  seq_list->data[0] = element;
  seq_list->size++;
}
/*-----implement push_back_in_seq_list function End-----*/

void insert_in_seq_list(seq_list_t *seq_list, int pos, elem_t element) {
  
  /*判断seq_list是否为空*/
  if (NULL == seq_list){
    printf("seq_list为空!\n");
    exit(1);
  } 
  /*顺序表若满,则进行扩容*/
  if (seq_list->size >= seq_list->capicity)
    expansion_seq_list(seq_list);
  /*判断插入的位置是否位于有效范围内*/
  if (pos <= 0 || pos > seq_list->size + 1){
    printf("请确认你的插入位置!\n");
    exit(1);
  }
  // /*判断用户输入的pos是否是顺序表的头部或者尾部*/
  // if( 1 == pos){
  //   push_front_in_seq_list(seq_list, element);
  //   exit(0);
  // }
  // if (pos == seq_list->size){
  //   push_back_in_seq_list(seq_list, element);
  //   exit(0);
  // }
  /*从顺序表最后一个数据元素到pos位置上的数据元素依次向后移动*/
  int end = seq_list->size - 1;
  while(end >= pos - 1){
    seq_list->data[end + 1] = seq_list->data[end];
    end--;
  }
  /* for (size_t i = seq_list->size;i >= pos;i--) {
    seq_list->data[i] = seq_list->data[ i - 1];
  } */
  /*在pos位置上插入元素*/
  seq_list->data[pos - 1] = element;
  seq_list->size++;
}
