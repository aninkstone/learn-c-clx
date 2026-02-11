#include <iostream>

int main(){
    int j = 100;
    int i = 0;
    printf("%d\n", j);
    int l = 1;
    int o = 0;
    if (i < l) {
        for (; i <= j; i++) {
            o = o + i;
        }
        printf("%d\n", i);
    }
    else {
        printf("%d\n", j);
    }
    return 0;
}