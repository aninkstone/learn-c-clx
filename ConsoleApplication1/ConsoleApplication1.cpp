#include <iostream>

int main() {
    char Addition = 0;
    scanf("%c", &Addition);
    switch (Addition) {
    case'+':
        printf("加法\n");
        break;
    case'-':
        printf("减法\n");
        break;
    case'*':
        printf("乘法\n");
        break;
    case'/':
        printf("除法\n");
        break;
    case'%':
        printf("求余\n");
        break;
    default :
        printf("无效");
        break;
    }
    return 0;
}