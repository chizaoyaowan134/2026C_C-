#include <cstdio>
#include <cstring>

int main() {

    char str[55];

    scanf("%s", str);

    int len = strlen(str);

    bool flag = true;

    for (int i = 0, j = len - 1; i < j; i ++, j --) {

        if (str[i] != str[j]) {
            flag = false;
            break;
        }

    }

    if (flag) {
        printf("YES");
    } else {
        printf("NO");
    }


}