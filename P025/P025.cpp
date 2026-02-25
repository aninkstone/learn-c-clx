#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include "list.h"

/**
 * 打印测试模块信息
 */
static void LogModule(const char* name) {
    printf("[TEST MODULE] %s\n", name);
}

/**
 * 测试链表生命周期：创建、长度获取、索引获取及销毁
 */
void TestLifecycle() {
    LogModule("Lifecycle and Indexing");

    size_t mCount = 10;
    struct Node* mHead = CreateList(mCount);
    
    assert(mHead != NULL);
    assert(GetListLength(mHead) == mCount);

    // 验证首尾
    assert(IsHead(mHead) == true);
    struct Node* mTail = GetNodeByIndex(mHead, mCount - 1);
    assert(mTail != NULL);
    assert(IsTail(mTail) == true);

    // 验证索引越界
    assert(GetNodeByIndex(mHead, mCount) == NULL);

    ClearList(mHead);
    // 根据描述，ClearList 后仅保留头节点
    assert(GetListLength(mHead) == 1);
    assert(IsTail(mHead) == true);

    DestroyList(mHead);
    printf("-> Lifecycle test passed.\n");
}

/**
 * 测试节点插入操作（适配更新后的接口）
 */
void TestInsertOperations() {
    LogModule("Insert Operations");

    struct Node* mHead = CreateList(1);
    mHead->x = 100;

    // 测试在头之后插入
    struct Node* mNewNodeAfter = InsertAfter(mHead, mHead);
    assert(mNewNodeAfter != NULL);
    assert(GetListLength(mHead) == 2);
    assert(NextNode(mHead) == mNewNodeAfter);
    assert(PreviousNode(mNewNodeAfter) == mHead);

    // 测试在节点之前插入
    struct Node* mNewNodeBefore = InsertBefore(mHead, mNewNodeAfter);
    assert(mNewNodeBefore != NULL);
    assert(GetListLength(mHead) == 3);
    // 逻辑顺序应为: Head -> NewNodeBefore -> NewNodeAfter
    assert(NextNode(mHead) == mNewNodeBefore);
    assert(NextNode(mNewNodeBefore) == mNewNodeAfter);

    DestroyList(mHead);
    printf("-> Insert operations test passed.\n");
}

/**
 * 测试节点删除操作
 */
void TestDeleteOperations() {
    LogModule("Delete Operations");

    struct Node* mHead = CreateList(3);
    struct Node* mTarget = GetNodeByIndex(mHead, 1);
    assert(mTarget != NULL);

    bool mResult = DeleteNode(mHead, mTarget);
    assert(mResult == true);
    assert(GetListLength(mHead) == 2);

    // 验证连接是否修补正确
    struct Node* mTail = GetNodeByIndex(mHead, 1);
    assert(PreviousNode(mTail) == mHead);
    assert(NextNode(mHead) == mTail);

    DestroyList(mHead);
    printf("-> Delete operations test passed.\n");
}

/**
 * 测试异常与边界情况
 */
void TestRobustness() {
    LogModule("Robustness");

    // NULL 探测
    assert(GetListLength(NULL) == 0);
    assert(IsHead(NULL) == false);
    assert(IsTail(NULL) == false);
    assert(PreviousNode(NULL) == NULL);
    assert(NextNode(NULL) == NULL);
    assert(DeleteNode(NULL, NULL) == false);

    printf("-> Robustness test passed.\n");
}

int main() {
    printf("=== Starting Doubly Linked List Unit Tests ===\n");

    TestLifecycle();
    TestInsertOperations();
    TestDeleteOperations();
    TestRobustness();

    printf("=== All Tests Finished Successfully ===\n");
    return 0;
}
