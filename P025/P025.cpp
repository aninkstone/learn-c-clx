#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include "list.h"

/**
 * 打印测试进度
 */
static void LogTestStep(const char* stepName) {
    printf("[RUNNING] %s...\n", stepName);
}

/**
 * 测试链表的创建与基本属性获取
 */
void TestLifecycle() {
    LogTestStep("TestLifecycle");

    size_t mInitialLength = 5;
    struct Node* mHead = CreateList(mInitialLength);
    
    assert(mHead != NULL);
    assert(GetListLength(mHead) == mInitialLength);
    assert(IsHead(mHead) == true);
    
    struct Node* mTail = GetNodeByIndex(mHead, mInitialLength - 1);
    assert(mTail != NULL);
    assert(IsTail(mTail) == true);
    assert(NextNode(mTail) == NULL);

    ClearList(mHead);
    // ClearList 后通常只剩头节点
    assert(GetListLength(mHead) == 1);
    assert(IsTail(mHead) == true);

    DestroyList(mHead);
    printf("[PASSED] TestLifecycle\n");
}

/**
 * 测试节点的插入与链接逻辑
 */
void TestInsertOperations() {
    LogTestStep("TestInsertOperations");

    struct Node* mHead = CreateList(1);
    mHead->x = 10;

    // 测试 InsertAfter
    struct Node* mNodeAfter = InsertAfter(mHead);
    assert(mNodeAfter != NULL);
    mNodeAfter->x = 20;
    assert(GetListLength(mHead) == 2);
    assert(NextNode(mHead) == mNodeAfter);
    assert(PreviousNode(mNodeAfter) == mHead);

    // 测试 InsertBefore
    struct Node* mNodeBefore = InsertBefore(mNodeAfter);
    assert(mNodeBefore != NULL);
    mNodeBefore->x = 15;
    assert(GetListLength(mHead) == 3);
    assert(NextNode(mHead) == mNodeBefore);
    assert(NextNode(mNodeBefore) == mNodeAfter);

    DestroyList(mHead);
    printf("[PASSED] TestInsertOperations\n");
}

/**
 * 测试节点的删除逻辑
 */
void TestDeleteOperations() {
    LogTestStep("TestDeleteOperations");

    struct Node* mHead = CreateList(3);
    struct Node* mMidNode = GetNodeByIndex(mHead, 1);
    struct Node* mTailNode = GetNodeByIndex(mHead, 2);

    // 删除中间节点
    bool mIsDeleted = DeleteNode(mHead, mMidNode);
    assert(mIsDeleted == true);
    assert(GetListLength(mHead) == 2);
    assert(NextNode(mHead) == mTailNode);
    assert(PreviousNode(mTailNode) == mHead);

    // 删除尾节点
    mIsDeleted = DeleteNode(mHead, mTailNode);
    assert(mIsDeleted == true);
    assert(GetListLength(mHead) == 1);
    assert(IsTail(mHead) == true);

    DestroyList(mHead);
    printf("[PASSED] TestDeleteOperations\n");
}

/**
 * 测试边界条件与异常输入
 */
void TestBoundaryConditions() {
    LogTestStep("TestBoundaryConditions");

    // 空指针安全性测试
    assert(GetListLength(NULL) == 0);
    assert(IsHead(NULL) == false);
    assert(IsTail(NULL) == false);
    assert(NextNode(NULL) == NULL);
    assert(PreviousNode(NULL) == NULL);
    assert(GetNodeByIndex(NULL, 0) == NULL);
    assert(DeleteNode(NULL, NULL) == false);

    // 索引越界测试
    struct Node* mHead = CreateList(2);
    assert(GetNodeByIndex(mHead, 5) == NULL);

    DestroyList(mHead);
    printf("[PASSED] TestBoundaryConditions\n");
}

/**
 * 主程序入口
 */
int main() {
    printf("--- Starting Doubly Linked List Unit Tests ---\n");

    TestLifecycle();
    TestInsertOperations();
    TestDeleteOperations();
    TestBoundaryConditions();

    printf("--- All Unit Tests Completed Successfully ---\n");
    return 0;
}
