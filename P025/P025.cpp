/**
 * 文件名: test_list.c
 * 描述: 针对 list.h 定义的双向链表接口的单元测试
 *        头节点被视为链表中的一个普通节点（即链表长度为节点总数）
 * 编译: gcc -o test_list test_list.c list.c -I.
 * 运行: ./test_list
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "list.h"  // 假设头文件名为 list.h

 // 辅助函数：打印链表（调试用）
void printList(const char* msg, struct Node* head) {
    printf("%s: ", msg);
    struct Node* p = head;
    int idx = 0;
    while (p) {
        printf("[%d](%d,%d) up=%p next=%p ", idx++, p->x, p->y, p->up, p->next);
        p = p->next;
    }
    printf("\n");
}

// 辅助函数：计算链表节点数（遍历计数）
size_t countNodes(struct Node* head) {
    size_t cnt = 0;
    struct Node* p = head;
    while (p) {
        cnt++;
        p = p->next;
    }
    return cnt;
}

// 辅助函数：验证链表双向连接的正确性
int verifyList(struct Node* head) {
    if (head == NULL) return 1;
    struct Node* prev = NULL;
    struct Node* curr = head;
    while (curr) {
        if (curr->up != prev) {
            printf("验证失败: 节点 %p 的 up 应为 %p，实际为 %p\n", curr, prev, curr->up);
            return 0;
        }
        prev = curr;
        curr = curr->next;
    }
    return 1;
}

// ---------- 测试用例 ----------

void test_CreateList() {
    printf("=== 测试 CreateList ===\n");

    // 1. length = 0 应返回 NULL
    struct Node* head = CreateList(0);
    assert(head == NULL);
    printf("CreateList(0) 返回 NULL: 通过\n");

    // 2. length = 5 创建链表
    head = CreateList(5);
    assert(head != NULL);
    // 节点总数应为 5
    size_t cnt = countNodes(head);
    assert(cnt == 5);
    // 验证头节点的 up 为 NULL
    assert(head->up == NULL);
    // 验证双向链接正确
    assert(verifyList(head));
    // 验证 GetListLength 返回 5
    assert(GetListLength(head) == 5);
    printf("CreateList(5) 创建 5 个节点，双向链接正确: 通过\n");

    DestroyList(head);
    printf("测试 CreateList 完成\n\n");
}

void test_DestroyList() {
    printf("=== 测试 DestroyList ===\n");
    struct Node* head = CreateList(3);
    assert(head != NULL);
    DestroyList(head);
    // 无法直接验证内存释放，但确保没有崩溃
    printf("DestroyList 执行无崩溃: 通过\n\n");
}

void test_ClearList() {
    printf("=== 测试 ClearList ===\n");
    struct Node* head = CreateList(4);
    assert(head != NULL);
    // 记录头节点指针
    struct Node* savedHead = head;
    // 清空链表（保留头节点）
    ClearList(head);
    // 验证头节点未被释放
    assert(head == savedHead);
    // 验证头节点的 x, y 被清零
    assert(head->x == 0 && head->y == 0);
    // 验证头节点的 next 变为 NULL（即只有头节点）
    assert(head->next == NULL);
    // 验证链表长度变为 1（因为头节点还在）
    assert(GetListLength(head) == 1);
    // 验证双向链接：只有一个节点，其 up 应为 NULL
    assert(verifyList(head));
    printf("ClearList 正确清空数据节点，仅保留头节点: 通过\n");

    DestroyList(head);  // 释放头节点
    printf("测试 ClearList 完成\n\n");
}

void test_InsertAfter() {
    printf("=== 测试 InsertAfter ===\n");
    struct Node* head = CreateList(2);  // 两个节点：head 和 head->next
    assert(head != NULL);
    struct Node* first = head->next;    // 第二个节点

    // 1. 在头节点后插入
    struct Node* new1 = InsertAfter(head);
    assert(new1 != NULL);
    // 验证新节点插入在 head 和 first 之间
    assert(head->next == new1);
    assert(new1->up == head);
    assert(new1->next == first);
    assert(first->up == new1);
    assert(verifyList(head));
    assert(GetListLength(head) == 3);  // 长度变为 3

    // 2. 在中间节点后插入（在 new1 后）
    struct Node* new2 = InsertAfter(new1);
    assert(new2 != NULL);
    assert(new1->next == new2);
    assert(new2->up == new1);
    assert(new2->next == first);
    assert(first->up == new2);
    assert(verifyList(head));
    assert(GetListLength(head) == 4);

    // 3. 在尾节点后插入（在 first 后，此时 first 是尾）
    struct Node* new3 = InsertAfter(first);
    assert(new3 != NULL);
    assert(first->next == new3);
    assert(new3->up == first);
    assert(new3->next == NULL);
    assert(verifyList(head));
    assert(GetListLength(head) == 5);

    printf("InsertAfter 在头部、中间、尾部插入均正确: 通过\n");
    DestroyList(head);
    printf("测试 InsertAfter 完成\n\n");
}

void test_InsertBefore() {
    printf("=== 测试 InsertBefore ===\n");
    struct Node* head = CreateList(2);  // 两个节点：head 和 head->next
    assert(head != NULL);
    struct Node* first = head->next;    // 第二个节点

    // 1. 在头节点前插入（成为新头节点）
    struct Node* new_head = InsertBefore(head);
    assert(new_head != NULL);
    // 新节点成为头，其 up 应为 NULL
    assert(new_head->up == NULL);
    assert(new_head->next == head);
    assert(head->up == new_head);
    // 更新头指针
    head = new_head;
    assert(verifyList(head));
    assert(GetListLength(head) == 3);  // 长度变为 3

    // 2. 在中间节点前插入（在 head->next 前，即原 head 前）
    struct Node* mid = head->next;  // 原 head
    struct Node* new_mid = InsertBefore(mid);
    assert(new_mid != NULL);
    assert(mid->up == new_mid);
    assert(new_mid->next == mid);
    assert(new_mid->up == head);    // head 是前一个节点
    assert(head->next == new_mid);
    assert(verifyList(head));
    assert(GetListLength(head) == 4);

    // 3. 在尾节点前插入
    struct Node* tail = head;
    while (tail->next) tail = tail->next;
    struct Node* new_tail_prev = InsertBefore(tail);
    assert(new_tail_prev != NULL);
    assert(tail->up == new_tail_prev);
    assert(new_tail_prev->next == tail);
    // 新节点的前驱应是原 tail 的前驱
    assert(new_tail_prev->up != NULL);
    assert(verifyList(head));
    assert(GetListLength(head) == 5);

    printf("InsertBefore 在头前、中间、尾前插入均正确: 通过\n");
    DestroyList(head);
    printf("测试 InsertBefore 完成\n\n");
}

void test_DeleteNode() {
    printf("=== 测试 DeleteNode ===\n");
    struct Node* head = CreateList(4);  // 4个节点：n0, n1, n2, n3
    assert(head != NULL);
    struct Node* n1 = head->next;
    struct Node* n2 = n1->next;
    struct Node* n3 = n2->next;

    // 1. 删除中间节点 (n1)
    bool ret = DeleteNode(head, n1);
    assert(ret == true);
    // 验证链接：head 应直接指向 n2
    assert(head->next == n2);
    assert(n2->up == head);
    assert(verifyList(head));
    assert(GetListLength(head) == 3);

    // 2. 删除头节点 (head)
    ret = DeleteNode(head, head);
    assert(ret == true);
    head = n2;  // 更新头指针为原 n2，因为 head 被删
    assert(head->up == NULL);
    assert(verifyList(head));
    assert(GetListLength(head) == 2);

    // 3. 删除尾节点 (n3)
    struct Node* tail = head;
    while (tail->next) tail = tail->next;
    ret = DeleteNode(head, tail);
    assert(ret == true);
    // 验证新尾节点
    struct Node* new_tail = head;
    while (new_tail->next) new_tail = new_tail->next;
    assert(new_tail->next == NULL);
    assert(verifyList(head));
    assert(GetListLength(head) == 1);

    // 4. 尝试删除不存在的节点（应返回 false）
    struct Node fakeNode;
    ret = DeleteNode(head, &fakeNode);
    assert(ret == false);

    printf("DeleteNode 正确删除中间、头、尾节点，并处理不存在节点: 通过\n");
    DestroyList(head);
    printf("测试 DeleteNode 完成\n\n");
}

void test_PreviousNode_NextNode() {
    printf("=== 测试 PreviousNode 和 NextNode ===\n");
    struct Node* head = CreateList(3);  // 三个节点：n0, n1, n2
    struct Node* n1 = head->next;
    struct Node* n2 = n1->next;

    assert(PreviousNode(head) == NULL);
    assert(NextNode(head) == n1);
    assert(PreviousNode(n1) == head);
    assert(NextNode(n1) == n2);
    assert(PreviousNode(n2) == n1);
    assert(NextNode(n2) == NULL);

    printf("PreviousNode 和 NextNode 返回正确: 通过\n");
    DestroyList(head);
    printf("\n");
}

void test_IsHead_IsTail() {
    printf("=== 测试 IsHead 和 IsTail ===\n");
    struct Node* head = CreateList(3);
    struct Node* n1 = head->next;
    struct Node* n2 = n1->next;

    assert(IsHead(head) == true);
    assert(IsTail(head) == false);
    assert(IsHead(n1) == false);
    assert(IsTail(n1) == false);
    assert(IsHead(n2) == false);
    assert(IsTail(n2) == true);

    printf("IsHead 和 IsTail 判断正确: 通过\n");
    DestroyList(head);
    printf("\n");
}

void test_GetListLength() {
    printf("=== 测试 GetListLength ===\n");
    struct Node* head = CreateList(5);
    assert(GetListLength(head) == 5);
    // 插入一个节点
    InsertAfter(head);
    assert(GetListLength(head) == 6);
    // 删除一个节点
    DeleteNode(head, head->next);
    assert(GetListLength(head) == 5);
    // 清空（保留头节点）
    ClearList(head);
    assert(GetListLength(head) == 1);
    DestroyList(head);
    printf("GetListLength 随操作正确更新: 通过\n\n");
}

void test_GetNodeByIndex() {
    printf("=== 测试 GetNodeByIndex ===\n");
    struct Node* head = CreateList(4);  // 索引 0,1,2,3
    // 索引 0 应返回头节点
    assert(GetNodeByIndex(head, 0) == head);
    // 索引 1 返回第二个节点
    assert(GetNodeByIndex(head, 1) == head->next);
    // 索引 3 返回最后一个节点
    assert(GetNodeByIndex(head, 3) == head->next->next->next);
    // 索引超出范围应返回 NULL？函数未定义，这里不测试越界
    printf("GetNodeByIndex 在有效范围内返回正确节点: 通过\n");
    DestroyList(head);
    printf("\n");
}

// 综合场景测试
void test_integration() {
    printf("=== 综合场景测试 ===\n");
    struct Node* head = CreateList(1);  // 只有一个节点
    assert(head != NULL);
    assert(GetListLength(head) == 1);

    // 在头后插入一个节点
    struct Node* node1 = InsertAfter(head);
    assert(node1 != NULL);
    assert(GetListLength(head) == 2);
    // 在 node1 后插入
    struct Node* node2 = InsertAfter(node1);
    assert(GetListLength(head) == 3);
    // 在 head 前插入一个新头
    struct Node* new_head = InsertBefore(head);
    head = new_head;  // 更新头
    assert(GetListLength(head) == 4);

    // 删除中间节点 (原 node1)
    struct Node* to_del = head->next->next;  // 应该是 node1
    bool ret = DeleteNode(head, to_del);
    assert(ret == true);
    assert(GetListLength(head) == 3);

    // 验证链表完整性
    assert(verifyList(head));

    // 通过索引访问
    struct Node* idx2 = GetNodeByIndex(head, 2);
    assert(idx2 != NULL);
    assert(IsTail(idx2) == true);  // 第三个节点应为尾

    // 清空链表（保留头节点）
    ClearList(head);
    assert(GetListLength(head) == 1);
    assert(head->next == NULL);

    DestroyList(head);
    printf("综合场景测试通过\n\n");
}

int main() {
    printf("========== 双向链表单元测试（头节点计入长度） ==========\n\n");

    test_CreateList();
    test_DestroyList();
    test_ClearList();
    test_InsertAfter();
    test_InsertBefore();
    test_DeleteNode();
    test_PreviousNode_NextNode();
    test_IsHead_IsTail();
    test_GetListLength();
    test_GetNodeByIndex();
    test_integration();

    printf("========== 所有测试通过 ==========\n");
    return 0;
}