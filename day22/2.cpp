#include <cstdio>
#include <cstring>


int main() {

    int n;

    scanf("%d", &n);

    getchar();

    char str[100];

    for (int i = 0; i < n; i ++) {

        fgets(str, sizeof(str), stdin);

        str[strcspn(str, "\r\n")] = '\0';

        printf("%s\n", str);



    }

    return 0;



}