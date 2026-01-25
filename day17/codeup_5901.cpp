#include <cstdio>
#include <cstring>

char c[300];

int main() {

    scanf("%s", c);

    int len = strlen(c);
    int i = 0;
    int j = len - 1;

    while (i < j) {
        if (c[i] != c[j]) {
            printf("NO");
            return 0;
        }
        i ++;
        j --;
    }

    printf("YES");

    return 0;


}