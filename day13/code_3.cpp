#include <cstdio>
#include <cstring>

int main() {

    char str[55];

    int n;
    scanf("%d", &n);

    getchar();

    for (int i = 0; i < n; i++) {

        scanf("%[^\n]%*c", str);

        puts(str);

    }

    return 0;


}
