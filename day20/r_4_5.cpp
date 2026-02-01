#include <cstdio>
#include <cstring>

int main() {

    char str[85][85];

    int count = 0;

    while (true) {

        scanf("%s", str[count]);
        count ++;

        char c = getchar();

        if (c == '\n') {
            break;
        }

    }

    for (int i = count - 1; i >= 0; i --) {

        printf("%s", str[i]);

        if (i > 0) {

            printf(" ");
        }
    }

    return 0;


}