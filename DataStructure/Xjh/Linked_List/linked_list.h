#ifndef __LINKED_LIST_H__
#define __LINKED_LIST_H__

typedef struct node node_t;
typedef int elem_t;
// 定义一个结构体类型表示链表中的结点类型
struct node {
  // 结点中的数据
  elem_t data;
  // 下一个结点的地址
  node_t *next;
};

#endif
/*-----OTHER-----*/

/*遍历链表中结点的数据*/
void traversal_linked_list(node_t *head);

/*计算链表的长度*/
void length_linked_list(node_t *head, unsigned short *length);

/*-----OTHER-----*/

/*-----Insert-----*/

/*将新结点插入到链表的尾部*/
void push_back_linked_list(node_t **head, elem_t data);

/*-----INSERT-----*/

/*-----DELETE-----*/

/*删除链表中的尾部元素*/
void pop_back_linked_list(node_t **head);

/*-----DELETE-----*/
