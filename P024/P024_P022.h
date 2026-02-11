#pragma once
/**
 * @file linked_list.h
 * @brief 单链表数据结构及操作接口
 *
 * 本模块提供浮点数单链表的创建、读写、计数和销毁功能
 */

#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>

    /**
        * @brief 链表节点结构体
        *
        * 每个节点包含一个浮点数值和指向下一个节点的指针
        */
    struct Node {
        int x;           /**< 节点存储的x数值 */
        int y;           /**< 节点存储的y数值 */
        struct Node* next;  /**< 指向下一个节点的指针，链表末尾为NULL */
        int orientation;     /**< 1是向上2是向下3是向左4是向右 */
    };

    /**
        * @brief 创建指定长度的链表
        *
        * 动态分配内存创建包含指定节点数量的链表，所有节点初始值为0.0f
        *
        * @param node_count 需要创建的节点数量，必须为正整数
        * @return struct Node* 链表头节点指针，创建失败返回NULL
        *
        * @note 调用者负责在不再使用时调用DestroyList释放内存
        */
    struct Node* CreateList(int node_count);

    /**
        * @brief 为指定索引的节点设置值
        *
        * 遍历链表找到指定索引位置的节点并设置其值
        *
        * @param index 节点索引（从0开始）
        * @param value 要设置的浮点数值
        * @param head 链表头节点指针
        * @return bool 设置成功返回true，索引越界或链表为空返回false
        */
    bool ApplyValue(int index, char y_x,int value, struct Node* head);

    /**
        * @brief 读取指定索引节点的值
        *
        * @param index 节点索引（从0开始）
        * @param head 链表头节点指针
        * @return float 读取到的浮点数值，索引越界时返回default_value
        */
    int ReadValue(int index, struct Node* head);

    /**
        * @brief 统计链表节点数量
        *
        * 遍历链表计算节点总数
        *
        * @param head 链表头节点指针
        * @return int 链表节点数量，空链表返回0
        */
    int CountList(struct Node* head);

    /**
        * @brief 销毁链表并释放内存
        *
        * 遍历链表释放所有节点内存，防止内存泄漏
        *
        * @param head 链表头节点指针（函数调用后指针变为无效）
        *
        * @note 调用此函数后，head指针不应再被使用
        */
    void DestroyList(struct Node* head);

#ifdef __cplusplus
}
#endif

#endif /* LINKED_LIST_H */