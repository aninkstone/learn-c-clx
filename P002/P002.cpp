#include <iostream>

int main() {
    int i = 0;
    int j = 0;
    for (; i <= 99 + 8; i++) {
        j = i + j;
    }
    printf("%d\n", j);
    return 0;
}