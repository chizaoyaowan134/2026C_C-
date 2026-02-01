#include <cstdio>
#include <cstring>



int main() {

    char str[265];
    scanf("%s", str);

    getchar();

    // 双指针法
    int i = 0;
    int j = strlen(str) - 1;

    bool isRight = true;

    while (i < j) {
        if (str[i] != str[j]) {
            isRight = false;
            break;
        } else {
            i ++;
            j --;
        }

    }

    if (isRight) {
        printf("YES");
    } else {
        printf("NO");
    }
}