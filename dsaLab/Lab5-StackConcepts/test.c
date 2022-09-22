#include <stdio.h>
void test(char st[100]) {
    st[0] = 'A';
}

int main() {
    char st[100];
    test(st);
    printf("%s",st);
}