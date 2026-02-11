#include <stdio.h>
#include <string.h>

int main() {
    char password[20];
    int attempts = 0;
    int max_attempts = 5;

    while (attempts < max_attempts) {
        printf("请输入密码(还剩%d次): ", max_attempts - attempts);
        scanf("%s", password);

        if (strcmp(password, "123abc") == 0) {
            printf("登录成功！");
            break;
        }
        else {
            printf("密码错误！\n");
            attempts++;
        }
    }

    if (attempts == max_attempts) {
        printf("尝试次数用尽，账户锁定！");
    }
    return 0;
}