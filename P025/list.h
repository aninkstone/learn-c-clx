#ifndef __MYLIST_H__
#define __MYLIST_H__

#include <stddef.h>
#include <stdbool.h>

struct Node {
    int x;           /**< 节点存储的x数值 */
    int y;           /**< 节点存储的y数值 */
    struct Node* next;  /**< 指向下一个节点的指针，链表末尾为NULL */
    struct Node* up; /**< 指向上一个节点的指针，链表头为NULL */
};

/**
 * 基础生命周期管理
 */

// 创建指定长度的链表，初始化节点空间
struct Node* CreateList(size_t length);

// 彻底销毁链表，释放所有节点内存
void DestroyList(struct Node* head);

// 清空链表内容，但保留头节点（如果适用）或释放除头以外的节点
void ClearList(struct Node* head);

/**
 * 节点操作
 */

// 在指定节点之后插入新节点
struct Node* InsertAfter(struct Node* head, struct Node* target);

// 在指定节点之前插入新节点
struct Node* InsertBefore(struct Node* head,struct Node* target);

// 将节点从链表中移除并释放内存
bool DeleteNode(struct Node* head, struct Node* node);

/**
 * 查询与索引
 */
// 获取当前节点的前驱节点
struct Node* PreviousNode(struct Node* node);

// 获取当前节点的后继节点
struct Node* NextNode(struct Node* node);

// 检查是否为尾节点
bool IsTail(struct Node* node);

// 检查是否为头节点
bool IsHead(struct Node* node);

// 获取链表总长度
size_t GetListLength(struct Node* head);

// 根据索引获取节点
struct Node* GetNodeByIndex(struct Node* head, size_t index);

#endif
