#include <cstdio>
#include <cstring>


int main() {

    char str[55];

    int n;
    scanf("%d", &n);

    getchar();

    for (int i = 0; i < n; i ++) {

        fgets(str, 55, stdin);
        str[strcspn(str, "\n")] = 0;

        puts(str);

    }

    return 0;
}