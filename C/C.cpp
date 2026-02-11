#include <iostream>
struct Node {
    int data;           // 数据域
    struct Node* next;  // 指针域，指向下一个节点
};

// 在链表末尾添加节点
void append(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
	
struct Node* tou = (struct Node*)malloc(sizoef(struct Node));
memset(tou, 0, sizeof(struct Node));
struct Node* ptr = tou;
for (int i = 0; i < 100; i++) {
    if (ptr->next == NULL) {
        ptr->next = (struct Node*)malloc(sizoef(struct Node));
        memset(ptr->next, 0, sizeof(struct Node));
    }
    ptr = ptr->next;
}
// 设链表100个节点




int main() {
    // 方法1：完全初始化
    int numbers[5] = { 1, 2, 3, 4, 5 };

    // 方法2：部分初始化（剩余元素自动初始化为0）
    int numbers[5] = { 1, 2, 3 }; // 相当于 {1, 2, 3, 0, 0}

    // 方法3：不指定长度，编译器自动计算
    int numbers[] = { 1, 2, 3, 4, 5 }; // 自动创建长度为5的数组

    // 方法4：先声明，后赋值
    int scores[5];
    scores[0] = 90;
    scores[1] = 85;
    // ... 以此类推
int scores[5] = {90, 85, 77, 92, 88}; // 创建
printf("%d", scores[1]); // 访问
scores[2] = 80; // 修改
}
#include <stdlib.h> // 必不可少！
void* malloc(size_t size);
//空          类型  函数





#define (0) NULL
int main() {
    int n = 5;
    int *arr = 0;

    // 第一步 & 第二步：申请内存并类型转换
    arr = (int *)malloc(n * sizeof(int));

    // 第三步：检查是否申请成功
    if (arr == NULL) {
        printf("内存申请失败！\n");
        return 1; // 退出程序
    }
	memset(arr, 0, n * sizeof(int));
    // ... 现在可以使用 arr 了，它就像一个大小为5的数组 ...

    // ！！！非常重要的一步！！！
    free(arr); // 使用完毕后，释放内存

    return 0;
}
int o = 0;//变量
const int p = 0;//变量前加const常量

inline int square(int x) {
    return x * x;
}//内联函数加inline
