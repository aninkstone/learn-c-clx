#include <stdio.h>

int h(int l, int p);
int main() {
    int e = 0;
    int i = 0;
    int j = 0;
    scanf("%d %d", &e, &i);
    j = h(i, e);
    printf("%d\n",  j);
    return 0;
}
int h(int l, int p) {
    int u = l + p;
    return u;
}